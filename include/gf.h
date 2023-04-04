#ifndef GRIDFRIEND_H
#define GRIDFRIEND_H
#include <ncurses.h>

#include <functional>
#include <string>
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

// forward declare Screen
struct Screen;
// Zone on a grid
struct Zone
{
    // this tells us how many cells there are
    // and where to render
    Screen* screen;

    // this tells us the dimensions of our zone
    // its grid position
    int grid_row_index;
    int grid_column_index;
    // how far it spans
    int grid_row_span;
    int grid_column_span;

    // this tells us how to render the zone
    // after responding to user input
    std::function<void(UserInputEvent)> render;
};

// A screen is a bunch of cells with a grid overlay
struct Screen
{
    Screen(
            int grid_rows,
            int grid_columns,
            int cell_rows,
            int cell_columns);
    std::vector<std::vector<Cell>> cells;
    std::vector<Zone> zones; // one zone takes focus at a time, holds widget
};

struct App
{
    void listen();
};

}

#endif

