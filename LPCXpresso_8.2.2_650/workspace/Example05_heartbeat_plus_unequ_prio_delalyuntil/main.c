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

#include "lpc_types.h"
#include "lpc17xx_clkpwr.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_timer.h"


/* The task function. */
void vTaskFunction( void *pvParameters );
void vTaskFunction1(void *pvParameters );
void vTaskHeartBeat(void *pvParameters );
static void prvToggleLED( void );
void vSetupTimerForRunTimeStats( void );
void vSetupTimer0( unsigned int TICKmicroseconds  );

/* Define the strings that will be passed in as the task parameters.  These are
defined const and off the stack to ensure they remain valid when the tasks are
executing. */
const char *pcTextForTask1 = "Task 1 is running";
const char *pcTextForTask2 = "Task 2 is running";
const char *pcTextForTask3 = "Heart Beat is running";
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
	//vSetupTimerForRunTimeStats( );

	//lecture - processor's control registers - refer to CMSIS core library headers and source files
    //          explore the user-manual of lpc17xx
	//          explore the schematics of lpcxpresso board of lpc17xx
	//          repeat the above steps for all the hw related operations below ???
	//
	//lecture - chapter 8 (pin selection) and chapter 9 (GPIO) of lpc17xx user-manual
	//          must be read
	//          refer to section 8.1 of lpc17xx user-manual
	//          refer to Table 75 of section 8.1 of lpc17xx user-manual
	//          refer to Table 79 of section 8.5 of lpc17xx user-manual
	//          refer to Table 81 of section 8.5.2 of lpc17xx user-manual
	//          refer to Table 102 of section 9.5 of lpc17xx user-manual
	//          refer to table 104 of section 9.5.1 of lpc17xx user-manual
	//          need to experiment and check these bits ???
	//
	//
	//
	//
    //
	//lecture - initializing Timer0 of controller for another set
	//        - of periodic ticks
	//
	vSetupTimer0( 1000 );  //1000usecs - 1msec ticks


	// lecture - Initialise P0_22 for the LED.
    // lecture - refer to lpc17xx user-manual
	//
	//
	LPC_PINCON->PINSEL1	&= ( ~( 3 << 12 ) );
	LPC_GPIO0->FIODIR |= ( 1 << 22 );



	/* Create the first task at priority 1... */
	xTaskCreate( vTaskFunction, "Task 1", 240, (void*)pcTextForTask1, 1, NULL );

	/* ... and the second task at priority 2.  The priority is the second to
	last parameter. */
	xTaskCreate( vTaskFunction1, "Task 2", 240, (void*)pcTextForTask2, 2, NULL );


	xTaskCreate( vTaskHeartBeat, "HeartBeat", 240, (void*)pcTextForTask3,3,NULL );
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



void vTaskHeartBeat( void *pvParameters )
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

		vTaskDelayUntil( &xLastWakeTime, ( 250 / portTICK_RATE_MS ) );
		prvToggleLED();
		//ultimestamp2 = portGET_RUN_TIME_COUNTER_VALUE();

		//vPrintStringAndNumber( pcTaskName, (ultimestamp2-ultimestamp1) );
	}
}

static void prvToggleLED( void )
{
unsigned long ulLEDState;

    //
    //lecture - explore Table 102 of section 9.5 of lpc17xx user-manual
    //
    //

	/* Obtain the current P0 state. */
	ulLEDState = LPC_GPIO0->FIOPIN;

	/* Turn the LED off if it was on, and on if it was off. */
	//LPC_GPIO0->FIOCLR = ulLEDState & ( 1 << 22 );
	//LPC_GPIO0->FIOSET = ( ( ~ulLEDState ) & ( 1 << 22 ) );

	//lecture - nomenclature used here and used in the lpc17xx user-manual
    //          vary slightly
	//
	//lecture - explore Table 102 of section 9.5 of lpc17xx user-manual
	//          explore 9.6.2 and use FIOPIN
    //          explore Table 106 and Table 107 for FIOSET
	//          explore Table 108 and Table 109 for FIOCLR

	/* Turn the LED off if it was on, and on if it was off. */
	//LPC_GPIO0->FIOCLR = ulLEDState & ( 1 << 22 );
	//LPC_GPIO0->FIOSET = ( ( ~ulLEDState ) & ( 1 << 22 ) );

	//lecture - we may try to replace the above code with
	//
	//
	//        - ch8 and ch9 of lpc17xx user-manual
	//
	LPC_GPIO0->FIOPIN = (ulLEDState ^ ( 1<<22 ));

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

//lecture - to be used for Timer 0 / Timer 1 of lpc17xx controller
//
//
//
void vSetupTimer0( unsigned int TICKmicroseconds  )
{

	TIM_TIMERCFG_Type TMR0_Cfg;
	TIM_MATCHCFG_Type TMR0_Match;

  // Power-on Timer 0
   LPC_SC->PCONP |= 1 << 1;

   // Initialise Timer 0, prescale counter = 1 µs
   TMR0_Cfg.PrescaleOption = TIM_PRESCALE_USVAL;
   TMR0_Cfg.PrescaleValue = 1;

   // Use channel 0, MR0
   TMR0_Match.MatchChannel = 0;

   // Enable interrupt when MR0 matches the value in TC register
   TMR0_Match.IntOnMatch = ENABLE;

   // Enable reset on MR0: timer will reset if MR0 matches it
   TMR0_Match.ResetOnMatch = TRUE;

   // Don't stop on MR0 if MR0 matches it
   TMR0_Match.StopOnMatch = FALSE;

   // Do nothing for external output pin if match
   TMR0_Match.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;

   // Tick value
   // Set Match value, count value in microseconds in this version.
   TMR0_Match.MatchValue = TICKmicroseconds;

   // Set configuration for Tim_config and Tim_MatchConfig
   TIM_Init(LPC_TIM0, TIM_TIMER_MODE, &TMR0_Cfg);
   TIM_ConfigMatch(LPC_TIM0, &TMR0_Match);

   // Highest priority = Timer 0
   NVIC_SetPriority(TIMER0_IRQn, 0);

   //
   // Enable interrupt for Timer 0
   NVIC_EnableIRQ(TIMER0_IRQn);

   // Start Timer 0
   TIM_Cmd(LPC_TIM0, ENABLE);

}


unsigned int Tick_count_G = 0;

void TIMER0_IRQHandler(void)
   {
   if ((LPC_TIM0->IR & 0x01) == 0x01)   // If MR0 interrupt, proceed
      {
  //    LPC_TIM0->IR |= 1 << 0;           // Clear MR0 interrupt flag

      // Increment tick count
      Tick_count_G++;


      }
   }



