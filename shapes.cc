#include "shapes.hh"

void Shape::setColor(const char *c){
    color = c;
}

Circle::Circle(int r){
    radius = r;
}

Triangle::Triangle(int b, int h){
    base = b; 
    heigth = h;
}

Rectangle::Rectangle(int b,int h)
{
    base = b;
    heigth = h;
}

float Circle::CalculateArea() {
    return 3.141516f * radius * radius;
}

float Triangle::CalculateArea() {
    return base * heigth/2; 
}

float Rectangle::CalculateArea()
{
    return base * heigth;
}

void Circle::Draw() {
    printf("Draw Circle\n");
}

void Triangle::Draw() {
    printf("Draw Triangle\n");
}

void Rectangle::Draw()
{
    printf("Draw Rectangle\n");
}

float Circle::CalculatePerimeter()
{
    return 2 * 3.141516f * radius;
}

float Triangle::CalculatePerimeter()
{
    float hypotenuse = sqrt(base * base + heigth * heigth);
    return base + heigth + hypotenuse;
}

float Rectangle::CalculatePerimeter()
{
    return 2 * (base + heigth);
}

void Circle::Scale(float scaFactor) {
    radius = radius * scaFactor;
}

void Triangle::Scale(float scaFactor) {
    base = base * scaFactor;
    heigth = heigth * scaFactor;
}

void Rectangle::Scale(float scaFactor) {
    base = base * scaFactor;
    heigth = heigth * scaFactor;
}

bool Circle::compare_to(IComparable* other)
{
    Circle* otherCircle = (Circle*) other;
    return otherCircle->radius == radius;
}

bool Triangle::compare_to(IComparable* other)
{
    Triangle* otherTriangle = (Triangle*) other;
    return (otherTriangle->base == base && otherTriangle->heigth == heigth);
}

bool Rectangle::compare_to(IComparable* other)
{
    Rectangle* otherRectangle = (Rectangle*) other;
    return (otherRectangle->base == base && otherRectangle->heigth == heigth);
}