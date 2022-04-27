#pragma once
#include <string>
#include "Renderable.hpp"

class Label : public Renderable
{
private:
    std::string text;
public:
    Label(int x, int y, std::string text);
    Label(int x, int y, std::string text, bool visible);
    virtual void Render();
    virtual ~Label();
};
