#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*(unsigned int*)(RCC_BASE + 0x30))
#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*(unsigned int*)(GPIOA_BASE + 0x00))
#define GPIOA_ODR (*(unsigned int*)(GPIOA_BASE + 0x14))



volatile int counter=0;
void LED_MorseCode_Dot(void)    //Output a dot
    {
      GPIOA_ODR |= 0x20;
      while (counter<200000) 
      {counter++;}        
      counter=0;
      
      GPIOA_ODR &= 0xFFFFFFDF;
      
      while (counter<1000000)
      {counter++;}        
      counter=0;  
    }
    
void LED_MorseCode_Dash(void)    //Output a dash
    {
      GPIOA_ODR |= 0x20;
      while (counter<1000000)
      {counter++;}        
      counter=0;
      
      GPIOA_ODR &= 0xFFFFFFDF;
      while (counter<1000000)
      {counter++;}        
      counter=0;  
    }


void MorseCode_Y(void)          //Morse Code for "Y"
{
    LED_MorseCode_Dash();
    LED_MorseCode_Dot();
    LED_MorseCode_Dash();
    LED_MorseCode_Dash();
}
void MorseCode_A(void)          //Morse Code for "A"
{
    LED_MorseCode_Dot();
    LED_MorseCode_Dash();
}
void MorseCode_O(void)          //Morse Code for "O"
{
    LED_MorseCode_Dash();
    LED_MorseCode_Dash();
    LED_MorseCode_Dash();
}


int main()
{   
RCC_AHB1ENR = 0x01; // Enable clock to GIPOA
GPIOA_MODER = 0xA8000400; //Set GIPOA to output

    MorseCode_Y();      //Output "Y"
    MorseCode_A();      //Output "A"
    MorseCode_O();      //Output "O"

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


