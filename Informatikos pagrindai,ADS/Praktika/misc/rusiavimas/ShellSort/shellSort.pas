 
program Shellsorting;

const size=50;
type intArray = array[1..size] of longint;
var i: integer;
M:intArray;

procedure shellSort(mas:intArray);
var i,j,k,step,elem:integer;
steps:array[0..15] of longint;
begin
	steps[0] := 4356424;
	steps[1] := 1355339;
	steps[2] := 543749;
	steps[3] := 213331;
	steps[4] := 84801;
	steps[5] := 27901;
	steps[6] := 11969;
	steps[7] := 4711;
	steps[8] := 1968;
	steps[9] := 815;
	steps[10] := 277;
	steps[11] := 97;
	steps[12] := 31;
	steps[13] := 7;
	steps[14] := 3;
	steps[15] := 1;
	
	for k:=0 to 15 do begin
		step := steps[k];
		write('Isorinis');
		readln;
		for i:= step to size do begin
			elem := mas[i];
			j:=i;
			while((j>=step) AND (mas[j-step]>elem)) do begin
				mas[j] := mas[j-step];
				j := j-step;
				write('w ');
				readln;
			end;
			mas[j] := elem;
		end; 
	end;
	
	
end;
begin
writeln('Atsitiktinis masyvas:');
	for i:=1 to size do begin
		M[i]:=random(999999999)+1;
		write(M[i],' ');
		if i mod 7 = 0 then writeln;
	end;
	writeln;
	shellSort(M);
	writeln('Surikiuotas masyvas:');
	for i:=1 to size do begin
		write(M[i],' ');
		if i mod 10 = 0 then writeln;
	end;
end.

