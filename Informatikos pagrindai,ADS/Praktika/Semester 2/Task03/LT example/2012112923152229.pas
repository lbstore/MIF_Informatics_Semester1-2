program ok;
type dvipsar = ^dvipelem;
   dvipelem = record
               priekin : dvipsar;
               duom : integer;
               atgal : dvipsar;
              end;
   var elem, elemd, elemk : dvipsar;

   procedure Sukurti_dvipsar (var pradzia, pabaiga : dvipsar);
      var g : dvipsar;
          x : integer;
   begin
      pradzia := nil;
      pabaiga := nil;
         writeln('Kuriame dvipusi sarasa. Iveskite sveikus skaicius. Noredami baigti, iveskite 0.');
         readln (x);
         while x <> 0 do
            begin
               if pradzia = nil
               then
                  begin
                     new (g);
                     g^.duom := x;
                     g^.priekin := nil;
                     g^.atgal := nil;
                     pradzia := g;
                     pabaiga := g;
                     readln (x);
                  end
               else
                  begin
                     new (g);
                     g^.duom := x;
                     g^.priekin := nil;
                     g^.atgal := pabaiga;
                     pabaiga^.priekin := g;
                     pabaiga := g;
                     readln (x);
                  end;
             end;
            writeln('Sarasas sekmingai sukurtas!');
   end;

   procedure Iterpti_elem (var pradzia, pabaiga: dvipsar);
      var i,k,y : integer;
      begin
      elemk:=pradzia;
         writeln('Iveskite sveikaji elemento numeri, pries kuri bus iterptas nukopijuotas elementas:');
         readln (y);
         if y = 1
            then
               begin
                  writeln('Iveskite numeri elemento, kuri norite nukopijuoti ir iterpti i sarasa:');
                  readln (k);   
                  i := 1;
                 while (i<k) and (elemk <> nil) do
                    begin
                       elemk := elemk^.priekin;
                       inc(i);
                    end;//
                 if i = k
                    then
                       begin
						  writeln('Rodykle nukreipta i ', k, '-aji elementa.');
						  new(elem);
						  elem^.duom :=elemk^.duom;
						  elemk:= pradzia;
						  elem^.atgal := nil;
						  elemk^.atgal := elem;
						  elem^.priekin := elemk;
						  pradzia := elem;
						  writeln('Elementas sekmingai iterptas!');
						  readln();
                        end;//
                  
               end
            else
              begin
                 i := 1;
                 while (i<y) and (elemk <> nil) do
                    begin
                       elemk := elemk^.priekin;
                       inc(i);
                    end;//
                 if i = y
                    then
                       begin
                         elemd:= pradzia;
                          writeln('Rodykle nukreipta i ', y, '-aji elementa.');
                          writeln('Iveskite numeri elemento, kuri norite nukopijuoti ir iterpti i sarasa:');
                          readln (k);
                             
                               i := 1;
                               while (i<k) and (elemd <> nil) do
                                  begin
                                    elemd := elemd^.priekin;
                                    inc(i);
                                  end;//
                             
                          if i = k
                          then
                            begin
                            writeln('Rodykle nukreipta i ', k, '-aji elementa.');
                            new (elem);
                            elem^.duom :=elemd^.duom;
                            elem^.atgal := elemk^.atgal;
                            elemk^.atgal^.priekin := elem;
                            elem^.priekin := elemk;
                            elemk^.atgal := elem;
                            writeln('Elementas sekmingai iterptas!');
                            end//

                         else writeln('Sarase yra maziau nei ', k, ' elementu.');
                         readln();//
                      end;

                end;//else
      end;


   procedure Spausdinti (pradzia : dvipsar);
      var s : dvipsar;
   begin
      writeln('Spausdiname sarasa:');
      s := pradzia;
      while s <> nil do
         begin
            write(s^.duom, ' ');
            s := s^.priekin;
         end;
      writeln;
      readln();
   end;

   procedure Naikinti_dvipsar (var pradzia, pabaiga : dvipsar);
      var s : dvipsar;
   begin
      writeln('Naikiname sarasa nuo pabaigos.');
      while pradzia <> nil do
         begin
            s := pradzia;
            if pabaiga <> pradzia
            then
               begin
                  while s^.priekin <> pabaiga do
                     s := s^.priekin;
                  writeln(' Naikiname ', s^.priekin^.duom);
                  pabaiga := s;
                  dispose(s^.priekin);
               end
            else
               begin
                  writeln(' Naikiname pirma: ', s^.duom);
                  dispose(s);
                  pradzia := nil;
                  pabaiga := nil;
               end;
         end;
      writeln('sarasas istrintas!');
      readln();
   end;

         var pr, pab : dvipsar;
         begin
            Sukurti_dvipsar (pr, pab);
            Iterpti_elem (pr, pab);
            Spausdinti (pr);
            Naikinti_dvipsar (pr, pab);
         end.
