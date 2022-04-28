#pragma once
#include "Element.hpp"
#include "OOtui.hpp"

class Circle : public Element
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
