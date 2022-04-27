#pragma once

class Renderable
{
public:
    virtual ~Renderable(){};
    virtual void Render() = 0;
};
