#include <gf.h>
#include <ncursesw/ncurses.h>
#include <locale.h>

int main()
{
    // create app with certain grid size

    // populate app with widgets

    // set-up callback to switch on input
    // potentially updating widget's state

    // begin app listening

    setlocale(LC_ALL, "");
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();

    printw("type any character 👉 to see it in bold: \n");
    refresh();

    int ch = getch();
    if (ch == KEY_F(1))
    {
        printw("F1 pressed!\n");
    }
    else
    {
        printw("The pressed key is: ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    getch();

    echo();
    noraw();
    endwin();
}

