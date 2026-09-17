#include "shapes.hh"

void Shape::setColor(const char *c){
    color = c;
}

Circle::Circle(int r){
    radius = r;
}

Triangle::Triangle(int b, int h){
    base = b; heigth = h;
}

float Circle::CalculateArea() {
    return 3.141516f * radius * radius;
}

float Triangle::CalculateArea() {
    return base * heigth/2; 
}

void Circle::Draw() {
    printf("Circle\n");
}

void Triangle::Draw() {
    printf("Draw\n");
}
