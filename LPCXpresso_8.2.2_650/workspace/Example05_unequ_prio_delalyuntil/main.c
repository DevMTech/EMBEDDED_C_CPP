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
//
//
//lecture - periodic tasks with different priorities - this is a better implementation
//          compared to Example04
//
//lecture - extra code is added for timing measurement - however, using diagnostic messages
//          may add additional latency to measured parameters, if not taken care of !!!
//
//
//lecture - refer to diagram ?? of slides ??
//
/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "basic_io.h"

/* The task function. */
void vTaskFunction( void *pvParameters );
void vTaskFunction1(void *pvParameters );

/* Define the strings that will be passed in as the task parameters.  These are
defined const and off the stack to ensure they remain valid when the tasks are
executing. */
const char *pcTextForTask1 = "Task 1 is running";
const char *pcTextForTask2 = "Task 2 is running";

/*-----------------------------------------------------------*/

int main( void )
{
    //
	//lecture - we set-up an extra hw timer for high resolution time-stamps
	//          we will be using these time-stamps to measure the performance of
	//          periodic real-time tasks
	//
	//lecture - modify the set-up of hw timer, as per resolution needs
	//
	//
	vSetupTimerForRunTimeStats( );
	/* Create the first task at priority 1... */
	xTaskCreate( vTaskFunction, "Task 1", 240, (void*)pcTextForTask1, 1, NULL );

	/* ... and the second task at priority 2.  The priority is the second to
	last parameter. */
	xTaskCreate( vTaskFunction1, "Task 2", 240, (void*)pcTextForTask2, 2, NULL );

	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();	
	
	/* If all is well we will never reach here as the scheduler will now be
	running.  If we do reach here then it is likely that there was insufficient
	heap available for the idle task to be created. */
	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

unsigned long ultimestamp1 = ( configCPU_CLOCK_HZ / configTICK_RATE_HZ ) - 1UL;
unsigned long ultimestamp2 = 0;
unsigned long ultimestamp3 = 0;
void vTaskFunction( void *pvParameters )
{
char *pcTaskName;
portTickType xLastWakeTime;

	/* The string to print out is passed in via the parameter.  Cast this to a
	character pointer. */


    pcTaskName = ( char * ) pvParameters;

	/* The xLastWakeTime variable needs to be initialized with the current tick
	count.  Note that this is the only time we access this variable.  From this
	point on xLastWakeTime is managed automatically by the vTaskDelayUntil()
	API function. */
    //
	//lecture - read the current sw system clock - the system clock is driven by system tick/handler
	//
    //
	xLastWakeTime = xTaskGetTickCount();

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		//vPrintString( pcTaskName );

		/* We want this task to execute exactly every 250 milliseconds.  As per
		the vTaskDelay() function, time is measured in ticks, and the
		portTICK_RATE_MS constant is used to convert this to milliseconds.
		xLastWakeTime is automatically updated within vTaskDelayUntil() so does not
		have to be updated by this task code. */
        //
		//lecture - before blocking - read the current time-stamp from the extra hw timer,
		//          which is running
		//
		//ultimestamp1  = portGET_RUN_TIME_COUNTER_VALUE();
		//ultimestamp2 = SysTick->VAL;

        //
		//lecture - this API will add our task to a delayed list - the time-base is
		//          sw system clock and the future time-stamp is based on first parameter and
		//          second parameter
		//
		//lecture - for more details on vTaskDelayUntil(), refer to task.h and tasks.c - more
		//          comments are provided, in those files
		//
		//
		//
		vTaskDelayUntil( &xLastWakeTime, ( 200 / portTICK_RATE_MS ) );
		//reading systick current value of counter for measuring scheduling jitter -
		//task release time latency - from the point of interrupt event to
		//the execution of the instruction of a periodic task
		//
		ultimestamp3 = SysTick->VAL;
		//
		//lecture - after wake-up - read the current time-stamp from the extra hw timer,
		//          which is running
		//ultimestamp2 = portGET_RUN_TIME_COUNTER_VALUE();
        //
		//lecture - this API is used to print information to the diagnostic console
		//
		//lecture - param1 must be a pointer to a string and param2 must be a number
		//
		//
		//
		//vPrintStringAndNumber( pcTaskName, (ultimestamp2 - ultimestamp1) );
		vPrintStringAndNumber( pcTaskName, (ultimestamp1 - ultimestamp2) );
		//vPrintStringAndNumber( pcTaskName, (ultimestamp1 - ultimestamp3) );
		//vPrintStringAndNumber( pcTaskName, (ultimestamp2 + ultimestamp1 - ultimestamp3) );
	}
}

