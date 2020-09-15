#include "color.h"

float Color::getBlue() const
{
    return blue;
}

void Color::setBlue(float value)
{
    blue = value;
}

float Color::getGreen() const
{
    return green;
}

void Color::setGreen(float value)
{
    green = value;
}

float Color::getRed() const
{
    return red;
}

void Color::setRed(float value)
{
    red = value;
}

Color::Color()
{

}

Color::Color(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}
