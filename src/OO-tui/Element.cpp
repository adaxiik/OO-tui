#include "Element.hpp"
#include "OOtui.hpp"

Element::Element(Vector2 position)
{
    this->position = position;
    this->visible = true;
    this->color = Color::WHITE;
}

Element::Element(Vector2 position, bool visible)
{
    this->position = position;
    this->visible = visible;
    this->color = Color::WHITE;
}

Element::Element(Vector2 position, Color color)
{
    this->position = position;
    this->visible = true;
    this->color = color;
}

Element::Element(Vector2 position, bool visible, Color color)
{
    this->position = position;
    this->visible = visible;
    this->color = color;
}

Element::~Element()
{
}

void Element::SetVisible(bool visible)
{
    this->visible = visible;
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

bool Element::IsVisible()
{
    return this->visible;
}