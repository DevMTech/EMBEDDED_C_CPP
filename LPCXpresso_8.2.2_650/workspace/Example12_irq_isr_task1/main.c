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
#include "semphr.h"

/* Demo includes. */
#include "basic_io.h"

/* Library includes. */
#include "LPC17xx.h"

/* The interrupt number to use for the software interrupt generation.  This
could be any unused number.  In this case, the first chip level (non-system)
interrupt is used */

//lecture - refer to user-manual of lpc17xx for more details !!!

//
//
//
//lecture - we must use this example to illustrate interrupt latency and
//          scheduling jitter !!!
//
//lecture - modify the code to test for preemptions/priorities/context switching
//
//

#define mainSW_INTERRUPT_ID		( 0 )

/* Macro to force an interrupt. */

//lecture - refer to lpc17xx user-manual and CMSIS source files

#define mainTRIGGER_INTERRUPT()	NVIC_SetPendingIRQ( mainSW_INTERRUPT_ID )

/* Macro to clear the same interrupt. */

//lecture - refer to lpc17xx user-manual and CMSIS source files

#define mainCLEAR_INTERRUPT()	NVIC_ClearPendingIRQ( mainSW_INTERRUPT_ID )



/* The priority of the software interrupt.  The interrupt service routine uses
an (interrupt safe) FreeRTOS API function, so the priority of the interrupt must
be equal to or lower than the priority set by
configMAX_SYSCALL_INTERRUPT_PRIORITY - remembering that on the Cortex-M3 high
numeric values represent low priority values, which can be confusing as it is
counter intuitive. */
//
//
//lecture - refer to kernel configuration settings for interrupts
//
//
//

#define mainSOFTWARE_INTERRUPT_PRIORITY 		( 5 )



/* The tasks to be created. */
static void vHandlerTask( void *pvParameters );
static void vPeriodicTask( void *pvParameters );
static void vPeriodicTask1( void *pvParameters);

static void vSetupTimerForRunTimeStats( void );

/* Enable the software interrupt and set its priority. */
static void prvSetupSoftwareInterrupt(void);

/* The service routine for the interrupt.  This is the interrupt that the
task will be synchronized with. */
void vSoftwareInterruptHandler( void );

/*-----------------------------------------------------------*/

/* Declare a variable of type xSemaphoreHandle.  This is used to reference the
semaphore that is used to synchronize a task with an interrupt. */
//
//
//

xSemaphoreHandle xBinarySemaphore;

/*-----------------------------------------------------------*/

int main( void )
{
    /* Before a semaphore is used it must be explicitly created.  In this example
    a binary semaphore is created. */

	//lecture - refer to semphr.h for
	//        - binary semaphore management
	vSetupTimerForRunTimeStats();

	/* Before a semaphore is used it must be explicitly created.  In this example
	    a binary semaphore is created. */

	//lecture - refer to semphr.h and queue.c for more details and comments
	//        - binary semaphore management
    //
	//lecture - we need to check for errors - modify the code accordingly
	//
	//
	vSemaphoreCreateBinary( xBinarySemaphore );

    /* Check the semaphore was created successfully. */
    if( xBinarySemaphore != NULL )
    {
    	/* Enable the software interrupt and set its priority. */
    	prvSetupSoftwareInterrupt();

        /* Create the 'handler' task.  This is the task that will be synchronized
        with the interrupt.  The handler task is created with a high priority to
        ensure it runs immediately after the interrupt exits.  In this case a
        priority of 3 is chosen. */
        xTaskCreate( vHandlerTask, "Handler", 240, NULL, 3, NULL );

        /* Create the task that will periodically generate a software interrupt.
        This is created with a priority below the handler task to ensure it will
        get preempted each time the handler task exits the Blocked state. */
        xTaskCreate( vPeriodicTask, "Periodic", 240, NULL, 4, NULL );
        xTaskCreate( vPeriodicTask1, "Periodic1", 240, NULL, 5, NULL );
        /* Start the scheduler so the created tasks start executing. */
        vTaskStartScheduler();
    }

    /* If all is well we will never reach here as the scheduler will now be
    running the tasks.  If we do reach here then it is likely that there was
    insufficient heap memory available for a resource to be created. */
    for( ;; );
    return 0;
}
/*-----------------------------------------------------------*/
unsigned long volatile ultimestamp1 =0;
unsigned long volatile ultimestamp2=0;
unsigned long volatile ultimestamp3 = 0;

static void vHandlerTask( void *pvParameters )
{
    /* As per most tasks, this task is implemented within an infinite loop.

    Take the semaphore once to start with so the semaphore is empty before the
    infinite loop is entered.  The semaphore was created before the scheduler
    was started so before this task ran for the first time.*/
	//
    //
	//lecture - handler task will first decrement the binary semaphore and block for an event -
	//          this event will be triggered by the an ISR - see the ISR code below !!!
    //
	//
	xSemaphoreTake( xBinarySemaphore, 0 );

    for( ;; )
    {
        /* Use the semaphore to wait for the event.  The task blocks
        indefinitely meaning this function call will only return once the
        semaphore has been successfully obtained - so there is no need to check
        the returned value. */
        xSemaphoreTake( xBinarySemaphore, portMAX_DELAY );
        //
        //lecture - timestamp3 must be collected here - it will when the high priority task is scheduled
        //          and executed - timestamp3 - timestamp1 will give scheduling jitter -
        //          can be measured here (approx.)
        ultimestamp3  = portGET_RUN_TIME_COUNTER_VALUE();
        //vPrintStringAndNumber( "timestamp1", (ultimestamp1) );
        //vPrintStringAndNumber( "timestamp2", (ultimestamp2) );
        //vPrintStringAndNumber( "timestamp3", (ultimestamp3) );
        //vPrintStringAndNumber( "Interrupt Latency", (ultimestamp2-ultimestamp1) );
        vPrintStringAndNumber( "Scheduling jitter", (ultimestamp3-ultimestamp1) );
        /* To get here the event must have occurred.  Process the event (in this
        case we just print out a message). */
        //vPrintString( "Handler task - Processing event.\n" );
    }
}
/*-----------------------------------------------------------*/


