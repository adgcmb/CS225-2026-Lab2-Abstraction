#include <stdio.h>
#include <vector>
#include <iostream>
#include "shapes.cc"

int main() {

    Circle circle(5);
    Triangle triangle(2,6);

    Shape *shapeCircle = &circle;
    Shape *shapeTriangle = &triangle;
    shapeCircle->setColor("Blue");
    shapeTriangle->setColor("Red");
        
    std::vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&triangle);

    float totalArea = 0;
    for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
        Shape* shape = *it;
        totalArea += shape->CalculateArea();
        shape->Draw();
    }

    printf("Total area=%.2f\n", totalArea);
    return 0;
}


