getadj(Pos,List):-
    findall(Adj,adjacent(Pos,Adj),List).

adjacent([X,Y],[X1,Y]):-
    X1 is X + 1,
    valid([X1,Y]).
adjacent([X,Y],[X1,Y]):-
    X1 is X - 1,
    valid([X1,Y]).
adjacent([X,Y],[X,Y1]):-
    Y1 is Y + 1,
    valid([X,Y1]).
adjacent([X,Y],[X,Y1]):-
    Y1 is Y - 1,
    valid([X,Y1]).

valid([X,Y]) :-
    limitx(Xl),
    limity(Yl),
    0 < X,
    0 < Y,
    X <= Xl,
    Y <= Yl.
