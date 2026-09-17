#ifndef SHAPES_HH
#define SHAPES_HH

#include <iostream>
#include <math.h>

class IDrawable
{
    public:
        virtual void Draw() = 0;
};

class Shape : public IDrawable {
    protected:
        const char* color;
    public:
        virtual void setColor(const char *c);
        virtual float CalculateArea() = 0;
};

class Circle : public Shape{
    int radius;
    public:
        Circle(int r);
        float CalculateArea() override;
        void Draw() override;
};

class Triangle : public Shape {
    int base, heigth;
    public:
        Triangle(int b,int h);        
        float CalculateArea() override;
        void Draw() override;
};

#endif