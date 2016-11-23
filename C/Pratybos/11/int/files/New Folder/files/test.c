# include <stdio.h>
# include <stdlib.h>
# include "mod.h"


int main(int argc, char **argv)
{
	struct Stack st;
	push(&st,15);
	push(&st,4);
	push(&st,18);
	//printf("%d %d %d\n",st.data[1],st.data[2],st.data[3]);
	stackInfo(st);
	
	int elem=pop(&st);
	printf("Popped %d\n",elem);
	stackInfo(st);
	printf("Program succes\n");
	return 0;
}

