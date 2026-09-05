#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


string decimalToBinary(long long n) {
    if (n == 0) return "0";
    bool isNegative = n < 0;
    if (isNegative) n = -n;

    string binary = "";
    while (n > 0) {
        binary += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    if (isNegative) binary += "-";
    reverse(binary.begin(), binary.end());
    return binary;
}

string decimalToHex(long long n) {
    if (n == 0) return "0";
    stringstream ss;
    ss << hex << uppercase << n;
    return ss.str();
}


void binaryToDecimal() {
    string bin;
    cout << "Enter binary number: ";
    cin >> bin;
    try {
        size_t idx;
        long long dec = stoll(bin, &idx, 2);
        if (idx != bin.length()) throw invalid_argument("");
        cout << "Decimal: " << dec << endl;
        cout << "Hexadecimal: " << decimalToHex(dec) << endl;
    } catch (...) {
        cout << "Error: Invalid binary string!" << endl;
    }
}


void hexToDecimal() {
    string hexStr;
    cout << "Enter hexadecimal number: ";
    cin >> hexStr;
    try {
        size_t idx;
        long long dec = stoll(hexStr, &idx, 16);
        if (idx != hexStr.length()) throw invalid_argument("");
        cout << "Decimal: " << dec << endl;
        cout << "Binary: " << decimalToBinary(dec) << endl;
    } catch (...) {
        cout << "Error: Invalid hexadecimal string!" << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n================================" << endl;
        cout << "       NUMBER CONVERTER         " << endl;
        cout << "================================" << endl;
        cout << "1. Decimal to Binary & Hexadecimal" << endl;
        cout << "2. Binary to Decimal & Hexadecimal" << endl;
        cout << "3. Hexadecimal to Decimal & Binary" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option (1-4): ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a valid choice." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 4) {
            cout << "Exiting Number Converter. Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1: {
                long long dec;
                cout << "Enter decimal number: ";
                if (cin >> dec) {
                    cout << "Binary: " << decimalToBinary(dec) << endl;
                    cout << "Hexadecimal: " << decimalToHex(dec) << endl;
                } else {
                    cout << "Error: Invalid decimal number!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                break;
            }
            case 2:
                binaryToDecimal();
                break;
            case 3:
                hexToDecimal();
                break;
            default:
                cout << "Please select an option between 1 and 4." << endl;
        }
    }
    return 0;
}