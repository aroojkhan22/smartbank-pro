#include "Account.h"

Account::Account() {
    accountNumber = 0;
    name = "";
    balance = 0.0;
}

Account::Account(int accNo, string accName, double accBalance) {
    accountNumber = accNo;
    name = accName;
    balance = accBalance;
}

void Account::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cin.ignore();

    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> balance;
}

void Account::showAccount() const {
    cout << "\n--- Account Details ---" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << endl;
}

void Account::deposit(double amount) {
    balance += amount;
    cout << "Deposit successful.\n";
}

void Account::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient balance.\n";
    } else {
        balance -= amount;
        cout << "Withdrawal successful.\n";
    }
}

int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}