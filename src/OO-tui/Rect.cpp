#include "Rect.hpp"
#include "OOtui.hpp"
Rect::Rect(Vector2 position, Vector2 size) : Pixelable(position)
{
    this->size = size;
}

Rect::Rect(Vector2 position, Vector2 size, Color color) : Pixelable(position, color)
{
    this->size = size;
}

Rect::Rect(Vector2 position, Vector2 size, char character) : Pixelable(position, character)
{
    this->size = size;
}

Rect::Rect(Vector2 position, Vector2 size, char character, Color color) : Pixelable(position, character, color)
{
    this->size = size;
}

Rect::~Rect()
{
}

Vector2 Rect::GetSize() const
{
    return this->size;
}

int Rect::GetWidth() const
{
    return this->size.x;
}

int Rect::GetHeight() const
{
    return this->size.y;
}

void Rect::Render() const
{
    OOtui &tui = OOtui::GetInstance();
    for (int x = 0; x < this->GetWidth(); x++)
    {
        tui.PutPixel({position.x + x, position.y}, {character, color});
        tui.PutPixel({position.x + x, position.y + this->GetHeight() - 1}, {character, color});
    }
    for (int y = 0; y < this->GetHeight(); y++)
    {
        tui.PutPixel({position.x, position.y + y}, {character, color});
        tui.PutPixel({position.x + this->GetWidth() - 1, position.y + y}, {character, color});
    }
}