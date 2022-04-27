#include "Label.h"


Label::Label(int x, int y, std::string text): Renderable(x, y, true)
{
    this->text = text;
}

Label::Label(int x, int y, std::string text, bool visible): Renderable(x, y, visible)
{
    this->text = text;
}

Label::~Label() {
    
}