static void vPeriodicTask( void *pvParameters )
{
    /* As per most tasks, this task is implemented within an infinite loop. */
    for( ;; )
    {
        /* This task is just used to 'simulate' an interrupt.  This is done by
        periodically generating a software interrupt. */
        vTaskDelay( 5 / portTICK_RATE_MS );

        /* Generate the interrupt, printing a message both before hand and
        afterwards so the sequence of execution is evident from the output. */
        //vPrintString( "Periodic task - About to generate an interrupt.\n" );
        //lecture - timestamp1 must be collected before the interrupt is generated
        //
        ultimestamp1  = portGET_RUN_TIME_COUNTER_VALUE();

        mainTRIGGER_INTERRUPT();
        //vPrintString( "Periodic task - Interrupt generated.\n\n" );
    }
}

static void vPeriodicTask1( void *pvParameters )
{
    /* As per most tasks, this task is implemented within an infinite loop. */
    for( ;; )
    {
        /* This task is just used to 'simulate' an interrupt.  This is done by
        periodically generating a software interrupt. */
        vTaskDelay( 5 / portTICK_RATE_MS );

        /* Generate the interrupt, printing a message both before hand and
        afterwards so the sequence of execution is evident from the output. */
        //vPrintString( "Periodic task1 \n" );
        //lecture - timestamp1 must be collected before the interrupt is generated
        //
        //ultimestamp1  = portGET_RUN_TIME_COUNTER_VALUE();

        //mainTRIGGER_INTERRUPT();
        //vPrintString( "Periodic task - Interrupt generated.\n\n" );
    }
}

/*-----------------------------------------------------------*/
//
//lecture - explore lpc17xx manual and CMSIS source files
//
//lecture - refer to 34.4.2.7 of lpc17xx user-manual - also, section 6.5.11
//          refer to 34.4.2, 34.4.2.2, 34.4.2.3 and related sections of the user-manual
//          refer to related CMSIS files
//
//
static void prvSetupSoftwareInterrupt()
{

	/* The interrupt service routine uses an (interrupt safe) FreeRTOS API
	function so the interrupt priority must be at or below the priority defined
	by configSYSCALL_INTERRUPT_PRIORITY. */
	NVIC_SetPriority( mainSW_INTERRUPT_ID, mainSOFTWARE_INTERRUPT_PRIORITY );

	/* Enable the interrupt. */
	NVIC_EnableIRQ( mainSW_INTERRUPT_ID );
}
/*-----------------------------------------------------------*/


void vSoftwareInterruptHandler( void )
{
portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;


    //lecture - timestamp2 is collected here in the interrupt handler(ISR)
    //          timestamp2-timestamp1 gives the interrupt latency(approx.)
    ultimestamp2  = portGET_RUN_TIME_COUNTER_VALUE();

    /* 'Give' the semaphore to unblock the task. */
    //
    //lecture - what happens, when this API is invoked ??
    //          this is an ISR safe API ??
    //
    //lecture - refer to semphr.h and queue.c for more details and comments
    //
    //
    xSemaphoreGiveFromISR( xBinarySemaphore, &xHigherPriorityTaskWoken );

    /* Clear the software interrupt bit using the interrupt controllers
    Clear Pending register. */
    //
    //lecture - refer to 34.4.2.5 and 34.4.2.9.1 - in the case of software
    //          triggered interrupt using ISER, we must clear using ICER
    //
    mainCLEAR_INTERRUPT();

    /* Giving the semaphore may have unblocked a task - if it did and the
    unblocked task has a priority equal to or above the currently executing
    task then xHigherPriorityTaskWoken will have been set to pdTRUE and
    portEND_SWITCHING_ISR() will force a context switch to the newly unblocked
    higher priority task.

    NOTE: The syntax for forcing a context switch within an ISR varies between
    FreeRTOS ports.  The portEND_SWITCHING_ISR() macro is provided as part of
    the Cortex-M3 port layer for this purpose.  taskYIELD() must never be called
    from an ISR! */
    //
    //lecture - if a higher priority task is woken up, this API will invoke
    //          the scheduler !!! otherwise, it will return like any other
    //          interrupt return - certain specifics are handled for CM3
    //
    //
    portEND_SWITCHING_ISR( xHigherPriorityTaskWoken );
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

/* Power up and drive the timer 0. */

static void vSetupTimerForRunTimeStats( void )
{
const unsigned long TCR_COUNT_RESET = 2, CTCR_CTM_TIMER = 0x00, TCR_COUNT_ENABLE = 0x01;

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
LPC_TIM0->PR =  ( configCPU_CLOCK_HZ / 1000000UL ) - 1UL;

/* Start the counter. */
LPC_TIM0->TCR = TCR_COUNT_ENABLE;
}






