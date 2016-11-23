#include <stdlib.h>
#include <stdio.h>
#include "BTM.h"

typedef int customType;

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
	printf("ok");
	getchar();
	int number=2;
	insertValue(&localT,&number,&compare);
	
	return 0;
}
