#pragma once
#include <string>
#include "Element.hpp"

class Label : public Element
{
private:
    std::string text;
public:
    Label(std::string text, Vector2 position);
    Label(std::string text, Vector2 position, Color color);

    virtual void Render() const;
    virtual ~Label();

    void SetText(std::string text);
    std::string GetText() const;
};
