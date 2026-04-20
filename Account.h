#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    Account();
    Account(int accNo, string accName, double accBalance);

    void createAccount();
    void showAccount() const;
    void deposit(double amount);
    void withdraw(double amount);

    int getAccountNumber() const;
    double getBalance() const;
};

#endif