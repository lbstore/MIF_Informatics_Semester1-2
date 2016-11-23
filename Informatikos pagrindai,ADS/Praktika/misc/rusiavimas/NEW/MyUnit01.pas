unit MyUnit01;

interface
type Array_Of_Numbers = array[1..1000] of integer;
    Array_Of_String = array [1..10000] of string;
    
procedure swapInt(var a,b:integer);
procedure swapStr(var a,b:string);
function letter( x:char):boolean;
function number( x:char):boolean;
function findWowels(anyWord:string):integer;
function valIntChoice (UserInput:string):integer;
function validName(Name:string):boolean;
procedure InsertionIntSort(var Q:Array_Of_Numbers; kiekis:integer);
procedure InsertionStrSort(var Q:Array_Of_String; kiekis:integer);




implementation

procedure InsertionIntSort(var Q:Array_Of_Numbers; kiekis:integer);
var a1,a2,lyginamasis:integer;//ciklas 1 ir ciklas 2
begin
    for a1:=1 to kiekis do begin
        //lyginamasis:=Q[a1];
        for a2:=(a1) to kiekis do begin
            if Q[a1]>Q[a2] then swapInt(Q[a1],Q[a2]);
        end;
    end;


end;


procedure InsertionStrSort(var Q:Array_Of_String; kiekis:integer);
var a1,a2,lyginamasis:integer;//ciklas 1 ir ciklas 2
begin
    for a1:=1 to kiekis do begin
        //lyginamasis:=Q[a1];
        for a2:=(a1+1) to kiekis do begin
            if Q[a1]>Q[a2] then swapStr(Q[a1],Q[a2]);

        end;
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

function letter( x:char):boolean;

var t:boolean;
value:integer;

begin
    t:=false;
    value:=Ord(x);
    if ((value>64) AND (value<91)) OR ((value>96) AND (value<123)) then
    t:=true;

    letter:=t;
end;

function number( x:char):boolean;

var t:boolean;
value:integer;
begin
    t:=false;
    value:=Ord(x);
    if (value<58)AND(value>47) then
    t:=true;

    number:=t;
end;

function findWowels(anyWord:string):integer;

var a,amount:integer;

begin
amount:=0;
 for a:=1 to length(anyWord) do begin
  case anyWord[a] of
  'a' :amount:=amount+1;
  'e' :amount:=amount+1;
  'i' :amount:=amount+1;
  'y' :amount:=amount+1;
  'o' :amount:=amount+1;
  'u' :amount:=amount+1;
  end;
 end;
findwowels:=amount;
end;


function valIntChoice (UserInput:string):integer;
var pasirinkimas,error:integer;
begin
    repeat
    readln(UserInput);
    Val (UserInput, pasirinkimas, error);
    if NOT((error=0) AND ((pasirinkimas = 1)OR(pasirinkimas = 2))) then
        writeln('Blogas formatas, bandykite dar karta');

    until (error=0) AND ((pasirinkimas = 1)OR(pasirinkimas = 2));
    valIntChoice:=pasirinkimas;
    pasirinkimas:=0;
end;


function validName(Name:string):boolean;
var a:integer;
    c1:char;

begin

a:=0;
validName:=true;

if NOT((length(name)-POS('.txt',name))=3) then validName:=false;
    if NOT(length(Name)>3 )then validName:=false
    else begin
        for a:=1 to length(name) do begin


            c1:=Name[a];
            a:=a+1;
            if (  NOT letter(c1) AND (NOT number(c1))  AND  (NOT (c1 = '.')) )then validName:=false
            end;

     end;


end;


end.
