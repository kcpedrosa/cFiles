/*****************************************************************************
 *   ex15.c                                    Version 20180714.101818       *
 *                                                                           *
 *   Brief description                                                       *
 *   Copyright (C) 2016-2018    by Ruben Carlo Benante                       *
 *****************************************************************************
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License.          *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************
 *   To contact the author, please write to:                                 *
 *   Ruben Carlo Benante                                                     *
 *   Email: rcb@beco.cc                                                      *
 *   Webpage: www.beco.cc                                                    *
 *   Phone: +55 (81) 3184-7555                                               *
 *****************************************************************************/

/* ------------------------------------------------------------------------- */
/**
 * @file ex15.c
 * @ingroup GroupUnique
 * @brief Brief description
 * @details This program really do a nice job as a template, and template only!
 * @version 20160908.182830
 * @date 2016-09-08
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc ex15.c -o ex15.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex15.c
 */

/* ------------------------------------------------------------------------- */
/* includes at ex15.h */

#include "ex15.h" /* To be created for this template if needed */

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This
 * @details Ladies and
 *
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int kpress; /* tecla pressionada no laco principal */
    wins_t win; /* info para ncurses */

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hV")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    /* initialize ncurses */
    ex15_init(&win);

    /* laco principal */
    do
    {

        wrefresh(win.w[win.wi]);

        kpress=getch();

        if(kpress== 'b')
        {
            win.wi=1;
            padd(&win);
        }
        if(kpress==KEY_F(1) || kpress=='1')
        {
            if(win.wi!=0)
            {
                win.wo=win.wi;
                win.wi=0;
                phelp(&win);
            }
            else
            {
                 switch(win.wo)
                 {
                     case 0:
                         win.wi=0;
                         ex15_init(&win);
                         break;
                     case 1:
                         win.wi=1;
                         padd(&win);
                         break;
                     case 2:
                         win.wi=2;
                         psearch(&win);
                         break;
                     case 3:
                         win.wi=3;
                         pchange(&win);
                         break;
                     case 4:
                         win.wi=4;
                         pdel(&win);
                         break;
                     case 5:
                         win.wi=5;
                         pabout(&win);
                         break;
                }
            }
        }
        if(kpress==KEY_F(2) || kpress=='2')
        {
            msgstatus(win, "Already up-to-date", STOK);
        }
        /*if(kpress==KEY_F(3) || kpress=='3')
        {
            msgstatus(win, "Sorry, I can save nothing yet", STOK);
        }
        if(kpress==KEY_F(3 || kpress=='3')
        {
            if(msgstatus(win, "Are you sure you want to get out?(y/n)", STYESNO) == 1) //chama funcao msgstatues();
            {
               //nao sei o que fazer por hora
            }
        }*/
        if(kpress==KEY_F(4)||kpress=='4')
        {
            if(msgstatus(win, "Are you sure you want to get out?(y/n)", STYESNO) == 1)  /*chama a funcao msgstatus()*/
            {
                kpress = 'q';
            }
        }

        if(kpress==KEY_F(5)||kpress=='5')
        {
         if (win.wi == 0)
             pabout(&win);
         else
         {
             win.wo=win.wi;
             win.wi = (win.wi-1)%NWIN;
            switch(win.wi)
            {

                case 0:
                    phelp(&win);
                    break;
                case 1:
                    padd(&win);
                    break;
                case 2:
                    psearch(&win);
                    break;
                case 3:
                    pchange(&win);
                    break;
                case 4:
                    pdel(&win);
                    break;
                case 5:
                    pabout(&win);
                    break;
            }
         }
        }

        if(kpress==KEY_F(6)||kpress=='6')
        {
            win.wo=win.wi;
            win.wi = (win.wi+1)%NWIN;
            switch(win.wi)
            {

                case 0:
                    phelp(&win);
                    break;
                case 1:
                    padd(&win);
                    break;
                case 2:
                    psearch(&win);
                    break;
                case 3:
                    pchange(&win);
                    break;
                case 4:
                    pdel(&win);
                    break;
                case 5:
                    pabout(&win);
                    break;

            }

        }

        if(kpress=='s')
            msgstatus(win, "oi na linha de status", STOK);//teste linha de status


        napms(50);
    } while(kpress!='q');

    bomb(win, "", 0, NULL);
}


