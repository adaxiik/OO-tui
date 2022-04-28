#include "FilledRect.hpp"
#include "OOtui.hpp"

FilledRect::FilledRect(Vector2 position, Vector2 size) : Rect(position, size)
{
}

FilledRect::FilledRect(Vector2 position, Vector2 size, Color color) : Rect(position, size, color)
{
}

FilledRect::FilledRect(Vector2 position, Vector2 size, char character) : Rect(position, size, character)
{
}

FilledRect::FilledRect(Vector2 position, Vector2 size, char character, Color color) : Rect(position, size, character, color)
{
}

FilledRect::~FilledRect()
{
}

void FilledRect::Render() const
{
    OOtui &tui = OOtui::GetInstance();
    for (int x = 0; x < this->GetWidth(); x++)
        for (int y = 0; y < this->GetHeight(); y++)
            tui.PutPixel({position.x + x, position.y + y}, {character, color});
}
