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


//math library for OpenGL
#include <glm/glm.hpp>

glm::mat3 rotationX(float angle) {
    return {
        {1, 0, 0},
        {0, cos(angle), -sin(angle)},
        {0, sin(angle), cos(angle)}
    };
}
glm::mat3 rotationY(float angle) {
    return {
        {cos(angle), 0, sin(angle)},
        {0, 1, 0},
        {-sin(angle), 0, cos(angle)}
    };
}
glm::mat3 rotationZ(float angle) {
    return {
        {cos(angle), -sin(angle), 0},
        {sin(angle), cos(angle), 0},
        {0, 0, 1}
    };
}


glm::vec3 points[8] = {
    {-8, -8, -8},
    {8, -8, -8},
    {8, 8, -8},
    {-8, 8, -8},
    {-8, -8, 8},
    {8, -8, 8},
    {8, 8, 8},
    {-8, 8, 8}
};


int main(int argc, char const *argv[])
{
    OOtui &tui = OOtui::GetInstance();
    tui.Init(WIDTH, HEIGHT);
    tui.SetTargetFPS(15);
    int offsetX = 40;
    int offsetY = 15;
    while (!tui.shouldExit())
    {
        Clear().Render();
        
        for(auto &point : points)
        {   
            point = rotationX(0.07f) * point;
            point = rotationY(0.05f) * point;
            point = rotationZ(0.04f) * point;
            //Circle({(int)point.x+offsetX, (int)point.y+offsetY}, 1, '*',Color::RED).Render();
        }

        //stupid, but Im lazy to think too much
        Line({(int)points[0].x+offsetX, (int)points[0].y+offsetY}, {(int)points[1].x+offsetX, (int)points[1].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[1].x+offsetX, (int)points[1].y+offsetY}, {(int)points[2].x+offsetX, (int)points[2].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[2].x+offsetX, (int)points[2].y+offsetY}, {(int)points[3].x+offsetX, (int)points[3].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[3].x+offsetX, (int)points[3].y+offsetY}, {(int)points[0].x+offsetX, (int)points[0].y+offsetY}, '*', Color::RED).Render();

        Line({(int)points[4].x+offsetX, (int)points[4].y+offsetY}, {(int)points[5].x+offsetX, (int)points[5].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[5].x+offsetX, (int)points[5].y+offsetY}, {(int)points[6].x+offsetX, (int)points[6].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[6].x+offsetX, (int)points[6].y+offsetY}, {(int)points[7].x+offsetX, (int)points[7].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[7].x+offsetX, (int)points[7].y+offsetY}, {(int)points[4].x+offsetX, (int)points[4].y+offsetY}, '*', Color::RED).Render();

        Line({(int)points[0].x+offsetX, (int)points[0].y+offsetY}, {(int)points[4].x+offsetX, (int)points[4].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[1].x+offsetX, (int)points[1].y+offsetY}, {(int)points[5].x+offsetX, (int)points[5].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[2].x+offsetX, (int)points[2].y+offsetY}, {(int)points[6].x+offsetX, (int)points[6].y+offsetY}, '*', Color::RED).Render();
        Line({(int)points[3].x+offsetX, (int)points[3].y+offsetY}, {(int)points[7].x+offsetX, (int)points[7].y+offsetY}, '*', Color::RED).Render();
        Rect({0, 0}, {WIDTH, HEIGHT}, '#', Color::BLUE).Render();
        std::string fpsLabel = "FPS: " + std::to_string(1/tui.GetFrameTime());
        Label(fpsLabel, {0, 0}, Color::RED).Render();


        tui.Render();
        tui.ReadKeys();
    }
    tui.Destroy();
}