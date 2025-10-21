#include <iostream>
using namespace std;

class SimpleList {
    int arr[100];   // storage array (fixed size to avoid extra headers)
    int size;       // tracks number of elements currently in list
public:
    // Constructor: initialize internal state
    SimpleList() {
        size = 0;
        
    }

    // Add an element to the end
    void add(int val) {
        if (size < 100)          // check space
            arr[size++] = val;   // place value then increment size
        else
            cout << "List full\n";
    }

    // Remove first matching element
    void remove(int val) {
        int pos = -1;
        // find position of val
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) { pos = i; break; }
        }
        // if found, shift elements left to overwrite
        if (pos != -1) {
            for (int i = pos; i < size - 1; i++)
                arr[i] = arr[i + 1];
            size--;               // reduce element count
        } else {
            cout << "Value not found\n";
        }
    }

    // Display elements
    void display() {
        cout << "List: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    // Return current size
    int getSize() { return size; }
};

int main() {
    SimpleList lst;
    lst.add(10);
    lst.add(20);
    lst.add(30);
    lst.display();
    lst.remove(20);
    lst.display();
    cout << "Size: " << lst.getSize() << endl;
}
