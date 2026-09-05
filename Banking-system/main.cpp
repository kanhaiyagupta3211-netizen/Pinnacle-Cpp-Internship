#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Transaction {
    string type;
    double amount;
    double balanceAfter;
};

class BankAccount {
private:
    int accountNumber;
    string holderName;
    int pin;
    double balance;
    vector<Transaction> history;

public:
    BankAccount(int accNo, string name, int userPin, double initialDeposit) {
        accountNumber = accNo;
        holderName = name;
        pin = userPin;
        balance = initialDeposit;
        history.push_back({"Initial Deposit", initialDeposit, balance});
    }

    int getAccountNumber() const { return accountNumber; }

    bool verifyPin(int enteredPin) const {
        return pin == enteredPin;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "\nError: Deposit amount must be greater than zero!" << endl;
            return;
        }
        balance += amount;
        history.push_back({"Deposit", amount, balance});
        cout << "\nSuccess: Deposited $" << fixed << setprecision(2) << amount << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "\nError: Withdrawal amount must be greater than zero!" << endl;
            return;
        }
        if (amount > balance) {
            cout << "\nError: Insufficient funds! Current Balance: $" << fixed << setprecision(2) << balance << endl;
            return;
        }
        balance -= amount;
        history.push_back({"Withdrawal", amount, balance});
        cout << "\nSuccess: Withdrawn $" << fixed << setprecision(2) << amount << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    void displayBalance() const {
        cout << "\n------------------------------------" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << holderName << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "------------------------------------" << endl;
    }

    void displayHistory() const {
        cout << "\n========== TRANSACTION HISTORY ==========" << endl;
        cout << left << setw(18) << "Type" << setw(12) << "Amount" << setw(12) << "Balance" << endl;
        cout << "-----------------------------------------" << endl;
        for (const auto& txn : history) {
            cout << left << setw(18) << txn.type 
                 << "$" << setw(11) << fixed << setprecision(2) << txn.amount 
                 << "$" << fixed << setprecision(2) << txn.balanceAfter << endl;
        }
        cout << "=========================================" << endl;
    }
};

int main() {
    vector<BankAccount> accounts;
    int nextAccNo = 1001;
    int choice;

    while (true) {
        cout << "\n======================================" << endl;
        cout << "          BANKING SYSTEM              " << endl;
        cout << "======================================" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. View Transaction History" << endl;
        cout << "6. Exit" << endl;
        cout << "Select an option (1-6): ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 6) {
            cout << "\nThank you for banking with us. Goodbye!" << endl;
            break;
        }

        if (choice == 1) {
            string name;
            int pin;
            double depositAmount;

            cout << "Enter account holder name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Create a 4-digit PIN: ";
            cin >> pin;
            cout << "Enter initial deposit amount: ";
            cin >> depositAmount;

            if (depositAmount < 0) {
                cout << "Error: Initial deposit cannot be negative." << endl;
                continue;
            }

            accounts.emplace_back(nextAccNo, name, pin, depositAmount);
            cout << "\nAccount successfully created!" << endl;
            cout << "Your Account Number is: " << nextAccNo << " (Keep it safe)" << endl;
            nextAccNo++;
        } else if (choice >= 2 && choice <= 5) {
            int accNo, pin;
            cout << "Enter Account Number: ";
            cin >> accNo;

            BankAccount* currentAcc = nullptr;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == accNo) {
                    currentAcc = &acc;
                    break;
                }
            }

            if (!currentAcc) {
                cout << "\nError: Account not found!" << endl;
                continue;
            }

            cout << "Enter your PIN: ";
            cin >> pin;
            if (!currentAcc->verifyPin(pin)) {
                cout << "\nError: Incorrect PIN! Access denied." << endl;
                continue;
            }

            if (choice == 2) {
                double amt;
                cout << "Enter deposit amount: ";
                cin >> amt;
                currentAcc->deposit(amt);
            } else if (choice == 3) {
                double amt;
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                currentAcc->withdraw(amt);
            } else if (choice == 4) {
                currentAcc->displayBalance();
            } else if (choice == 5) {
                currentAcc->displayHistory();
            }
        } else {
            cout << "Invalid choice! Please select between 1 and 6." << endl;
        }
    }

    return 0;
}