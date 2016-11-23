static int addCounter,subCounter;
int add(int a1, int a2){
	addCounter++;
	return a1+a2;
}

int sub(int a1, int a2){
	subCounter++;
	return a1-a2;
}

int findAddCount(){
	return addCounter;
}
int findSubCount(){
	return subCounter;
}
int findTotalCount(){
	return subCounter + addCounter;
}

