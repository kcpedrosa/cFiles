%#!/usr/bin/swipl -q -G64m -L64m -t main -f none -s
%  Uncomment the live above to run as executable prolog script
%  -q : Operate silently
%  -G : Set global stack
%  -L : Set local stack
%  -t main : Set goal to main
%  -f none : Do not use an initialization file
%  -s : Turn this file into an executable
%       prolog script (use chmod +x t1clpr.pl)
%

/***************************************************************************
 *   ex10.pl                            Version 20210617.014017            *
 *                                                                         *
 *   An English Test to show how big your vocabulary is                    *
 *   Copyright (C)                            *
 *   Original version by Ruben Carlo Benante                               *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */

/*

A list of questions in the form:

The synonym of love is:
a. like
b. left
c. life
d. live

Alternative 'a' is always right.
It should be shuffled randomly before presenting the question.

Source: https://www.arealme.com/vocabulary-size-test/en/

*/

list50([[synonym, love, [like, left, life, live]],
        [synonym, much, [many, less, rather, deal]],
        [synonym, child, [kid, chill, call, forget]],
        [synonym, large, [big, new, tiny, faded]],
        [synonym, deal, [sale, plea, recoup, claim]],
        [synonym, companion, [partner, fool, mirror, entrapment]],
        [synonym, trash, [junk, crack, squeeze, punch]],
        [synonym, above, [over, pierce, slow, work]],
        [synonym, specify, [designate, capitulate, arcane, assail]],
        [synonym, fall, [drop, spit, squeal, succeed]],
        [antonym, old, [new, tell, small, age]],
        [antonym, yes, [no, notice, yep, nice]],
        [antonym, come, [go, try, most, live]],
        [synonym, fly, [soar, hop, peer, drink]],
        [antonym, active, [passive, unable, inability, disagree]],
        [antonym, dangerous, [safe, silly, careless, sadness]],
        [antonym, distant, [near, disease, flex, obey]],
        [antonym, narrow, [broad, scold, punish, near]],
        [antonym, separate, [unite, weak, ordinary, break]],
        [antonym, normal, [extraordinary, doubt, standard, protracted]],
        [synonym, spade, [shovel, needle, club, oak]],
        [synonym, done, [finished, embellished, squeaked, talked]],
        [synonym, beg, [implore, recant, fancy, answer]],
        [synonym, lax, [negligent, mindful, neurotic, delectable]],
        [synonym, quash, [defeat, evade, enumerate, assist]],
        [synonym, minor, [trivial, crude, presidential, flow]],
        [synonym, drab, [lackluster, admissible, barbaric, spiffy]],
        [synonym, related, [pertinent, steadfast, alien, intrinsic]],
        [synonym, annoying, [obnoxious, facile, clinker, counter]],
        [synonym, incipient, [nascent, galling, chromatic, capricious]],
        [antonym, foul, [fair, repelling, nasty, dirty]],
        [antonym, compensate, [underpay, coordinate, extortion, hooking]],
        [antonym, acquiesce, [resist, gentle, inept, irascible]],
        [antonym, adamant, [vacillant, disdain, adjunct, aerate]],
        [antonym, alienate, [reunite, away, sluggish, aggressive]],
        [antonym, avulse, [suture, dry, aver, timid]],
        [antonym, catalyst, [prevention, current, damp, nadir]],
        [antonym, amorphous, [definite, allay, abridge, inimical]],
        [antonym, aggrieved, [exacerbate, recalcitrant, buoyant, warped]],
        [antonym, apologist, [critic, physicist, fidelity, canon]],
        [synonym, widow, [dowager, sire, fiend, spank]],
        [synonym, omen, [harbinger, opulence, mystic, demand]],
        [synonym, querulous, [fractious, fugacious, vapid, extemporaneous]],
        [synonym, hightail, [abscond, report, perturb, surmise]],
        [synonym, gargantuan, [titanic, promiscuous, virtuous, equestrian]],
        [antonym, avarice, [generosity, deny, dependence, yoke]],
        [antonym, alacrity, [sluggishness, intimate, provoker, soother]],
        [antonym, altruism, [egoism, apocrypha, noisome, extraneous]],
        [antonym, affinity, [antipathy, disperse, needy, warped]],
        [antonym, baneful, [salubrious, blighted, jejune, inveigled]]]).

/* ---------------------------------------------------------------------- */

