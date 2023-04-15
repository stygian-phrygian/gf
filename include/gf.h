#ifndef GRIDFRIEND_H
#define GRIDFRIEND_H
#include <ncurses.h>

#include <functional>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace gf
{

using UserInputEvent = int;

// TODO make this a concept
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
            int top_left_row,
            int top_left_col,
            // our widget's absolute dimensions
            int height,
            int width) const;
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

using Listener = std::function<void(UserInputEvent)>;
struct App
{
    // RAII around ncurses
    App();
    ~App();
    // TODO default arguments?
    void listen(std::optional<Listener> listener);
    std::vector<Grid::Layout> layouts;
private:
    void default_listener();
};

}

#endif

