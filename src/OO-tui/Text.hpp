#include "Pixelable.hpp"

/**
 * @brief Text class for rendering 8x8 bitmap font
 * @sa Label
 * 
 */
class Text : public Pixelable
{
private:
    std::string text;
public:
    Text(std::string text, Vector2 position);
    Text(std::string text, Vector2 position, Color color);
    Text(std::string text, Vector2 position, char character);
    Text(std::string text, Vector2 position, char character, Color color);

    virtual ~Text();
    virtual void Render() const;
    void SetText(std::string text);
    std::string GetText() const;
};

