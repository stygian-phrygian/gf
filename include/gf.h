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


/*
 * general idea:
 *     an app is one or more screens
 *
 *     a screen is a matrix of cells with a grid overlay
 *
 *     a zone is a segment within that grid that houses some update function
 *
 *     an update function is something that takes user input and mutates the
 *     cells within its zone
 *
 * TODO: how do we deal with multiple zones all rendering concurrently?
 */

using UserInputEvent = int;
using Cell = char;
using Screen = std::vector<std::vector<Cell>>; // row by col

// A widget is a user interface element. It knows:
// - how to update its state from user input events
// - how to print itself onto a Screen
struct Widget
{
    // update state given user input event
    void update(UserInputEvent e);
    // print view onto screen
    void print(
            Screen& screen,
            int top_row,
            int right_col,
            int bot_row,
            int left_col);
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
    Layout(int rows, int cols, Screen& screen) :
        rows{rows},
        cols{cols},
        screen{screen}
    {}

    int rows;
    int cols;
    Screen& screen;
    std::map<Zone, Widget> widgets;
};

}

struct App
{
    // RAII around ncurses
    App();
    ~App();
    void listen();
    void focus_layout(Grid::Layout& layout);

    Screen screen;
    std::set<Grid::Layout> layouts;
};

}

#endif

