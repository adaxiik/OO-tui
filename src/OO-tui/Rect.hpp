#pragma once
#include "Pixelable.hpp"
class Rect : public Pixelable
{
private:
    Vector2 size;
public:
    Rect(Vector2 position, Vector2 size);
    Rect(Vector2 position, Vector2 size, Color color);
    Rect(Vector2 position, Vector2 size, char character);
    Rect(Vector2 position, Vector2 size, char character, Color color);
    virtual void Render() const;
    virtual ~Rect();

    Vector2 GetSize()const;
    int GetWidth()const;
    int GetHeight()const;

    void SetSize(Vector2 size);

};