## Objetivos

#### Introdução

Os objetivos são maneiras de controlar as ações do agente, numa programação puramente por memória. O trabalho Wumpus passado tradicionalmente na cadeira de Lógica Matemática da POLI-UPE requer um agente deste tipo, e portanto não devem ser usadas ações puramente reativas. Para demonstrar a importância disto, o API demonstrado no arquivo memoryagent.pl nem sequer passa as percepções para o predicado de ações, porque estas são *completamente desnecessárias* num agente que age apenas por memória.

#### Como Organizar

O predicado principal que manipula a memória deve conter várias checagens, que decidem qual o objetivo a ser utilizado. Geralmente, se nenhum dos critérios para trocar para outro objetivo foi cumprido, o agente deve utilizar o objetivo "explorar" por padrão.

Cada objetivo representa um conjunto específico de ações. No caso, cada objetivo deve ter uma instância(versão, ou como preferir chamar) do predicado de escolher ações, como já demonstrado no memoryagent.pl.

Também é importante manter uma lista "pilha" com os objetivos anteriores, para caso precise retornar a um anterior. E se seguir as recomendações do professor, você vai precisar.

**Objetivos recomendados:**

* Explorar

    Pode ser tratado como o objetivo padrão: no caso, toda vez que não houver um objetivo, é explorar.

    Neste objetivo, o agente deve procurar casas seguras não-exploradas, guardadas na memória. O agente simplesmente acha uma rota de baixo custo até a casa desejada e a segue. Ao serem exploradas todas as casas seguras, pode-se inicializar os objetivos "sair" ou "arriscar"

* Pegar Ouro

    Pode até parecer confuso, por só precisar de uma ação, mas é feito da seguinte maneira: no predicado manipulador de objetivos, toda vez que houver um brilho, ativa-se o objetivo "pegarouro", e continua-se o processamento. No predicado de escolher ações, toda vez que o objetivo for "pegarouro", ele retorna uma ação grab, e usa o predicado de retornar ao objetivo anterior (mencionado anteriormente) para sair do objetivo de pegar ouro.

* Matar Wumpus

    O agente deve manter na memória uma lista de locais do Wumpus. Toda vez que ele encontra uma casa com fedor, ele tenta triangular o cheiro até achar a casa exata do Wumpus. Quando ele acha essa casa, o agente seta o objetivo "mata"(ou "matarwumpus"). No predicado de escolher ações, toda vez que este objetivo for acionado, o agente deve tentar achar a casa colinear ao Wumpus mais próxima, ou seja, a casa mais próxima onde se pode atirar no Wumpus. Ao chegar nessa casa, o agente gira para mirar no Wumpus, e atira.

    No predicado de memória, quando a percepção grito for sentida(o que indica que o Wumpus morreu), deve-se remover o objetivo e retornar ao anterior.

* Sair

    Este objetivo é um dos que mais pode variar. Podem haver diversos critérios para inicializá-lo: matar o Wumpus, ter um ou mais ouros, ou ter um número de ações muito alto, com risco de morte. Para ter um agente mais eficiente, é recomendado deixar apenas um limite no número de ações como critério para saída, além, é claro, do critério de saída para quando já se explorou todo o mapa(lista seguras=lista visitadas).

    Um agente relativamente otimizado não precisa de mais de 20 ações para sair, mas uma margem de 30 é aceitável. No caso, ao chegar em 70~80 ações tomadas, o objetivo "sair" deve ser inicializado imediatamente.

    Para as ações deste objetivo, podem ser reutilizadas varias partes do objetivo explorar: para cumprir o objetivo sair, só é necessário criar uma rota para a casa [1,1], e dar climb quando chegar.

* Arriscar

    Objetivo de certa forma opcional. É certamente bom tentar fazer, mas só dá resultados consideráveis em certas situações.

    O objetivo arriscar deve calcular o risco de certas com  chance de perigo serem realmente perigosas, e checar se tem alguma casa com risco baixo o suficiente para valer à pena arriscar uma morte. Além disso, é bom também colocar critérios como: baixo número de ações após acabar a exploração, pouco número de ouros e Wumpus vivo.

    Ao ser achada uma casa com boas chances de valer o risco, o predicado de ações para objetivo(arricar) deve rotear o agente até a casa desejada.

    **Nota:** Se a casa desejada tem risco de conter um morcego, após entrar nela, usar o GPS é uma maneira fácil de saber se a casa tinha ou não um morcego.
