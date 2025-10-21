#include <iostream>
using namespace std;

class Math {
public:
    // Overloaded functions: compile-time selection by parameter types
    int add(int a, int b) {          // version for integers
        return a + b;
    }
    float add(float a, float b) {    // version for floats
        return a + b;
    }
};

class Base {
public:
    // virtual enables run-time polymorphism
    virtual void show() {
        cout << "Base class\n";
    }
};

class Derived : public Base {
public:
    // override base method to provide new behavior
    void show() {
        cout << "Derived class\n";
    }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;         // calls int version at compile time
    cout << m.add(2.5f, 3.5f) << endl;   // calls float version at compile time

    Base *b = new Derived();             // create derived object via base pointer
    b->show();                           // run-time: Derived::show called
    delete b;
}
