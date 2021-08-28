#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

typedef struct point {//store infos about position
	int x;
	int y;
} point;

/*store the directions to be consulted*/
typedef enum dir{
	UP,
	DOWN,
	LEFT,
	RIGHT,
} dir;

//positioning initial direction and vars of next position
dir currentDir = RIGHT;
point posicao;

int nextY,
	nextX;
//function to print
void draw(point Drawpoint){
	clear();//when prints, erases earlier position
	box(stdscr, 0, 0);//boundaries to where chars can go
	mvprintw(Drawpoint.y,Drawpoint.x, "#");
	refresh();//resets the screen
}

int main(void)
{
	int ch;//receives the input of keyboard

	initscr();//init the screen
	cbreak();//change the input type of the keyboard
	noecho();
	
	curs_set(FALSE);//hide the cursor, is optional
	keypad(stdscr, TRUE);//permits the use of arrows
	//timeout(100);//move without the input
	//returns -1 after the time ends

	while(1){
		ch = getch();//catch the input from keyboard
		if(ch == KEY_RIGHT){
			currentDir = RIGHT;
		}else if(ch == KEY_LEFT){
			currentDir = LEFT;
		}else if(ch == KEY_UP){
			currentDir = UP;
		}else if(ch ==  KEY_DOWN){
			currentDir = DOWN;
		}
		
		if(currentDir == RIGHT) nextX++;
			else if(currentDir == LEFT) nextX--;
			else if(currentDir == UP) nextY--;
			else if(currentDir == DOWN) nextY++;

			posicao.y = nextY;
			posicao.x = nextX;
			draw(posicao);
			usleep(60000);
		}

	getch();
	endwin();


return 0;
}