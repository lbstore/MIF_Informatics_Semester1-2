program uzduotis4;
uses crt,MyUnitGeneral,MyUnitStr;

type WordStruct=record
        number:integer;
        startingLetter:char;
        inWord:string;
        correct:boolean;
        end;


var
numbArray:array[1..1000] of integer;
strArray:array [1..10000] of string;
error,sk,tempNumb,ProgramNumber,InputMethod,outputMethod,i,i2,j,k,l,wowels,pasirinkimas,pradzia,pabaiga,willSort:integer;
inFileName,outFileName,textas,UserIn,Numeris:string;
d,rez:text;
c1,c2,desiredLetter,UserInputLetter:char;
M:array[1..1000] of WordStruct;



/////////////----------------/////////////////

BEGIN
    writeln('Iveskite "1" jei norite rusiuoti duomenis');
    writeln('Iveskite "2" jei rusiuoti nenorite.');
    willSort:=valIntChoice(UserIn);
    WriteLn('Pasirinkite programos versija (1,2)');
    ProgramNumber:=valIntChoice(UserIn);
    Writeln('Kokiu budu ivesite duomenis?');
    WriteLn('1 - klaviatura , 2 - is tekstinio failo');
    InputMethod:=valIntChoice(UserIn);

  if InputMethod=2 then begin

        write('Iveskite duomenu failo pavadinima (.txt) :');
        repeat
        readln(inFileName);
        assign(d,inFileName);
        {$I-} //klaidu tikrinimas IO's direktorijoje off
        reset(d);
        {$I+}
        error:=IOResult;
        if  (error <> 0) OR (NOT validName(inFileName)) then begin
                Writeln('Nera nurodyto failo arba blogas pavadinmas, bandykite dar karta ');
                end;
    until (error = 0) AND (validName(inFileName));
  end;


  i:=1;
  j:=0;
  k:=1; //kiekis
  case ProgramNumber of
  1 : Begin
        writeln('Programa nr1. Skaiciu skaitmenu suma.');writeln;
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
                    pabaiga:=pabaiga-1;

                                                                                // writeln(length(textas));write(' ',Numeris,' L',l,' Pr',pradzia,' Pb',pabaiga,' ','- ',k,' = ',M[k].number);writeln;

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
        end;//else close

        for i:=1 to k do numbArray[i]:=(M[i].number);

        if willSort=1 then InsertionIntSort(numbArray,k);

        for i:=1 to k do begin
            tempNumb:=0;
            repeat
                sk:=numbArray[i] MOD 10;         //paskutinis skaitmuo
                numbArray[i]:=numbArray[i] DIV 10;//pamazinamas per skaitmeni i kaire
                tempNumb:=tempNumb+sk;
            until (numbArray[i]=0);
            numbArray[i]:=tempNumb;
        end;
    end;//Case 1 close

  2 : Begin
            writeLn('Programa Nr.2.  Zodziu, su "n" balsemis atrinkimas'); writeln;
            if (InputMethod = 1) then begin
                write('iveskite teksta:');
                readln(textas);
                repeat
                    repeat
                        l:=l+1;//length
                        c1:=textas[l];
                        if ((NOT letter(c1)) AND (letter(c2))) then k:=k+1;
                        c2:=c1; // char1(naujas) char2(pries tai buves)                                                                          //write(c1,' ',j);readln;
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
                        if EOF(d) then break
                        until letter(c1);
                        if letter(c1) then M[k].inWord:=M[k].inWord+c1;
                    until EOF(d)=true;
                end;

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
                   
                for i:=1 to k do strArray[i]:=M[i].inWord;
                if willSort=1 then InsertionStrSort(strArray,k);
                for i:=1 to k do M[i].inWord:=strArray[i];

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
        if  (validName(outFileName)=false) then
                Writeln('Blogas pavadinmas, bandykite dar karta ');
    until (validName(outFileName)=true);
   close(d);
   assign(rez,outFileName);
   rewrite(rez);
   end;

    clrscr;
    writeln;
   
    case outputMethod of
    1: Begin
            case ProgramNumber of
            1: for i:=1 to k do writeln(NumbArray[i]);
            2: for i:=1 to k do if M[i].correct then writeln(M[i].inWord);
            end;
       end;
    2: Begin
            case ProgramNumber of
            1: for i:=1 to k do writeln(rez,NumbArray[i]);
            2: for i:=1 to k do if M[i].correct then writeln(rez,M[i].inWord);
            end;
        close(rez);
        end;
    end;
    
    writeln;
    writeln('Jusu pasirinkimai:');
    writeln;
    writeln('Rusiavimas:',willSort,' Programos numeris:',ProgramNumber);
    writeln('Ivedimo budas:',InputMethod,' Isvedimo budas:', OutputMethod);
    writeln;
    writeln('--PABAIGA--');
    readln;
END.
