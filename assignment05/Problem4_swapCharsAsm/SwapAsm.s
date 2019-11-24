
/*******************************************************************************
File name       : SwapCharsAsm.s
Description     : Assembly language function for swaping two chars
*******************************************************************************/   
    
    PUBLIC SwapCharsAsm       	// Making SwapCharsAsm available to other modules.
                        	
    
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
    
    THUMB             // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : SwapCharsAsm
Description     : Swao two chars; returns 0 if the two chars are identical; otherwise, return 1

C Prototype     : int SwapCharsAsm(Char*, Char*);

Parameters      : R0,R1: Addresses of two chars
Return value    : R0
*******************************************************************************/  

SwapCharsAsm
    MOVS	R2,R0        // R2=R0;
    LDRB 	R0,[R2]      // load the char into R0, in byte
    LDRB 	R3,[R1]      // load the other char into R3, in byte
    CMP		R0,R3     // compare these two chars
    BNE         Not_Equal		// Branch to if not equal
    MOVS        R0,#0;	//move 0 to R0 so the function returns 0
    B Exit	//Branch to exit
Not_Equal:
    LDRB 	R3,[R2]      // load the char into R0, in byte
    LDRB 	R0,[R1]      // load the other char into R3, in byte
    STRB 	R0,[R2]      // store the char in R0 to the address indicated by R2, in byte
    STRB 	R3,[R1]      // store the char in R3 to the address indicated by R1, in byte
    MOVS        R0,#1;	//move 1 to R0 so the function returns 1
Exit: 
    BX LR               // return (with function result in R0)

    END
