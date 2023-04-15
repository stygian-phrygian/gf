#include <gf.h>

using namespace gf;

int main()
{
    // create app with grid layout
    App app{};
    int rows = 3;
    int cols = 4;
    app.layouts.emplace_back(Grid::Layout{rows, cols});
    auto& widgets = app.layouts.front().widgets;

    // populate grid layout with widgets
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            widgets.insert({/* TODO */});
        }
    }

    // TODO set-up callback to switch on input
    // potentially updating widget's state

    // begin app listening
    app.listen();
}

