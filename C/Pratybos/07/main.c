
//1 typedef
//2 setpoint (p,koordinates x, koordinates y)  arba po viena funkcijos dirbti su tuo tasku
//3 get x get y


/*struct stack;
int data
int size
deti i stack push(st,p1);
isimti is stack p2 = pop(st);
sort pagal distance
operacijos, stack, 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Point{

	double x,y;
	double distance;
}Point;

typedef struct Stack{
	int size;
	Point *data;
	
	
}Stack;


//Functions work with coordinates
void setPoint(Point *p,double a1, double a2){
	p -> x = a1;
	p -> y = a2;

}

double heronsSqrt(double number){ //Saknis iteraciniu Heron'o budu   http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method
	double guess, lastGuess,checking;
	double precision=0.000001;
	lastGuess=0;
	guess=0;
	if (number==0){
		return number;
	}else{
		guess=(number/3);
		while (1) {
			lastGuess=guess;
			guess=( guess + ( number / guess ))/2;
			checking=(lastGuess - guess);
			if (checking<0){
				checking=checking*(-1);
			}
			if ((checking) <= precision ){
				break;
			}
		}
	}
	return(guess);
	
}

int getX(Point *p){
	return p -> x;
}
int getY(Point *p){
	return p -> y;
}
void setDistance(Point *p,double value){
	p -> distance = value;
}

//functions work with everything else
Point pop(Stack *stk){
	(stk -> size)=stk->size-1;
	return (stk -> data[stk -> size]);
}

double square(double number){
	return (number*number);
}

double distance(Point *p){
	double number;
	number=(square(p->x)+(square(p->y)));
	return heronsSqrt(number);
}

void getMemory(Point** array1,int arraySize){
    *array1= malloc(arraySize*sizeof(Point));
};

void relocateMemory(Point** array1,int arraySize){
    *array1= realloc(*array1,arraySize);
};

void push(Stack *stk,Point poin){

	
	stk -> size++;
	if (stk -> size>3){
		relocateMemory(&stk ->data,stk->size+1);
	}
	stk -> data[stk -> size-1]=poin;
}

void calculateDistance(Stack *stk){
	int arraySize = stk -> size;
	int i;
	double ats;
	Point temp;
	for (i = 0;i<arraySize;i++){
		temp= (stk -> data[i]);
		ats = distance(&temp);
		stk -> data[i].distance=ats;
	}
}

void swapPoints(struct Point *pt1,struct Point *pt2){
	struct Point copy;
	copy=*pt1;
	*pt1 = *pt2;
	*pt2 = copy;
}

void sort(Stack *stk){
	int arraySize= (stk -> size);
	int i,j;
	for (i=0; i<arraySize; i++){
		for (j=i; j<arraySize;j++){
		if ((stk->data[i].distance) > (stk -> data[j].distance)){
				swapPoints(&(stk->data[i]),&(stk->data[j]));
			}
		}
	}	
}
 
void printStack(Stack *stk){
	int i;
	for (i=0;i<(stk -> size);i++){
		printf("%3lf %lf %lf \n",stk->data[i].x,stk->data[i].y,stk->data[i].distance);
	}
}

int main(int argc, char **argv)
{
	
	Stack st;
	Point pt;
	Point ats;
	st.size=0;
	getMemory(&st.data,10);
	
	setPoint(&pt,4,3);
	push(&st,pt);
	setPoint(&pt,0,4);
	push(&st,pt);
	setPoint(&pt,4,4);
	push(&st,pt);
	setPoint(&pt,7,2);
	push(&st,pt);
	setPoint(&pt,8,10);
	push(&st,pt);
	printStack(&st);
	calculateDistance(&st);
	ats=pop(&st);
	sort(&st);
	printf("\n");
	printStack(&st);

	return 0;
}


	/*
	union Test{
		int i;
		float f;
		char c[4];
	}t;
	int index=0;
	for (index = 0 ;index < 4; index++){
			t.c[index]=0;
	}
	t.i = 258;
	//t.c[3]=200;
	printf("%d %f %d",t.i,t.f,t.c[0]);
	
	*/
