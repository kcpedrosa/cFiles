#include <stdio.h>
#include <curses.h>
int main (void)
{
initscr();
noecho();
cbreak();
printw(20, 30, "BONJOUR A TOUS! ");
getch();
endwin();

return 0;
}