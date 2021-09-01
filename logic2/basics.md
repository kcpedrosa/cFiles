Anotações do Wumpus 2017s1, originalmente em /Annotations

## O Mundo Wumpus

O mundo Wumpus é uma caverna que consiste de salas conectadas por passagens. À espreita, em algum lugar da caverna, está o Wumpus, um monstro fétido, devorador de arqueiros agentes inteligentes que invadem a sua sala. O Wumpus pode ser morto pelo agente, mas este só tem uma flecha!

Algumas salas contém buracos sem fundo, nos quais cairá qualquer um que vagar por ele (com exceção do Wumpus, que é muito grande para cair no buraco).

Opcionalmente, salas podem ter super-morcegos, que jogam o agente para alguma casa aleatória.

Nos há também uma vantagem: em algum(ou mais) lugar(es) há um monte de ouro.

Este é um excelente ambiente para teste de programação lógica.

#### Detalhes da Programação

* Você é um agente, que provavelmente começará na casa 1x1, e possui uma única flecha.
* O ambiente pode ir até 20x20, mas fixaremos uma versão 1.0, que será 5x5.
* O fedor do Wumpus atinge toda casa adjacente, que não seja adjacente diagonalmente, inclusive a sua própria casa.
* O buraco pode estar em qualquer posição aleatória. Se cair no buraco, morreu. Ele também tem uma brisa, que pode ser sentida nas casas adjacentes, da mesma forma que o fedor do Wumpus. Não há brisa na casa do buraco.
* Você escuta o farfalhar das asas do super-morcego, também nas casas adjacentes. O morcego não te mata. Se você entrar na casa que ele está, você é transportado aleatoriamente para uma outra casa, podendo esta ser o buraco, o Wumpus, ou uma casa normal. O morcego não muda sua orientação. A casa do morcego também tem ruído.
* Também há pepitas de ouro. Seu brilho não reluz nas casas adjacentes, apenas na sua própria casa.
* Temos, para o agente, além da posição, a orientação, que pode ser de 0(dir), 90(cim), 180(esq), e 270(bai) graus.
* O Wumpus também tem orientação.
* Na pasta do projeto, terá um simulador(Wumpus.pl). Não deve ser alterado.
* Também haverá um outro arquivo, criado pelo grupo( agente00X.pl).
* O mundo passa para o agente as percepções que ele está tendo.
* O agente, então, decide o que quer fazer, enviando, para o mundo, uma ação.
* O agente deve estar sem percepções na primeira casa.
* É um jogo de turnos. Uma vez você joga, na outra, o Wumpus.

#### Ações

* goforward (anda pra frente).
* turnright (vira para a direita, ou seja, subtraindo 90 graus).
* turnleft  (vira para a esquerda, ou seja, adicionando 90 graus).
* grab (pegar ouro, só funciona na casa do ouro).
* shoot (atira sua única flecha. Quando você atira a flecha, ela percorre todo o labirinto, no angulo em que foi atirada e para. Quando o Wumpus morre, ele solta um grito. Se ele não gritar, é por quê está vivo).
* sit (passar a vez).
* climb (sair da caverna. Só funciona na casa 1x1).

#### Percepções

[Stench, Breeze, Glitter, Bump, Scream, Rustle]
Tradução: [Fedor, Vento, Brilho, Trombada, Grito, Ruido]

* Trombada é a percepção que o mundo manda para o agente quando ele tenta andar para uma casa que não existe, quando ele está no fim do labirinto e bate na parede. Ocorre apenas durante um ciclo.
* Grito é a percepção que o mundo manda para o agente quando o Wumpus morre. O fedor continua.
* O morcego não se move: fica sempre no mesmo lugar.

#### Sistema Novo

O mapa do Wumpus foi atualizado, para um dodecaedro. Cada sala tem três portas, ocupando, cada uma, uma das quatro direções.
Pesquisar Wumpus-dodecahedron-map.png.

#### Configuração

* O agente começa com 0 pontos.
* Cada vez que você fizer um movimento, perde um ponto.
* Se morrer, perde 1000 pontos. Causas de morte: buraco, Wumpus ou fadiga.
* Você tem um número máximo de ações permitidas, que vale o produto das dimensões do tabuleiro, vezes 4(no caso do Wumpus padrão). Ao ultrapassar esse número, morre de fadiga.
* Ao matar o Wumpus, ganha 1000 pontos.
* Para cada pepita de ouro encontrada, ganha 500 pontos.
* world_setup é a única linha que não se pode mexer.
* O Wumpus tem vários tipos de movimentos que podem ser configurados. Na configuração original, ele só se move ao escutar um tiro ou quando alguém entra em sua caverna, começando com uma orientação aleatória.
* Ao entrar na casa do Wumpus, ele executa uma ação. Se ao final das ações do Wumpus e do agente, os dois continuarem na mesma casa, o agente morre.
* O Wumpus sente o cheiro do agente a duas casas de distância. Se a configuração escolhida for a bulldozer, assim que ele sentir o cheiro do agente, começa a segui-lo, até que o agente saia do range.
* Na versão 1, usaremos a configuração stander, na qual o Wumpus não se move.
* Na versão 2, usaremos a configuração walker, na qual o Wumpus só se move se entrar na caverna dele, ou se ele ouvir um tiro.

#### Versões

* v1.0-Grid, stander.
* v2.0-Dodeca, walker.

