unit MyUnitStr;

interface

function letter( x:char):boolean;
function number( x:char):boolean;
function findWowels(anyWord:string):integer;
function valIntChoice (UserInput:string):integer;
function validName(Name:string):boolean;



implementation

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
  case lowercase(anyWord[a]) of
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


END.//End of Unit
