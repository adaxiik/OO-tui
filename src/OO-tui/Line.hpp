#pragma once
#include "Pixelable.hpp"

class Line : public Pixelable
{
private:
    Vector2 start;
    Vector2 end;
public:
    Line(Vector2 start, Vector2 end);
    Line(Vector2 start, Vector2 end, Color color);
    Line(Vector2 start, Vector2 end, char character);
    Line(Vector2 start, Vector2 end, char character, Color color);
    virtual void Render() const;
    virtual ~Line();

};
