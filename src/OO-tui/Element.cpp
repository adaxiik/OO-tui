#include "Element.hpp"
#include "OOtui.hpp"

Element::Element(Vector2 position)
{
    this->position = position;
    this->character = '#';
    this->color = Color::WHITE;
}

Element::Element(Vector2 position, char character)
{
    this->position = position;
    this->character = character;
    this->color = Color::WHITE;
}

Element::Element(Vector2 position, Color color)
{
    this->position = position;
    this->character = '#';
    this->color = color;
}

Element::Element(Vector2 position, char character, Color color)
{
    this->position = position;
    this->character = character;
    this->color = color;
}

Element::~Element()
{
}

void Element::SetCharacter(char character)
{
    this->character = character;
}

void Element::SetPosition(int x, int y)
{
    this->position.x = x;
    this->position.y = y;
}

void Element::SetPosition(Vector2 position)
{
    this->position = position;
}

void Element::SetColor(Color color)
{
    this->color = color;
}

Color Element::GetColor()
{
    return this->color;
}

Vector2 Element::GetPosition()
{
    return this->position;
}

char Element::GetCharacter()
{
    return this->character;
}