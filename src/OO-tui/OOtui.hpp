#pragma once
#include <vector>
#include <string>
#include "Renderable.hpp"

#define OO_TUI_KEY_ESC 27
#define OO_TUI_KEY_ENTER 10
#define OO_TUI_KEY_BACKSPACE 127
#define OO_TUI_KEY_TAB 9

enum Color
{
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

struct Vector2
{
    int x, y;
};

struct Pixel
{
    char character;
    Color color;
};

class OOtui
{
private:
    static OOtui *instance;
    OOtui();
    Pixel *buffer;
    int width, height;
    bool hasColors;
    bool keys[256];

    double startTime;
    double frameTime;
    int targetFPS;

public:
    static OOtui &GetInstance();

    /**
     * @brief Must be called before any other OOtui function.
     * 
     * @param width 
     * @param height 
     * 
     */
    void Init(int width, int height);
    
    /**
     * @brief Must be called at the end of the program to clean up buffers
     * 
     */
    void Destroy();

    /**
     * @brief Render current frame queue to screen
     * 
     */
    void Render();
    
    /**
     * @brief Check if a key is pressed
     * 
     * @param key to check
     * @return true if key is pressed
     */
    bool isPressed(int key) const;

    /**
    * 
    * @note should call ReadKeys() to update the pressed keys
    * 
    * @return true if the user pressed the escape key
    */
    bool shouldExit() const;

    /**
    * @brief Read the pressed keys 
    * 
    * @note Doesn't capture arrow keys
    * 
    */
    void ReadKeys();

    /**
     * 
     * @return Time in seconds since Init() was called
     */
    double GetTime() const;

    /**
     * @brief Set Pixel at position 
     * 
     * @param position Position of the pixel
     * @param pixel Char and color of the pixel
     * 
     * @return true if the pixel was set
     * 
     */
    bool PutPixel(Vector2 position, Pixel pixel);

    /**
     * @brief Return time in seconds from last Render() call
     * 
     * @return Frame time in seconds 
     */
    double GetFrameTime() const;

    /**
     * @brief Set the target FPS
     * 
     * @param fps 
     */
    void SetTargetFPS(int fps);


    int GetWidth() const;
    int GetHeight() const;

    ~OOtui();
};
