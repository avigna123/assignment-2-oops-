#include <iostream>
using namespace std;

class Sports;  // forward declaration for friend

class Student {
    int marks;
public:
    // constructor sets marks 
    Student(int m) {
        marks = m;
    }
    friend void total(Student, Sports);  // friend declaration
};

class Sports {
    int score;
public:
    // constructor sets score
    Sports(int s) {
        score = s;
    }
    friend void total(Student, Sports);
};

// friend function can access private members of both classes
void total(Student st, Sports sp) {
    cout << "Total = " << (st.marks + sp.score) << endl;
}

int main() {
    Student s(80);
    Sports sp(15);
    total(s, sp);
}
