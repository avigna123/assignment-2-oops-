#include <iostream>
using namespace std;

class Sorter {
    int arr[10];   // storage for up to 10 elements
    int n;         // actual number of elements
public:
    // input copies values array into internal storage
    void input(int a[], int size) {
         n = size;
        for (int i = 0; i < n; i++) arr[i] = a[i];
    }

    // Bubble sort algorithm
    void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // display elements
    void display() {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int data[5] = {5, 2, 9, 1, 3};
    Sorter s;
    s.input(data, 5);
    cout << "Before: "; s.display();
    s.bubbleSort();
    cout << "After:  "; s.display();
}
