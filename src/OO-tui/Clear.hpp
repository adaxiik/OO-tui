#pragma once
#include "Renderable.hpp"
#include "OOtui.hpp"
class Clear : public Renderable
{
private:
public:
    Clear();
    virtual void Render();
    virtual ~Clear();
};

