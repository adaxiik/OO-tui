#pragma once

class Renderable
{
public:
    virtual ~Renderable(){};
    virtual void Render() const = 0;
};
