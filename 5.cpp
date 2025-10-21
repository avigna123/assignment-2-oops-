#include <iostream>
using namespace std;

class Person {
public:
    char name[20];
    // setName copies characters one-by-one
    void setName(const char n[]) {
        int i = 0;
        while (n[i] && i < 19) { name[i] = n[i]; i++; }
        name[i] = '\0';
    }
    void show() { cout << "Name: " << name << endl; }
};

class Athlete {
public:
    char sport[20];
    // setSport copies characters one-by-one
    void setSport(const char s[]) {
        int i = 0;
        while (s[i] && i < 19) { sport[i] = s[i]; i++; }
        sport[i] = '\0';
    }
    void show() { cout << "Sport: " << sport << endl; }
};

class SportsPerson : public Person, public Athlete {
public:
    // display resolves ambiguous show() by specifying the base class
    void display() {
        Person::show();    // show name from Person
        Athlete::show();   // show sport from Athlete
    }
};

int main() {
    SportsPerson sp;
    sp.setName("Bob");
    sp.setSport("Cricket");
    sp.display();
}
