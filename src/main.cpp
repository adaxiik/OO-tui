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
#include "OO-tui/RandomQueue.hpp"

//sin cos
#include <cmath>
#define WIDTH 80 
#define HEIGHT 30 
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    OOtui &tui = OOtui::GetInstance();
    tui.Init(WIDTH, HEIGHT);
    tui.SetTargetFPS(15);

    
    RandomQueue<Circle*> circles;
    circles.PushItem(new Circle({5,5}, 4, Color::RED));
    circles.PushItem(new Circle({10,10}, 5, Color::GREEN));
    circles.PushItem(new Circle({17,7}, 8, Color::BLUE));
    circles.PushItem(new Circle({20,20}, 3, Color::YELLOW));
    circles.PushItem(new Circle({15,15}, 9, Color::CYAN));

    // specify as Element, so I can use SetPosition() later..
    Element *c = circles.PopItem();

    RandomQueue<Rect*> rects;
    rects.PushItem(new Rect({5,5}, {4, 4}, Color::YELLOW));
    rects.PushItem(new FilledRect({10,10}, {5, 5}, Color::BLUE));
    rects.PushItem(new FilledRect({17,7}, {8, 8}, Color::GREEN));
    rects.PushItem(new FilledRect({20,20}, {3, 3}, Color::RED));
    rects.PushItem(new Rect({15,15}, {9, 9}, Color::CYAN));

    Element *r = rects.PopItem();



    while (!tui.shouldExit())
    {

        Clear clear;
        tui.AddToRenderQueue(&clear);

        int ypos = (int)(std::sin(tui.GetTime() * 2) * 8) + 10;
        int xpos = (int)(std::cos(tui.GetTime() * 2) * 16) + 20;

        c->SetPosition({xpos, ypos});
        tui.AddToRenderQueue(c);
        
        
        // Line l({xpos, ypos}, {18, 9}, Color::GREEN);
        // tui.AddToRenderQueue(&l);


        tui.AddToRenderQueue(r);


        std::string fps = std::to_string(1/tui.GetFrameTime());
        Label fpsLabel("FPS: " + fps, {0, 0}, Color::MAGENTA);
        tui.AddToRenderQueue(&fpsLabel);

        //ypos = (int)(std::sin(-tui.GetTime() * 2) * 5) + 10;
        // xpos = (int)(std::cos(-tui.GetTime() * 3) * 10) + 20;

        // Text t1("OO-tui", {xpos, 20}, 'O', Color::YELLOW);
        // tui.AddToRenderQueue(&t1);


        tui.ReadKeys();
        tui.Render();

    }
    //delete selected elements
    delete c;
    delete r;

    //delete non-popped elements
    while (!circles.IsEmpty())
        delete circles.PopItem();


    while (!rects.IsEmpty())
        delete rects.PopItem();


    tui.Destroy();
    return 0;
}