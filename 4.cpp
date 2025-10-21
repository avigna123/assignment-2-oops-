#include <iostream>
using namespace std;

class Person {
protected:
    char name[20];
    int age;
public:
    // setPerson initializes fields step-by-step
    void setPerson(const char n[], int a) {
        // Step 1: copy characters of name
        int i = 0;
        while (n[i] && i < 19) { name[i] = n[i]; i++; }
        name[i] = '\0';
        // Step 2: set age
        age = a;
    }
    void showPerson() { cout << "Name: " << name << ", Age: " << age << endl; }
};

class Employee : public Person {
protected:
    int id;
public:
    // setEmployee uses setPerson then sets id
    void setEmployee(const char n[], int a, int i) {
        setPerson(n, a);   // reuse Person initialization
        id = i;            // set employee id
    }
    void showEmployee() {
        showPerson();
        cout << "ID: " << id << endl;
    }
};

class Manager : public Employee {
    char dept[20];
public:
    // setManager sets Person/Employee fields then department
    void setManager(const char n[], int a, int i, const char d[]) {
        setEmployee(n, a, i);   // init name, age, id
        int k = 0;
        while (d[k] && k < 19) { dept[k] = d[k]; k++; }
        dept[k] = '\0';
    }
    void showManager() {
        showEmployee();
        cout << "Department: " << dept << endl;
    }
};

int main() {
    Manager m;
    m.setManager("Alice", 35, 101, "IT");
    m.showManager();
}
