# Setup:

1. Create a new project in IAR following the steps from the slide deck
2. Create a counter local variable and increment the counter several times.
3. Run the program in the simulator environment and answer the following questions:

# Observe and answer:

1. Inject 0x1FFFFFFF for the \"counter\" value in the variable window, then step thru the program only once to increment \"counter\".
* a) What is the value of the \"counter\" from the \"Locals\" window?  
 __Answer: 0x20000000__
* b) What is the value of the \"counter\" in the \"Register\" window?  
 __Answer: 0x20000000__
* c) Which flags are set in the APSR register? Explain why?	No flag is set.  
__Because it is still positive number and no carry or overflow happened.__


2. If your write all Fs (0XFFFFFFFF) in the Register value for \"counter\" then step thru the program once to increment \"counter\"
* a) What happens to the value of \"counter\" in the \"Locals\" window?   
__Answer: It become "0x00000000"__
* b) What flags, if any, are set in the APSR?	  
__Answer: Flag Zero flag and Carry falg are set in the APSR.__

3. Change the \"counter\" variable type in your code to \"unsigned\". Inject the values \"0x1FFFFFFF\" then step thru the program to increment the \"counter\" once:
* a) What is the value of \"counter\" from the \"Locals\" window after incrementing for each value?	  
__Answer: 0x20000000__
* b) What flags, if any, are set in the APSR? Explain why?	No flag is set.   
__Answer: Because it is still positive number and no carry or overflow happened.__

4. Change the \"counter\" variable type in your code to \"unsigned\". Inject the values \"0xFFFFFFFF\" then step thru the program to increment the \"counter\" once:
* a) What is the value of \"counter\" in the \"Locals\" window after incrementing for each value?  
__Answer: It become "0x00000000"__
* b) What flags, if any, are set in the APSR? Explain why?  
__Answer: Flag Zero flag and Carry flag are set in the APSR. Because 0x00000000 is zero and a carry happened.__

5. Move the \"counter\" variable outside of main (at the top of the file):
* a) What is the scope of the variable \"counter\"?   
__Answer: It' scope is global.__
* b) Is it still visible in the \"Locals\" view?  
__Answer: No__
* c) In which window view can we track \"counter\" now?  
__Answer: In "Statics" view__
* d) What is the address of the \"counter\" variable in memory?  
__Answer: Its address is "0x20000000"__

6. Change the source code to the following, then run the program still in the simulator:
* a) What is the value of \"counter\" at the end of the program (halting at the return 0 statement)  
__Answer: Its value is 4.__
* b) Explain why the counter value has changed?  
__Answer: Because the value is increased by using the pointer. The pointer p_int points to the address "0x20000000", which is where the counter stores the data.__

7. Change the setting of IAR to run the same program on the evaluation board:
* a) What is the address where \"counter\" is stored?  
__Answer: "0x20000000"__
* b) Is the \"counter\" variable stored in RAM or ROM?  
__Answer: in RAM__
* c) What is the value of \"counter\" at the end of the program (halting at the return 0 statement).  
__Answer: Its value is 4.__
