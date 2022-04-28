#include "Circle.hpp"

Circle::Circle(Vector2 position, int radius): Element(position)
{
    this->radius = radius;
}
Circle::Circle(Vector2 position, int radius, char character): Element(position, character)
{
    this->radius = radius;
}
Circle::Circle(Vector2 position, int radius, Color color): Element(position, color)
{
    this->radius = radius;
}
Circle::Circle(Vector2 position, int radius, char character, Color color): Element(position, character, color)
{
    this->radius = radius;
}
Circle::~Circle()
{
}
void Circle::Render()
{
    int x, y;
    for (y = -radius; y <= radius; y++)
        for (x = -radius; x <= radius; x++)
            if (x * x + y * y <= radius * radius)
                OOtui::GetInstance().PutPixel({x + position.x, y + position.y}, {this->character, this->color});

}