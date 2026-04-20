#include <iostream>
#include <vector>
#include "Account.h"
using namespace std;

int findAccountIndex(const vector<Account>& accounts, int accNo) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNo) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<Account> accounts;
    int choice, accNo;
    double amount;

    do {
        cout << "\n======================================" << endl;
        cout << "         SMARTBANK PRO SYSTEM         " << endl;
        cout << "======================================" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Show All Accounts" << endl;
        cout << "3. Search Account by Number" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Account acc;
                acc.createAccount();
                accounts.push_back(acc);
                cout << "Account added successfully.\n";
                break;
            }

            case 2: {
                if (accounts.empty()) {
                    cout << "No accounts found.\n";
                } else {
                    for (const auto& acc : accounts) {
                        acc.showAccount();
                    }
                }
                break;
            }

            case 3: {
                cout << "Enter account number to search: ";
                cin >> accNo;

                int index = findAccountIndex(accounts, accNo);
                if (index == -1) {
                    cout << "Account not found.\n";
                } else {
                    accounts[index].showAccount();
                }
                break;
            }

            case 4: {
                cout << "Enter account number: ";
                cin >> accNo;

                int index = findAccountIndex(accounts, accNo);
                if (index == -1) {
                    cout << "Account not found.\n";
                } else {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[index].deposit(amount);
                }
                break;
            }

            case 5: {
                cout << "Enter account number: ";
                cin >> accNo;

                int index = findAccountIndex(accounts, accNo);
                if (index == -1) {
                    cout << "Account not found.\n";
                } else {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[index].withdraw(amount);
                }
                break;
            }

            case 6:
                cout << "Thank you for using SmartBank Pro.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}