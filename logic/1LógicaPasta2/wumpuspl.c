%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    Hunt The Wumpus - World Simulator                                          %
%    Copyright (C) 2012 - 2016  Ruben Carlo Benante <rcb at beco dot cc>        %
%                                                                               %
%    This program is free software; you can redistribute it and/or modify       %
%    it under the terms of the GNU General Public License as published by       %
%    the Free Software Foundation; version 2 of the License.                    %
%                                                                               %
%    This program is distributed in the hope that it will be useful,            %
%    but WITHOUT ANY WARRANTY; without even the implied warranty of             %
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              %
%    GNU General Public License for more details.                               %
%                                                                               %
%    You should have received a copy of the GNU General Public License along    %
%    with this program; if not, write to the Free Software Foundation, Inc.,    %
%    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   Special thanks to:
%     - Gregory Yob
%     - Larry Holder 
%     - Walter Nauber
%
% A Prolog implementation of the Wumpus world invented by Gregory Yob (1972)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% To allow an agent to run with the Wumpus Simulator you need to define:
%   init_agent : 
%       It will be called only once, at the start. Put here definitions and
%       other start code you need (asserts, retracts, and so on)
%   run_agent :
%       It will be called each turn by the simulator.
%       Input: perceptions from the world.
%       Expected output: an action for the agent to perform.
%   world_setup([Size, Type, Move, Gold, Pit, Bat, [RandS, RandA]]):
%       This is a fact. It will be consulted only once at the beginning,
%       even before init_agent. It will configure the world as you say,
%       or use a default in case of conflicts or mistakes.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Lista de Percepcao: [Stench, Breeze, Glitter, Bump, Scream, Rustle]
% Traducao: [Fedor, Vento, Brilho, Trombada, Grito, Ruido]
% Acoes possiveis (abreviacoes):
% 1. goforward (go)                - andar
% 2. turnright (turn, turnr ou tr) - girar sentido horario
% 3. turnleft (turnl ou tl)        - girar sentido anti-horario
% 4. grab (gr)                     - pegar o ouro
% 5. shoot (sh)                    - atirar a flecha
% 6. sit (si)                      - sentar (nao faz nada, passa a vez)
% 7. climb (cl)                    - sair da caverna
% 8. gps                           - pega sua posicao e orientacao
%
% Costs (Custos):
% Actions: -1 (Andar/Girar/Pegar/Sair/Atirar/Sentar/GPS)
% Die: -1000 (morrer no buraco, wumpus ou de fadiga)
% Killing the Wumpus: +1000 (matar Wumpus)
% Climbing alive with golds: +500 for each gold (sair com ouro)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% To run the example, start PROLOG with (rode o exemplo iniciando o prolog com):
% swipl -s agenteXXX.pl
% then do the query (faca a consulta):
% ?- start.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% world_setup([Size, Type, Move, Gold, Pit, Bat, Adv])
%
% Size and Type: - fig62, 4
%                - grid, [2-9] (default 4)
%                - dodeca, 20
%       +--------+-----------+
%       |  Type  |    Size   |
%       +--------+-----------+
%       | fig62  | 4 (fixed) |
%       | grid   | 2 ... 9   |
%       | dodeca | 20 (fixed)|
%       +--------+-----------+
%
% Configuration:
%    1.   Size: 0,2..9,20, where: grid is [2-9] or 0 for random, dodeca is 20, fig62 is 4.
%    2.   Type: fig62, grid or dodeca
%    3.   Move: stander, walker, runner (wumpus movement)
%    4.   Gold: Integer is deterministic number, float from 0.0<G<1.0 is probabilistic
%    5.   Pits: Idem, 0 is no pits.
%    6.   Bats: Idem, 0 is no bats.
%    7.   Adv: a list with advanced configuration in the form [RandS, RandA]:
%       - RandS - yes or no, random agent start position
%       - RandA - yes or no, random agent start angle of orientation
%
% examples: 
% * default:
%      world_setup([4, grid, stander, 0.1, 0.2, 0.1, [no, no]]).
% * size 5, 1 gold, 3 pits, some bats prob. 0.1, agent randomly positioned
%      world_setup([5, grid, stander, 1, 3, 0.1, [yes]]). 
%
%   Types of Wumpus Movement
%       walker    : original: moves when it hears a shoot, or you enter its cave
%       runner    : go forward and turn left or right on bumps, maybe on pits
%       wanderer  : arbitrarily choses an action from [sit,turnleft,turnright,goforward]
%       spinner   : goforward, turnright, repeat.
%       hoarder   : go to one of the golds and sit
%       spelunker : go to a pit and sit
%       stander   : do not move (default)
%       trapper   : goes hunting agent as soon as it leaves [1,1]; goes home otherwise
%       bulldozer : hunt the agent as soon as it smells him
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% agente007.pl:
%
% Strategy: goes only forward, do not turn, do not grab gold, do not come back
% Performance: it does not go very well as you can imagine
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:- use_module(library(lists)).
:- use_module(wumpus, [start/0]). % agente usa modulo simulador

