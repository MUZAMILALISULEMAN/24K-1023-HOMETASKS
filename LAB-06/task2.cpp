#include <iostream>
#include <stack>
using namespace std;

int main() {
    string userInput;
        cout << "ENTER POSTFIX EXPRESSION (NO SPACES): ";
    cin >> userInput;
    
    stack<int> valueStack;
        for (int i = 0; i < userInput.length(); i++) {
            if (isdigit(userInput[i])) {
                valueStack.push(userInput[i] - '0');
            } else {
                int secondOperand = valueStack.top(); valueStack.pop();
                    int firstOperand = valueStack.top(); valueStack.pop();
                switch (userInput[i]) {
                    case '+': valueStack.push(firstOperand + secondOperand); break;
                        case '-': valueStack.push(firstOperand - secondOperand); break;
                    case '*': valueStack.push(firstOperand * secondOperand); break;
                    case '/': valueStack.push(firstOperand / secondOperand); break;
                }
            }
        }
    cout << "THE ANSWER IS: " << valueStack.top() << endl;
        return 0;
}