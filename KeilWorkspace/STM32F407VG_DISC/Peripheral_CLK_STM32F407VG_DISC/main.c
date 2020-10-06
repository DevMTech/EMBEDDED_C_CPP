#include <stdint.h>
#include "stm32f407xx.h"

int main (void)
{	
	RCC_TypeDef *pRCC;
	ADC_TypeDef *pADC;	
	GPIO_TypeDef *pGPIO;
		
	
	pRCC = RCC;
	
	pADC = ADC1;	// ADC_BASE_ADDRESS = 0x40012000
	pGPIO = GPIOA;
	
	
	// BEFORE ACCESSING ANY PERIPHERAL, THE ASSOCIATED CLOCK HAS TO BE ENABLED 
		
	// RM0900 DM00031020 6.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
	pRCC->APB2ENR |= (1 << 8); //SET BIT 8 TO ENABLE ADC1 // pRCC->APB2ENR = pRCC->APB2ENR | (1 << 8);
	
	// RM0900 DM00031020 6.3.10 RCC AHB1 peripheral clock register (RCC_AHB1ENR)
	pRCC->AHB1ENR |= (1 << 0); //SET BIT 0 TO ENABLE GPIOA
	
	
	
	// AFTER ENABLING PERIPHERAL CLKS, WE CAN ACCESS PERIPHERAL REGISTERS
	
	pADC->CR1 = 0x55;
	pGPIO->PUPDR = 0x11; // 8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR)
	
	
	
	// 1. Turn ON HSE OSC.
	// STM32F446xx RM0390 -ARM-32-bit-dm00135183.pdf 	
	// 6.3.1 RCC clock control register (RCC_CR)
	
	// STM32F407VG - RM0090 - en.DM00031020.pdf
	// 7.3.1 RCC clock control register (RCC_CR)
	pRCC->CR |= (1 << 16); // 16th bit 'HSE ON' is SET
	
	// 2. Wait until the HSE becomes stable
	while(!(pRCC->CR)&(1<<17)); // Wait until 'HSE READY'(bit 17 of CR) becomes 1, 
															// indicating that the XTAL has become stable
	
	// 3. Select HSE as the system clk
	// STM32F446xx RM0390 -ARM-32-bit-dm00135183.pdf	
  // 6.3.3 RCC clock configuration register (RCC_CFGR)
	// Bits 1:0 SW[1:0]: System clock switch
	// Set and cleared by software to select the system clock source
	
	// STM32F407VG - RM0090 - en.DM00031020.pdf
	// 7.3.3 RCC clock configuration register (RCC_CFGR)
	// 01: HSE oscillator selected as system clock
	pRCC->CFGR &= ~(0x3 << 0); // clearing Bits 1:0
	pRCC->CFGR |= (0x1 << 0);  // 01: HSE oscillator selected as system clock 
	
	
	return 0;
}