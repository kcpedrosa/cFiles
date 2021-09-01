%Exercise 2: FatorialOfANumber
%Author: kcpedrosa
%Data: 28/08/2021

fatorial(0,1).

fatorial(N,R):-
    N > 0,
    M is N - 1,
    fatorial(M,S),
    R is N * S,
    !.

%The same of writting
%once(f(N,R).
