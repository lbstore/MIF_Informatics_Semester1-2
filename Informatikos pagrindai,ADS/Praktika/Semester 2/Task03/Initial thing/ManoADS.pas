unit ManoADS;

interface

type doublyLinkedList = ^dLLelem;
	dLLelem = record
		next,prev:doublyLinkedList;
		num:integer;
	end;

var elem,elemNew:doublyLinkedList;

function findTotal(headLoc:doublyLinkedList):integer;
function findAmmount(headLoc:doublyLinkedList):integer;
procedure initializeList(var headLoc,tailLoc:doublyLinkedList);
procedure printList(headLoc:doublyLinkedList);
procedure printListBackwards(tailLoc:doublyLinkedList);
procedure printElement(headLoc:doublyLinkedList;index:integer);
procedure insertNode(var headLoc,tailLoc:doublyLinkedList; number:integer);

implementation

function findTotal(headLoc:doublyLinkedList):integer;
var totalLoc:integer;
begin
totalLoc:=0;
	if NOT (headLoc = nil ) then begin
	totalLoc:=totalLoc+headLoc^.num;
		if NOT(headLoc^.next = nil) then begin//List is not empty
				totalLoc:=totalLoc+findTotal(headLoc^.next);
		end;
	end else totalLoc:=0; //List is empty
	findTotal:=totalLoc;
end;

function findAmmount(headLoc:doublyLinkedList):integer;
begin
	
	if NOT(headLoc = nil) then begin
		findAmmount:=1+findAmmount(headLoc^.next);
	end else findAmmount:=0;
end;

procedure initializeList(var headLoc,tailLoc:doublyLinkedList);
var newNode:doublyLinkedList;
number:integer;
begin
	headLoc:=nil;
	tailLoc:=nil;
	writeln('Initializing new list, type your numbers');
	writeln('0 = Stop the list');
	readln(number);
	while NOT(number = 0) do begin
		new(newNode);
		newNode^.num:=number;
		newNode^.next :=nil;
		if headLoc = nil then begin
			newNode^.prev := nil;
			headLoc:=newNode;
		end else begin 
			newNode^.prev := tailLoc;
			tailLoc^.next:=newNode;
		end;	
		tailLoc:=newNode;
		readln(number);
	end;	
end;

procedure printList(headLoc:doublyLinkedList);
begin
	writeln('Printing out list in order');
	while NOT(headLoc=nil) do begin
		write(headLoc^.num,' ');
		headLoc:=headLoc^.next;
	end;
	writeln;
end;

procedure printListBackwards(tailLoc:doublyLinkedList);
begin
	writeln('Printing out list in reverse');
	while NOT(tailLoc=nil) do begin
		write(tailLoc^.num,' ');
		tailLoc:=tailLoc^.prev;
	end;
end;

procedure insertNode(var headLoc,tailLoc:doublyLinkedList; number:integer);
var i,index:integer;
enoughElements:boolean;
begin
	elemNew:=headLoc;
	writeln('type element index you want to inser element to');
	repeat
		writeln('Choose spot 1..',findAmmount(headLoc),' (0 to insert to last spot)');
		readln(index);
		
	until ((index<=findAmmount(headLoc))AND(index>=0));
	new(elem);
	elem^.num:=number;
	
	if index = 0 then begin //Insert element to tail
	elemNew:=tailLoc;
	elemNew^.next:=elem;
	elem^.next:=nil;
	elem^.prev:=elemNew;
	tailLoc:=elem;
	end else if index = 1 then begin //Insert element to head
			elem^.prev:=nil;
			elem^.next:=elemNew;
			headLoc:=elem;
		end else begin
			enoughElements:=true;
			for i:=2 to index do begin
				if elemNew= nil then begin		
					enoughElements:=false;
				end;	
				if enoughElements then elemNew:=elemNew^.next;
			end;
			if (enoughElements) then begin
				elem^.prev:=elemNew^.prev;
				elemNew^.prev^.next:=elem;
				elem^.next:=elemNew;
				elemNew^.prev:=elem;
			end else writeln('Insufficient ammount of elements');
		writeln('Inserted to spot: ', index);	
		end;
end;


procedure printElement(headLoc:doublyLinkedList;index:integer);
var i:integer;
begin
	repeat
	writeln('Type in element to print');
	readln(index);
	until (index>0)AND (index<=findTotal(headLoc));
	for i:=1 to index-1 do begin
		headLoc:=headLoc^.next;
	end;
	writeln(headLoc^.num);
end;



END.
