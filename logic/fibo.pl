:-dynamic([memo_fibo/2]).

fibo(0,1) :- !.
fibo(Num,Res) :- 
    memo_fibo(Num,Res),!.
fibo(Num,Res) :-
    Num > 0,
    N1 is Num - 1,
    fibo(N1,Prev),
    Res is Num + Prev,
    assert(memo_fibo(Num,Res)),!.
