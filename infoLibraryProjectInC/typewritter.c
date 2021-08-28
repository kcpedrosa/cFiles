#include <ncurses.h>
#include <stdlib.h>

 int main(void)
 {
 char ch;

 initscr();
 addstr("Type a few lines of text\n");
 addstr("Press ~ to quit\n");
 refresh();

 while( (ch = getch()) != '~')
 ;

 endwin();
 return 0;
}