main :-
    writeln('Welcome to the English Vocabulary Test Program'),
    list50(Questions),
    getq(1,Questions,0),
    nl,
    !.

/*  I didn't manage to finish the grades. no one I asked knew how to change 
*   from the probabilities to that number scale from 25 to 30325.
*   This is the closest I got(it's still kind of far).
getgrade(0,25).

getgrade(Number,Grade) :-
    N1 is Number - 1,
    writeln(N1),
    getgrade(N1,G1),
    writeln(G1),
    G0 is 1 / ( 5 * sqrt(2* pi) ) * e ^ (-1/2 * ( (Number-25) / 5) ^ 2 ),
    Grade is G1 + G0 * 30325.
 */  

 printgrade(0) :-
    writeln('You have scored a 0...'),
    writeln('You somehow managed to get all answers wrong. Can you even read this?').

 printgrade(Grade) :-
     Grade < 5,
     writef("You have scored a %w...\n", [Grade]),
     writeln('You have the vocabulary of an average toddler.').

 printgrade(Grade) :-
     Grade < 10,
     writef("You have scored a %w...\n", [Grade]),
     writeln('How surprising! You have the vocabulary of a SMART toddler.').

 printgrade(Grade) :-
     Grade < 15,
     writef("You have scored a %w.\n", [Grade]),
     writeln('You are quite an amateur at English.').

 printgrade(Grade) :-
     Grade < 20,
     writef("You have scored a %w.\n", [Grade]),
     writeln('Your vocabulary is slightly below average. Keep it up!.').

 printgrade(Grade) :-
     Grade < 25,
     writef("You have scored a %w.\n", [Grade]),
     writeln('You have an average vocabulary. Nothing to be proud of, but at least youre not the worst').

 printgrade(Grade) :-
     Grade < 30,
     writef("You have scored a %w.\n", [Grade]),
     writel('Hmm... Thats a surprisingly good vocabulary you have there.').

 printgrade(Grade) :-
     Grade < 35,
     writef("You have scored a %w.\n", [Grade]),
     writeln('Your vocabulary is at the level of the average professional writer.').

 printgrade(Grade) :-
     Grade < 40,
     writef("You have scored a %w!\n", [Grade]),
     writeln('Quite a genius we got here.').

 printgrade(Grade) :-
     Grade < 45,
     writef("You have scored a %w!.\n", [Grade]),
     writeln('You are pretty much this generations shakespeare.').

 printgrade(Grade) :-
     Grade < 50,
     writef("You have scored a %w!!!.\n", [Grade]),
     writeln('Why did you even doubt your knowledge?').

 printgrade(50) :-
     writeln('You have scored a %w?!!!\n'),
     writeln('Did you use a cheat sheet or something?').

getq(51,_,RightNumber) :-
    %getgrade(RightNumber,Grade),
    %writeln(RightNumber),
    %writeln(Grade).
    printgrade(RightNumber).

getq(Index,[Question|Questions],RightNumber) :-
    Question = [Subject,Word,Answers],
    random_permutation(Answers,RandA),
    writef("%w: What is the %w of %w?\n",[Index,Subject,Word]),
    writef("a. %w\nb. %w\nc. %w\nd. %w\n",RandA),
    readA(Answer),
    testAnswer(Answer,Answers,RandA,RightNumber,NewNumber),
    NewInd is Index + 1,
    getq(NewInd,Questions,NewNumber).

readA(Answer) :-
    read(A),
    validate(A,Answer).

validate(a,a).
validate(b,b).
validate(c,c).
validate(d,d).
validate(_,Answer) :-
    writeln('Invalid Answer. Please use one letter from (abcd).'),
    readA(Answer).

testAnswer(Answer,Answers,RandA,OldNum,NewNum) :-
    checkA(Answer,Answers,RandA),
    NewNum is OldNum + 1.

testAnswer(Answer,Answers,RandA,Num,Num) :-
    not(checkA(Answer,Answers,RandA)).

checkA(a,Answers,RandA) :-
    nth1(1,RandA,A),
    nth1(1,Answers,A).
checkA(b,Answers,RandA) :-
    nth1(2,RandA,A),
    nth1(2,Answers,A).
checkA(c,Answers,RandA) :-
    nth1(3,RandA,A),
    nth1(3,Answers,A).
checkA(d,Answers,RandA) :-
    nth1(4,RandA,A),
    nth1(4,Answers,A).


/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20210620.224740 */

