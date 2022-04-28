#pragma once
#include <string>
#include "Element.hpp"

class Label : public Element
{
private:
    std::string text;
public:
    Label(Vector2 position, std::string text);
    Label(Vector2 position, Color color);
    Label(Vector2 position, char character, Color color);
    virtual void Render() = 0;
    virtual ~Label();
};
