//#define RCC_BASE 0x40023800
//#define RCC_AHB1ENR (*(unsigned int*)(RCC_BASE + 0x30))
//#define GPIOA_BASE 0x40020000
//#define GPIOA_MODER (*(unsigned int*)(GPIOA_BASE + 0x00))
//#define GPIOA_ODR (*(unsigned int*)(GPIOA_BASE + 0x14))

#include "stm32f401xe.h"

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


while(1)
{
//8.4.6
//GPIOA base address: 0x40020000
//Address offset: 0x14
//write: 0x20  
 
    delay(1000000);
    GPIOA->ODR |= GPIO_ODR_OD5_Msk;

    delay(1000000);
    GPIOA->ODR &= (~GPIO_ODR_OD5_Msk);
}    
    
  return 0;
}




