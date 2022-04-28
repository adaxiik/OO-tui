#pragma once
#include "OOtui.hpp"
#include "Renderable.hpp"

class Element: public Renderable
{
protected: 
    Vector2 position;
    Color color;

public:
    Element(Vector2 position);
    Element(Vector2 position, Color color);

    virtual ~Element();
    virtual void Render() = 0;

    void SetPosition(int x, int y);
    void SetPosition(Vector2 position);
    Vector2 GetPosition();
    void SetColor(Color color);
    Color GetColor();
};
