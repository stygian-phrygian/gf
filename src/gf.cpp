#include <gf.h>

namespace gf
{

App::App()
{
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();
}

App::~App()
{
    echo();
    noraw();
    endwin();
}

// TODO
void App::listen()
{

}

}
