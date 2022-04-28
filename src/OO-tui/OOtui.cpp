#include "OOtui.hpp"
#include "cstdio"
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <chrono>

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
        std::printf("\033[?25h"); // re-enable cursor
        std::printf("\033[0;0H\033[2J"); // clear screen
        instance = nullptr;
    }
}

void OOtui::Init(int width, int height)
{
    this->width = width;
    this->height = height;
    this->buffer = new Pixel[width * height];
    this->startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0;
    std::printf("\033[?25l"); // hide cursor
    std::printf("\033[0;0H\033[2J"); // clear screen
    system("stty -icanon -echo"); // disable terminal echo

    setvbuf(stdout, NULL, _IOFBF, 8*width*height); // enable stdout buffering
}

void OOtui::Render()
{
    // calculate frame time
    static double lastTime = 0;
    double currentTime = this->GetTime();
    this->frameTime = currentTime - lastTime;
    lastTime = currentTime;


    for (auto &&r : this->renderQueue)
        r->Render();
    this->renderQueue.clear();

    std::printf("\033[0;0H\033"); // move cursor to top left
    for (int y = 0; y < this->height; y++)
    {
        for (int x = 0; x < this->width; x++)
        {
            auto& p = this->buffer[y * this->width + x];
            std::printf("\033[3%dm%c", p.color, p.character);
        }
        std::printf("\n");
    }
    std::fflush(stdout);

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
    char buf[4] = {0};
    fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
    int numRead = read(0, buf, 4);
    for (int i = 0; i < numRead; i++)
    {
        keys[(int)buf[i]] = true;
    }
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

void OOtui::AddToRenderQueue(Renderable *r)
{
    this->renderQueue.push_back(r);
}

double OOtui::GetFrameTime() const
{
    return this->frameTime;
}