//#define RCC_BASE 0x40023800
//#define RCC_AHB1ENR (*(unsigned int*)(RCC_BASE + 0x30))
#define RCC_AHB1ENR_GPIOA (*(unsigned int*)(0x42000000 + 0x23830*32 + 0*4))     //bit band address for RCC_AHB1ENR_GPIOA

//#define GPIOA_BASE 0x40020000
//#define GPIOA_MODER (*(unsigned int*)(GPIOA_BASE + 0x00))
#define GPIOA_MODER5_LOWER (*(unsigned int*)(0x42000000 + 0x20000*32 + 10*4))   //bit band address for GPIOA_MODER5 lower bit
#define GPIOA_MODER5_HIGHER (*(unsigned int*)(0x42000000 + 0x20000*32 + 11*4))  //bit band address for GPIOA_MODER5 higher bit

//#define GPIOA_ODR (*(unsigned int*)(GPIOA_BASE + 0x14))
#define GPIOA_ODR5 (*(unsigned int*)(0x42000000 + 0x20014*32 + 5*4))     //bit band address for GPIOA_ODR5


volatile int counter=0;


int main()
{   
RCC_AHB1ENR_GPIOA = 0x01;       // Enable clock to GIPOA
GPIOA_MODER5_LOWER = 0x01;      
GPIOA_MODER5_HIGHER = 0x00;     //Set GPIOA_MODER5 to 0x01

while(1)
{
      GPIOA_ODR5 = 0x01;
      while (counter<1000000) 
      {counter++;}        
      counter=0;
      
      GPIOA_ODR5 = 0x00;;
      
      while (counter<1000000)
      {counter++;}        
      counter=0;  

}
  return 0;
}

//6.3.9
//base address 0x40023800
//RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
//Address offset: 0x30
//write:0x01

//8.4.1
//GPIO port mode register (GPIOx_MODER) (x = A..E and H)
//40020000
//Address offset: 0x00
//Write: 0x400


//8.4.6
//GPIOA base address: 0x40020000
//Address offset: 0x14
//write: 0x20


