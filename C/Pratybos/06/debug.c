// nera standartiniu biblioteku
//nera "deklaruotu" funkciju
int main(){
	int *b;
	r(b); //Funkcija kvieciama pries jos paskelbima
	int *a=(int *)malloc(b);   //nezinomas dydis(nera sizeof)				
	f(a,b); // funkcija f turi 2 parametrus, nors aprase yra tik vienas, 
	//funcijos aprasas yra veliau negu kreipiamasi i funkcija
	
	for(int i=0;i<10;printf("%d",*a++)); 
	//i tipa reikia paskelbti ne ciklo viduj, nebent naudojant c99 standarta
	//*a++ nedideja i todel nesibaigia ciklas, *a++ negali atvaizduoti reiksmes, nes nera funcija ar funcijos pointeris (taip sako debugger'is)
	
	{}system("pause");}//{} sklaustai beprasmiai, kodas kreipiasi i biblioteka kurios neitrauke
	//pabaigoje pageidautina return 0;
	
	// funkcijos paskelbtos kodo apacioje, todel i jas negalima kreiptis
	void f(a){//Blogi parametru tipai ir ju kiekis
		for(i=0;i<=b;i++){
			*(a+i)=1;
			for(int j=1;j<=i;j++){//j paskelbtas ciklo viduje, analogiska situacija
				a[i]*=j;// masyvas del klaidu anksciau yra nesukurtas
				}
			}
		}
	void r(b){ //blogas parametro tipas (turi buti *b, nes norima "pass by reference"
		scanf("%d\n", b);
		}
