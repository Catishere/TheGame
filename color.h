#ifndef COLOR_H
#define COLOR_H


class Color
{
    float red;
    float green;
    float blue;
public:
    Color();
    Color(float red, float green, float blue);
    float getBlue() const;
    void setBlue(float value);
    float getGreen() const;
    void setGreen(float value);
    float getRed() const;
    void setRed(float value);
};

#endif // COLOR_H
