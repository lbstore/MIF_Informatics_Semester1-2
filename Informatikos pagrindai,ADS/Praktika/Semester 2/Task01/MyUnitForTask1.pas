unit MyunitForTask1;

interface
const tenThousand=10000;
type
     Array_Of_String = array [1..tenThousand] of string;

     StringRecord = record
     inf:string;
     endOfLine:boolean;
     end;
type
     array_Str_Record = array [1..tenThousand] of StringRecord;

function Modify(str:string):string;
function IntToStr(int:integer):string;
//procedure readTextToFile(var textFile:text; var strRecordArray:array_Str_Record; var numberOfW:integer);

implementation

//---
Function IntToStr(int:integer):String;
var productString:String;
begin
    Str(int,productString);
    IntToStr:=productString;
end;

//--- Pakeicia string pagal uzduoti
function Modify(str:string):string;
var lengthOfStr,p,ammount:integer;
c1,c2,unwantedChr:char;
toStr:string;
begin
    Modify:='';
    lengthOfStr:=length(str);
    c2:=str[1];
    for p:=2 to lengthOfStr+1 do begin
        c1:=str[p];

        if (c2<>c1)AND(ammount>1) then begin
            Modify:=Modify+c2+'$'+IntToStr(ammount);
            ammount:=0;
            unwantedChr:=c2;
        end;
        
        if (c2<>c1)AND(c2<>unwantedChr) then begin
            Modify:=Modify+c2;
            ammount:=1;
        end
        else ammount:=ammount+1;
        
        c2:=c1;
    end;
end;

{
procedure readTextToFile(var textFile:text; var strRecordArray:array_Str_Record; var numberOfW:integer);
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
    }
END.//End of Unit