/* ------------------------------------------------------------------------- */
/* inicio de cada tela */
void modelo(wins_t *pw)  // modelo inicial de todas as janelas
{

//  if(pw->wi!=pw->wo)
//  {
//      pw->wo=pw->wi;
        wclear(pw->w[pw->wi]);
        box(pw->w[pw->wi], 0, 0);
//  }

    mvwprintw(pw->w[pw->wi], 1, (COLS/2)-16, "Nome do Programa"); // altera o nome do programa aqui, por enquanto e subtrai a quant de caracteres
    mvwhline(pw->w[pw->wi], 2, 1, '-', COLS-2);// linha de divisoria(LD)
    mvwprintw(pw->w[pw->wi], 3, 1, nomejanela[pw->wi]);// nome da tela que se encontra
    mvwhline(pw->w[pw->wi], 4, 1, '-', COLS-2);//LD

    mvwhline(pw->w[pw->wi], LINES-4, 1, '-', COLS-2); //LD
}
/* ------------------------------------------------------------------------- */
/* Linha de atalhos */
void atalhos()  // atalhos
{
    attron(A_REVERSE);
    mvprintw(LINES-1, 0,"F1 Help "); // atalho 1
    mvprintw(LINES-1, 9, "F2 Load "); // atalho 2
    mvprintw(LINES-1, 18,"F3 Save "); // atalho 3
    mvprintw(LINES-1, 27, "F4 quit "); // atalho 4
    mvprintw(LINES-1, COLS-35, "F5 Prev "); // atalho 5
    mvprintw(LINES-1, COLS-26, "F6 Next "); // atalho 6
    mvprintw(LINES-1, COLS-17, "F7 Unkn "); // atalho 7
    mvprintw(LINES-1, COLS-8, "F8 Unkn "); // atalho 8
    attroff(A_REVERSE);
}
/* ------------------------------------------------------------------------- */
/* imprime tela 00: help */
void phelp(wins_t *pw)
{
    int lst=8; // linha que inicia os helps

    IFDEBUG("phelp()"); // funcao caso de erro ao iniciar
    pw->wi=0;
    modelo(pw); //funcao de template de cada pagina

    mvwprintw(pw->w[pw->wi], lst, 1,   "<f1> ou <1>  : Abre o help");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f2> ou <2>  : Carrega ultima alteracao");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f3> ou <3>  : Salva alteracoes");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f4> ou <4>  : Sai do programa");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f5> ou <5>  : Retrocede a pagina");
    mvwprintw(pw->w[pw->wi], lst++, 1, "<f6> ou <6>  : Avanca a pagina");

    wrefresh(pw->w[pw->wi]);
}

/* ------------------------------------------------------------------------- */
/* imprime tela 01 : adicionar livro  */
void padd(wins_t *pw)
{
    FILE *file; /*Arquivo*/
    char nomeLivro[100]; /*String com nome do Livro*/
    int lst = 5; /*Linha que inicia*/
    int kpress; /*Tecla Pressionada*/

    IFDEBUG("padd()"); // funcao caso de erro ao iniciar
    pw->wi=1;
    modelo(pw); //funcao de template de cada pagina

    file = fopen("livros.txt", "a"); /*Abre arquivo*/

    if(file == NULL) /*Arquivo vazio*/
    {
        mvwprintw(pw->w[pw->wi], lst, 1, "Arquivo não pode ser aberto");
        wrefresh(pw->w[pw->wi]); /*Update Screen*/
        getch();
        endwin(); /*Fecha janela*/
    }

    mvwprintw(pw->w[pw->wi], lst, 1,   "Insira o nome do novo livro: ");
    wrefresh(pw->w[pw->wi]); /*Update the screen*/
    mvwscanw(pw->w[pw->wi], lst, 30, " %[^\n]s", nomeLivro);  /*Escreve no arquivo*/
    mvwprintw(pw->w[pw->wi], lst+40, 1,   "**Nao esqueca de salvar pressionando F3.** ");
    wrefresh(pw->w[pw->wi]); /*Update Screen*/

    /*isso aq precisa ir p main, só n sei como*/
    kpress = getch();
    if(kpress==KEY_F(3) || kpress=='3')
    {
        fprintf(file, "%s; \n", nomeLivro); /*Insere o que foi escrito no arquivo*/
        mvwprintw(pw->w[pw->wi], lst+40, 1,   "**Salvo com sucesso**");
    }
    /*fim do que precisa ir pra main*/

    fclose(file); /*Fecha arquivo*/

    wrefresh(pw->w[pw->wi]);
    endwin();/*Fecha Janela*/

}
/* ------------------------------------------------------------------------- */
/* imprime tela 02 : procurar livro  */
void psearch(wins_t *pw)
{

    IFDEBUG("psearch()"); // funcao caso de erro ao iniciar
    pw->wi=2;
    modelo(pw); //funcao de template de cada pagina

}
/* ------------------------------------------------------------------------- */
/* imprime tela 03 : mudar livro  */
void pchange(wins_t *pw)
{

    IFDEBUG("pchange()"); // funcao caso de erro ao iniciar
    pw->wi=3;
    modelo(pw); //funcao de template de cada pagina

}
/* ------------------------------------------------------------------------- */
/* imprime tela 04 : apagar livro  */
void pdel(wins_t *pw)
{

    IFDEBUG("pdel()"); // funcao caso de erro ao iniciar
    pw->wi=4;
    modelo(pw); //funcao de template de cada pagina

}
/* ------------------------------------------------------------------------- */
/* imprime tela 05 : sobre biblioteca  */
void pabout(wins_t *pw)
{

    IFDEBUG("pabout()"); // funcao caso de erro ao iniciar
    pw->wi=5;
    modelo(pw); //funcao de template de cada pagina

}
/* ------------------------------------------------------------------------- */

