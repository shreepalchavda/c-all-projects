#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

protected:
    string accountNumber;
    string accountHolderName;

public:
    BankAccount(string accNo, string name, double bal)
        : accountNumber(accNo), accountHolderName(name), balance(bal) {}

    virtual ~BankAccount() {} 
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!" << endl;
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    virtual void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual double calculateInterest() {
        return 0.0; 
    }
};


class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    double calculateInterest() override {
        return getBalance() * interestRate;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << endl;
    }
};


class CheckingAccount : public BankAccount {
public:
    CheckingAccount(string accNo, string name, double bal)
        : BankAccount(accNo, name, bal) {}

    double calculateInterest() override {
        return 0.0;
    }
};


class FixedDeposit : public BankAccount {
private:
    double interestRate;

public:
    FixedDeposit(string accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    double calculateInterest() override {
        return getBalance() * interestRate;
    }
};


int main() {
    BankAccount* account = nullptr;
    int choice;

    cout << "Select Account Type:\n";
    cout << "1. Savings Account\n";
    cout << "2. Checking Account\n";
    cout << "3. Fixed Deposit Account\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
        account = new SavingsAccount("1001", "John Doe", 1000, 0.05);
    else if (choice == 2)
        account = new CheckingAccount("2001", "John Doe", 1000);
    else if (choice == 3)
        account = new FixedDeposit("3001", "John Doe", 5000, 0.08);
    else {
        cout << "Invalid choice!";
        return 0;
    }

    int option;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Info\n";
        cout << "4. Calculate Interest\n";
        cout << "5. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        if (option == 1) {
            double amount;
            cout << "Enter amount: ";
            cin >> amount;
            account->deposit(amount);
        }
        else if (option == 2) {
            double amount;
            cout << "Enter amount: ";
            cin >> amount;
            account->withdraw(amount);
        }
        else if (option == 3) {
            account->displayAccountInfo();
        }
        else if (option == 4) {
            cout << "Interest: " << account->calculateInterest() << endl;
        }

    } while (option != 5);

    delete account;
    return 0;
}