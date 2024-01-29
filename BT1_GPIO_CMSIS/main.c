#include "stm32f10x.h"
static void delay_1s()
{
	SysTick->LOAD = 9000000 - 1; // 
	SysTick->CTRL = 1; // cho phep systick timer voi tan so 72/8 = 9MHz
	while((SysTick->CTRL & 0x10000) == 0); 
	SysTick->CTRL = 0; // dung systick timer
}
int main()
{
	RCC->APB2ENR |= (1<<4); // portC clock enable
	GPIOC->CRH |= ( (1<<20) | (1<<21) ); // set PC13 output voi max speed 50MHz
	GPIOC->CRH &= ~( (1<<22) | (1<< 23) ); // PC13 output push-pull
	while(1)
	{
		GPIOC->BSRR |= (1<<(16+13)); // PC13 = 0
		delay_1s();
		GPIOC->BSRR |= (1<<13); // PC13 = 1
		delay_1s();
	}
}
