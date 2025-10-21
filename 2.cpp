#include <iostream>
using namespace std;

class SimpleMap {
    char keys[10][20];    // up to 10 keys, each max 19 chars + null
    char values[10][20];  // corresponding values
    int count;            // number of stored pairs
public:
    // Constructor: initialize count
    SimpleMap() {
        count = 0;
    }

    // Insert key-value pair
    void insert(const char key[], const char value[]) {
        // copy key into keys[count]
        int i = 0;
        while (key[i] && i < 19) { keys[count][i] = key[i]; i++; }
        keys[count][i] = '\0';
        // copy value into values[count]
        i = 0;
        while (value[i] && i < 19) { values[count][i] = value[i]; i++; }
        values[count][i] = '\0';
        count++;  // update pair count
    }

    // Search for key and print corresponding value
    void search(const char key[]) {
        for (int i = 0; i < count; i++) {
            int j = 0;
            // compare characters
            while (keys[i][j] == key[j] && key[j] != '\0') j++;
            if (key[j] == '\0') { // match found
                cout << "Value: " << values[i] << endl;
                return;
            }
        }
        cout << "Key not found\n";
    }

    // Display all key-value pairs
    void display() {
        for (int i = 0; i < count; i++)
            cout << keys[i] << " : " << values[i] << endl;
    }
};

int main() {
    SimpleMap dict;
    dict.insert("apple", "fruit");
    dict.insert("car", "vehicle");
    dict.display();
    dict.search("apple");
}
