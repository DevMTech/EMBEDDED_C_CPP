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

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
//
//lecture - another good example for measuring time-stamps and performance
//          parameters
//
//lecture - this example illustrates performance statistics measurements
//
//
/* The task functions. */
static void prvDemoTask( void *pvParameters );
static void prvStatsTask( void *pvParameters );

/*-----------------------------------------------------------*/

int main( void )
{
	/* Init the semi-hosting. */
	printf( "\n" );

	//lecture - experimentation
	//
	vSetupTimerForRunTimeStats( );
	/* Two tasks are created above the idle task priority (at tskIDLE_PRIORITY + 
	1) that just use up some processing time before blocking for a very short 
	period. */
	xTaskCreate( prvDemoTask, "Demo1", 240, "DemoTask1",	tskIDLE_PRIORITY + 1, NULL );
    //xTaskCreate( prvDemoTask, "Demo2", 240, "DemoTask2", tskIDLE_PRIORITY + 2, NULL );

	/* The highest priority task (created at tskIDLE_PRIORITY + 2 ) runs every 
	five seconds and prints out the run time stats. */
	xTaskCreate( prvStatsTask, "Stats", 240, "StatsTask", tskIDLE_PRIORITY + 3, NULL );

	/* Start the scheduler so the test task starts executing. */
	vTaskStartScheduler();	
	
	/* If all is well we will never reach here as the scheduler will now be
	running.  If we do reach here then it is likely that there was insufficient
	heap available for the idle task to be created. */
	for( ;; );
	return 0;
}
/*-----------------------------------------------------------*/

static void prvDemoTask( void *pvParameters )
{

	char *pcTaskName;
volatile unsigned long ulLoopCounter;
volatile unsigned long ultimestamp1 =0, ultimestamp2=0;
const unsigned long ulMaxLoopCount = 0x1fffUL;
portTickType xLastExecutionTime;


/* The task will run every 5 milliseconds. */
const portTickType xBlockPeriod = ( 50 / portTICK_RATE_MS );

     pcTaskName = ( char * ) pvParameters;
	/* Initialise xLastExecutionTime to the current time.  This is the only
	time this variable needs to be written to explicitly.  Afterwards it is
	updated internally within the xTaskDelayUnitl() API function. */
	xLastExecutionTime = xTaskGetTickCount();

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Wait until it is time to run this task again. */
		//lecture - experiment - for time stamps
		//
		//
        //ultimestamp1  = portGET_RUN_TIME_COUNTER_VALUE();
		//vTaskDelayUntil( &xLastExecutionTime, xBlockPeriod );
		vTaskDelay(xBlockPeriod);
		ultimestamp1 = portGET_RUN_TIME_COUNTER_VALUE();

		vPrintStringAndNumber( pcTaskName, ultimestamp1 );
		//vPrintStringAndNumber( pcTaskName, ultimestamp2 );

		//vPrintStringAndNumber( pcTaskName, (ultimestamp2-ultimestamp1) );
		
		/* This loop is just to ensure the task uses up enough processing time
		to register in the run time statistics. */
		//for( ulLoopCounter = 0; ulLoopCounter < ulMaxLoopCount; ulLoopCounter++ )
		//{
			/* There is nothing to do here.  Just perform a "no operation" to
			ensure there are some instructions generated. */
		//	__asm volatile( "NOP " );
		//}
	}
}
/*-----------------------------------------------------------*/

static void prvStatsTask( void *pvParameters )
{

	char *pcTaskName;
portTickType xLastExecutionTime;
volatile unsigned long ultimestamp1 =0, ultimestamp2=0;

/* The buffer used to hold the run time stats text needs to be quite large.  It 
is therefore declared static to ensure it is not allocated on the task stack.  
This makes this function non re-entrant. */
static signed char cStringBuffer[ 512 ]; 

/* The task will run every 5 seconds. */
const portTickType xBlockPeriod = ( 500 / portTICK_RATE_MS );
pcTaskName = ( char * ) pvParameters;
	/* Initialise xLastExecutionTime to the current time.  This is the only
	time this variable needs to be written to explicitly.  Afterwards it is
	updated internally within the xTaskDelayUntil() API function. */
	xLastExecutionTime = xTaskGetTickCount();

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Wait until it is time to run this task again. */
		//vTaskDelayUntil( &xLastExecutionTime, xBlockPeriod );

		/* Wait until it is time to run this task again. */
				//lecture - experiment - for time stamps
				//
				//
		        //ultimestamp1  = portGET_RUN_TIME_COUNTER_VALUE();
				vTaskDelayUntil( &xLastExecutionTime, xBlockPeriod );
				ultimestamp1 = portGET_RUN_TIME_COUNTER_VALUE();

				vPrintStringAndNumber( pcTaskName, ultimestamp1 );
				//vPrintStringAndNumber( pcTaskName, ultimestamp2 );

				//vPrintStringAndNumber( pcTaskName, (ultimestamp2-ultimestamp1) );



		/* Generate a text table from the run time stats.  This must fit into
		the cStringBuffer array. */
		//vTaskGetRunTimeStats( cStringBuffer );
		
		/* Print out column headings for the run time stats table. */
		//consoleprint( "\nTask\t\tAbs\t\t%\n" );
		//consoleprint( "------------------------------------" );
		
		/* Print out the run time stats themselves. */
		//consoleprint( cStringBuffer );
	}
}
/*-----------------------------------------------------------*/

/* This function configures a timer to be used as the run time statistics time 
base.  The function implementation requires knowledge of the LPC17xx peripheral 
registers, and uses macros that are available when the LPC17xx.h header file is 
used.  In this example LPC17xx.h is included from FreeRTOSConfig.h. */

//lecture - we must explore this code with lpc17xx user-manual and reverse
//          engineer
//          we must experiment and test, if the results are ok
//
//lecture - start with chapter21 of lpc17xx user-manual and refer to other chapters
//          which are cross-referenced - note down all the details for each register
//          and bits
//
//         - initially, explore as per register values and bit values??
//         - next, read the ch21 thoroughly ??
//
//         - start with register values/ bit values

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
//          we must spot the values of CCLK ?? need to check more on clock related
//          details - explore more ??
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
	LPC_TIM0->PR =  ( configCPU_CLOCK_HZ / 10000UL ) - 1UL;

	/* Start the counter. */
	LPC_TIM0->TCR = TCR_COUNT_ENABLE;
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


