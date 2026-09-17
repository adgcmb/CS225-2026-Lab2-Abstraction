# CS225 Lab 2: Abstraction, Abstract Classes, and Interfaces

## Overview

This lab demonstrates the principles of **abstraction**, **abstract classes**, and **interfaces** in C++ through:
1. A **Shape hierarchy** showing polymorphism with abstract base classes

---

## Key Concepts

### 1. Abstract Classes
An abstract class is a class that contains at least one **pure virtual function** (a function declared with `= 0`). Abstract classes cannot be instantiated directly and must be inherited by concrete classes that implement the pure virtual methods.

### 2. Interfaces
In C++, an interface is typically modeled as an abstract class where **all methods are pure virtual**. Interfaces define a contract that derived classes must implement.

### 3. Polymorphism
The ability to use a base class pointer or reference to call derived class methods, enabling runtime method resolution.

---

## Project Structure

```
CS225-2026-Lab2-Abstraction/
├── main.cpp          # Entry point demonstrating shape polymorphism
├── shapes.hh         # Shape hierarchy declarations
└── shapes.cc         # Shape hierarchy implementations
```

---

## Shape Hierarchy: Abstract Classes & Interfaces

### Class Diagram
```
IDrawable (Interface)
    └── Shape (Abstract Class)
            ├── Circle
            └── Triangle
```

### Key Components

#### `IDrawable` Interface (shapes.hh:7-11)
```cpp
class IDrawable
{
    public:
        virtual void Draw() = 0;  // Pure virtual function
};
```
- Defines a **contract**: any class inheriting from `IDrawable` must implement `Draw()`
- Cannot be instantiated directly

#### `Shape` Abstract Class (shapes.hh:13-19)
```cpp
class Shape : public IDrawable {
    protected:
        const char* color;
    public:
        virtual void setColor(const char *c);
        virtual float CalculateArea() = 0;  // Pure virtual
};
```
- Inherits from `IDrawable`, so it **must** implement `Draw()` (or remain abstract)
- Contains its own pure virtual method: `CalculateArea()`
- Concrete classes inheriting from `Shape` must implement **both** `Draw()` and `CalculateArea()`

#### Concrete Classes: `Circle` and `Triangle`
Both implement the pure virtual methods from their parent classes:
- `CalculateArea()` — computes the geometric area
- `Draw()` — outputs the shape type

### Polymorphism in Action (main.cpp)
```cpp
Shape *shapeCircle = &circle;        // Circle treated as Shape
Shape *shapeTriangle = &triangle;     // Triangle treated as Shape

std::vector<Shape*> shapes;
shapes.push_back(&circle);
shapes.push_back(&triangle);

for (auto it = shapes.begin(); it != shapes.end(); it++) {
    Shape* shape = *it;
    totalArea += shape->CalculateArea();  // Calls appropriate derived method
    shape->Draw();                         // Calls appropriate derived method
}
```
- Base class pointers (`Shape*`) can point to derived objects
- The correct derived class method is called at runtime (dynamic dispatch)

---

## How to Run

### Compile
```bash
# Compile main.cpp with shapes
c++ main.cpp -o main

# Or compile separately
c++ -c shapes.cc -o shapes.o
c++ main.cpp shapes.o -o main
```

### Execute
```bash
./main
```

### Expected Output
```
Circle
Draw
Total area=XX.XX
```
(Where XX.XX is the sum of the circle's and triangle's areas)

---

## Learning Objectives

- Understand how to create **abstract classes** using pure virtual functions
- Implement and use **interfaces** in C++
- Apply **polymorphism** through base class pointers
- Recognize when to use **virtual destructors** (not shown here — see lab extensions)

---

## Lab Extensions (Try These!)

1. **Add More Shapes**: Create `Rectangle`, `Square` classes that inherit from `Shape`
2. **Fix the Bug**: The `Triangle::Draw()` method outputs "Draw" instead of "Triangle"
3. **Virtual Destructors**: Add virtual destructors to prevent memory leaks when deleting through base pointers
4. **Add Color Display**: Modify `Draw()` to include the shape's color

---

## Code Standards

- Use clear, descriptive names for classes and methods
- Always override virtual methods with the `override` keyword
- Keep interface classes focused on a single responsibility
- Document pure virtual methods to clarify their purpose for implementers

---

## References

- C++ Abstract Classes: [cppreference.com](https://en.cppreference.com/w/cpp/language/abstract_class)
- Polymorphism in C++: [GeeksforGeeks](https://www.geeksforgeeks.org/polymorphism-in-c/)
- Interfaces in C++: [LearnCpp.com](https://www.learncpp.com/)

---

*CS225 - Object-Oriented Programming, 2026*