#pragma once
#include "Rect.hpp"

class FilledRect : public Rect
{
public:
    FilledRect(Vector2 position, Vector2 size);
    FilledRect(Vector2 position, Vector2 size, Color color);
    FilledRect(Vector2 position, Vector2 size, char character);
    FilledRect(Vector2 position, Vector2 size, char character, Color color);
    virtual void Render() const;
    virtual ~FilledRect();
};
