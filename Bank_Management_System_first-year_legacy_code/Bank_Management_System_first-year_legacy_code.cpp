#include <iostream> 
#include <string> 
using namespace std;


int main() {
    double checkingBalance, savingBalance, amount;
    string transactionType, accountType;

    cout << "Enter initial checking account balance: ";
    cin >> checkingBalance;

    while (checkingBalance < 0) {
        cout << "Please enter a positive amount!\n";
        cin >> checkingBalance;
    }

    cout << "Enter initial saving account balance: ";
    cin >> savingBalance;

    while (savingBalance < 0) {
        cout << "Please enter a positive amount!\n";
        cin >> savingBalance;
    }

    while (true) {
        cout << "Transaction type (d: deposit, w: withdrawal, t: transfer, q: quit): ";
        cin >> transactionType;

        if (transactionType == "q") break;

        cout << "Account type (c: checking, s: saving): ";
        cin >> accountType;
        cout << "Enter transaction amount: ";
        cin >> amount;

        if (transactionType == "d") {
            if (accountType == "c") checkingBalance += amount;
            else if (accountType == "s") savingBalance += amount;
        }
        else if (transactionType == "w") {
            if (accountType == "c") checkingBalance -= amount;
            else if (accountType == "s") savingBalance -= amount;
        }

        else if (transactionType == "t") {
            if (accountType == "c") {
                checkingBalance -= amount;
                savingBalance += amount;
            }
            else if (accountType == "s") {
                savingBalance -= amount;
                checkingBalance += amount;
            }
        }
    }

    cout << "Final Checking Balance: " << checkingBalance << "\n";
    cout << "Final Saving Balance: " << savingBalance << "\n";


    return 0;
}