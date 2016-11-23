program uzduotis3;
uses crt;

type WordStruct=record
        number:integer;
        startingLetter:char;
        inWord:string;
        correct:boolean;
        end;
        
        
var
error,sk,tempNumb,ProgramNumber,InputMethod,outputMethod,i,j,k,l,wowels,pasirinkimas,pradzia,pabaiga:integer;
inFileName,outFileName,textas,UserIn,Numeris:string;
d,rez:text;
c1,c2,desiredLetter,UserInput:char;
M:array[1..1000] of WordStruct;


//----------------------

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

//---------------------

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


//---------------------

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

findWowels:=amount;

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


//------------------------

function validName(Name:string):boolean;
var a:integer;
    c1:char;

begin

a:=0;
validName:=true;
                                                                                //writeln(Name,' ',validName,' ',a,' ',c1,' ',length(name));
if NOT((length(name)-POS('.txt',name))=3) then validName:=false;
    if NOT(length(Name)>3 )then validName:=false
    else begin
        for a:=1 to length(name) do begin


            c1:=Name[a];
            a:=a+1;
            if (  NOT letter(c1) AND (NOT number(c1))  AND  (NOT (c1 = '.')) )then validName:=false
            end;

     end;

                                                                                //writeln(Name,' ',validName,' ',a,' ',c1,' ');
end;

/////////////----------------/////////////////

