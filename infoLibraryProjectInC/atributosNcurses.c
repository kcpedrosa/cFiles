#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char ** argv)
{
	initscr();
	if(!has_colors()){
		printw("O terminal nao consegue reproduzir cores");
		return -1;
	}
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_WHITE)

	atton(COLOR_PAIR(1));
	printw("Hello world");
	attoff(COLOR_PAIR(1));

	getch();
	endwin();

/*
	cbreak();
	noecho();

	
	int destaque;
	int escolha;
	int ymax, xmax;
	char opcoes[3][10] = {"opcao 1","opcao 2","opcao 3"};
	int i;

	getmaxyx(stdscr, ymax, xmax);
	WINDOW * janela = newwin(7, (xmax - 6),(ymax - 9), 3);
	box(janela, 0 , 0);
	refresh();
	wrefresh(janela);

	keypad(janela, true);

	
	if(escolha == 10){
			break;// type enter [value 10 equals to enter]
		}
		mvprintw(2,7,"You chose: %s", opcoes[destaque]);
		getch();
		endwin();
}*/
	return 0;
}