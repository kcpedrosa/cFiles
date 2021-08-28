%Exercise 3: FibonacciSequence
%Author: kcpedrosa
%Date: 28/08/2021

fibonacci(0,1).             %initialization.
fibonacci(1,1).

fibonacci(X,Y):-
    X > 1,
    X1 is X - 1,
    X2 is X - 2,
    fibonacci(X1,Y1),        %Well, I tried to make a smaller
    fibonacci(X2,Y2),        %version, but prolog isn't that
    Y is Y1 + Y2,            %smart.
    !.
