program Noname11;
uses MyUnit01;
var k,i:integer;
M:array[1..1000] of integer;
begin
readln(k);
writeln(k);
for i :=1 to k do begin
    readln(M[i]);
    end;
for i:=1 to k do begin
    write(' ',M[i]);
    end;
    InsertionIntSort(M,k);
    readln;
for i:=1 to k do begin
    write(' ',M[i]);
    end;
    readln;

end.
