% Exercicio 5: Fish Riddle estructured
%Author: kcpedrosa
%Date: 28/08/2021

person(norwegian).
person(dane).
person(brit).
person(german).
person(swede).

color(yellow).
color(blue).
color(red).
color(green).
color(white).

smoke(dunhill).
smoke(blends).
smoke(pallmall).
smoke(prince).
smoke(bluemaster).

drink(water).
drink(tea).
drink(milk).
drink(coffee).
drink(beer).

animal(cats).
animal(horses).
animal(birds).
animal(fish).
animal(dogs).

% main goals start now

main :-
    %persons(P1,P2,P3,P4,P5),
    %colors(C1,C2,C3,C4,C5),
    %smokes(S1,S2,S3,S4,S5),
    %drinks(D1,D2,D3,D4,D5),
    %animals(A1,A2,A3,A4,A5),

    tab(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
    writef("%8l %12l %12l %12l %12l %8l\n",['House #','Person','Color','Cigar','Drink','Pet']),
    writef("%8l %12l %12l %12l %12l %8l\n",[1,P1,C1,S1,D1,A1]),
    writef("%8l %12l %12l %12l %12l %8l\n",[2,P2,C2,S2,D2,A2]),
    writef("%8l %12l %12l %12l %12l %8l\n",[3,P3,C3,S3,D3,A3]),
    writef("%8l %12l %12l %12l %12l %8l\n",[4,P4,C4,S4,D4,A4]),
    writef("%8l %12l %12l %12l %12l %8l\n",[1,P5,C5,S5,D5,A5]),
    !.

tab(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)) :-
            rule1(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule2(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule3(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule4(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule5(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule6(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule7(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule8(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule9(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule10(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule11(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule12(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule13(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule14(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule15(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)),
            rule16(house(1,P1,C1,S1,D1,A1),house(2,P2,C2,S2,D2,A2),house(3,P3,C3,S3,D3,A3),house(4,P4,C4,S4,D4,A4),house(5,P5,C5,S5,D5,A5)).

rule1(house(1,brit,red,_,_,_),_,_,_,_).
rule1(_,house(2,brit,red,_,_,_),_,_,_).
rule1(_,_,house(3,brit,red,_,_,_),_,_).
rule1(_,_,_,house(4,brit,red,_,_,_),_).
rule1(_,_,_,_,house(5,brit,red,_,_,_)).

rule2(house(1,swede,_,_,_,dogs),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule2(house(1,_,_,_,_,_),house(2,swede,_,_,_,dogs),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule2(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,swede,_,_,_,dogs),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule2(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,swede,_,_,_,dogs),house(5,_,_,_,_,_)).
rule2(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,swede,_,_,_,dogs)).

rule3(house(1,dane,_,_,tea,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule3(house(1,_,_,_,_,_),house(2,dane,_,_,tea,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule3(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,dane,_,_,tea,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule3(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,dane,_,_,tea,_),house(5,_,_,_,_,_)).
rule3(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,dane,_,_,tea,_)).

rule4(house(1,_,green,_,_,_),house(2,_,white,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule4(house(1,_,_,_,_,_),house(2,_,green,_,_,_),house(3,_,white,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule4(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,green,_,_,_),house(4,_,white,_,_,_),house(5,_,_,_,_,_)).
rule4(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,green,_,_,_),house(5,_,white,_,_,_)).

rule5(house(1,_,green,_,coffee,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule5(house(1,_,_,_,_,_),house(2,_,green,_,coffee,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule5(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,green,_,coffee,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule5(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,green,_,coffee,_),house(5,_,_,_,_,_)).
rule5(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,green,_,coffee,_)).

rule6(house(1,_,_,pallmall,_,birds),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule6(house(1,_,_,_,_,_),house(2,_,_,pallmall,_,birds),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule6(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,pallmall,_,birds),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule6(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,pallmall,_,birds),house(5,_,_,_,_,_)).
rule6(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,pallmall,_,birds)).

rule7(house(1,_,yellow,dunhill,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule7(house(1,_,_,_,_,_),house(2,_,yellow,dunhill,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule7(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,yellow,dunhill,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule7(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,yellow,dunhill,_,_),house(5,_,_,_,_,_)).
rule7(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,yellow,dunhill,_,_)).

rule8(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,milk,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).

rule9(house(1,norwegian,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).

rule10(house(1,_,_,blends,_,_),house(2,_,_,_,_,cats),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule10(house(1,_,_,_,_,_),house(2,_,_,blends,_,_),house(3,_,_,_,_,cats),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule10(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,blends,_,_),house(4,_,_,_,_,cats),house(5,_,_,_,_,_)).
rule10(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,blends,_,_),house(5,_,_,_,_,cats)).
rule10(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,cats),house(5,_,_,blends,_,_)).
rule10(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,cats),house(4,_,_,blends,_,_),house(5,_,_,_,_,_)).
rule10(house(1,_,_,_,_,_),house(2,_,_,_,_,cats),house(3,_,_,blends,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule10(house(1,_,_,_,_,cats),house(2,_,_,blends,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).

rule11(house(1,_,_,dunhill,_,_),house(2,_,_,_,_,horses),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule11(house(1,_,_,_,_,_),house(2,_,_,dunhill,_,_),house(3,_,_,_,_,horses),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule11(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,dunhill,_,_),house(4,_,_,_,_,horses),house(5,_,_,_,_,_)).
rule11(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,dunhill,_,_),house(5,_,_,_,_,horses)).
rule11(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,horses),house(5,_,_,dunhill,_,_)).
rule11(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,horses),house(4,_,_,dunhill,_,_),house(5,_,_,_,_,_)).
rule11(house(1,_,_,_,_,_),house(2,_,_,_,_,horses),house(3,_,_,dunhill,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule11(house(1,_,_,_,_,horses),house(2,_,_,dunhill,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).

rule12(house(1,_,_,bluemaster,beer,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule12(house(1,_,_,_,_,_),house(2,_,_,bluemaster,beer,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule12(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,bluemaster,beer,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule12(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,bluemaster,beer,_),house(5,_,_,_,_,_)).
rule12(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,bluemaster,beer,_)).

rule13(house(1,german,_,prince,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule13(house(1,_,_,_,_,_),house(2,german,_,prince,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule13(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,german,_,prince,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule13(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,german,_,prince,_,_),house(5,_,_,_,_,_)).
rule13(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,german,_,prince,_,_)).

rule14(house(1,norwegian,_,_,_,_),house(2,_,blue,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule14(house(1,_,_,_,_,_),house(2,norwegian,_,_,_,_),house(3,_,blue,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule14(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,norwegian,_,_,_,_),house(4,_,blue,_,_,_),house(5,_,_,_,_,_)).
rule14(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,norwegian,_,_,_,_),house(5,_,blue,_,_,_)).
rule14(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,blue,_,_,_),house(5,norwegian,_,_,_,_)).
rule14(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,blue,_,_,_),house(4,norwegian,_,_,_,_),house(5,_,_,_,_,_)).
rule14(house(1,_,_,_,_,_),house(2,_,blue,_,_,_),house(3,norwegian,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule14(house(1,blue,_,_,_,_),house(2,norwegian,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).

rule15(house(1,_,_,blends,_,_),house(2,_,_,_,water,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule15(house(1,_,_,_,_,_),house(2,_,_,blends,_,_),house(3,_,_,_,water,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule15(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,blends,_,_),house(4,_,_,_,water,_),house(5,_,_,_,_,_)).
rule15(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,blends,_,_),house(5,_,_,_,water,_)).
rule15(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,water,_),house(5,_,_,blends,_,_)).
rule15(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,water,_),house(4,_,_,blends,_,_),house(5,_,_,_,_,_)).
rule15(house(1,_,_,_,_,_),house(2,_,_,_,water,_),house(3,_,_,blends,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule15(house(1,_,_,_,water,_),house(2,_,_,blends,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).

rule16(house(1,_,_,_,_,fish),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule16(house(1,_,_,_,_,_),house(2,_,_,_,_,fish),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule16(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,fish),house(4,_,_,_,_,_),house(5,_,_,_,_,_)).
rule16(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,fish),house(5,_,_,_,_,_)).
rule16(house(1,_,_,_,_,_),house(2,_,_,_,_,_),house(3,_,_,_,_,_),house(4,_,_,_,_,_),house(5,_,_,_,_,fish)).

%Initializations only after this point

persons(P1,P2,P3,P4,P5) :-
    person(P1),
    person(P2),
    not(P1 = P2),
    person(P3),
    not(P1 = P3),
    not(P2 = P3),
    person(P4),
    not(P1 = P4),
    not(P2 = P4),
    not(P3 = P4),
    person(P5),
    not(P1 = P5),
    not(P2 = P5),
    not(P3 = P5),
    not(P4 = P5).

colors(C1,C2,C3,C4,C5) :-
    color(C1),
    color(C2),
    not(C1 = C2),
    color(C3),
    not(C1 = C3),
    not(C2 = C3),
    color(C4),
    not(C1 = C4),
    not(C2 = C4),
    not(C3 = C4),
    color(C5),
    not(C1 = C5),
    not(C2 = C5),
    not(C3 = C5),
    not(C4 = C5).

smokes(S1,S2,S3,S4,S5) :-
    smoke(S1),
    smoke(S2),
    not(S1 = S2),
    smoke(S3),
    not(S1 = S3),
    not(S2 = S3),
    smoke(S4),
    not(S1 = S4),
    not(S2 = S4),
    not(S3 = S4),
    smoke(S5),
    not(S1 = S5),
    not(S2 = S5),
    not(S3 = S5),
    not(S4 = S5).

drinks(D1,D2,D3,D4,D5) :-
    drink(D1),
    drink(D2),
    not(D1 = D2),
    drink(D3),
    not(D1 = D3),
    not(D2 = D3),
    drink(D4),
    not(D1 = D4),
    not(D2 = D4),
    not(D3 = D4),
    drink(D5),
    not(D1 = D5),
    not(D2 = D5),
    not(D3 = D5),
    not(D4 = D5).

animals(A1,A2,A3,A4,A5) :-
    animal(A1),
    animal(A2),
    not(A1 = A2),
    animal(A3),
    not(A1 = A3),
    not(A2 = A3),
    animal(A4),
    not(A1 = A4),
    not(A2 = A4),
    not(A3 = A4),
    animal(A5),
    not(A1 = A5),
    not(A2 = A5),
    not(A3 = A5),
    not(A4 = A5).
