unit DvipusisSarasasADT;
//Laimonas Beniušis INFORMATIKA 1
interface
//dvipusio saraso tipas
type doublyLinkedList = ^dLLelem;
	dLLelem = record
		next,prev:doublyLinkedList;
		num:integer;
	end;

																		//Parametrai, kreipiantis i procedura/funkcija
function findTail(headLoc:doublyLinkedList):doublyLinkedList;						//sarasas
function findTotal(headLoc:doublyLinkedList):integer;								//sarasas
function findAmmount(headLoc:doublyLinkedList):integer;								//sarasas
function findAverage(headLoc:doublyLinkedList):real;								//sarasas
procedure initializeList(var headLoc:doublyLinkedList);								//sarasas
procedure printList(headLoc:doublyLinkedList);										//sarasas
procedure printElement(headLoc:doublyLinkedList;index:integer);						//sarasas, elemento indexas
procedure printListBackwards(headLoc:doublyLinkedList);								//sarasas
procedure insertNode(var headLoc:doublyLinkedList; number:integer;index:integer);	//sarasas, skaicius, elemento indexas
procedure deleteNode(var headLoc:doublyLinkedList; index:integer);					//sarasas, elemento indexas
procedure deleteList(var headLoc:doublyLinkedList);									//sarasas
implementation

function findTotal(headLoc:doublyLinkedList):integer;//Elementu suma
var totalLoc:integer;
begin
totalLoc:=0;
	if NOT (headLoc = nil ) then begin
	if headLoc^.num>0 then totalLoc:=totalLoc+headLoc^.num;
		if NOT(headLoc^.next = nil) then begin//Sarasas nera tuscias
				totalLoc:=totalLoc+findTotal(headLoc^.next);
		end;
	end else totalLoc:=0; //Sarasas tuscias
	findTotal:=totalLoc;
end;

function findAmmount(headLoc:doublyLinkedList):integer;//Elementu kiekis
begin
	if NOT(headLoc = nil) then begin
		findAmmount:=1+findAmmount(headLoc^.next);
	end else findAmmount:=0;
end;

procedure average(headLoc:doublyLinkedList; var amm,totalLoc :integer);//Elementu vidurkis
begin
	if NOT (headLoc = nil) then begin
		if headLoc^.num>0 then begin
			amm:=amm+1;
			totalLoc:=totalLoc+headLoc^.num;
		end;
		if NOT(headLoc^.next = nil) then begin
			average(headLoc^.next,amm,totalLoc);
		end;
	end;
end;

function findAverage(headLoc:doublyLinkedList):real;
var totalLoc,amm:integer;
begin
	totalLoc:=0;
	amm:=0;
	average(headLoc,amm,totalLoc);
	findAverage:=totalLoc/amm
end;
procedure initializeList(var headLoc:doublyLinkedList);
begin
	headLoc:=nil;	
end;

procedure printList(headLoc:doublyLinkedList);//Spausdina sarasa
begin
	write('Printing out list in order: ');
	while NOT(headLoc=nil) do begin
		write(headLoc^.num,' ');
		headLoc:=headLoc^.next;
	end;
	writeln;
end;

procedure printListBackwards(headLoc:doublyLinkedList);//Spausdina sarasa nuo galo
var tail:doublyLinkedList;
begin
	write('Printing out list in reverse: ');
	tail:=findTail(headLoc);
	while NOT(tail=nil) do begin
		write(tail^.num,' ');
		tail:=tail^.prev;
	end;
	writeln;
end;

procedure printElement(headLoc:doublyLinkedList;index:integer);//Spausdina pasirinkta elementa
var i:integer;
begin
	if headLoc<>nil then begin
		if (index<0)OR(index>findAmmount(headLoc)) then begin
			writeln('No such element')
		end else begin	
				for i:=1 to index-1 do begin
					headLoc:=headLoc^.next;
				end;
			writeln(headLoc^.num);
		end;
	end else writeln('List empty');
end;

function findTail(headLoc:doublyLinkedList):doublyLinkedList;//Suranda saraso gala
begin
findTail:=headloc;
		while findTail^.next<>nil do
		findTail:=findTail^.next;
end;


procedure insertNode(var headLoc:doublyLinkedList; number:integer;index:integer);//Iterpia elementa i sarasa
var i:integer;
var elem,elemNew,tail:doublyLinkedList;
begin
	elem:=headLoc;//Pradzia issaugoma lokaliai
	if ((index>findAmmount(headLoc))OR(index<0)) then writeln('Wrong index')
	else begin
		//Sukuriame elementa
		new(elemNew);
		elemNew^.num:=number;
		//Patikrinam kur ji iterpti
			if index = 0 then begin //Iterpiame i pradzia
				if headLoc<>nil then begin
					elem^.prev:=elemNew;
				end;
				elemNew^.prev:=nil;
				elemNew^.next:=elem;
				headLoc:=elemNew;
			end else begin
			if index = findAmmount(headLoc) then begin//Iterpiame i gala
				tail:=findTail(headLoc);
				elem:=tail;
				elem^.next:=elemNew;
				elemNew^.next:=nil;
				elemNew^.prev:=elem;
			
			end else begin
					for i:=1 to index do begin	//Iteruojame iki pasirinkto elemeto
						if elem^.next<>nil then begin //Apsauga nuo perzengimo per toli
							elem:=elem^.next
						end;
					end;
				
					{if elem^.prev <> nil then write('prev: ',elem^.prev^.num,'; '); //Debugging purposes
					write('current: ',elem^.num,'; ');
					if elem^.next <> nil then writeln('next: ',elem^.next^.num);}
					
					//Iterpiame pries pasirinkta elementa
					
					elemNew^.prev:=elem^.prev;
					elemNew^.next:=elem;
					elem^.prev^.next:=elemNew;
					elem^.prev:=elemNew;
					elem:=elem^.prev;
					elem:=elemNew;
					
					{if elem^.prev <> nil then write('prev: ',elem^.prev^.num,'; ');//Debugging pusposes
					write('current: ',elem^.num,'; ');
					if elem^.next <> nil then writeln('next: ',elem^.next^.num);
					writeln;}
				end;		
			end; 
		writeln(number,' Inserted to spot: ', index);	
	end;
end;


procedure deleteNode(var headLoc:doublyLinkedList;index:integer);//Pasaliname pasirinkta elementa
var i:integer;
elem:doublyLinkedList;
begin
	elem:=headLoc;
	if (index<1)OR(index>findAmmount(headLoc)) then writeln('No such element')
	else begin	
		if index = 1 then begin
			headLoc:=elem^.next;
			headLoc^.prev:=nil;
			dispose(elem);
		end else begin
			for i:=1 to index-1 do begin
				elem:=elem^.next;
			end;
			
			elem^.next^.prev:=elem^.prev;//Perveda rodykles ir atsikrato elemento
			elem^.prev^.next:=elem^.next;
			dispose(elem);
		end;
		//writeln('Element Nr.',index,' with value ',elem^.num,' was removed');
	end;
end;

procedure deleteList(var headLoc:doublyLinkedList);	
var
elem,tail:doublyLinkedList;
begin
	elem:=headLoc;
	tail:=findTail(headLoc);
	while headLoc <> nil do begin
		if	(elem <> tail) then begin
			while elem^.next <> tail do begin
				elem:=elem^.next;
			end;
			tail:=elem;
			dispose(elem^.next);
		end else begin
			dispose(elem);
			headLoc:=nil;
			tail:=nil;
		end;
	end;
	writeln('List deleted');
end;

END.
