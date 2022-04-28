#include <iostream>
#include <unistd.h>
#include "OO-tui/OOtui.hpp"
#include "OO-tui/Clear.hpp"
#include "OO-tui/Circle.hpp"
#include "OO-tui/Label.hpp"
#include "OO-tui/Text.hpp"
#include "OO-tui/Rect.hpp"
#include "OO-tui/FilledRect.hpp"
#include <cmath>
#define WIDTH 80 
#define HEIGHT 30 
int main(int argc, char const *argv[])
{
    OOtui &tui = OOtui::GetInstance();
    tui.Init(WIDTH, HEIGHT);
    //tui.SetTargetFPS(15);
    while (!tui.shouldExit())
    {

        Clear c;
        tui.AddToRenderQueue(&c);
        int ypos = (int)(std::sin(tui.GetTime() * 2) * 5) + 10;
        int xpos = (int)(std::cos(tui.GetTime() * 2) * 10) + 20;
        Circle c1({xpos, ypos+30}, 5, Color::RED);
        tui.AddToRenderQueue(&c1);


        Rect r1({0, 0}, {WIDTH, HEIGHT}, Color::BLUE);
        tui.AddToRenderQueue(&r1);

        FilledRect r2({10, 10}, {5, 5}, Color::CYAN);
        tui.AddToRenderQueue(&r2);


        std::string fps = std::to_string(1/tui.GetFrameTime());
        Label fpsLabel("FPS: " + fps, {0, 0}, Color::MAGENTA);
        tui.AddToRenderQueue(&fpsLabel);

        //ypos = (int)(std::sin(-tui.GetTime() * 2) * 5) + 10;
        xpos = (int)(std::cos(-tui.GetTime() * 3) * 10) + 20;

        Text t1("OO-tui", {xpos, 20}, 'O', Color::YELLOW);
        tui.AddToRenderQueue(&t1);


        tui.ReadKeys();
        tui.Render();

        //usleep(66000); // 15 fps
        //usleep(16000); // 60 fps
    }
    tui.Destroy();
}