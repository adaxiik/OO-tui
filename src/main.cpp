#include <iostream>
#include <unistd.h>
#include "OO-tui/OOtui.hpp"
#include "OO-tui/Clear.hpp"
#include "OO-tui/Circle.hpp"
#include <cmath>
int main(int argc, char const *argv[])
{
    OOtui &tui = OOtui::GetInstance();
    tui.Init(50, 30);

    while (!tui.shouldExit())
    {
        Clear c;
        tui.AddToRenderQueue(&c);

        int ypos = (int)(std::sin(tui.GetTime()*2)*5)+10;
        int xpos =(int)(std::cos(tui.GetTime()*2)*10)+20;

        Circle c1({xpos,ypos}, 5,Color::RED);
        tui.AddToRenderQueue(&c1);

        ypos = (int)(std::sin(-tui.GetTime()*2)*5)+10;
        xpos =(int)(std::cos(-tui.GetTime()*3)*10)+20;

        Circle c2({xpos+5,ypos}, 5,Color::GREEN);
        tui.AddToRenderQueue(&c2);

        tui.ReadKeys();
        tui.Render();

        //usleep(66000); // 15 fps
        usleep(16000); // 60 fps

    }
    tui.Destroy();
}