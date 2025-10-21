#include <iostream>
using namespace std;

class Shape {
public:
    // Virtual base methods provide default behavior
    virtual float area() { return 0; }        // default area
    virtual float perimeter() { return 0; }   // default perimeter
};

class Rectangle : public Shape {
    float l, b;   // length and breadth
public:
    // Constructor: set dimensions step-by-step
    Rectangle(float x, float y) {
        // Step 1: assign length
        l = x;
        // Step 2: assign breadth
        b = y;
    }

    // Override area and perimeter
    float area() { return l * b; }
    float perimeter() { return 2 * (l + b); }
};

int main() {
    Rectangle r(4, 5);
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
}
