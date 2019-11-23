# EMBSYS100 - AU19 ASSIGNMENT 05
### Goal
The goals for the assignment this week:
1. To gain in depth understanding of the pass-by-value nature of C.
2. To gain hands on experience with the ARM Cortex-M4 assembly language.

### Problems:
1. Create a function that allows swapping of two pointers.
* a. Explain what the “main” function does to the CSTACK in order setup the input arguments prior to calling the swap_pointer() function?  
__The "main" function prepared the CSTACK for the variables prior to calling the function.__

* b. And what are the values in R0 & R1 when swap_pointer() is called?
__Values of R0 and R1 are the two input arguments.__  


* c. Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns, showing the values of the pointers and what they are pointing to, similar to the picture below:
![screenshot for Problem1](https://github.com/dayao-live/EMBSYS100---AU19/blob/master/assignment05/Problem1_SwapPointers/P1_screenshot.PNG)

2. Run sqrAsm code from the class demo:
* a. Copy HelloWorld from Assignment 1.
* b. Download the file sqrAsm.s and copy it to the project directory.
* c. In IAR, add sqrAsm.s file to your project. Now you should be able to see the file from the Workspace Window.  
* d. Modify main.c to call sqrAsm function.
* e. Run your program on the board, and capture a snapshot image of the output from TeraTerm.
![screenshot for TeraTerm](https://github.com/dayao-live/EMBSYS100---AU19/blob/master/assignment05/Problem2_SqrAsm/TeraTerm_screenshot.PNG)

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
