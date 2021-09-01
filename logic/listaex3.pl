somalista([],0).
somalista([X|Y],N):-
	somalista(Y,T),
	N is T+1.

/*write that and hit enter
?- somalista([2,a,c],T).
T = 3.

?- somalista([2,a,c,5],T).
T = 4.
*/