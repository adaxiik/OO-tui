#include "Pixelable.hpp"

Pixelable::Pixelable(Vector2 position) : Element(position)
{
    this->character = '#';
    this->color = Color::WHITE;
}

Pixelable::Pixelable(Vector2 position, Color color) : Element(position, color)
{
    this->character = '#';
}

Pixelable::Pixelable(Vector2 position, char character) : Element(position)
{
    this->character = character;
    this->color = Color::WHITE;
}

Pixelable::Pixelable(Vector2 position, char character, Color color) : Element(position, color)
{
    this->character = character;
}

Pixelable::~Pixelable()
{
}

void Pixelable::SetCharacter(char character)
{
    this->character = character;
}

char Pixelable::GetCharacter()
{
    return this->character;
}