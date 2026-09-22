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

    Circle c1(3);
    Circle c2(3);

    Shape* pc1 = &c1;
    Shape* pc2 = &c2;

    if(pc1->compare_to(pc2))
    {
        printf("They are equal");
    }
    return 0;
}


