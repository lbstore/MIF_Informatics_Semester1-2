#include <stdio.h>
#include "mod.h"
#include "module.h"
int main(int argc, char **argv)
{
	printf("%d\n",add(1,2));
	printf("%d\n",add(3,1));
	printf("Add count: %d\n",findAddCount());
	printf("%d\n",sub(5,1));
	printf("%d\n",sub(10,2));
	printf("%d\n",execute(1,2,add));
	printf("Sub Count: %d\n",findSubCount());
	printf("Total Count: %d\n",findTotalCount());
	return 0;
}

