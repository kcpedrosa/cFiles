%Exercise 2: FatorialOfANumber
%Author: kcpedrosa
%Data: 28/08/2021

f(0,1).

f(N,R):-
    N > 0,
    M is N - 1,
    f(M,S),
    R is N * S,
    !.

%The same of writting
%once(f(N,R).