void vTaskFunction1( void *pvParameters )
{
char *pcTaskName;
portTickType xLastWakeTime;

	/* The string to print out is passed in via the parameter.  Cast this to a
	character pointer. */


    pcTaskName = ( char * ) pvParameters;

	/* The xLastWakeTime variable needs to be initialized with the current tick
	count.  Note that this is the only time we access this variable.  From this
	point on xLastWakeTime is managed automatically by the vTaskDelayUntil()
	API function. */

	//lecture - repeat the same for task2
    //
    //          however, enable the diagnostics, in one of the tasks at a time -
    //          diagnostic messages increase the latency and you may see large
    //          latencies ???
	//

	xLastWakeTime = xTaskGetTickCount();

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		//vPrintString( pcTaskName );

		/* We want this task to execute exactly every 250 milliseconds.  As per
		the vTaskDelay() function, time is measured in ticks, and the
		portTICK_RATE_MS constant is used to convert this to milliseconds.
		xLastWakeTime is automatically updated within vTaskDelayUntil() so does not
		have to be updated by this task code. */

		//lecture - we need to explore this API, using reference manual,
		//          user-manual and source-code
		//ultimestamp1  = portGET_RUN_TIME_COUNTER_VALUE();

		vTaskDelayUntil( &xLastWakeTime, ( 70 / portTICK_RATE_MS ) );
		//ultimestamp2 = portGET_RUN_TIME_COUNTER_VALUE();

		//vPrintStringAndNumber( pcTaskName, (ultimestamp2-ultimestamp1) );
	}
}





/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
	/* This function will only be called if an API call to create a task, queue
	or semaphore fails because there is too little heap RAM remaining. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed char *pcTaskName )
{
	/* This function will only be called if a task overflows its stack.  Note
	that stack overflow checking does slow down the context switch
	implementation. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
	/* This example does not use the idle hook to perform any processing. */
}
/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This example does not use the tick hook to perform any processing. */
}



/* This function configures a timer to be used as the run time statistics time
base.  The function implementation requires knowledge of the LPC17xx peripheral
registers, and uses macros that are available when the LPC17xx.h header file is
used.  In this example LPC17xx.h is included from FreeRTOSConfig.h. */

//lecture - explore this code with lpc17xx user-manual and reverse
//          engineer
//
//
//lecture - start with chapter21 of lpc17xx user-manual and refer to other chapters
//          which are cross-referenced
//
//
//         - hw timer is programmed as per required resolution
//
//
//

void vSetupTimerForRunTimeStats( void )
{
const unsigned long TCR_COUNT_RESET = 2, CTCR_CTM_TIMER = 0x00, TCR_COUNT_ENABLE = 0x01;

	/* Power up and drive the timer 0. */
//
//
//lecture - refer to chapter 4 of lpc17xx user-manual
//          refer to Table 14 of section 4.2 of lpc17xx user-manual
//          refer to section 4.8.5 and 4.8.6 / Table 43
//          refer to section 4.8.9/Table 46 of lpc17xx user-manual
//          refer to section 21.1 of Timer 0/1/2/3
//          PCONP bit 1 is set to enable Timer 0
//          PCLKSEL0 register can be referred to in Table 40
//          PCLKSEL0 is used to set the PLCK_peripheral to CCLK (same as CPU clock frequency)
//          we must spot the values of CCLK ??
//          TCR(Timer Control register) can be used to reset Timer counter and
//          pre-scale counter - refer to Table 428
//          CTCR register can be used to select between Timer mode and counter mode -
//          in our case, we select Timer mode - in Timer mode, TC is incremented
//          as per prescale counter register and prescale register
//          PR is programmed and its value is used to match with prescale counter -
//          we need to explore and find why the value has been chosen - it may
//          connection with systick timer's tick period
//          TCR can also be used to enable prescale counter and Timer counter,
//          as per Timer mode operation
//
//          once enabled, TC (Timer Counter register) is an upcounting register
//          we can read it, when needed ??? it acts as a time-stamp ??
//          we can find the difference between 2 time-stamps and calculate
//          the time elapsed, latency ??
//
//
	LPC_SC->PCONP |= 0x02UL;
	LPC_SC->PCLKSEL0 = ( LPC_SC->PCLKSEL0 & (~(0x3<<2)) ) | ( 0x01 << 2 );

	/* Reset Timer 0 */
	LPC_TIM0->TCR = TCR_COUNT_RESET;

	/* The timer needs to just count up continuously. */
	LPC_TIM0->CTCR = CTCR_CTM_TIMER;

	/* The clock driving the timer is prescaled to a frequency that is good enough
	to get a decent resolution,	but not so fast that the counter value will
	overflow too quickly. */
	//lecture - what is the pre-scale value ?
	//lecture - what is the clock frequency value ?

	LPC_TIM0->PR =  ( configCPU_CLOCK_HZ / 10000UL ) - 1UL;

	/* Start the counter. */
	LPC_TIM0->TCR = TCR_COUNT_ENABLE;
}
