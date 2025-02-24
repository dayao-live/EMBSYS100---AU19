/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay  // delay() is defined outside this file.

    PUBLIC control_user_led         // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led
Description     : - Uses Peripheral registers at base 0x4000.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

control_user_led
    // <TODO: Add your code for the function here>

    PUSH {LR}   // Save the input arguments as needed and LR
    CMP R0,#0   //Does the state equal to 0?
    BEQ off     //branch to off if yes
    CMP R0,#1   //Does the state equal to 0?
    BNE exit    //branch to exit if not

on:
    MOVW R0,#0x0014               //move lower 16 bit of #0x40020014 into R0
    MOVT R0,#0x4002               //move upper 16 bit of #0x40020014 into R0   
    LDR R2,[R0]         //load the output data register value into R2
    ORR R2,R2,#0x00000020 //bitwise OR with 0x20
    STR R2,[R0]         //load the output data register value back 

    MOVS R0,R1  // load the iterations from R1 into R0
    BL delay    //call delay function

off:
    MOVW R0,#0x0014               //move lower 16 bit of #0x40020014 into R0
    MOVT R0,#0x4002               //move upper 16 bit of #0x40020014 into R0 
    LDR R2,[R0] //load the output data register value into R2
    AND R2,R2,#0xFFFFFFDF       //bitwise AND with 0xFFFFFFDF
    STR R2,[R0]  //load the output data register value back

    MOVS R0,R1  // load the iterations from R1 into R0
    BL delay    //call delay function

exit:
    POP {LR}        // Restore Risgters and LR
    BX LR           // Return

    END
