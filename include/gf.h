#ifndef GRIDFRIEND_H
#define GRIDFRIEND_H
#include <ncurses.h>

#include <functional>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace gf
{

using UserInputEvent = int;

// A widget is a user interface element. It knows:
// - how to update its state from user input events
// - how to print itself onto an ncurses WINDOW
struct Widget
{
    // update state given user input event
    void update(UserInputEvent e);
    // print view
    void print(
            // the stdscr window
            WINDOW* window,
            // absolute position of our view's top left corner on stdscr
            std::pair<int, int> top_left_corner /*rows cols*/,
            // our view's dimensions
            int height,
            int width);
};

namespace Grid
{

struct Zone
{
    int row;
    int col;
    int row_span;
    int col_span;
};

struct Layout
{
    Layout(int rows, int cols) :
        rows{rows},
        cols{cols}
    {}
    int rows;
    int cols;
    std::map<Zone, Widget> widgets;
};

}

struct App
{
    // RAII around ncurses
    App();
    ~App();
    void listen();
    std::vector<Grid::Layout> layouts;
};

}

#endif

