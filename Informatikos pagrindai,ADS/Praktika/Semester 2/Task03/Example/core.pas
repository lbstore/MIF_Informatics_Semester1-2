Program linkedlists;
Uses Crt;

Type
     TStudRec = Record
      Name, Surname : String;
      Id, Age : Integer;
      Gender : Char;
     End;

     TNodePtr = ^TNode;
     TNode = Record
      StudRec : TStudRec;
      NodePtr : TNodePtr;
     End;

Var
    Head, Tail : TNodePtr;
    SampRec : TStudRec;

Procedure InitLL;
Begin
 Head := nil;
 Tail := Head;
End;

Procedure AddRecord(StudRec : TStudRec);
Var
    Node : TNode;

Begin
 Node.StudRec := StudRec;
 New(Node.NodePtr);
 If Head = nil then
  Begin
   New(Head);
   New(Tail);
   Head^ := Node;
  End Else
  Begin
   Tail^.NodePtr^ := Node;
  End;
 Tail^ := Node;
End;

Procedure InsertRecordByIndex(Index : Integer; StudRec : TStudRec);
Var
    i : Integer;
    TempPtr : TNodePtr;
    Node, TempNode : TNode;
    Done : Boolean;

Begin
 Done := False;
 if Head = nil then
  Exit;
 i := 0;
 TempPtr := Head;
 Node.StudRec := StudRec;
 New(Node.NodePtr);
 If (Index = 0) then
  Begin
   TempNode := Head^;
   Head^ := Node;
   Node.NodePtr^ := TempNode;
   Done := True;
  End;
 If not Done then
  While (i < Index-1) do
   Begin
    If (TempPtr^.NodePtr^.NodePtr = nil) then
     Begin
      Done := True;
      Break;
     End;
    i := i + 1;
    TempPtr := TempPtr^.NodePtr;
   End;
 If not Done then
  Begin
   TempNode := TempPtr^.NodePtr^;
   TempPtr^.NodePtr^ := Node;
   Node.NodePtr^ := TempNode;
  End;
End;

Procedure InsertRecordByID(ID : Integer; StudRec : TStudRec);
Var
    TempPtr : TNodePtr;
    Node, TempNode : TNode;
    Done : Boolean;

Begin
 Done := False;
 if Head = nil then
  Exit;
 TempPtr := Head;
 Node.StudRec := StudRec;
 New(Node.NodePtr);
 If (TempPtr^.StudRec.ID = ID) then
  Begin
   TempNode := Head^;
   Head^ := Node;
   Node.NodePtr^ := TempNode;
   Done := True;
  End;
 While not Done do
  Begin
   If (TempPtr^.StudRec.ID = ID) then
    Break;
   If (TempPtr^.NodePtr^.NodePtr = nil) then
    Begin
     Done := True;
     Break;
    End;
   TempPtr := TempPtr^.NodePtr;
  End;
 If not Done then
  Begin
   TempNode := TempPtr^.NodePtr^;
   Node.NodePtr^ := TempNode;
   TempPtr^.NodePtr^ := Node;
  End;
End;

Procedure DeleteNodeWithID(ID : Integer);
Var
    TempPtr, PrevPtr : TNodePtr;
    Done : Boolean;

Begin
 Done := False;
 if Head = nil then
  Exit;
 PrevPtr := Head;
 TempPtr := Head;
 While True do
  Begin
   If (TempPtr^.StudRec.ID = ID) then
    Break;
   If (TempPtr^.NodePtr^.NodePtr = nil) then
    Begin
     Done := True;
     Break;
    End;
   PrevPtr := TempPtr;
   TempPtr := TempPtr^.NodePtr;
  End;
 If not Done then
  Begin
   If TempPtr = Head then
    Head := Head^.NodePtr
   Else
   Begin
    PrevPtr^.NodePtr := TempPtr^.NodePtr;
   End;
  End;
End;

Procedure PrintAll(Head : TNodePtr);
Var
    Node : TNodePtr;

Begin
 New(Node);
 Node := Head;
 While Node^.NodePtr <> nil do
  Begin
   Writeln('=================');
   Writeln(Node^.StudRec.Name);
   Writeln(Node^.StudRec.Surname);
   Writeln(Node^.StudRec.Id);
   Writeln(Node^.StudRec.Age);
   Writeln(Node^.StudRec.Gender);
   Writeln('=================');
   Node := Node^.NodePtr;
  End;
 Writeln('Done Printing.');
End;

Procedure AssignRecord(StudRec : TStudRec; Name, Surname : String; ID, Age : Integer; Gender : Char);
Begin
 SampRec.Name    := Name;
 SampRec.Surname := Surname;
 SampRec.Age     := Age;
 SampRec.Id      := Id;
 SampRec.Gender  := Gender;
End;

Begin
 ClrScr;
 InitLL;
 AssignRecord(SampRec, 'Victor', 'Saliba', 19, 12345, 'M');
 AddRecord(SampRec);
 AssignRecord(SampRec, 'Mario', 'Petrack', 42, 00011, 'M');
 AddRecord(SampRec);
 AssignRecord(SampRec, 'Mary', 'Kels', 22, 20211, 'F');
 AddRecord(SampRec);
 AssignRecord(SampRec, 'Ken', 'Bolimpart', 19, 04148, 'M');
 AddRecord(SampRec);
 AssignRecord(SampRec, 'Kelly', 'Becks', 16, 04148, 'F');
 InsertRecordByID(00011, SampRec);
 DeleteNodeWithID(20211);
 Writeln('Done.');
 PrintAll(Head);
 Readln;
End.
