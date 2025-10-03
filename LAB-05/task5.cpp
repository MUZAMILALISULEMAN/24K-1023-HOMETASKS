 	#include<iostream>
using namespace std;

class DigitCalculator {
    int number;

public:
    DigitCalculator() {
        number = 0;
    }

    void setNumber(int num) {
        number = num;
    }

    int calculateDigitSum(int value) {
        if(value == 0) {
            return 0;
        }
        return (value % 10) + calculateDigitSum(value / 10);
    }

    int findFinalDigit(int value) {
        if(value < 10) {
            return value;
        }
        int currentSum = calculateDigitSum(value);
        return findFinalDigit(currentSum);
    }

    void displayResult() {
        int result = findFinalDigit(number);
        cout << "FINAL DIGIT IS: " << result << endl;
    }
};

int main() {
    DigitCalculator calculator;
    int inputNumber;
    
    cout << "ENTER A NUMBER: ";
    cin >> inputNumber;
    
    calculator.setNumber(inputNumber);
    calculator.displayResult();

    return 0;
}