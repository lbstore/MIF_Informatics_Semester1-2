program uzduotis_3;

var choice,choice1:integer;
label pradzia;

////////////////////

procedure pirma;


var  n,c,i,x,j:integer;

M:array[1..100] of integer;
begin
  writeln('kiek skaiciu norite suvesti?  (max 100)');
  readln(x);
  for i:=1 to x do begin
  write('skaiciaus nr',i,': ');
  readln(M[i]);
  n:=0;
  repeat
    c:=M[i] MOD 10;
    M[i]:=M[i] DIV 10;
    n:=n+c;
  until(M[i]=0);
  M[i]:=M[i]+n;
  end;

  for j:=1 to x do begin
  writeln(M[j]);
  end;
  
  writeln;
  writeln('PROGRAMOS PABAIGA');
  writeln;
  writeln('"ENTER" isejimui' );
  Readln;

end;

/////////////////////////////

procedure antra;

label start;
    type WordStruct = record
            startingLetter:char;
            inWord:string;
            end;


    var d,rez:text;
    word:array[1..1000] of WordStruct;
    inFileName,outFileName:string;
    i,j,words,value,numberOfWowels:integer;
    c1,c2,desiredLetter:char;




function letter( x:char):boolean;

var t:boolean;

begin
    t:=false;
    value:=Ord(x);
    if ((value>64) AND (value<91)) OR ((value>96) AND (value<123)) then
    t:=true;

    letter:=t;
end;

//---------------------

function number( x:char):boolean;

var t:boolean;

begin
    t:=false;
    value:=Ord(x);
    if (value<58)AND(value>47) then
    t:=true;

    number:=t;
end;


//---------------------

function findWowels(anyWord:string):integer;

var a,amount:integer;

begin
amount:=0;
 for a:=1 to length(anyWord) do begin
  case anyWord[a] of
  'a' :   begin
            amount:=amount+1;
            end;
  'e' :   begin
            amount:=amount+1;
            end;
  'i' :   begin
            amount:=amount+1;
            end;
  'y' :   begin
            amount:=amount+1;
            end;
  'o' :   begin
            amount:=amount+1;
            end;
  'u' :   begin
            amount:=amount+1;
            end;
  end;
end;

findWowels:=amount;

end;

//-------------------------

function validName(Name:string):boolean;
var a:integer;
x:char;
tempWord:string;
begin
a:=0;
validName:=true;

    for a:=1 to length(name) do begin
        a:=a+1;
        x:=Name[a];
        if (  (NOT letter(x)) AND (NOT number(x))  AND  ((x = '.')=false) )then validName:=false
        end;
        
     tempWord:=copy(name,length(name)-3,4);
     if tempWord<>'.txt' then validName:=false;

end;




////////////////////////////

begin

  repeat

    start:
    write('Irasykte pradiniu duomenu failo varda (.txt) : ');
    readln(inFileName);
    assign(d,inFileName);
    {$I-} //klaidu tikrinimas IO's direktorijoje off
    reset(d);
    {$I+} //klaidu tikrinimas on
    if  ((length(inFilename)<1) OR (IOresult <> 0)) OR (validName(inFileName)=false) then begin
    
    
            Writeln('Nera nurodyto failo, bandykite dar karta ');
            goto start;
            end;
   until ((IOResult = 0) AND ((length(inFileName)>1)) );

  repeat
    write('Irasykite rezultatu failo varda: ');
    readln(outFileName);
    if (NOT validName(outFileName)) OR (outFileName=inFileName) then Writeln('Bandykite dar karta ');
  until (validName(outFileName)AND(outFileName<>inFileName));

  assign(rez,outFileName);
  rewrite(rez);

  write('Irasykite raide, kuria prasidedancius zodzius jus norite isvesti: ');
  readln(desiredLetter);
  writeln;
  writeln('Irasykite skaiciu balsiu,');
  write('kuris turi buti zodziuose prasidedanciuose raide ',desiredLetter,' :');
  readln(numberOfWowels);
  desiredLetter:=LowerCase(desiredLetter);

  i:=1;
  repeat

        repeat

            c2:=c1;  // char1(naujas) char2(pries tai buves)
            read(d,c1);

            if EOln(d) then readln(d);

            if (NOT letter(c1)) AND (letter(c2)) then i:=i+1;

            if EOF(d) then break;

        until letter(c1);

        if letter(c1) then begin

            word[i].inWord:=word[i].inWord+c1;

            end;

  until EOF(d)=true;

  close(d);
  words:=i-1;

  for j:=1 to words do begin

    word[j].startingLetter:=LowerCase(word[j].inWord[1]);
    if (word[j].startingLetter = desiredLetter) AND (findWowels(word[j].inWord) = numberOfWowels) then  writeln(rez,word[j].inWord);

  end;

 {
 //debugging porposes
  for j:=1 to words do begin
    writeln(word[j].inWord);
  end;
  }

  close(rez);
  writeln;
  writeln('PROGRAMOS PABAIGA');
  writeln;
  writeln('Rezultatai issaugoti ', outFileName ,' Byloje');
  writeln;
  writeln('"ENTER" isejimui' );
  Readln;
end;

BEGIN

repeat
    writeln('Kuri programos varianta pasirinksite? (1 , 2) ');
    readln(choice);
    if (NOT choice=1)AND(NOT choice=2) then
        writeln('Neteisingas pasirinkimas (1 , 2), bandykite dar karta');
        
until (choice=1)OR(choice=2);

pradzia:
    
    case choice of
    1:pirma;
    2:antra;
    end;
    choice:=(choice MOD 2) +1;
    

if (choice1<>2) then begin
    writeln('norite pabandyti kita varianta? (sutikimui iveskite "1") ');
    readln(choice1);
    if (choice1 = 1) then begin
        choice1:=2;
        goto pradzia;
        end;
    end;
END.


