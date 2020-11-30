/*
    FreeRTOS V6.1.1 - Copyright (C) 2011 Real Time Engineers Ltd.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    ***NOTE*** The exception to the GPL is included to allow you to distribute
    a combined work that includes FreeRTOS without being obliged to provide the
    source code for proprietary components outside of the FreeRTOS kernel.
    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public
    License and the FreeRTOS license exception along with FreeRTOS; if not it
    can be viewed here: http://www.freertos.org/a00114.html and also obtained
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!

    http://www.FreeRTOS.org - Documentation, latest information, license and
    contact details.

    http://www.SafeRTOS.com - A version that is certified for use in safety
    critical systems.

    http://www.OpenRTOS.com - Commercial support, development, porting,
    licensing and training services.
*/



//lecture - equal priority tasks, using different functions

/* FreeRTOS.org includes. */

//lecture - FreeRTOS.h includes many other includes of FreeRTOS
//lecture - refer to FreeRTOS.h for more comments
//lecture - task.h is needed for using task creation APIs and other objects
#include "FreeRTOS.h"

#include "task.h"

//lecture - used for semihosting - mainly useful for console printing

/* Demo includes. */
#include "basic_io.h"

/* Used as a loop counter to create a very crude delay. */
#define mainDELAY_LOOP_COUNT		( 0xfffff )

//lecture - task prototypes

/* The task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

/*-----------------------------------------------------------*/
//lecture - since 2 tasks are of same priority, there are 2 possible schedules -
//          if kernel preemption is enabled, RR/time-slicing is enabled
//          if kernel preemption is disabled, RR/time-slicing is disabled
//lecture - refer to comments, in FreeRTOSConfig.h
//
//lecture - if the kernel preemption is disabled, is there a possibility of
//          a proper schedule ??
//
int main( void )
{
	//lecture - as per the rules semihosting - this is nothing to do with FreeRTOS
	//
	/* Init the semi-hosting. */

	printf( "\n" );
    //
	//lecture - refer to task.h and tasks.c for more comments on xTaskCreate()
	//          and xTaskGenericCreate()
	//
	//lecture - in this implementation, the stack allocated will be used as task stack, which
	//          is independent of the main stack - this will be clear, if you look at the
	//          internals of task creation API and context switching mechanism
	//
	/* Create one of the two tasks. */
	xTaskCreate(	vTask1,		/* Pointer to the function that implements the task. */
					"Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
					240,		/* Stack depth in words. */
					NULL,		/* We are not using the task parameter. */
					1,			/* This task will run at priority 1. */
					NULL );		/* We are not using the task handle. */

	/* Create the other task in exactly the same way. */
	xTaskCreate( vTask2, "Task 2", 240, NULL, 1, NULL );

	/* Start the scheduler so our tasks start executing. */
    //
	//
	//lecture - vTaskStartScheduler() initializes hw timer, creates idle task and loads the most
	//          eligible task on the processor - control is passed to the kernel from here !!!!
	//
	//
	//lecture - if vTaskStartScheduler() is successful,
	//
	//lecture - refer to task.h and tasks.c for more comments on vTaskStartScheduler()
	//
	//
	//
	vTaskStartScheduler();


	//lecture - we will reach here, if there is error - otherwise, we should never reach here

	/* If all is well we will never reach here as the scheduler will now be
	running.  If we do reach here then it is likely that there was insufficient
	heap available for the idle task to be created. */
	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

void vTask1( void *pvParameters )
{
const char *pcTaskName = "Task 1 is running\n";
volatile unsigned long ul;

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		//lecture - refer to basic_io.c
        //lecture - uses semihosting feature of the development environment !!!
		//        - is this API using locks ? uses scheduler locking
		//
		vPrintString( pcTaskName );

		//lecture - a dummy loop - just for demo ??
		/* Delay for a period. */
		for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
		{
			/* This loop is just a very crude delay implementation.  There is
			nothing to do in here.  Later exercises will replace this crude
			loop with a proper delay/sleep function. */
		}
	}

	//??????delete your task
}
/*-----------------------------------------------------------*/
//lecture - just a duplicate of the first task's code

void vTask2( void *pvParameters )
{
const char *pcTaskName = "Task 2 is running\n";
volatile unsigned long ul;

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		vPrintString( pcTaskName );

		/* Delay for a period. */
		for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
		{
			/* This loop is just a very crude delay implementation.  There is
			nothing to do in here.  Later exercises will replace this crude
			loop with a proper delay/sleep function. */
		}
	}
}
/*-----------------------------------------------------------*/
//
//lecture - we may use hooks for
//          printing diagnostics, statistics and time-stamps ???
//
//lecture - typically invoked, when there is a heap allocation failure !!!
void vApplicationMallocFailedHook( void )
{
	/* This function will only be called if an API call to create a task, queue
	or semaphore fails because there is too little heap RAM remaining. */
	for( ;; );
}
/*-----------------------------------------------------------*/


//lecture - can be used, if we need to check stack overflow
//          there are different techniques to check stack overflow
//          use appropriate technique as per need
void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
	/* This function will only be called if a task overflows its stack.  Note
	that stack overflow checking does slow down the context switch
	implementation. */
	for( ;; );
}
/*-----------------------------------------------------------*/
//lecture - we may use the idle hook to print the diagnostics and
//          system information - this will not interfere with
//          the real-time tasks


void vApplicationIdleHook( void )
{
	/* This example does not use the idle hook to perform any processing. */
}
/*-----------------------------------------------------------*/

//lecture - if need to process some code, during every system tick
//          processing ???

void vApplicationTickHook( void )
{
	/* This example does not use the tick hook to perform any processing. */
}


