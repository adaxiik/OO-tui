#include "Line.hpp"
#include "OOtui.hpp"
Line::Line(Vector2 start, Vector2 end) : Pixelable(start)
{
    this->start = start;
    this->end = end;
}

Line::Line(Vector2 start, Vector2 end, Color color) : Pixelable(start, color)
{
    this->start = start;
    this->end = end;
}

Line::Line(Vector2 start, Vector2 end, char character) : Pixelable(start, character)
{
    this->start = start;
    this->end = end;
}

Line::Line(Vector2 start, Vector2 end, char character, Color color) : Pixelable(start, character, color)
{
    this->start = start;
    this->end = end;
}

Line::~Line()
{
}

void Line::Render() const
{
    OOtui &tui = OOtui::GetInstance();
    int x0 = this->start.x;
    int y0 = this->start.y;
    int x1 = this->end.x;
    int y1 = this->end.y;
    
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    while (true)
    {
        tui.PutPixel({x0, y0}, {character, color});
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 >= dy)
        {
            if(x0 == x1)
                break;
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            if(y0 == y1)
                break;
            err += dx;
            y0 += sy;
        }
    }
}
