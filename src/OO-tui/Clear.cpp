#include "Clear.hpp"
#include "OOtui.hpp"

Clear::Clear()
{
}

Clear::~Clear()
{
}
void Clear::Render() const
{
    OOtui &tui = OOtui::GetInstance();
    for (int y = 0; y < tui.GetHeight(); y++)
        for (int x = 0; x < tui.GetWidth(); x++)
            tui.PutPixel({x, y}, {' ', Color::BLACK});
}