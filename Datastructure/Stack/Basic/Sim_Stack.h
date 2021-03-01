/* 2021. 03. 01
 * Creater : Gunhee Choi
 * This file is Stack Simulation header
 */

#ifndef SIM_STACK_H
#define SIM_STACK_H
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

#include "basic.h"

typedef struct {
	int * data;
	int capacity;
	int top;
} StackType;

void stack_test_function();
void init_stack(StackType * stack);
int is_full();
int is_empty();
int push(StackType * stack, int data);
int pop();
int peek();

#endif