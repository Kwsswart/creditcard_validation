#include <iostream>
#include <string>

using namespace std;

/**
 *  This program is using the Luhn Algorithm: https://en.wikipedia.org/wiki/Luhn_algorithm to validate a Credit Card Number
 * 
 *  Steps:
 *      1) Double every second digit, starting from the right. 
 *      2) If this results in double digit number, add both the digits to obtain single digit number.
 *      3) Sum all the numbers and store value into a variable: 'resultSum' ''.
 *      4) Add every odd placed digit from the right to the value 'resultSum'
 *      5) Check if the final 'resultSum' is a multiple of 10. If yes Credit Card Number is Valid else Not.
*/

bool isNumberString(const string& s) {
    /// Determin whether every char in string in a Number
    int len = s.length();
    for (int i=0; i<len; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    string creditCardNumber;

    cout << "This uses the Luhn Algorithm: https://en.wikipedia.org/wiki/Luhn_algorithm to validate a Credit Card Number"<< endl;
    cout << "Enter 'exit' anytime to quit" << endl;

    while (true) {

        cout << "Please enter a credit card number to validate: ";
        cin >> creditCardNumber;

        if (creditCardNumber == "exit") {
            break;
        } 
        else if (!isNumberString(creditCardNumber)) {
            cout << "Invalid Input!" << endl;
            continue;
        }

        int len = creditCardNumber.length();
        int resultSum = 0;

        for (int i = len-2; i >= 0; i -= 2) {
            // convert string to the int and double it.
            int dbl = ((creditCardNumber[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            resultSum += dbl;
        }

        for (int i = len-1; i>=0; i-=2) {
            // convert string to the int.
            resultSum += (creditCardNumber[i] - 48);
        }
        
        cout << (resultSum % 10 == 0 ? "Valid Input!": "Invalid Input!") << endl;

        continue;
    }
    return 0;
}