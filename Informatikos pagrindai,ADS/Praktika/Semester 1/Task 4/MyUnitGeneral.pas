unit MyUnitGeneral;

interface
type Array_Of_Numbers = array[1..1000] of integer;
     Array_Of_String = array [1..10000] of string;
    
procedure swapInt(var a,b:integer);
procedure swapStr(var a,b:string);
procedure InsertionIntSort(var Q:Array_Of_Numbers; kiekis:integer);
procedure InsertionStrSort(var Q:Array_Of_String;  kiekis:integer);
procedure selectionIntSort(var Q:Array_Of_Numbers; kiekis:integer);
procedure selectionStrSort(var Q:Array_Of_String;  kiekis:integer);


implementation

procedure InsertionIntSort(var Q:Array_Of_Numbers; kiekis:integer);
var a1,a2:integer;//ciklas 1 ir ciklas 2
begin
    for a1:=1 to kiekis do begin
        for a2:=(a1) to kiekis do begin
            if Q[a1]>Q[a2] then swapInt(Q[a1],Q[a2]);
        end;
    end;
end;


procedure InsertionStrSort(var Q:Array_Of_String; kiekis:integer);
var a1,a2:integer;//ciklas 1 ir ciklas 2
begin
    for a1:=1 to kiekis do begin
        for a2:=(a1+1) to kiekis do begin
            if Q[a1]>Q[a2] then swapStr(Q[a1],Q[a2]);

        end;
    end;
end;

procedure selectionIntSort(var Q:Array_Of_Numbers;kiekis:integer);
var a1,a2,k,indx,min:integer;
begin
    for a1:=1 to kiekis do begin
    min:=Q[a1];
    indx:=a1;
        for a2:=a1+1 to kiekis do begin
            if min>Q[a2] then begin
                                min:=Q[a2];
                                indx:=a2;
                                end;
            end;
        swapInt(Q[a1],Q[indx]);
        end;
end;


procedure selectionStrSort(var Q:Array_Of_String;kiekis:integer);
var a1,a2,k,indx:integer;
min:string;
begin
    for a1:=1 to kiekis do begin
    min:=Q[a1];
    indx:=a1;
        for a2:=a1+1 to kiekis do begin
            if min>Q[a2] then begin
                                min:=Q[a2];
                                indx:=a2;
                                end;
            end;
        swapStr(Q[a1],Q[indx]);
        end;
end;

procedure swapInt(var a,b:integer);
var c:integer;
begin
  c:=a;
  a:=b;
  b:=c;
end;

procedure swapStr(var a,b:string);
var c:string;
begin
    c:=a;
    a:=b;
    b:=c;
end;

END.//End of Unit
