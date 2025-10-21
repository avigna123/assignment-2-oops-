#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual: forces derived classes to implement area()
    virtual float area() = 0;
    virtual ~Shape() {}  // virtual destructor for safe polymorphic deletion
};

class Circle : public Shape {
    float r;
public:
    // Constructor sets radius step-by-step
    Circle(float radius) {
        // Step 1: store radius
        r = radius;
    }
    float area() { return 3.14f * r * r; }
};

class Square : public Shape {
    float side;
public:
    // Constructor sets side length step-by-step
    Square(float s) {
        // Step 1: store side length
        side = s;
    }
    float area() { return side * side; }
};

int main() {
    Shape *s1 = new Circle(2);
    Shape *s2 = new Square(3);
    cout << "Circle Area: " << s1->area() << endl;
    cout << "Square Area: " << s2->area() << endl;
    delete s1;
    delete s2;
}
