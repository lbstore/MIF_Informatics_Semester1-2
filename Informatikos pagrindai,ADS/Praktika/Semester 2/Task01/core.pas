{
1. Parašyti funkcija, kuri duotame tekste keleta iš eiles einanciu vienodu simboliu (išskyrus tarpus) pakeicia vienu tokiu simboliu,
$ ir skaiciumi buvusiu simboliu
(pvz., tekstas "aaa bbuvvvvo" turi buti pakeistas i "a$3 b$2uv$4o").
Pertvarkytus žodžius išsaugoti atmintyje. Kita funkcija atliks maksimalaus/minimalaus elemento metodo rušiavima.
 }


program task01;
uses
MyUnitForTask1,
MyUnitStr,
MyUnitGeneral;
const tenThousand=10000;



type
    StringRecord = record
    inf:string;
    endOfLine:boolean;
    end;
            
    //Array_Of_Numbers = array[1..tenThousand] of integer;
    Array_Of_String = array[1..tenThousand] of string;
    array_Str_Record = array [1..tenThousand] of StringRecord;  //


var
arrayStringOriginal : array_Str_Record;//
arrayStringModified : array_Str_Record; //
finalArray : Array_Of_String;
    
i,numberOfWords,error:integer;
//numberOfTries:integer;
inFileName,outFileName:string;
textIn,textOut:text;


procedure readTextToFile(var textFile:text;var strRecordArray:array_Str_Record; var numberOfW:integer);
var i:integer;
begin
i:=1;
    while NOT(EOF(textFile)) do begin
        repeat
            read(textFile,strRecordArray[i].inf);
            i:=i+1;
        until EOln(textFile);
        if NOT(EOF(textFile))then readln(textFile);
        strRecordArray[i].endOfLine:=true;
    end;
    numberOfW:=i;
end;

      

BEGIN
    WriteLn('Welcome!');
    repeat  // inFailo vardo skaitymas
        {if (numberOfTries>5) then begin
            writeln('Fix something and launch again later');
            readln;
            halt;
        end;}
        Write('Write the name of your input text file(.txt): ');
        readln(inFileName);
        assign(textIn,inFileName);
        {$I-} //klaidu tikrinimas IO's direktorijoje off
        reset(textIn);
        {$I+}
        error:=IOResult;
        if  (error <> 0) OR (NOT validName(inFileName)) then begin
            Writeln('No such file or invalid file name, try again');
            ///numberOfTries:=numberOfTries+1;
        end;
    until (error = 0) AND (validName(inFileName));

    writeln;
    writeln('OK');
    writeln;
    writeln('File was found');
    writeln;

    //texto skaitymas i masyva
    readTextToFile(textIn,arrayStringOriginal,numberOfWords);

    close(textIn);

     // Is originalaus masyvo rasymas i kita
    for i:=1 to numberOfWords do begin
        arrayStringModified[i].inf:=Modify(arrayStringOriginal[i].inf);
        arrayStringModified[i].endOfLine:=arrayStringOriginal[i].endOfLine;
        finalArray[i]:=arrayStringModified[i].inf;
    end;
    

    
    //SelectionStrSort(finalArray,numberOfWords);     //rusiavymas?
  
    // outFailo vardo skaitymas
    repeat
        Write('Write the name of your output text file(.txt): ');
        readln(outFileName);
        if  (NOT validName(outFileName)) then begin
            Writeln('Invalid file name, try again');
        end;
    until (validName(outFileName));
    assign(textOut,outFileName);
    rewrite(textOut);
    
    //israsymas
    for i:=1 to numberOfWords do begin
        if arrayStringModified[i].endOfLine then writeln(textOut);
        write(textOut,arrayStringModified[i].inf);

    end;
    close(textOut);
    writeln('Great success');
    writeln(outFileName,' was saved in the same directory as ',inFileName);
    readln;

END. //THE END
