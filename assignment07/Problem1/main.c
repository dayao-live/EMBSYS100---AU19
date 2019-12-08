//#define RCC_BASE 0x40023800
//#define RCC_AHB1ENR (*(unsigned int*)(RCC_BASE + 0x30))
//#define GPIOA_BASE 0x40020000
//#define GPIOA_MODER (*(unsigned int*)(GPIOA_BASE + 0x00))
//#define GPIOA_ODR (*(unsigned int*)(GPIOA_BASE + 0x14))

#include "stm32f401xe.h"

#define SYS_CLOCK_HZ 16000000u

void delay(unsigned int iterations);

void delay(unsigned int iterations)
{
  while(iterations>0)
  {
    iterations--;
  }
}

int main()
{   
//6.3.9
//base address 0x40023800
//RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
//Address offset: 0x30
//write:0x01
//RCC_AHB1ENR = 0x01;  // Enable clock to GIPOA
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

//8.4.1
//GPIO port mode register (GPIOx_MODER) (x = A..E and H)
//40020000
//Address offset: 0x00
//Write: 0x400
//GPIOA_MODER |= 0xA8000400; //Set GIPOA to output
GPIOA->MODER |= GPIO_MODER_MODE5_0;

    SysTick->LOAD = SYS_CLOCK_HZ-1;     //Counts from SYS_CLOCK_HZ
    SysTick->VAL = 0x0;                 //Clear initial value
    SysTick->CTRL = 0x7;                //Enable interrupt

while(1)
{
//8.4.6
//GPIOA base address: 0x40020000
//Address offset: 0x14
//write: 0x20  
 
//    delay(1000000);


}    
    
  return 0;
}




