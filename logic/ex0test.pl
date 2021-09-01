male(dickinson).
male(murray).
male(smith).
male(mcbrain).
male(livio).
male(livio2).
male(gers).

female(turunen).
female(doropesch).
female(magda).
female(myrian).
female(marta).
female(juliana).
female(luiza).
female(gil).
female(livia).
female(angelagossow).

parent(murray,dickinson).
parent(doropesch,dickinson).
parent(murray,turunen).
parent(doropesch,turunen).
parent(murray,luiza).
parent(juliana,luiza).
parent(gers,doropesch).
parent(myrian,doropesch).
parent(livio2,livia).
parent(gil,livia).
parent(livio2,angelagossow).
parent(gil,angelagossow).
parent(livio,murray).
parent(marta,murray).
parent(livio,smith).
parent(marta,smith).
parent(livio,magda).
parent(marta,magda).
parent(livio,livio2).
parent(marta,livio2).

child(X,Y):-
    parent(Y,X).

fullsibling(X,Y):-
    father(Z,X),
    father(Z,Y),
    mother(W,X),
    mother(W,Y),
    X\=Y.

halfsibling(X,Y):-
    parent(Z,X),
    parent(Z,Y),
    parent(W,X),
    not(parent(W,Y)),
    not(Z=W),
    not(X=Y).

sibling(X,Y) :-
    fullsibling(X,Y).
sibling(X,Y) :-
    halfsibling(X,Y).
    

cousin(X,Y):-
    parent(Z,X),
    parent(W,Y),
    sibling(Z,W).
  
grandparent(X,Y):-
    parent(X,Z),
    parent(Z,Y).

grandchild(X,Y):-
    grandparent(Y,X).

brother(X,Y):-
    male(X),
    sibling(X,Y).

sister(X,Y):-
    female(X),
    sibling(X,Y).

halfbrother(X,Y):-
    male(X),
    halfsibling(X,Y).

halfsister(X,Y):-
    female(X),
    halfsibling(X,Y).

fullbrother(X,Y):-
    male(X),
    fullsibling(X,Y).

fullsister(X,Y):-
    female(X),
    fullsibling(X,Y).

father(X,Y):-
    male(X),
    parent(X,Y).

mother(X,Y):-
    female(X),
    parent(X,Y).

grandfather(X,Y):-
    male(X),
    grandparent(X,Y).

grandmother(X,Y):-
    female(X),
    grandparent(X,Y).

son(X,Y):-
    male(X),
    child(X,Y).

daughter(X,Y):-
    female(X),
    child(X,Y).

grandson(X,Y):-
    male(X),
    grandchild(X,Y).

granddaughter(X,Y):-
    female(X),
    grandchild(X,Y).

uncle(X,Y):-
    parent(Z,Y),
    brother(X,Z).

aunt(X,Y):-
    parent(Z,Y),
    sister(X,Z).

nephew(X,Y):-
    son(X,Z),
    sibling(Z,Y).

niece(X,Y):-
    daughter(X,Z),
    sibling(Z,Y).
