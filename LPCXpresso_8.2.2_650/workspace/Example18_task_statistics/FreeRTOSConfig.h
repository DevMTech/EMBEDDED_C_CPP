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


/******************************************************************************
	See http://www.freertos.org/a00110.html for an explanation of the
	definitions contained in this file.
******************************************************************************/

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "LPC17xx.h"

/*-----------------------------------------------------------
 * Application specific definitions.

 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *----------------------------------------------------------*/
//
//
//
//lecture - configuration parameters that start with config define attributes of
//          the kernel and in some cases, add code to the kernel
//lecture - if this option is set to 1, preemption will be enabled in system tick
//          handler and other places - system APIs and ISRs
//lecture - if this option is set to 0, preemption will be disabled in system tick
//          handler - will be still enable,in other places - system APIs and
//          ISRs
//lecture - refer to tasks.c. queue.c and port.c
//
//lecture - you can find preemption points in various parts of the kernel - portYIELD_WITHIN_API()
//
//lecture - idle task hook function will be invoked from idle task at end of each iteration of
//          idle task method - if the option is set, we must provide a method, in our application code
//
//lecture - no. of priorities are configurable - more the no., levels of ready queues increases -
//          foot-print may increase
//lecture - TICK_HOOK is used to execute a method, during sys tick handler - we must define a
//          tick handler, in our application code
//
//lecture - CPU_CLOCK_HZ is the frequency of the clock that drives systick timer
//
//lecture - systick timer is set to generate hw interrupts with 1000hz frequency - 1msec period of
//          hw timer interrupt
//
//lecture - minimal stack is provided - to get actual length, multiply by word length
//
//lecture - heap size is configurable - in this case, 10kiB - depends on controller
//
//lecture - TRACE facility must be used for visualization and debugging - refer to examples for
//          clarity
//
//lecture - we use 32-bit sw system clock, which is driven by sys tick timer/handler
//
//
//lecture - IDLE task will yield, if SHOULD_YIELD is set and PREEMPTION is set - otherwise, only
//          time-slice is applied
//
//lecture - co-routines are very lightweight tasks, which share stacks - we do not use them - you can
//          just ignore co-routines
//
//lecture - mutexes can be enabled or disabled
//
//lecture - we use counting semaphores
//
//lecture - kernel aware debugging may use registry for store handles
//
//lecture - stack overflow can be checked - there are 2 methods - in addition, a stack overflow hook
//          must be provided
//
//lecture - malloc failed hook will be invoked, when pvPortMalloc() is invoked and returns NULL
//
//
#define configUSE_PREEMPTION		0
#define configUSE_IDLE_HOOK			1
#define configMAX_PRIORITIES		( ( unsigned portBASE_TYPE ) 5 )
#define configUSE_TICK_HOOK			1
#define configCPU_CLOCK_HZ			( 100000000UL )
#define configTICK_RATE_HZ			( ( portTickType ) 1000 )
#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 100 )
#define configTOTAL_HEAP_SIZE		( ( size_t ) ( 10 * 1024 ) )
#define configMAX_TASK_NAME_LEN		( 12 )
#define configUSE_TRACE_FACILITY	0
#define configUSE_16_BIT_TICKS		0
#define configIDLE_SHOULD_YIELD		0
#define configUSE_CO_ROUTINES 		0
#define configUSE_MUTEXES			1

#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

#define configUSE_COUNTING_SEMAPHORES 	1
#define configUSE_ALTERNATIVE_API 		0
#define configCHECK_FOR_STACK_OVERFLOW	2
#define configUSE_RECURSIVE_MUTEXES		0
#define configQUEUE_REGISTRY_SIZE		0
#define configGENERATE_RUN_TIME_STATS	0
#define configUSE_MALLOC_FAILED_HOOK	1

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
//
//lecture - some of these INCLUDE_ options are needed to include or exclude these methods from the
//          kernel
//
//lecture - INCLUDE_vTaskSuspend is needed to enable vTaskSuspend(), xTaskResume() and related APIs
//          when this is set, maximum delay is infinite - otherwise, it will a definite value - in ticks !!!
//
//lecture - we can set INCLUDE_uxTaskGetStackHighWaterMark to check the worst case usage of stack ??
//
//
#define INCLUDE_vTaskPrioritySet			1
#define INCLUDE_uxTaskPriorityGet			1
#define INCLUDE_vTaskDelete					1
#define INCLUDE_vTaskCleanUpResources		0
#define INCLUDE_vTaskSuspend				1
#define INCLUDE_vTaskDelayUntil				1
#define INCLUDE_vTaskDelay					1
#define INCLUDE_uxTaskGetStackHighWaterMark	0

/* Use the system definition, if there is one */
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       __NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       5        /* 32 priority levels */
#endif
//
//
//lecture - this is the interrupt priority assigned to FreeRTOS system interrupts - SYSTICK, PENDSV and
//          SVC
//
/* The lowest priority. */
#define configKERNEL_INTERRUPT_PRIORITY 	( 31 << (8 - configPRIO_BITS) )
//
//
//lecture - this is the highest interrupt priority that can be assigned to any ISR that may
//          use FREERTOS ISR safe methods - interrupts with priorities assigned between
//          configKERNEL_INTERRUPT_PRIORITY and configMAX_SYSCALL_INTERRUPT_PRIORITY(inclusive)
//          are typically disabled by kernel code, during critical sections
//
//
/* Priority 5, or 160 as only the top three bits are implemented. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( 5 << (8 - configPRIO_BITS) )
//
//lecture - useful for time-stamp measurements - we can increase the frequency of the clock
//          if we need higher resolution to better understand the latencies of parameters

/* vSetupTimerForRunTimeStats() is defined in main.c and configures TIM0 as
a free running, 10KHz, 32-bit timer/counter.  portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()
is called automatically when the scheduler is started whenever 
configGENERATE_RUN_TIME_STATS is set to 1. */
//void vSetupTimerForRunTimeStats( void );
//#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() vSetupTimerForRunTimeStats()

/* The current TIM0 counter value provides the run time statistics time. */
#define portGET_RUN_TIME_COUNTER_VALUE() LPC_TIM0->TC

/*-----------------------------------------------------------*/

#endif /* FREERTOS_CONFIG_H */

