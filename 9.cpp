#include <iostream>
using namespace std;

class BankAccount {
    char name[20];
    float balance;
public:
    // Constructor: initialize name and balance 
    BankAccount(const char n[], float b) {
        int i = 0;
        while (n[i] && i < 19) { name[i] = n[i]; i++; }
        name[i] = '\0';
        if (b >= 0) balance = b;
        else balance = 0;  // prevent negative initial balance
    }

    // Deposit with simple validation
    void deposit(float amt) {
        if (amt > 0) balance += amt;
        else cout << "Invalid deposit\n";
    }

    // Withdraw with sufficient funds check
    void withdraw(float amt) {
        if (amt > balance) cout << "Insufficient funds\n";
        else balance -= amt;
    }

    // Display account details
    void display() { cout << "Name: " << name << ", Balance: " << balance << endl; }
};

int main() {
    BankAccount acc("John", 1000);
    acc.display();
    acc.deposit(500);
    acc.withdraw(200);
    acc.display();
}
