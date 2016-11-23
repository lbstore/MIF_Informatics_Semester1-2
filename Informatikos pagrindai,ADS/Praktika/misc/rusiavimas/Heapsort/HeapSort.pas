program heapsorting;

const size=50;
type intArray = array[1..size] of integer;

var i: integer;
M:intArray;

procedure swap (var a1,a2:integer);
var copy:integer;
begin
	copy:=a1;
	a1:=a2;
	a2:=copy;
end;

procedure shiftDown(var A:intArray; k:integer);
var t,s:integer;
continue:boolean;
begin
t:=1;
continue:=true;
	while continue do begin
		if (2*t>k) then continue:=false // cia buvo break
		else begin
			s:=2*t;
			if s+1 <= k then begin
				if A[s+1]>A[s] then begin
					s:=s+1;
				end;
			end;
		end;
		if (A[t]>A[s]) then continue:=false;	 // cia buvo break
		if continue then  begin	
			swap(A[t],A[s]);
			T:=s;
		end;
	end;
end;

procedure shiftUp(var A:intArray; k:integer);
var t,s:integer;
begin
	s:=k;
	t:=s div 2;
	while (A[t] < A[s]) AND (s>1) do begin
		swap(A[s],A[t]);
		s:=t;
		if s>1 then t:=s div 2;
	end;
end;

procedure makeHeap(var A:intArray; n:integer);
var i:integer;
begin
	for i:=2 to n do begin
		shiftUp(A,i);
	end;
	for i:=n downto 2 do begin
		swap(A[1],A[i]);
		shiftDown(A,i-1);
	end;
end;
begin
randomize;

writeln('Atsitiktinis masyvas:');
	for i:=1 to size do begin
		M[i]:=random(1000)+1;
		write(M[i],' ');
		if i mod 10 = 0 then writeln;
	end;
	writeln;
	writeln('Surikiuotas masyvas:');
	makeHeap(M,size);
	for i:=1 to size do begin
		write(M[i],' ');
		if i mod 10 = 0 then writeln;
	end;
end.

