program uzduotis5;
uses crt,MyUnitGeneral,MyUnitStr;

type WordStruct=record
        number:integer;
        startingLetter:char;
        inWord:string;
        correct:boolean;
        end;
        
type list=^element;
    element = record
        number:integer;
        kitas:list;
    end;


var

p,pirmas:list;
numbArray:array[1..1000] of integer;
strArray:array [1..10000] of string;
keyboardInput,screenDisplay,showInterface,willSort:boolean;
error,sk,tempNumb,ProgramNumber,i,i2,j,k,l,wowels,skaicius,choice,pradzia,pabaiga:integer;
inFileName,outFileName,textas,UserIn,Numeris:string;
d,rez:text;
c1,c2,desiredLetter,UserInputLetter:char;
M:array[1..1000] of WordStruct;



/////////////----------------/////////////////

BEGIN
    //writeln(validName('rezul.txt'));
    willSort:=false;
    screenDisplay:=false;
    keyboardInput:=false;
    showInterface:=false;
    write('Iveskite "1" jei norite matyti grazia vartotojo sasaja');
    writeln(' "2" jei paprasta');
    choice:=valIntChoice(UserIn);
    if (choice=1) then  showInterface:=true;

     if showInterface then begin Textcolor(15); TextBackground(10); HighVideo;  end;
     if showInterface then begin clrscr; GotoXY(19,1);end;
        writeln('Iveskite "1" jei norite rusiuoti duomenis');
     if showInterface then GotoXY(19,2);
        writeln('Iveskite "2" jei rusiuoti nenorite.');



    Choice:=valIntChoice(UserIn);
    if (choice=1) then willSort:=true;
    
    if showInterface then begin clrscr; GotoXY(19,1);end;
    WriteLn('Pasirinkite programos versija (1,2)');
    if showInterface then begin GotoXY(19,9);
        writeln('Programa Nr1. Skaiciu skaitmenu suma.');
        GotoXY(19,11);
        writeln('Programa Nr.2.  Zodziu, su "n" balsemis atrinkimas');
    end;
    ProgramNumber:=valIntChoice(UserIn);
    
    if showInterface then begin clrscr; GotoXY(19,1);end;
    Writeln('Kokiu budu ivesite duomenis?');
    if showInterface then GotoXY(19,2);
    WriteLn('1 - klaviatura , 2 - is tekstinio failo');

    choice:=valIntChoice(UserIn);
    if (choice=1) then keyboardInput:=true;

  if NOT keyboardInput then begin

         if showInterface then begin clrscr; GotoXY(19,1);end;
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
   if showInterface then begin clrscr; GotoXY(19,1);end;
  
  case ProgramNumber of
  1 : Begin
        writeln('Programa nr1. Skaiciu skaitmenu suma.');writeln;
        if (keyboardInput) then begin
         if showInterface then begin GotoXY(19,2);end;
            writeln('Iveskite skaicius, norint baigti, ivesti "0"');
            repeat
             if showInterface then Textcolor(15);
            Write('skaicius Nr.',k,' :');
                repeat
                    readln(UserIn);
                    Val (UserIn, skaicius, error);
                    if NOT(error=0) then writeln('Blogas formatas, bandykite dar karta');
                until (error=0);
                if (skaicius=0) then break;
                new(p);
                p^.number:=skaicius;
                p^.kitas:=pirmas;
                pirmas:=p;
                k:=k+1;
            until (skaicius=0);
            k:=k-1;
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


                    Val (Numeris, numbArray[k], error);
                    if ((error<>0)AND(numbArray[k]=0))then k:=k-1;
                    numeris:='';
                    k:=k+1;
                until (l>=length(textas));
            end;
            //close(d);
            k:=k-1;
            
            for i:=1 to k do begin
            new(p);
            p^.number:=numbArray[i];
            p^.kitas:=pirmas;
            pirmas:=p;
            end;

        end;//else close
        i:=1;
        p:=pirmas;
        while (p<>nil) do begin
          numbArray[k-i+1]:=p^.number;
          i:=i+1;
          p:=p^.kitas;
        end;

        if willSort then InsertionIntSort(numbArray,k);

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
             if showInterface then begin clrscr; Textcolor(15); GotoXY(19,1);end;
            writeLn('Programa Nr.2.  Zodziu, su "n" balsemis atrinkimas'); writeln;

             if showInterface then begin GotoXY(19,2);end;
            if (keyboardInput) then begin
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

                repeat
                     if showInterface then begin clrscr; TextColor(15); GotoXY(19,1);end;
                    write('Iveskite raide, kuria turi prasideti zodis:');
                    readln(desiredLetter);
                    if showInterface then Textcolor(4);
                    if(NOT(letter(desiredLetter)))then writeln('Blogas formatas, bandykite dar karta');
                until (letter(desiredLetter));
                desiredLetter:=lowercase(desiredLetter);
                repeat
                     if showInterface then begin clrscr; TextColor(15); GotoXY(19,1);end;
                    write('Iveskite balsiu skaiciu:');
                    readln(UserIn);
                    if showInterface then Textcolor(4);
                    Val (UserIn, wowels, error);
                    if NOT(error=0) then writeln('Blogas formatas, bandykite dar karta');
                until (error=0);



                for i:=1 to k do begin
                   M[i].correct:=false;
                end;

                for i:=1 to k do strArray[i]:=M[i].inWord;
                if willSort then InsertionStrSort(strArray,k);
                for i:=1 to k do M[i].inWord:=strArray[i];


                for i:=1 to k do begin
                    M[i].startingLetter:=lowercase(M[i].inWord[1]);
                    if (findWowels(M[i].inWord)=wowels)AND(M[i].startingLetter=desiredLetter) then M[i].correct:=true;

                    end;


        end;//Case 2 close

  end;//Case close
    if showInterface then begin clrscr; TextColor(15); GotoXY(19,1);end;
    Writeln('Kokiu budu norite matyti rezultatus?');
    if showInterface then GotoXY(19,2);WriteLn('1 - ekrane , 2 - text faile');



    choice:=valIntChoice(UserIn);
    if (choice=1) then screenDisplay:=true;

    if (NOT screenDisplay) then begin
        if showInterface then begin clrscr; TextColor(15); gotoXY(19,1); end;
        write('Iveskite rezultato failo pavadinima (.txt) :');
        repeat
        readln(outFileName);
        if  (validName(outFileName)=false) then
                Writeln('Blogas pavadinmas, bandykite dar karta ');
    until (validName(outFileName)=true);



   end;
   if (keyboardInput=false) then begin
   if (inFileName=outFileName)then close(d);
   assign(rez,outFileName);
   rewrite(rez);
   end;
     if showInterface then begin i2:=1; clrscr; end;


    writeln;
    if showInterface then begin clrscr;end;
    if screenDisplay then
        Begin
            case ProgramNumber of
            1: for i:=1 to k do begin
                                if showInterface then GotoXY(30,i);
                                writeln(NumbArray[i]);
                                end;
            2: for i:=1 to k do begin
                if showInterface then GotoXY(30,i2+1);
                if M[i].correct then begin writeln(M[i].inWord);  i2:=i2+1; end;
                end;
            end;
        end else
        
        Begin
            case ProgramNumber of
            1: for i:=1 to k do writeln(rez,NumbArray[i]);
            2: for i:=1 to k do if M[i].correct then writeln(rez,M[i].inWord);
            end;
        close(rez);
        end;

    if showInterface then Textcolor(1);
    writeln;writeln;writeln;writeln;writeln;
    writeln('Jusu pasirinkimai:');
    writeln;
    writeln('Rusiavimas:',willSort);
    writeln('Programos numeris:',ProgramNumber);
    writeln('Ivedimo budas klaviaratura:',keyboardInput);
    writeln('Isvedimo budas ekrane:',screenDisplay);
    if showInterface then Textcolor(0);
    if showinterface then write('                                   ');
    writeln('--PABAIGA--');
    readln;
END.
