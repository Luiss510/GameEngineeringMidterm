#ifndef BASICSTRUCTS_H
#define BASICSTRUCTS_H

#ifdef _WIN32
#include <Windows.h>
#else
typedef unsigned char byte;
#endif

struct Color
{
    Color(byte _r, byte _g, byte _b, byte _a)
    {
        R = _r;
        G = _g;
        B = _b;
        A = _a;
    }

    byte R;
    byte G;
    byte B;
    byte A;
};

struct Point
{
    Point(unsigned int _x, unsigned int _y)
    {
        X = _x;
        Y = _y;
    }

    unsigned int X;
    unsigned int Y;
};

struct Rect
{
    Rect(unsigned int _x1, unsigned int _y1, unsigned int _x2, unsigned int _y2)
    {
        X1 = _x1;
        Y1 = _y1;
        X2 = _x2;
        Y2 = _y2;
    }

    unsigned int X1;
    unsigned int Y1;
    unsigned int X2;
    unsigned int Y2;
};

#endif // BASICSTRUCTS_H
