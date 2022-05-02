#include <iostream>
#include <unistd.h>
#include "OO-tui/OOtui.hpp"
#include "OO-tui/Clear.hpp"
#include "OO-tui/Circle.hpp"
#include "OO-tui/Label.hpp"
#include "OO-tui/Text.hpp"
#include "OO-tui/Rect.hpp"
#include "OO-tui/FilledRect.hpp"
#include "OO-tui/Line.hpp"
#include <cmath>
#define WIDTH 80 
#define HEIGHT 30 




int main(int argc, char const *argv[])
{
    OOtui &tui = OOtui::GetInstance();
    tui.Init(WIDTH, HEIGHT);
    tui.SetTargetFPS(15);

    while (!tui.shouldExit())
    {
        Clear().Render();

        int ypos = (int)(std::sin(tui.GetTime() * 2) * 8) + 10;
        int xpos = (int)(std::cos(tui.GetTime() * 2) * 16) + 20;
        Circle ({xpos, ypos}, 5, Color::RED).Render();
        Line({xpos, ypos}, {18, 9}, Color::GREEN).Render();
        Rect({0, 0}, {WIDTH, HEIGHT}, Color::BLUE).Render();


        FilledRect({10, 10}, {5, 5}, Color::CYAN).Render();


        std::string fps = std::to_string(1/tui.GetFrameTime());
        Label("FPS: " + fps, {0, 0}, Color::MAGENTA).Render();


        //ypos = (int)(std::sin(-tui.GetTime() * 2) * 5) + 10;
        xpos = (int)(std::cos(-tui.GetTime() * 3) * 10) + 20;

        Text ("OO-tui", {xpos, 20}, 'O', Color::YELLOW).Render();


        tui.Render();
        tui.ReadKeys();
    }
    tui.Destroy();
}