/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex15", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "ex15");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");

    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex15", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------------- */
/* imprime na linha de status */
int msgstatus(wins_t win, char *msg, int tipo)
{
    IFDEBUG("msgstatus()");
    char const *const lc = "|Status line:";
    //int l = LINES-3;                         variavel inutilizada, ja tem STLINE no ex15.h
    int kpress;

    switch(tipo)
    {
        case STOK:
            mvwprintw(win.w[win.wi], STLINE, 5, "%s", msg);
            break;
        case STYESNO:
             mvwprintw(win.w[win.wi], STLINE, 1, "%s %s", lc, msg);
             wrefresh(win.w[win.wi]); //  a mensagem na tela
             do
             {
                kpress = getch();
                napms(30);
             }
             while(kpress != 'y' && kpress != 'n');

             if(kpress == 'y')
             {
                 return 1;
             }
             else
             {
                 return 0;
             }
             break;
         default:
             mvwprintw(win.w[win.wi], STLINE, 5, "status type undefined");
             break;
     }
     wrefresh(win.w[win.wi]);
     return 0;
 }

 /* ------------------------------------------------------------------------- */
 /* termina o programa graciosamente */
 void bomb(wins_t win, char *msg, int status, FILE *f)
 {
     IFDEBUG("bomb()");
     int i;

     if(f)
         fclose(f);
      for(i=0; i<NWIN; i++)
         delwin(win.w[i]);

 endwin();
     fprintf(stderr, msg);

     exit(status);
 }

 /* ------------------------------------------------------------------------- */
 /**
  * @ingroup GroupUnique
  * @brief This function initializes some operations before start
  * @details Details to be written in
  * multiple lines
  *
  * @return Void
  *
  * @author Ruben Carlo Benante
  * @version 20160908.182830
  * @date 2016-09-08
  * @copyright Use this tag only if not the same as the whole file
  *
  */
 void ex15_init(wins_t *pw)
 {
     IFDEBUG("ex15_init()");
     int i; /* indice */

     for(i=0; i<NWIN; i++)
         pw->menu[i]=0;

     pw->wi=0; /* inicia na tela de help */
     pw->wo=1; /* tela anterior aa mudanca */

     initscr(); /* inicializa ncurses */
     napms(10); /* aguarda initscr() */
     refresh(); /* inicializar tela */
     halfdelay(2); /* cbreak sem espera ocupada */
     noecho(); /* desliga eco de teclado */
     keypad(stdscr, TRUE); /* liga teclas de funcao */

     /* criar janelas */
     for(i=0; i<NWIN; i++)
     {
         pw->w[i]=newwin(LINES-1,COLS,0,0);
         if(pw->w[i]==NULL)
         {
             for(--i; i>=0; --i)
                 delwin(pw->w[i]);
             endwin();
             fprintf(stderr, "Error: can't create windows\n");
             exit(EXIT_FAILURE);
         }
     }

     pw->lmax=LINES; /* qtdd de linhas na tela */
     pw->cmax=COLS; /* qtdd de colunas na tela */
     wclear(pw->w[pw->wi]);
     box(pw->w[pw->wi], 0, 0);//criar borda
     atalhos();
     return;
 }

 /* esboço da função de movimentação */
 // Professor fez essa função no seu laço principal do programa gwork devido ele ser um programa simples com apenas uma tela para fazer alterações //
 // como o biblio vai ter 4 janelas como alterações precimanos fazer uma função que resouva esse problema nas 4 telas //
 /*    do
     {
         kpress=getch();
         if (Kpress == KEY_RIGHT)
         {
             if (dt.themenu)
                 dt=addmenu(dt);
             else
             dt=addcoin(dt);
         }
         if (Kpress == KEY_LEFT)
         {
             if (dt.themenu)
                 dt=submenu(dt);
             else
             dt=suncoin(dt);
         }
         if (kpress == KEY_UP)
         {
         if (dt.themenu)                                                                                                                                                                                    dt=addcoin(dt);
             else
             dt=submenu(dt)
         }
         if (Kpress == KEY_DOWN)
         {
            if (dt.themenu)
               dt=subcoin(dt);
            else
            dt=addmenu(dt);
         }
     }
 */
 /* ------------------------------------------------------------------------- */
 /* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline    */
 /* Template by Dr. Beco <rcb at beco dot cc>       Version 20180716.101436   */


/*                   */