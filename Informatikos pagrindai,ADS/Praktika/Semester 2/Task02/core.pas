
program task02;


const thousand = 1000;
type arrayOfStr = array[1..thousand] of string;

var howMany,j : integer;
sortableArray:arrayOfStr;
userInput:string;


procedure swapStr(var str1,str2:string);
var copy:string;
begin
	copy:=str1;
	str1:=str2;
	str2:=copy;
end;

procedure stringBubbleSort(var m:arrayOfStr;ammountOfElements:integer);
var a1,a2:integer;
begin
	for a1:=1 to ammountOfElements do begin
		for a2:=1 to ammountOfElements-a1 do begin
			if (m[a2] > m[a2+1]) then begin
				swapStr(m[a2],m[a2+1])
			end
		end
	end		
end;

function stringIsContinious(str:string):boolean;
var a1:integer;
begin
	stringIsContinious:=true;
	a1:=1;
	while ((stringIsContinious) AND (a1<=length(str))) do begin
		if (length(str)<1) then stringIsContinious:=false
		else begin 
			a1:=a1+1;
			if (str[a1]=' ') then stringIsContinious:=false;
		end	
	end
end;


BEGIN
	writeln('Write your words one by one , type "0" to stop');
	writeln;
	howMany:=0;
	userInput:='';
	
	repeat
		if howMany>0 then sortableArray[howMany]:=userInput;
		howMany:=howMany+1;
		write('Word #',howMany,':');
		repeat
		readln(userInput);
		if NOT(stringIsContinious(userInput)) then write('Word is empty or not continious, try again');
		until stringIsContinious(userInput);
	until userInput='0';
	
	stringBubbleSort(sortableArray,howMany);
	
	for j:=1 to howMany do begin
		writeln(sortableArray[j])
	end;
	
	writeln;
	writeln('The end.');
	readln;
	
	
END.

