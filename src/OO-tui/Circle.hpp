#pragma once
#include "Element.hpp"
#include "OOtui.hpp"

class Circle : public Element
{
private:
    int radius;
public:
    Circle(Vector2 position, int radius);
    Circle(Vector2 position, int radius, bool visible);
    Circle(Vector2 position, int radius, Color color);
    Circle(Vector2 position, int radius, bool visible, Color color);
    virtual ~Circle();
    virtual void Render();

};
