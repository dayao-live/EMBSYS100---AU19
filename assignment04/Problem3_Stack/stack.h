#ifndef __STACK_H__
#define __StACK_H__

void stack_init(void);
int stack_push(int element);
int stack_pop(int* element);
int stack_empty_check(void);
int stack_full_check(void);

#endif

