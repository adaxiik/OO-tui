#include "Label.hpp"
#include "OOtui.hpp"
Label::Label(std::string text, Vector2 position) : Element(position)
{
    this->text = text;
    this->color = Color::WHITE;
}

Label::Label(std::string text, Vector2 position, Color color) : Element(position, color)
{
    this->text = text;
}

void Label::Render() const
{
    for (size_t i = 0; i < this->text.length(); i++)
    {
        OOtui::GetInstance().PutPixel({this->position.x + (int)i, this->position.y}, {this->text[i], this->color});
    }
}


Label::~Label()
{
}

void Label::SetText(std::string text)
{
    this->text = text;
}

std::string Label::GetText() const
{
    return this->text;
}