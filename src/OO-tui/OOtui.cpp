#include "OOtui.hpp"
#include "cstdio"
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include <ncurses.h>

OOtui *OOtui::instance = nullptr;
OOtui::OOtui()
{
}
OOtui& OOtui::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new OOtui();
    }
    return *instance;
}
void OOtui::Destroy()
{
    if (instance != nullptr)
    {
        delete[] this->buffer;
        delete instance;
        endwin();
        instance = nullptr;
    }
}

void OOtui::Init(int width, int height) 
{
    this->width = width;
    this->height = height;
    this->buffer = new Pixel[width * height];
    this->startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0;
    this->targetFPS = 1000;

    // init colors
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    clear(); 
    refresh();

    #define COLOR_DEFAULT -1
    start_color();
    use_default_colors();
    init_pair(Color::BLACK, COLOR_BLACK, COLOR_DEFAULT);
    init_pair(Color::RED, COLOR_RED, COLOR_DEFAULT);
    init_pair(Color::GREEN, COLOR_GREEN, COLOR_DEFAULT);
    init_pair(Color::YELLOW, COLOR_YELLOW, COLOR_DEFAULT);
    init_pair(Color::BLUE, COLOR_BLUE, COLOR_DEFAULT);
    init_pair(Color::MAGENTA, COLOR_MAGENTA, COLOR_DEFAULT);
    init_pair(Color::CYAN, COLOR_CYAN, COLOR_DEFAULT);
    init_pair(Color::WHITE, COLOR_WHITE, COLOR_DEFAULT);


}

void OOtui::Render()
{
    double startTime = this->GetTime();

    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            auto& p = this->buffer[y * this->width + x];
            attron(COLOR_PAIR(p.color));
            mvaddch(y, x, p.character);
            attroff(COLOR_PAIR(p.color));
        }
    }
    refresh();
    static int sleepTime = std::max(0, (int)((1.0 / (double)this->targetFPS - (GetTime() - startTime))*1000000));
    usleep(sleepTime);

    this->frameTime = GetTime() - startTime;
}

OOtui::~OOtui()
{
}

bool OOtui::isPressed(int key) const
{
    return keys[key];
}


bool OOtui::shouldExit() const
{
    return keys[OO_TUI_KEY_ESC];
}


void OOtui::ReadKeys()
{
    std::memset(keys, 0, 256);
    int ch = getch();
    if(ch <256 && ch >= 0)
        keys[ch] = true;
    
    
}

double OOtui::GetTime() const
{
    //return time in seconds
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0 - this->startTime;    
}

bool OOtui::PutPixel(const Vector2 position,const Pixel pixel)
{
    if (position.x < 0 || position.x >= this->width || position.y < 0 || position.y >= this->height)
        return false;
    int index = position.y * this->width + position.x;
    this->buffer[index] = pixel;
    return true;
}

int OOtui::GetWidth() const
{
    return this->width;
}

int OOtui::GetHeight() const
{
    return this->height;
}

double OOtui::GetFrameTime() const
{
    return this->frameTime;
}

void OOtui::SetTargetFPS(int fps)
{
    this->targetFPS = fps;
}
