# EMBSYS100 - AU19 ASSIGNMENT 07
### Goal
The goals for the assignment this week:
1. Practice setting up a user-defined vector table.
2. Practice dealing with interrupts and the use of the SysTick timer.

### Problems:
1. Starting from the blinking LED code that you created using the GPIO registers:
* a. Define your own vector table.
* b. Enable use of CMSIS in project options settings.
* c. Add the files “stm32f401xe.h” & “system_stm32f4xx.h” to the folder where “main.c” is saved. You should be able to get these files thru STM32CubeMX. You could also get them by downloading the zip file “CMSIS_STM32_Device_Specific_Files.zip” from canvas site under the link Assignment\A06 folder
* d. Enable the use of the SysTick timer and its interrupt.
* e. Replace the delay() function with the use of the SysTick timer to blink the user LED.
* f. Set a break point inside the SysTick_Handler interrupt and capture a snapshot of the stack once inside the interrupt and LR value. Explain what are the values stored on the stack at the moment the Handler gets invoked.
__Code submitted.__  

2. __Bonus__: Improve your delay function to rely on the use of the SysTick timer instead of the busy-wait loop.
* a. Function prototype: void delay(uint32_t delayInMilliseconds)
* b. Use the function in your main.c file to blink the LED every 2 seconds.
* c. Hint: Setup the SysTick timer to trigger an interrupt every 1ms.
__Code submitted.__  
