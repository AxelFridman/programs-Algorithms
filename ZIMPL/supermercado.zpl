set I := {1..11};
set K := {1..8};
set W := {9..11};
param precios[I] := <1> 10, <2> 5,  <3> 3,  <4> 1,  <5> 9,<6> 3,  <7> 1,  <8> 9,<9> 3,  <10> 1,  <11> 9; 
param nutrientes[I] := <1> 7, <2> 3.5,  <3> 2,  <4> 0.7,  <5> 6,<6> 2,  <7> 0.45,  <8> 6.2,<9> 2,  <10> 0.71,  <11> 6; 
param abundania[I] :=  <1> 17, <2> 14,  <3> 6,  <4> 5.7,  <5> 20,<6> 12,  <7> 4.5,  <8> 17,<9> 9,  <10> 7.1,  <11> 6.2; 
param disponibilidad[I] :=  <1> 2, <2> 3,  <3> 4,  <4> 5,  <5> 2,<6> 3,  <7> 5,  <8> 7,<9> 4,  <10> 4,  <11> 5; 

var x[I] integer;
minimize gastos: sum <i> in I : precios[i] * x[i];


subto r1: (sum <i> in I: nutrientes[i] * x[i]) >= 50;
subto r2: (sum <i> in I: abundania[i] * x[i]) >= 150;
subto r3: (sum <k> in K: x[k]) >= 3;
subto r4: (sum <w> in W: x[w]) >= 3;
subto r5: forall <i> in I:  x[i] <= disponibilidad[i];