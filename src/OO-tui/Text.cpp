#include "Text.hpp"
#include "fonts/font8x8_basic.h"
Text::Text(std::string text, Vector2 position) : Pixelable(position)
{
    this->text = text;
    this->character = '#';
    this->color = Color::WHITE;
}

Text::Text(std::string text, Vector2 position, Color color) : Pixelable(position, color)
{
    this->text = text;
    this->character = '#';
}

Text::Text(std::string text, Vector2 position, char character) : Pixelable(position)
{
    this->text = text;
    this->character = character;
    this->color = Color::WHITE;
}

Text::Text(std::string text, Vector2 position, char character, Color color) : Pixelable(position, color)
{
    this->text = text;
    this->character = character;
}

Text::~Text()
{
}

void Text::SetText(std::string text)
{
    this->text = text;
}

std::string Text::GetText() const
{
    return this->text;
}

void Text::Render() const
{
    OOtui &tui = OOtui::GetInstance();
    for (int i = 0; i < this->text.length(); i++)
        for (int y = 0; y < 8; y++)
            for (int x = 0; x < 8; x++)
                if (font8x8[(int)this->text[i]][y] & (1 << x))
                    tui.PutPixel({this->position.x + (int)x + i * 8,
                                  this->position.y + (int)y},
                                 {this->character, this->color});
}
