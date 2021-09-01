:- use_module(wumpus/wumpus,[start/0]). % chama modulo wumpus

% opcoes padrao para mundo grid:
% grid 5x5
% wumpus parado
% 5% de ouro por casa, 4 buracos e um morcego
% 100 acoes max(5^2*4)
world_setup([5, grid, stander, 0.05, 4, 1, [no,no]]).

% aqui voce vai dizer quais predicados vao sofrer assert e retract
% ao longo do programa
% a sintaxe eh predicado/num_de_argumentos
% melhor usar um argumento e caso precise de varios coloca-los numa lista,
% que seria o unico argumento
% use nomes claros. pesquise snake_case na internet
:- dynamic([
    nflechas/1,
    nacoes/1,
    lista_de_casas_a/1,
    lista_de_casas_b/1,
    lista_de_casas_c/1,
    posicao_do_agente/1,
    orientacao_do_agente/1,
    rota_de_movimento/1,
    objetivo_atual/1,
    objetivos_anteriores/1,
    ultima_acao/1
    ]).

init_agent :-
    % sempre remova todos os asserts anteriores, pois um segundo start
    % no mesmo swipl vai dar erro senao remover 
    retractall(nflechas(_)),
    retractall(nacoes(_)),
    retractall(lista_de_casas_a(_)), % isso eh so um exemplo, com nomes
    retractall(lista_de_casas_b(_)), % ruins para nao servir num trabalho
    retractall(lista_de_casas_c(_)), % use nomes inteligentes
    retractall(posicao_do_agente(_)),
    retractall(orientacao_do_agente(_)),
    retractall(rota_de_movimento(_)),
    retractall(objetivo_atual(_)),
    retractall(objetivos_anteriores(_)),
    retractall(ultima_acao(_))

    assert(nflechas(1)), %padrao
    assert(nacoes(0)), % se seu contador for no comeco do run_agent como
                       % no exemplo, coloque zero, e se for no final, 1
    
    assert(lista_de_casas_a([])), % talvez voce queira a lista inicial vazia

    assert(lista_de_casas_b([[1,1]])), % assim que se faz uma lista de casas
                                       % com uma casa: repare nos colchetes
    assert(lista_de_casas_c([[2,1],[1,2]])), % lista de casas com duas casas
    
    assert(posicao_do_agente([1,1])), % posicao eh colchete simples
    assert(orientacao_do_agente(0)), % comeca no 0
    
    assert(rota_de_movimento([])), % voce pode deixar uma rota vazia ou
                                   % fazer uma inicial
    assert(objetivo_atual(objetivo_a)),
    assert(objetivos_anteriores([])).
    

% tente so chamar o predicado run_agent uma vez. eh melhor usar
% os predicados subordinados para variacao
run_agent(Percepcoes, Acao) :-
    % da +1 acoes
    conta_acao,
    % mapeia e seta objetivos
    usa_percepcao(Percepcao),
    % acao de acordo com objetivos
    qual_acao(Acao),
    proxima_acao(Acao).

% contador de acoes
conta_acao :-
    % voce tambem pode fazer `nacoes(A),retractall(nacoes(_)),` se quiser
    % ao inves desse retract aqui. so use isso em codigos simples como 
    % contadores
    retract(nacoes(A)),
    A1 is A + 1,
    assert(nacoes(A1)).

% voce pode fazer um unico predicado mapeia, mas para arriscar, mapear cada
% perigo individualmente eh melhor
usa_percepcao(Percepcao) :-
    ajusta_posicao(Percepcao),
    mapeia_morcego(Percepcao),
    mapeia_buraco(Percepcao),
    mapeia_wumpus(Percepcao),
    processa_objetivo(Percepcao).

% faca multiplas instancias desse predicado: uma para cada objetivo
qual_acao(Acao) :-
    objetivo(objetivo_a),
    acoes_obj_a(Acoes).
% sempre que ele falha em um, ele desce para o segundo predicado declarado
qual_acao(Acao) :-
    objetivo(objetivo_b),
    acoes_obj_b(Acoes).
%pode ter mais aqui

% eh melhor setar a exploracao no turno seguinte, quando voce atualiza as
% percepcoes. no caso, voce salva sua ultima acao, e na rodada seguinte
% processa
proxima_acao(Acao) :-
    retractall(ultima_acao(_)),
    assert(ultima_acao(Acao)).

%faca uma instancia desse predicado para o gps
ajusta_posicao(Percepcao) :-
    ultima_acao(acao_a),
    ajuste_a.
% em predicados onde talvez alguns casos nao sejam cobertos, voce faz uma
% ultima instancia que pega parametros ignorados(com underline).
% pode tanto ser so dado como fato, sem implicacao(o :- de predicados),
% tanto como um predicado
ajusta_posicao(_).

% deve ter VARIAS instancias, e definitivamente deve ter uma ultima
% "catchall" para casos que nao batem
processa_objetivo(Percepcao) :-
    % aqui voce coloca varias comparacoes, talvez checa numero de acoes ou
    % de flechas, ou talvez mapeamento
    processo_a,
    seta_objetivo(obj_b).

processa_objetivo(Percepcao):-
    % imagine que seu objetivo eh pegar o ouro. depois que o objetivo eh
    % cumprido, voce tem que voltar para o anterior, dai se cria um
    % predicado pra isso:
    ultima_acao(grab),      % grab so deve ser executado quando tem obj,
                            % entao logo apos voce volta para o ultimo:
    volta_objetivo.

processa_objetivo(_).

seta_objetivo(Objnovo) :-
    % novamente, se tiver chance de objetivo_atual falhar, nao de retract
    % direto desta forma. cuidado com a manipulacao de memoria do prolog
    retract(objetivo_atual(Objvelho)),
    assert(objetivo_atual(Objnovo),
    retract(objetivos_anteriores(Lista)), % isso deve ser uma lista
    assert(objetivos_anteriores([Objvelho|Lista])).
    % preste atencao na sintaxe: [cabeca|cauda]. A cabeca vai ser um
    % elemento, e a cauda eh uma lista a ser encaixada
    % exemplo: [1|[2,3]] vai ser igual a [1,2,3]. pode testar

volta_objetivo :- 
    % reseta o atual
    retractall(objetivo_atual(_)),
    % reseta e separa a nova lista
    retract(objetivos_anteriores([Novo|Resto])),
    assert(objetivo_atual(Novo)),
    assert(objetivos_Anteriores(Resto)). % Resto em si eh uma lista de obj
