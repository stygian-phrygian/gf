# GF - grid friend

## Definitions
GF is a thin wrapper around ncurses which adds some lacking useful features.
- grid layout (the only layout) with auto-resizing
- styles: bg/fg color, bold/italic text, borders
- widgets:
    - labels
    - buttons
    - text inputs
    - lists
    - matrices
    - graphs
    - pop-ups
    - drop-down menus
    - checkbox
    - tabs
    - file browser
    - whatever else you want to derive from the base Widget

A Widget is a base class with a render method. It takes user input, usually 
key press events but maybe mouse events or window resize events as well.

User input works in the following modes:
- Navigation mode
    - Navigate to widgets with arrow keys
    - Focus widget (enter input mode) with enter key / mouse click on specific widget
- Input mode
    - All input routed to focused widget
    - Widgets have default keybindings which may be overridden

Direct user input access, eg. overriding the default modal input, is possible. 
Just provide a callback that accepts events. Widget input may also be 
overriden similarly.

## Dependencies
Obviously, this library requires ncurses. Not using windows are you... dork?
`sudo apt install libncurses-dev`

## Inspiration
I like simple. The python based TUI, py_cui, is a major inspiration for this. 
Also, the Lost Boys OST.

## Example

```cpp

#include <ncurses.h>
#include <gridfriend.h>

int main()
{
    using namespace gf;

    // create app with certain grid size
    int rows = 3;
    int cols = 4;
    int tabs = 2;
    auto gf = GF{rows, cols, tabs};

    // populate app with widgets

    // set-up callback to switch on input
    // potentially updating widget's state

    // begin app listening

}

```
