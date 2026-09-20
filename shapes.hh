#ifndef SHAPES_HH
#define SHAPES_HH

#include <iostream>
#include <math.h>

class IScale
{
    public:
        virtual Scale(float scaFactor) = 0;
};

class IDrawable
{
    public:
        virtual void Draw() = 0;
};

class Shape : public IDrawable, public IScale {
    protected:
        const char* color;
    public:
        virtual void setColor(const char *c);
        virtual float CalculateArea() = 0
        virtual float CalculatePerimeter() = 0;

};

class Circle : public Shape{
    int radius;
    public:
        Circle(int r);
        float CalculateArea() override;
        void Draw() override;
        float CalculatePerimeter() override;
        void Scale(float scaFactor) override;
};

class Triangle : public Shape {
    int base, heigth;
    public:
        Triangle(int b,int h);        
        float CalculateArea() override;
        void Draw() override;
        float CalculatePerimeter() override;
        void Scale(float scaFactor) override;
};

class Rectangle : public Shape {
    int base, heigth;
    public:
        Rectangle(int b,int h);        
        float CalculateArea() override;
        void Draw() override;
        float CalculatePerimeter() override;
        void Scale(float scaFactor) override;
};

#endif