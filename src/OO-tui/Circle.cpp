#include "Circle.hpp"
#include "OOtui.hpp"
Circle::Circle(Vector2 position, int radius): Pixelable(position)
{
    this->radius = radius;
}
Circle::Circle(Vector2 position, int radius, char character): Pixelable(position, character)
{
    this->radius = radius;
}
Circle::Circle(Vector2 position, int radius, Color color): Pixelable(position, color)
{
    this->radius = radius;
}
Circle::Circle(Vector2 position, int radius, char character, Color color): Pixelable(position, character, color)
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