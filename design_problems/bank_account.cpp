#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(const string& name, double initialBalance = 0.0) {
        accountHolder = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
		balance += amount;
    }

    // Withdraw money
    bool withdraw(double amount) {
        if((balance - amount) < 0) {
			return false;
		}
		balance -= amount;
		return true;
    }

    // Check balance
    double getBalance() const {
        return balance;
    }

    // Optional: Print account info
    void printAccount() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account("John Doe", 100.0);

    account.printAccount();

    account.deposit(50.0);
    cout << "After deposit of $50:" << endl;
    account.printAccount();

    if(account.withdraw(30.0)) {
        cout << "Withdrawal of $30 successful." << endl;
    } else {
        cout << "Withdrawal failed: insufficient funds." << endl;
    }
    account.printAccount();

    if(account.withdraw(150.0)) {
        cout << "Withdrawal of $150 successful." << endl;
    } else {
        cout << "Withdrawal failed: insufficient funds." << endl;
    }
    account.printAccount();

    return 0;
}
