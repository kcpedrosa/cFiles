#include <curses.h>
main()
{
(void) initscr();
printw("BONJOUR A TOUS! ");
refresh();
endwin();
}