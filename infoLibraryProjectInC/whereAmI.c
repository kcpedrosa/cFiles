#include <ncurses.h>

 int main(void)
 {
 char ch='\0'; /* initialize ch to NULL */
 int row,col;

 initscr();

 addstr("Type some text; Enter '~' to end and see output:\n");
 refresh();

 while( (ch=getch()) != '~')
 ;

 getyx(stdscr,row,col);
 printw("\n\nThe cursor was at row %d, column %d\n",row,col);
 printw("when you stopped typing.");
 refresh();
 getch();
 getch();

 endwin();
 return 0;
 }