BEGIN
    //writeln(validname('failas.txt'));   readln;
    WriteLn('Pasirinkite programos versija (1,2)');
    ProgramNumber:=valIntChoice(UserIn);
    Writeln('Kokiu budu ivesite duomenis?');
    WriteLn('1 - klaviatura , 2 - is tekstinio failo');
    InputMethod:=valIntChoice(UserIn);

  if InputMethod=2 then begin

        write('Iveskite duomenu failo pavadinima (.txt) :');
        repeat
        //back:
        readln(inFileName);
        assign(d,inFileName);
        {$I-} //klaidu tikrinimas IO's direktorijoje off
        reset(d);
        {$I+}
        error:=IOResult;
        if  (error <> 0) OR (NOT validName(inFileName)) then begin
                Writeln('Nera nurodyto failo arba blogas pavadinmas, bandykite dar karta ');
                //goto back;
                end;
    until (error = 0) AND (validName(inFileName));
  end;


  i:=1;
  j:=0;
  k:=1; //kiekis
  case ProgramNumber of
  1 : Begin
        writeln('Programa nr1. Skaiciu skaitmenu suma.');
        if (InputMethod = 1) then begin
            writeln('Iveskite skaicius, norint baigti, ivesti "0"');
            repeat

            Write('skaicius Nr.',k,' :');
                repeat
                    readln(UserIn);
                    Val (UserIn, M[k].number, error);
                    if NOT(error=0) then writeln('Blogas formatas, bandykite dar karta');
                until (error=0);
                k:=k+1;
            until (M[k-1].number=0);
            k:=k-2;//eliminuoja paskutinius du '0'
        end
        else begin
        
            //Skaiciu atrinkimas is netvarkingo teksto
        
            while NOT EOF(d) do begin
                readln(d,textas);
                l:=1;//length
                repeat

                    pradzia:=l;
                    while NOT (Number(textas[pradzia])) do begin

                        pradzia:=pradzia+1;
                        l:=l+1;
                        if (l>=length(textas)) then break;
                        end;
                    pabaiga:=pradzia;
                    repeat

                        l:=l+1;
                        pabaiga:=pabaiga+1;
                    until NOT(Number(textas[pabaiga])) ;
                    pabaiga:=pabaiga-1;                                                                                                    // writeln(length(textas));write(' ',Numeris,' L',l,' Pr',pradzia,' Pb',pabaiga,' ','- ',k,' = ',M[k].number);writeln;

                    for i:=pradzia to pabaiga do
                    Numeris:=Numeris + textas[i];

                    Val (Numeris, M[k].number, error);
                    if ((error<>0)AND(M[k].number=0))then k:=k-1;
                    numeris:='';
                    k:=k+1;


                until (l>=length(textas));
            end;
            close(d);
            k:=k-1;

        end;
        for i:=1 to k do begin
            tempNumb:=0;
            repeat
                sk:=M[i].number MOD 10;         //paskutinis skaitmuo
                M[i].number:=M[i].number DIV 10;//pamazinamas per skaitmeni i kaire
                tempNumb:=tempNumb+sk;
            until (M[i].number=0);
            M[i].number:=tempNumb;
        end;
    end;
        
        


  2 : Begin
            writeLn('Programa Nr.2.  Zodziu, su pasirinktomis raidemis ir balsiu kiekiu atrinkimas');
            if (InputMethod = 1) then begin
                write('iveskite teksta:');
                readln(textas);
                repeat
                    repeat

                        l:=l+1;//length

                        c1:=textas[l];

                        
                        if ((NOT letter(c1)) AND (letter(c2))) then k:=k+1;
                        c2:=c1; // char1(naujas) char2(pries tai buves)
                                                                                //write(c1,' ',j);readln;
                    until letter(c1);
                    
                    if letter(c1) then M[k].inWord:=M[k].inWord+c1;

                until (l>=length(textas));
            end
            else begin
            
                    repeat

                        repeat

                        c2:=c1;
                        read(d,c1);
                        if EOln(d) then readln(d);
                        if (NOT letter(c1)) AND (letter(c2)) then k:=k+1;
                        if EOF(d) then break;
                        
                        until letter(c1);
                        
                        if letter(c1) then M[k].inWord:=M[k].inWord+c1;
                        
                    until EOF(d)=true;

                end;
                //k:=i;


                repeat
                    write('Iveskite raide, kuria turi prasideti zodis:');
                    readln(desiredLetter);
                    if(NOT(letter(desiredLetter)))then writeln('Blogas formatas, bandykite dar karta');
                until (letter(desiredLetter));
                desiredLetter:=lowercase(desiredLetter);
                repeat
                    write('Iveskite balsiu skaiciu:');
                    readln(UserIn);
                    Val (UserIn, wowels, error);
                    if NOT(error=0) then writeln('Blogas formatas, bandykite dar karta');
                until (error=0);
                


                for i:=1 to k do begin
                   M[i].correct:=false;
                   end;

                for i:=1 to k do begin
                    M[i].startingLetter:=lowercase(M[i].inWord[1]);
                    if (findWowels(M[i].inWord)=wowels)AND(M[i].startingLetter=desiredLetter) then M[i].correct:=true;

                    end;
                

        end;//Case 2 close

  end;//Case close
  
    Writeln('Kokiu budu norite matyti rezultatus?');
    WriteLn('1 - ekrane , 2 - text faile');
    outputMethod:=valIntChoice(UserIn);

    if (outputMethod = 2) then begin
    repeat
        write('Iveskite rezultato failo pavadinima (.txt) :');
        readln(outFileName);
        if  (validName(outFileName)=false)then
                Writeln('Blogas pavadinmas, bandykite dar karta ');
    until (validName(outFileName)=true);
   close(d);
   assign(rez,outFileName);
   rewrite(rez);
   end;

    //clrscr;
    writeln;

    case outputMethod of
    1: Begin
            case ProgramNumber of
            1: for i:=1 to k do writeln(M[i].number);
            2: for i:=1 to k do
            if M[i].correct then writeln(M[i].inWord);
            end;
       end;
    2: Begin
            case ProgramNumber of
            1: for i:=1 to k do writeln(rez,M[i].number);
            2: for i:=1 to k do if (M[i].correct) then writeln(rez,M[i].inWord);
            end;
        close(rez);
        end;
    end;
  
    writeln;
    writeln('--PABAIGA--');
    readln;
END.
