 // This module provides functions, which is necessary working with stack.

// Version history:
// v0: Created mod.c and mod.h files
// v1: used if sentences to fix some problems
//     added debugging mode (#define DEBUG 0)
// v2: now functions can operate with all types of variables

#define DEBUG 0
#include <stdlib.h> 
#include <stdio.h>
#include "mod.h"

//------------------------------------------------------------------------------
void push(struct Stack *s, int value)
{
  {
	if (s->size>0){
		s->size++;
		s->data = (int*)realloc(s->data,s->size*sizeof(int));
	} else {
		s->size=1;
		s->data = malloc(1*sizeof(int));
	}
    s->data[s->size-1] = value;//-1
    #if DEBUG
      printf("Pridetas elementas.\n");
    #endif
  }
}

//------------------------------------------------------------------------------
void stackInfo(struct Stack s){
	int i=0;
	for (i=0;i<s.size;i++){
		printf("%d element with value of %d\n",i,s.data[i]);
	}
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
int pop(struct Stack *s)
{
  if (s->size > 0)
  {
    #if DEBUG
      printf("ispopintas elementas.\n");
    #endif
    s->size=s->size-1;
    s->data = realloc(s->data,s->size*sizeof(int));
      //cia buvo  return s->data[--s->size];  
  }
  return s->data[s->size];
}


