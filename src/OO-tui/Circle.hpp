#pragma once
#include "Pixelable.hpp"
#include "OOtui.hpp"

class Circle : public Pixelable
{
private:
    int radius;
public:
    Circle(Vector2 position, int radius);
    Circle(Vector2 position, int radius, char character);
    Circle(Vector2 position, int radius, Color color);
    Circle(Vector2 position, int radius, char character, Color color);
    virtual ~Circle();
    virtual void Render();

};
