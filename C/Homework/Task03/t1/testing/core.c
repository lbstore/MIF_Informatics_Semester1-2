#include <stdlib.h>
#include <stdio.h>
#include "BTM.h"
#include <string.h>


int compare(const void *a, const void *b){

	customType A = *((customType*)a);
	customType B = *((customType*)b);
	if (A<B) {
		return 1;
	}else {
		return 0;
	}
}


int main(int argc, char **argv){
	TreeNode* localT;
	
	int number=5;
	printf("ok11");
	getchar();
	insertValue(&localT,&number,compare);
	number=3;
	insertValue(&localT,&number,compare);
	number=2;
	insertValue(&localT,&number,compare);
	number=10;
	insertValue(&localT,&number,compare);
	printf("test passed");
	getchar();
	printTree(&localT);
	
	return 0;
}
