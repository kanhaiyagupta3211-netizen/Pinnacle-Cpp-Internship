#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n==============================\n";
    cout << "       BASIC CALCULATOR\n";
    cout << "==============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exit\n";
    cout << "==============================\n";
}

int main() {

    int choice;
    double num1, num2;

    cout << "Welcome to Basic Calculator!\n";

    while (true) {

        showMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            cout << "\nThank you for using the calculator!\n";
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "\nInvalid choice! Please try again.\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {

            case 1:
                cout << "\nResult = " << num1 + num2 << endl;
                break;

            case 2:
                cout << "\nResult = " << num1 - num2 << endl;
                break;

            case 3:
                cout << "\nResult = " << num1 * num2 << endl;
                break;

            case 4:
                if (num2 == 0) {
                    cout << "\nError: Division by zero is not allowed.\n";
                } else {
                    cout << "\nResult = " << num1 / num2 << endl;
                }
                break;

            case 5:
                cout << "\nModulus works with integers only.\n";

                {
                    int a = static_cast<int>(num1);
                    int b = static_cast<int>(num2);

                    if (b == 0) {
                        cout << "Error: Modulus by zero is not allowed.\n";
                    } else {
                        cout << "Result = " << a % b << endl;
                    }
                }
                break;
        }
    }

    return 0;
}