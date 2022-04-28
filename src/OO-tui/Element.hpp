#pragma once
#include "OOtui.hpp"
#include "Renderable.hpp"


class Element: public Renderable
{
protected:
    char character;
    Vector2 position;
    Color color;

public:
    Element(Vector2 position);
    Element(Vector2 position, char character);
    Element(Vector2 position, Color color);
    Element(Vector2 position, char character, Color color);
    virtual ~Element();
    virtual void Render() = 0;

    void SetCharacter(char character);
    char GetCharacter();
    void SetPosition(int x, int y);
    void SetPosition(Vector2 position);
    Vector2 GetPosition();
    void SetColor(Color color);
    Color GetColor();
};
