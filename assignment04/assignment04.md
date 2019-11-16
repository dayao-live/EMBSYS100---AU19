# EMBSYS100 - AU19 ASSIGNMENT 04
### Goal
The goals for the assignment this week:
1. Practice the use of bit-banding region.
2. Examine the assembly code generated for a function with multiple parameters.
3. Go thru a design problem exercising key concepts we viewed so far (pointers, arrays, functions, design, API, testing…etc.)
4. Bonus: Apply usage of pointers and the understanding of Endianness.

### Problems:
1. Using bit-band region for peripherals:
* a. Convert the Blinking Led demo to use the corresponding bit-band address instead of the register address used in the peripheral region.  
__Done. Please see "main.c"__

* b. What instructions does the compiler produce in assembly for the “writing” to the GPIO bit when using bit-band address?  
__MOVS R0,#1__  
__LDR.N R1,[PC, #0x44]__
__STR R0,[R1]__

* c. What were the instructions produced when writing to the GPIOx_ODR bit[5] directly?
__LDR.N R2,[PC, #0x2c]__  
__MOVS R0,#1__  
__STR R0,[R2]__


2. Create a function with multiple arguments (5 arguments for example) and call that function from within another function. Trace thru the assembler and note:
* a. How does the calling function pass the values to the called function?  
__The calling function passed the values into registers R0,R1,R2,R3, and another one into stack.__

* b. What extra code did the compiler generate before calling the function with the multiple arguments?  
__The compiler stored one argument value into the stack.__

* c. What extra code did the compiler generate inside the called function with the multiple list of arguments?  
__The compiler pushed register R4-R8 values and Link Register value into the stack.__


* d. Any other observations?  
__Link register value has been pushed into stack and it was popped back to Program Counter register in the end inside the called function. The link register was used for other arithmetic calculation inside the called function.__

3. Following the queue data structure approach, design, implement and test a stack data structure:
* a. The following is the list of requirements:
i. The stack should have a predefined size
ii. The stack supports “int” data types.
iii. Provide a function to initialize the stack internals.
iv. Provide a function to push an element onto the stack
v. Provide a function to pop an element off the stack.
vi. Provide a function that returns 1 if stack is empty.
vii. Provide a function that returns 1 if stack is full.
* b. Provide a list of the test cases and their implementation inside of main.c
* c. Separate the stack code from the rest of the test code (create stack.h & stack.c)  
__Code submitted__

4. Bonus: Using the power of pointers and type casting, create a function that can determine if a computer is big-endian or little-endian. Test your function in the simulator and modify the Project Options (as shown in the figure below) against:  
* a. Device STM32F401RE
* b. Cortex M4 (Little endian option)
* c. Cortex M4 (Big Endian option)  
__Code submitted__
