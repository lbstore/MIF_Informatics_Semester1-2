{ Ieva Sriubaite 2kursas 1 grupe
Uzduotis nr. 32
1.Isrusiuokite masyvo elementus didejimo tvarka isrinkimo metodu, kai surusiuota dalis
formuojama masyvo pabaigoje
2.Isrusiuokite masyvo elementus mazejimo tvarka iterpimo metodu kai surusiuota dalis
formuojama masyvo pabaigoje
3.isrusiuokite masyvo elementus mazejimo tvarka burbulo metodu, kai surusiuota dalis
formuojama masyvo pabaigoje }

program sorting;

    // Duomenu failas
    const duomenu_failas = 'duomenys.txt';

    // sokoladas, kuriame saugoma visa info
    type sokoladas = Record
        pav     : String[20];
        kiek  : Integer;
        spalva  : Char;
        kaina   : Real;
        arskanus : Boolean;
    end;
        
    type list = ^rod;
        rod = record
        duomuo: sokoladas;
        next, prev : list;
     end;

    var key, sukeitimai, palyginimai : integer;


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Selection Sort  /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
procedure selectionSort(head, tail: list);
 var a, b: list;
     tmp: sokoladas;
 begin
    while (tail^.prev <> nil) do
    begin
        a:= tail;
        b:= tail^.prev;
        while b <> nil do
        begin
            inc(palyginimai);
            if ((b^.duomuo.pav) > (a^.duomuo.pav)) then
            begin
                a:= b;
            end;
            b:= b^.prev;
            inc(sukeitimai);
        end;
        
        tmp:= tail^.duomuo;
        tail^.duomuo:= a^.duomuo;
        a^.duomuo:= tmp;
        
        tail:= tail^.prev;
    end;
end;


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Insertion Sort  /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
procedure insertionSort(head, tail: list);
 var a,b,c: list;
    tmp: sokoladas;
 begin
    c:= head;
    while c <> nil do
    begin
        tmp:= c^.duomuo;
        inc(palyginimai);
        if (c^.prev<>nil) then
        begin
            a:= c^.prev;
            while ((a <> nil) AND (a^.duomuo.kiek < tmp.kiek)) do
            begin
                a^.next^.duomuo:= a^.duomuo;
                b:= a;
                a:= a^.prev;
                inc(palyginimai);
                inc(sukeitimai);
            end;
            if a<>nil then
                a^.next^.duomuo:= tmp
            else
            b^.duomuo:= tmp;
        end;
    c:= c^.next;
    end;
end;


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Bubble Sort  ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
procedure bubbleSort(head, tail: list);
var p, b: list;
    tmp: sokoladas;
begin
    p:= head;
    while p <> nil do
    begin
        b:= tail;
        while b <> head do
        begin
            if (b^.prev^.duomuo.kaina)<(b^.duomuo.kaina) then
            begin
                tmp:= b^.prev^.duomuo;
                b^.prev^.duomuo:= b^.duomuo;
                b^.duomuo:= tmp;
                inc(palyginimai);
                inc(sukeitimai);
            end
            else
            begin
                b:= b^.prev;
            end;
            inc(palyginimai);
        end;
        p:=p^.next;
    end;
end;


////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Saraso inicializavimas /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
procedure initList(var head, tail : list );
    var current : list;
    f : text;
begin
    assign(f, duomenu_failas);
    reset(f);
    while not eof(f) do
    begin
        new(current);
        readln(f, current^.duomuo.pav, current^.duomuo.spalva, current^.duomuo.kiek, current^.duomuo.kaina);
        current^.next := nil;
        if (head = nil) then
        begin
            current^.prev := nil;
            head := current;
        end
        else
        begin
            current^.prev := tail;
            tail^.next := current;
        end;
    tail := current;
      
    end;
    close(f);
end;

////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Saraso atspausdinimas //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
procedure printList(head: list);
    var current: list;
        s : string;
begin
   
    case key of
        1 : s := 'pavadinima';
        2 : s := 'kieki';
        3 : s := 'kaina';
        otherwise s := 'nieka';
    end;
    
    writeln('Surusiuota pagal ', s);
    writeln('Padaryta sukeitimu: ', sukeitimai );
    writeln('Padaryta palyginimu: ', palyginimai );
    writeln();
    writeln('------------------------------------------------------------');
    writeln('Pavadinimas        Spalva   Kiekis     Kaina');
    
    current := head;
    while (current <> nil) do
    begin
        writeln(current^.duomuo.pav, current^.duomuo.spalva, current^.duomuo.kiek:11, current^.duomuo.kaina:13:2);
        current := current^.next;
    end;
    writeln();
end;

{------------ Pagrindine programa -----------------}


var
    head, tail: list;

begin

    head := nil;
    tail := nil;

    // Inicilizuojam sarasa
    initList(head, tail);

    repeat
    
    // Atspauzdinam
    printList(head);
  
    // Menu
    writeln('Pasirinkite rusiavima metoda');
    writeln();
    writeln('1 - pagal pavadinima - Isrinkimo metodu (didejanciai)');
    writeln('2 - pagal kieki - Iterpimo metodu (mazejanciai)');
    writeln('3 - pagal kaina - Burbolo metodu (mazejanciai)');
    writeln('0 - iseiti is programos');
    writeln();
    write('Iveskite numeri: ');

    // Nuskaitom pasirinkima
    readln(key);
    writeln();

    sukeitimai := 0;
    palyginimai := 0;

    // Surusiuojam pagal pasirinkima
    case key of
        1: selectionSort(head, tail);
        2: insertionSort(head, tail);
        3: bubbleSort(head, tail);
    end;
  
  until (key = 0);
  
end.
