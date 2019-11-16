#include <assert.h>
#include "stack.h"

int main()
{
    int result=0;
    int test_element1=0;
    int test_element2=0;
    int test_element3=0;
    int test_element4=0;
    
    // *******************************************************************
    // Test1: Check if the stack is empty
    // *******************************************************************
    // Arrange:
    stack_init();
    
    // Act:
    result=stack_empty_check();
    
    // Assert:
    assert(result==0);
    
    // *******************************************************************
    // Test2: Push all elements into the stack until it is full
    // *******************************************************************
    
    // Act:
    result = stack_push(1);  
    // Assert:
    assert(result==0);    

    // Act:
    result = stack_push(2);    
    // Assert:
    assert(result==0);  
    
    // Act:
    result = stack_push(3);    
    // Assert:
    assert(result==0);   
    
    // Act:
    result = stack_push(4);    
    // Assert:
    assert(result==0);    
 
    // *******************************************************************
    // Test3: Check if the stack is full
    // *******************************************************************
    
    // Act:
    result=stack_full_check();
    
    // Assert:
    assert(result==0);
    
    // *******************************************************************
    // Test4: Pop all elements from the stack until it is empty
    // *******************************************************************
    
    // Act:
    result = stack_pop(&test_element1);  
    // Assert:
    assert(result==0);    

    // Act:
    result = stack_pop(&test_element2);    
    // Assert:
    assert(result==0);  
    
    // Act:
    result = stack_pop(&test_element3);    
    // Assert:
    assert(result==0);   
    
    // Act:
    result = stack_pop(&test_element4);    
    // Assert:
    assert(result==0);        
    
  return 0;
}
