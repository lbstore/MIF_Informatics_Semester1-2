program task03;

uses DvipusisSarasasADT;

var list1:doublyLinkedList;
var list2:doublyLinkedList;
var list3:doublyLinkedList;


BEGIN
	writeln('Program will find an average of your numbers');
	initializeList(list1);
	insertNode(list1,1,0);
	insertNode(list1,2,1);
	insertNode(list1,3,1);
	insertNode(list1,4,3);
	insertNode(list1,5,4);
	insertNode(list1,6,5);
	insertNode(list1,7,6);
	initializeList(list2);
	insertNode(list2,11,0);
	insertNode(list2,21,1);
	insertNode(list2,31,2);
	insertNode(list2,41,3);
	insertNode(list2,51,4);
	insertNode(list2,61,5);
	insertNode(list2,71,6);	
	
	readln;
	writeln('list1');
	if NOT(findAmmount(list1) = 0) then begin
		printList(list1);
		//deleteNode(list1,1);
		printList(list1);
		//deleteNode(list1,2);
		printList(list1);
	end;
	{readln;
	writeln('list2');
	if NOT(findAmmount(list2) = 0) then begin
		printList(list2);
		deleteNode(list2,0);
		printList(list2);
		deleteNode(list2,1);
		printList(list2);
	end;
	//deleteList(list2);
	printElement(list1,99);
	printElement(list2,2);	}
	writeln('Total:',findTotal(list1):4,' Ammount of elements:',findAmmount(list1):2,' Average:',findAverage(list1):5:2);
	//writeln('Total:',findTotal(list2):4,' Ammount of elements:',findAmmount(list2):2,' Average:',findAverage(list2):5:2);
	
END.

