#include "stm32f4xx.h"                  // Device header


// 6.3.10 RCC AHB1 peripheral clock register (RCC_AHB1ENR) -> AHB1 CLK ENABLE REGISTER
// DM00031020.pdf
// PORTD IS CONNECTED TO AHB1
// CLK ACCESS TO PORTD IS ENABLED BY SETTING BIT 3 OF RCC_AHB1ENR
#define GPIOD_CLOCK (1<<3) // AHB1ENR BIT 3 FOR PORTD


// 8.4.1 GPIO port mode register (GPIOx_MODER) (x = A..I/J/K) -> MODE REGISTER (32BIT REG. FOR 15 PINS)
// DM00031020.pdf
// MODERy[1:0] (y = 0 ... 15)
// 01: General purpose output mode
// CONFIGURE PINS 12-15 OF PORTD TO OUTPUT MODE 
#define GREEN_BIT	  (1U << 24) // MODER12
#define ORANGE_BIT 	(1U << 26) // MODER13
#define RED_BIT 		(1U << 28) // MODER14
#define BLUE_BIT 		(1U << 30) // MODER15


// LEDS CONNECTED TO PINS 12-15 OF PORTD : STM32F407G-DISC1 Peripherals SCHEMATIC
// 8.4.6 GPIO port output data register (GPIOx_ODR) (x = A..I/J/K)
// DM00031020.pdf
// SET BITS 12-15 OF ODR TO TURN ON THE 4 LEDS  
#define GREEN 	(1U << 12)
#define ORANGE 	(1U << 13)
#define RED 		(1U << 14)
#define BLUE 		(1U << 15)

uint32_t red_stack[64];
uint32_t blue_stack[64];

uint32_t *sp_red = &red_stack[63]; // Add sp_red to Watch 1
uint32_t *sp_blue = &blue_stack[63]; // Add sp_blue to Watch 1

volatile uint32_t  tick;
volatile uint32_t _tick;

void GPIO_Init(void);
void DelayS(uint32_t seconds);
void blueOn(void);
void blueOff(void);
void redOn(void);
void redOff(void);

int blue_main(void);
int red_main(void);


int main(void)
{	
//  volatile uint32_t start = 0U; 
	GPIO_Init();
	
//	if(start) // turn off 'FLOATING POINT HARDWARE' from 'TARGET' tab in 'OPTIONS FOR TARGET' in 'PROJECT' menu
//	{	blue_main();
//	}
//	else
//	{	red_main();
//	}
	
	// STACK FRAME OF red_main THREAD
	*(--sp_red) = (1U << 24); // xPSR - setting bit 24 of xPSR to tell processor to run in Thumb mode
	*(--sp_red) = (uint32_t)&red_main; // PC - ADDRESS OF RED MAIN THREAD IN PC 
	*(--sp_red) = 0x0000000AU; // LR  - THESE VALUES CAN BE ANY RANDOM VALUE, LR TO R0
	*(--sp_red) = 0x0000000BU; // R12
	*(--sp_red) = 0x0000000CU; // R3
	*(--sp_red) = 0x0000000DU; // R2
	*(--sp_red) = 0x0000000EU; // R1
	*(--sp_red) = 0x0000000FU; // R0
	
	
		// STACK FRAME OF blue_main THREAD
	*(--sp_blue) = (1U << 24); // xPSR - setting bit 24 of xPSR to tell processor to run in Thumb mode
	*(--sp_blue) = (uint32_t)&blue_main; // PC - ADDRESS OF BLUE MAIN THREAD IN PC 
	*(--sp_blue) = 0x00000001U; // LR  - THESE VALUES CAN BE ANY RANDOM VALUE, LR TO R0
	*(--sp_blue) = 0x00000002U; // R12
	*(--sp_blue) = 0x00000003U; // R3
	*(--sp_blue) = 0x00000004U; // R2
	*(--sp_blue) = 0x00000005U; // R1
	*(--sp_blue) = 0x00000006U; // R0
	
	while(1)
	{
		// 8.4.6 GPIO port output data register (GPIOx_ODR) (x = A..I/J/K)
		// DM00031020.pdf
		// GPIOD->ODR |= GREEN | ORANGE | RED | BLUE; // TURN ALL LEDS ON
		// GPIOD->ODR ^= GREEN | ORANGE | RED | BLUE; // TOGGLE ALL LEDS ON/OFF
		// DelayS(1);
		
		// blueOn();
		// DelayS(1);
		// blueOff();
		// DelayS(1);
	}
}	


void GPIO_Init(void)
{
	RCC->AHB1ENR |= GPIOD_CLOCK;
	GPIOD->MODER |= GREEN_BIT | ORANGE_BIT | RED_BIT | BLUE_BIT;
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/100U); // delay in seconds, clk running at MHz
	__enable_irq();
	
}	

// Cortex-M4 Devices - Generic User Guide - dui0553a_cortex_m4_dgug.pdf
// 2.3.7 Exception entry and return
// Exception entry occurs when there is a pending exception with sufficient priority and either:
//	• the processor is in Thread mode
//	• the new exception is of higher priority than the exception being handled, in which case
//		the new exception preempts the original exception.
// When one exception preempts another, the exceptions are nested
// Figure 2-3 Exception stack frame
// Without the Floating point storage activated, 
// only these 8 registers: xPSR(R15), PC(R14), LR(R13), R12, R3, R2, R1, R0 
// are stored on the stack as the Exception Stack frame
void SysTick_Handler(void)
{ ++tick;
} // SET BREAK POINT HERE TO SEE STACK FRAME WHEN EXCEPTION OCCURS

uint32_t getTick(void)
{ __disable_irq();
	_tick = tick;
	__enable_irq();
	
	return _tick;
}

void DelayS(uint32_t seconds)
{ seconds*= 100; // convert to milliseconds
	
	uint32_t temp = getTick();
	
	while(getTick() - temp < seconds) 
	{}
}

void blueOn(void)
{
	GPIOD->ODR |= BLUE;
}	

void blueOff(void)
{
	GPIOD->ODR &= ~BLUE;
}

void redOn(void)
{
	GPIOD->ODR |= RED;
}	

void redOff(void)
{
	GPIOD->ODR &= ~RED;
}

int blue_main(void)
{ while(1) 
	{	blueOn();
		DelayS(1);
		blueOff();
		DelayS(1);
	}
}

int red_main(void)
{	while(1) 
	{	redOn();
		DelayS(1);
		redOff();
		DelayS(1);
	}
}	
