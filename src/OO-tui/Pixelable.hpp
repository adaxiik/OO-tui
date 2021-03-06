#pragma once
#include "Element.hpp"

class Pixelable : public Element
{
protected:
    char character;
public:
    Pixelable(Vector2 position);
    Pixelable(Vector2 position, Color color);
    Pixelable(Vector2 position, char character);
    Pixelable(Vector2 position, char character, Color color);
    virtual void Render() const = 0;
    virtual ~Pixelable();
    void SetCharacter(char character);
    char GetCharacter() const;
};