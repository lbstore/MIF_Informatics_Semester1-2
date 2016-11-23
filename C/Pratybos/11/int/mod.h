

struct Stack {
  int *data;
  int size;
  int init;
};  

// This function adds element to the end of the structure.
void push(struct Stack *s, int value);

// This function removes element from the end of the structure.
int pop(struct Stack *s);
//int pop(struct Stack *s);

//This function prints out elements with their value
void stackInfo(struct Stack s);