% Versao 1.0
% Mundo: 
%    Tamanho (size) 5x5, quadrado (grid)
%    Wumpus nao anda
%    5% de chance de ouro por casa, 4 buracos e 1 morcego
%    agente inicia na casa [1,1], orientado para direita (0 graus)
%    Maximo de acoes antes de morrer de fome: Size^2x4 = 5x5x4 = 100 (media de 4 acoes por casa)
world_setup([5, grid, stander, 0.05, 4, 1, [no, no]]).

% Versao 2.0
% Mundo: 
%    Tamanho (size) aleatorio, quadrado (grid)
%    Wumpus com andar original: quando escuta flechada ou quando se entra em sua casa
%    10% de chance de ouro por casa, 8% buracos e 6% morcego
%    agente inicia em casa aleatoria, orientado tambem aleatoriamente (use GPS)
%    Maximo de acoes antes de morrer de fome: Size^2x4 = media de 4 acoes por casa
%    ou seja, se mundo 5x5, maximo de acoes eh 5^2x4=100
%
%world_setup([0, grid, walker, 0.1, 0.08, 0.06, [yes, yes]]).

% Versao 3.0
% Mundo: 
%    Tamanho (size) 20 casas, formato dodecaedro
%    Wumpus anda quando escuta flecha ou quando o agente entra em sua casa
%    5% de chance de ouro por casa, 3 buracos e 1 morcego
%    agente inicia na casa [1,1], orientado para direita (0 graus)
%    Maximo de acoes antes de morrer de fome: 100 (media de 5 acoes por casa)
%
%world_setup([20, dodeca, walker, 0.05, 3, 1, [no, no]]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Predicados dinamicos.
:- dynamic([
    matou_wumpus/1, 
    primeira_rodada/1, 
    agente_localizacao/1, 
    saida/1, 
    agente_orientacao/1, 
    lista_casas_visitadas/1, 
    lista_casas_perigosas/1, 
    lista_casas_seguras/1, 
    casas_visitadas/1, 
    lista_seguras_nao_visitadas/1, 
    agente_localizacao/1, 
    limite_do_mapa/1, 
    achou_limite/1, 
    ouro/1, 
    n_flecha/1, 
    movimentos_feitos/1, 
    debug_ativo/1
    ]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Inicie aqui seu programa.

init_agent:-
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Zerando predicados dinamicos
    retractall(movimentos_feitos(_)),
    retractall(num_acao(_)),
    retractall(debug_ativo(_)),
    retractall(matou_wumpus(_)),
    retractall(tem_ouro(_)),
    retractall(matou_wumpus(_)),
    retractall(n_flecha(_)),
    retractall(primeira_rodada(_)),
    retractall(casas_visitadas(_)),
    retractall(lista_seguras_nao_visitadas(_)),
    retractall(lista_casas_seguras(_)),
    retractall(lista_casas_visitadas(_)),
    retractall(lista_casas_perigosas(_)),
    retractall(agente_localizacao(_)),
    retractall(agente_orientacao(_)),
    retractall(limite_do_mapa(_)),
    retractall(achou_limite(_)),
    retractall(saida(_)),

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Opcoes de debug
    %assert(debug_ativo(1)), %Com degub
    assert(debug_ativo(0)), %Sem debug
   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Valores iniciais dos predicados dinamicos
    assert(num_acao(0)),
    assert(achou_limite(1)),
    assert(primeira_rodada(1)),
    assert(flecha(1)),
    assert(matou_wumpus(nao)),
    assert(tem_ouro(nao)),
    assert(saida([1,1])),
    assert(casas_visitadas([])),
    assert(lista_casas_seguras([])),
    assert(lista_casas_visitadas([])),
    assert(lista_casas_perigosas([])).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Iniciando jogada do agente
run_agent(Percepcao,Acao):- %Funcao principal ou esqueleto
    debug,
    num_acao(N),
    rodada_do_agente(Percepcao,Acao),
    %  wumpus_move_rule(Regra),
    % rodada_do_wumpus(Regra, Acao),
    lista_visitadas,
    retractall(num_acao(_)),
    N1 is N + 1,
    assert(num_acao(N1)). 
    
%Predicados de percepcoes do agente
sentiu_wumpus([yes|_]).            %fedor 
sentiu_brilho([_,_,yes|_]).        %brilho(ouro)
sentiu_perigo([_,yes|_]).          %buraco
sentiu_perigo([_,_,_,_,_,yes|_]).  %morcego
sentiu_batida([_,_,_,yes|_]).      %parede

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Achou limite

achou_limite_do_mapa(Percepcao):- %Caso o limite esteja na coluna
    not(sentiu_batida(Percepcao)),
    achou_limite(N),
    N == 1,
    agente_localizacao([X,_]),
    limite_do_mapa(L),
    X = L,
    L1 is L+1,
    retractall(limite_do_mapa(_)),
    assert(limite_do_mapa(L1)),
    !.

achou_limite_do_mapa(Percepcao):- %Caso o limite esteja na linha
    not(sentiu_batida(Percepcao)),
    achou_limite(N),
    N == 1,
    agente_localizacao([_,Y]),
    limite_do_mapa(L),
    Y = L,
    L1 is L+1,
    retractall(limite_do_mapa(_)),
    assert(limite_do_mapa(L1)),
    !.

achou_limite_do_mapa(_).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Objetivo
%pegar ouro
%explorar
%matar wumpus
%sair

rodada_do_agente(Percepcao, Acao):- %Considerando a presenca de buracos ou morcegos
    sentiu_perigo(Percepcao),
    primeira_rodada(Rodada),
    Rodada == 1,
    agente_localizacao([1,1]),
    objetivo(_, sair,Acao),
    !.

rodada_do_agente(Percepcao, Acao):- %Considerando a presenca de buracos ou morcegos
    sentiu_perigo(Percepcao),
    primeira_rodada(Rodada),
    Rodada == 1,
    retractall(primeira_rodada(_)),
    assert(primeira_rodada(2)),
    gps(Percepcao),
    explorar(Percepcao, Acao),
    !.

rodada_do_agente(Percepcao, Acao):- %Considerando a presenca do wumpus
    sentiu_wumpus(Percepcao),
    flecha(0),
    not(matou_wumpus(sim)),
    casas_seguras,
    explorar(Percepcao, Acao).

rodada_do_agente(Percepcao, Acao):- %Considerando a presenca do wumpus
    sentiu_wumpus(Percepcao),
    flecha(0),
    not(matou_wumpus(sim)),
    casas_perigosas,
    explorar(Percepcao, Acao).

rodada_do_agente(Percepcao, Acao):- %Considerando a presenca do wumpus
    sentiu_wumpus(Percepcao),
    objetivo(Percepcao, matar_wumpus,Acao),
    !.

rodada_do_agente(Percepcao, grab):- %Considerando a presenca do ouro
    sentiu_brilho(Percepcao),
    retractall(tem_ouro(_)),
    assert(tem_ouro(sim)).

rodada_do_agente(Percepcao, Acao):- %Considerando a presenca de uma casa perigosa
    sentiu_perigo(Percepcao),
    explorar(Percepcao, Acao).

rodada_do_agente(_, Acao):- %Considerando possuir ouro
    tem_ouro(sim),
    objetivo(_,sair, Acao).

rodada_do_agente([_,_,_,_,yes,_|_], Acao):- %Considerando matar o wumpus
    retractall(matou_wumpus(_)),
    assert(matou_wumpus(sim)),
    objetivo(_,sair,Acao),
    !.

rodada_do_agente(_, Acao):- %Considerando o wumpus morto
    matou_wumpus(sim),
    objetivo(_,sair,Acao),
    !.

rodada_do_agente(Percepcao, Acao):- %Para os demais casos
    explorar(Percepcao, Acao).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Rodada do wumpus
/*
rodada_do_wumpus(_, _):-
    matou_wumpus(sim),
    !.
rodada_do_wumpus(walker, AAct):-
    not(matou_wumpus(sim)),
    agente_localizacao([AX,AY]),
    wumpus_location(WX, WY),
    (AX = WX,
    AY = WY;
    AAct = shoot),
    random(N),
    !,
    (N =< 0.75,
    move_wumpus(AAct);
    N > 0.75,
    !).
rodada_do_wumpus(stander, AAct):-
    not(matou_wumpus(sim)),
    move_wumpus(AAct),
    !.*/
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Explorar    
explorar(Percepcao, Acao):- %Caso precise do gps
    gps(Percepcao),
    objetivo(Percepcao, explorar, Acao),
    !.

explorar(Percepcao, Acao):-
    % Nao ha casa segura que nao fora visitada = encurralado
    lista_casas_seguras(Casas_seguras),
    lista_casas_visitadas(Casas_visitadas),
    num_acao(N),
    not(N < 1),
    subtract(Casas_seguras, Casas_visitadas, Casas_seguras_nao_visitadas),
    length(Casas_seguras_nao_visitadas, 0),
    objetivo(Percepcao, sair, Acao),
    !.

explorar(Percepcao, Acao) :- %Considerando a quantidade de acoes feitas
    quantidadeDeMovimentosMaxima(M_max),
    num_acao(N),
    porcentagemLimiteDeMovimentos(P),
    M_per is P * M_max,
    N > M_per,
    objetivo(Percepcao, sair, Acao),
    !.

explorar(Percepcao, Acao):- %Caso bateu na parede
    sentiu_batida(Percepcao),
    agente_localizacao(Pos),
    casa_adjacente_limite(Pos),
    retractall(achou_limite(_)),
    assert(achou_limite(2)),
    limite(Pos),
    objetivo(Percepcao, explorar, Acao).

explorar([no,no,no,yes,no,no,[Pos,_]], Acao):- %Caso bateu na parede
    casa_adjacente_limite(Pos),
    retractall(achou_limite(_)),
    assert(achou_limite(2)),
    limite(Pos),
    objetivo(_, explorar, Acao).

explorar(Percepcao, Acao):- %Considerando a presenca de casa perigosa
    sentiu_perigo(Percepcao),
    casas_perigosas,
    objetivo(Percepcao, explorar, Acao),
    !.

explorar(Percepcao, Acao):- %Considerando a falta de casas perigosas
    not(sentiu_perigo(Percepcao)), 
    casas_seguras,
    objetivo(Percepcao, explorar, Acao),
    !.

explorar([no,no,no,no,no,no|_], Acao):- %Considerando a ausencia de sentido
    objetivo([no,no,no,no,no,no|_], explorar, Acao).

explorar(Percepcao, Acao):-          %Para as outras opcoes
    objetivo(Percepcao, explorar, Acao).

% mostrando o numero de ações do agente
movimentos_feitos:-
    movimentosfeitos(X),
    X1 is X+1,
    retractall(movimentos_feitos(_)),
    assert(movimentos_feitos(X1)).

% predicado para dizer quantas flechas o agente possui 
flecha:-
    n_flechas(F),
    F>0,
    F1 is F-1,
    retractall(n_flechas(_)),
    assert(n_flechas(F1)).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%Objetivos do agente

objetivo(_, sair, climb):- %sair da caverna
    agente_localizacao([X,Y]),
    saida([Q,W]),
    X == Q,
    Y == W,
    !.

objetivo(Percepcao, sair, Acao):- %ir a saida
    saida([X,Y]),
    casa_alvo(Percepcao, [X,Y], Acao).

objetivo(_, matar_wumpus, shoot):- %matar wumpus
    flecha(1),
    retractall(flecha(_)),
    assert(flecha(0)).

objetivo(Percepcao, explorar, Acao):- %explorar
    lista_casas_seguras(Casas_seguras),
    calcular_casa_alvo(Casas_seguras, [X,Y]),
    casa_alvo(Percepcao, [X,Y], Acao).

objetivo(_, explorar, goforward). %explorar
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Definição das casas.

%Casas perigosas.

casas_perigosas:- %Caso uma casa seja perigosa
    lista_casas_perigosas(Casas_perigosas),
    lista_casas_seguras(Casas_seguras),
    agente_localizacao(Pos),
    casasAdjacentes(Pos, Casas_adjacentes),
    subtract(Casas_adjacentes, Casas_seguras, Casas_adjacentes_perigosas),
    union(Casas_perigosas, Casas_adjacentes_perigosas, Novas_casas_perigosas),
    retractall(lista_casas_perigosas(_)),
    assert(lista_casas_perigosas(Novas_casas_perigosas)).

%Casas seguras.

casas_seguras:- %Caso a casa adjacente a segura seja perigosa
    agente_localizacao([X,Y]),
    lista_casas_perigosas(Casas_perigosas),
    casasAdjacentes([X,Y], Casas_adjacentes),
    intersection(Casas_adjacentes, Casas_perigosas, Casas_seguras),
    not(Casas_seguras==[]),
    subtract(Casas_perigosas, Casas_seguras, Novas_casas_perigosas),
    retractall(lista_casas_perigosas(_)),
    assert(lista_casas_perigosas(Novas_casas_perigosas)).

casas_seguras:- %Caso a posicao atual do agente e' segura
    agente_localizacao([X,Y]),
    lista_casas_seguras(Casas_seguras),
    not(member([X,Y], Casas_seguras)),
    retractall(lista_casas_seguras(_)),
    append(Casas_seguras, [[X,Y]], Novas_casas_seguras),
    assert(lista_casas_seguras(Novas_casas_seguras)).

casas_seguras:- %Caso a casa adjacente ao agente seja segura
    lista_casas_seguras(Casas_seguras),
    agente_localizacao([X,Y]),
    casasAdjacentes([X,Y], Casas_adjacentes),
    retractall(lista_casas_seguras(_)),
    union(Casas_seguras, Casas_adjacentes, Novas_casas_seguras),
    assert(lista_casas_seguras(Novas_casas_seguras)).
/*
casas_seguras:-
    lista_casas_perigosas(Casas_perigosas),
    lista_casas_seguras(Casas_seguras),
    agente_localizacao([X,Y]),
    casasAdjacentes([X,Y], Casas_adjacentes),
    union(Casas_seguras, Casas_adjacentes, Novas_casas_seguras),
    subtract(Casas_perigosas,Novas_casas_seguras,Novas_casas_seguras),
    assert(lista_casas_seguras(Novas_casas_seguras)).
*/
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Predicado para decidir o caminho para casa alvo.

calcular_casa_alvo(Casas_seguras, [X,Y]):- %Define o alvo da primeira acao
    lista_casas_visitadas(Casas_visitadas),
    subtract(Casas_seguras, Casas_visitadas, Casas_seguras_nao_visitadas),
    agente_localizacao(Pos),
    casasAdjacentes(Pos, Casas_adjacentes),
    intersection(Casas_adjacentes, Casas_seguras_nao_visitadas, [[X,Y]|_]),
    write([X,Y]),
    !.

calcular_casa_alvo(Casas_seguras, [X,Y]):- %Define os alvos das proximas acoes
    agente_localizacao(Pos),
    casasAdjacentes(Pos, Casas_adjacentes),
    intersection(Casas_adjacentes, Casas_seguras, [[X,Y]|_]).


%Casa alvo na casa adjacente de cima.

casa_alvo(Percepcao, [_,W], goforward):- %Se o alvo esta a frente do agente
    agente_localizacao([X,Y]),
    agente_orientacao(O),
    O == 90,
    Y < W,
    Y1 is Y+1,
    retractall(agente_localizacao(_)),
    assert(agente_localizacao([X,Y1])),
    achou_limite_do_mapa(Percepcao),
    !.

casa_alvo(_, [_,W], turnleft):- %Se o alvo esta a esquerda do agente
    agente_localizacao([_,Y]),
    agente_orientacao(O),
    O == 0,
    Y < W,
    retractall(agente_orientacao(_)),
    assert(agente_orientacao(90)),
    !.

casa_alvo(_, [_,W], turnright):- %Se o alvo esta a direita do agente
    agente_localizacao([_,Y]),
    agente_orientacao(O),
    Y < W,
    Nova_orientacao is O - 90,
    retractall(agente_orientacao(_)),
    assert(agente_orientacao(Nova_orientacao)),
    !.

%Casa alvo na casa adjacente de baixo.

casa_alvo(_, [_,W], goforward):- %Se o alvo esta a frente do agente
    agente_localizacao([X,Y]),
    agente_orientacao(O),
    O == 270,
    Y > W,
    Y1 is Y-1,
    retractall(agente_localizacao(_)),
    assert(agente_localizacao([X,Y1])),
    !.

casa_alvo(_, [_,W], turnleft):- %Se o alvo esta a direita do agente
    agente_localizacao([_,Y]),
    agente_orientacao(O),
    O >= 90,
    Y > W,
    Nova_orientacao is O + 90,
    retractall(agente_orientacao(_)),
    assert(agente_orientacao(Nova_orientacao)),
    !.

casa_alvo(_, [_,W], turnright):- %Se o alvo esta a direita do agente
    agente_localizacao([_,Y]),
    agente_orientacao(O),
    O == 0,
    Y > W,
    retractall(agente_orientacao(_)),
    assert(agente_orientacao(270)),
    !.

%Casa alvo na casa adjacente da direita.

casa_alvo(Percepcao, [Q,_], goforward):- %Se o alvo esta a frente do agente
    agente_localizacao([X,Y]),
    agente_orientacao(O),
    O == 0,
    X < Q,
    X1 is X+1,
    retractall(agente_localizacao(_)),
    assert(agente_localizacao([X1,Y])),
    achou_limite_do_mapa(Percepcao),
    !.

casa_alvo(_, [Q,_], turnleft):- %Se o alvo esta a esquerda do agente
    agente_localizacao([X,_]),
    agente_orientacao(O),
    O == 270,
    X < Q,
    retractall(agente_orientacao(_)),
    assert(agente_orientacao(0)),
    !.

casa_alvo(_, [Q,_], turnright):- %Se o alvo esta a direita do agente
    agente_localizacao([X,_]),
    agente_orientacao(O),
    X < Q,
    Nova_orientacao is O - 90,
    retractall(agente_orientacao(_)),
    assert(agente_orientacao(Nova_orientacao)),
    !.

% Casa alvo na casa adjacente da esquerda.

casa_alvo(_, [Q,_], goforward):- %Se o alvo esta na frente do agente
    agente_localizacao([X,Y]),
    agente_orientacao(O),
    O == 180,
    X > Q,
    X1 is X-1,
    retractall(agente_localizacao(_)),
    assert(agente_localizacao([X1,Y])),
    !.

casa_alvo(_, [Q,_], turnright):- %Se o alvo esta a direita do agente
    agente_localizacao([X,_]),
    agente_orientacao(O),
    O == 270,
    X > Q,
    retractall(agente_orientacao(_)),
    assert(agente_orientacao(180)),
    !.

casa_alvo(_, [Q,_], turnleft):-  %Se o alvo esta a tras do agente
    agente_localizacao([X,_]),
    agente_orientacao(O),
    O >= 0,
    X > Q,
    Nova_orientacao is O + 90,
    retractall(agente_orientacao(_)),
    assert(agente_orientacao(Nova_orientacao)),
    !.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Pegando localizacao e definindo limite do mapa.
gps([no,_,no,no,no,_,[[X,Y],O]]):-
    retractall(agente_localizacao(_)),
    retractall(agente_orientacao(_)),
    assert(agente_localizacao([X,Y])),
    assert(agente_orientacao(O)),
    definir_limite([X,Y]).

definir_limite([X,Y]):-
    X >= Y,
    assert(limite_do_mapa(X)).

definir_limite([_,Y]):-
    assert(limite_do_mapa(Y)).

limite([X,Y]):- %Determina o limite da casa a esquerda do agente
    agente_orientacao(O),
    O == 0,
    X1 is X-1,
    retractall(agente_localizacao(_)),
    assert(agente_localizacao([X1,Y])),
    retractall(limite_do_mapa(_)),
    assert(limite_do_mapa(X1)),
    !.

limite([X,Y]):- %Determina o limite da casa inferior a do agente
    agente_orientacao(O),
    O == 90,
    Y1 is Y-1,
    retractall(agente_localizacao(_)),
    assert(agente_localizacao([X,Y1])),
    retractall(limite_do_mapa(_)),
    assert(limite_do_mapa(Y1)).

casa_adjacente_limite([X,Y]):- %Caso a casa adjacente faz parte do limite
    lista_casas_visitadas(Casas_visitadas),
    lista_casas_seguras(Casas_seguras),
    subtract(Casas_seguras,[[X,Y]], Novas_casas_seguras),
    subtract(Casas_visitadas, [[X,Y]], Novas_casas_visitadas),
    retractall(lista_casas_visitadas(_)),
    retractall(lista_casas_seguras(_)),
    assert(lista_casas_visitadas(Novas_casas_visitadas)),
    assert(lista_casas_seguras(Novas_casas_seguras)).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Casas adjacentes. Confere posisao das casas adjacentes a do agente
casasAdjacentes(Pos, Lista_CasasAdjacentes):-
    casaDireita(Pos, ListaSuperior, ListaDireita),
    casaSuperior(Pos, [],ListaSuperior),
    casaEsquerda(Pos, ListaDireita, ListaEsquerda),
    casaInferior(Pos, ListaEsquerda, Lista_CasasAdjacentes).

%Casas Superiores.
casaSuperior([X,Y], Lista_CasasAdjacentes, Lista_superior):-
    Y1 is Y+1,
    limite_do_mapa(L),
    Y1 =< L,
    append(Lista_CasasAdjacentes,[[X,Y1]],Lista_superior),
    !.

casaSuperior(_, Lista_CasasAdjacentes, Lista_CasasAdjacentes).

%Casas da Direita.
casaDireita([X,Y], Lista_CasasAdjacentes, Lista_Direita):-
    X1 is X+1,
    limite_do_mapa(L),
    X1 =< L,
    append(Lista_CasasAdjacentes,[[X1,Y]],Lista_Direita),
    !.

casaDireita(_, Lista_CasasAdjacentes, Lista_CasasAdjacentes).

%Casas da Esquerda.
casaEsquerda([X,Y], Lista_CasasAdjacentes, Lista_Esquerda):-
    X2 is X-1,
    limite_do_mapa(L),
    X2 =< L,
    X2 >= 1,
    append(Lista_CasasAdjacentes,[[X2,Y]],Lista_Esquerda),
    !.

casaEsquerda(_, Lista_CasasAdjacentes, Lista_CasasAdjacentes).

%Casas Inferiores.
casaInferior([X,Y], Lista_CasasAdjacentes, Lista_inferior):-
    Y2 is Y-1,
    limite_do_mapa(L),
    Y2 =< L,
    Y2 >= 1,
    append(Lista_CasasAdjacentes,[[X,Y2]],Lista_inferior),
    !.

casaInferior(_, Lista_CasasAdjacentes, Lista_CasasAdjacentes).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Predicado para calcular lista de casas visitadas
lista_visitadas :-
    agente_localizacao([X,Y]),
    lista_casas_visitadas(Cv),
    not(member([X,Y], Cv)),
    append(Cv, [[X,Y]], Casas_visitadas1),
    retractall(lista_casas_visitadas(_)),
    assert(lista_casas_visitadas(Casas_visitadas1)).

lista_visitadas.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
porcentagemLimiteDeMovimentos(0.4). % 40%

quantidadeDeMovimentosMaxima(Q) :-
    limite_do_mapa(L),
    %get_setup_size(grid, _, L),
    L > 2, % com o mapa 2x2 nao ha necessidade de se importar com movimentos
    Q is L*L*4.


quantidadeDeMovimentosMaxima(324).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% Degubs
debug:-
    debug_ativo(1),
    limite_do_mapa(Limite),
    lista_casas_seguras(Casas_seguras),
    lista_casas_perigosas(Casas_perigosas),
    lista_casas_visitadas(Casas_visitadas),
    agente_localizacao(Pos),
    agente_orientacao(O),
    num_acao(N),
    nl,
    write('Limite do mapa:'),
    writeln(Limite),
    write('Localizacao:'),
    writeln(Pos),
    write('Orientacao:'),
    writeln(O),
    write('Casas visitadas:'),
    writeln(Casas_visitadas),
    write('Casas perigosas:'),
    writeln(Casas_perigosas),
    write('Casas seguras:'),
    writeln(Casas_seguras),
    write('Numero de acoes: '),
    writeln(N),
    sleep(1).

debug.

/* ----------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : PL config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20150620.224740 */
