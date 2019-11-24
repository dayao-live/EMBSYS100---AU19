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

3. Create a new file div2Asm.s and add the file to the same HelloWorld project above.
* a. Write the assembly code to take an input argument, divide it by 2, and return the result.
* b. Invoke the function “PrintString” from within divAsm before doing the division computation.
* c. Add a comment for every statement in your assembly function code.
* d. In the main.c, invoke dev2Asm(foo) and capture the screen output from TeraTerm.
![screenshot for TeraTerm](https://github.com/dayao-live/EMBSYS100---AU19/blob/master/assignment05/Problem3_div2Asm/TeraTerm_screenshot.PNG_div2.PNG)

4. Implement a swap function in assembly and call it “swapCharsAsm”:
* a. It takes as input two variables of char data type and swaps the two chars
* b. Add a comment for every statement in your assembly function code.
* c. Bonus: Returns 0 if the two chars are identical; otherwise, return 1.  
__Code submitted__

5. Bonus: Implement the swap_pointer() function from #1 above in assembly and call it swapPointersAsm().  
* a. Add a comment for every statement in your assembly function code.
* b. Take a snap shot of the output after invoking the swapPointerAsm() subroutine.  
__Sorry, didn't have time to do__
