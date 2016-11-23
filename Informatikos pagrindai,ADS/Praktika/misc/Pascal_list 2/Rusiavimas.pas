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
        pav     : String[13];
        kiek  : Integer;
        spalva  : Char;
        kaina   : Real;
        arskanus: boolean;
        
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
     current: list;
 begin
    writeln('Nesurusiuota pagal pavadinima:');
    current := head;
    while (current <> nil) do
    begin
        WriteLn(current^.duomuo.pav);
        current := current^.next;
    end;
    writeln();
    writeln('Rusiuojama su Selection:');
    sukeitimai := 0;
    palyginimai := 0;
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
        
        current := head;
        while (current <> nil) do
        begin
            Write(current^.duomuo.pav);
            current := current^.next;
        end;
    end;
    writeln();
    writeln('Atlikta sukeitimu: ', sukeitimai );
    writeln('Atlikta palyginimu: ', palyginimai );
    writeln();
    writeln('Surusiuota su Selection:');
    current := head;
    while (current <> nil) do
    begin
        WriteLn(current^.duomuo.pav);
        current := current^.next;
    end;


end;


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Insertion Sort  /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
procedure insertionSort(head, tail: list);
 var a,b,c: list;
    tmp: sokoladas;
    current: list;
 begin
    writeln('Nesurusiuota pagal spalva:');
    current := head;
    while (current <> nil) do
    begin
        WriteLn(current^.duomuo.spalva);
        current := current^.next;
    end;
    writeln();
    writeln('Rusiuojama su Insertion:');
    c:= head;
    sukeitimai := 0;
    palyginimai := 0;
    while c <> nil do
    begin
        tmp:= c^.duomuo;
        inc(palyginimai);
        if (c^.prev<>nil) then
        begin
            a:= c^.prev;
            while ((a <> nil) AND (a^.duomuo.spalva < tmp.spalva)) do
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
    
    current := head;
    while (current <> nil) do
    begin
        Write(current^.duomuo.spalva, ' ');
        current := current^.next;
    end;
    Writeln;
    
    end;
    writeln();
    writeln('Atlikta sukeitimu: ', sukeitimai );
    writeln('Atlikta palyginimu: ', palyginimai );
    writeln();
    writeln('Surusiuota su Insertion:');
    current := head;
    while (current <> nil) do
    begin
        WriteLn(current^.duomuo.spalva);
        current := current^.next;
    end;
end;


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Bubble Sort  ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
procedure bubbleSort(head, tail: list);
var p, b: list;
    tmp: sokoladas;
    current: list;
begin
    writeln('Nesurusiuota pagal kaina:');
    current := head;
    while (current <> nil) do
    begin
        WriteLn(current^.duomuo.kaina:2:2);
        current := current^.next;
    end;
    writeln();
    writeln('Rusiuojama su BubbleSort:');
    sukeitimai := 0;
    palyginimai := 0;
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
        
        current := head;
        while (current <> nil) do
        begin
            Write(current^.duomuo.kaina:2:2, ' ');
            current := current^.next;
        end;
    Writeln;
    end;
    writeln();
    writeln('Atlikta sukeitimu: ', sukeitimai );
    writeln('Atlikta palyginimu: ', palyginimai );
    writeln();
    writeln('Surusiuota su BubbleSort:');
    current := head;
    while (current <> nil) do
    begin
        WriteLn(current^.duomuo.kaina:2:2);
        current := current^.next;
    end;
end;


////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Saraso inicializavimas /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
procedure initList(var head, tail : list );
    var current : list;
    f : text;
    temp: string[5];
begin
    assign(f, duomenu_failas);
    reset(f);
    while not eof(f) do
    begin
        new(current);
        readln(f, current^.duomuo.pav, current^.duomuo.spalva, current^.duomuo.kiek, current^.duomuo.kaina, temp);

        if(pos('t', temp) > 0) then
            current^.duomuo.arskanus:= true
        else
             current^.duomuo.arskanus:= false;
             
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
        i : integer;
begin
    
    current := head;
    i := 0;
    while (current <> nil) do
    begin
        WriteLn(i, ' narys ');
        WriteLn('Pavadinimas: ', current^.duomuo.pav);
        WriteLn('Kiekis: ', current^.duomuo.kiek);
        WriteLn('Spalva: ', current^.duomuo.spalva);
        WriteLn('Kaina: ', current^.duomuo.kaina:2:2);
        WriteLn('Skonis: ', current^.duomuo.arskanus);
        writeln();
        inc(i);
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
    
    // Atspauzdinam pradini
    printList(head);

    selectionSort(head, tail);
    writeln();
    insertionSort(head, tail);
    writeln();
    bubbleSort(head, tail);
    writeln();
    
    // Atspauzdinam galutini
    printList(head);
    
  readln;
  
end.
