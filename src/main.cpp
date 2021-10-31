#include <curses.h>

int main() {
	char user_inp;
	initscr();
	noecho();
	int max_x, max_y;
	do {
		getmaxyx(stdscr, max_y, max_x);
		mvprintw(0, 0,"%i %i", max_y, max_x);
		mvprintw(max_y/2, max_x/2,"Hello");
		refresh();
		user_inp = getch();
	} while(user_inp != 'q');
	endwin();
}
