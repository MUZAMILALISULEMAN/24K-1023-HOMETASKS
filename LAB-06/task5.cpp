#include <iostream>
#include <stack>
using namespace std;

int main() {
    string userInput;
        cout << "ENTER YOUR INPUT: ";
    cin >> userInput;
    
    stack<int> calcStack;
        for(int i = userInput.length() - 1; i >= 0; i--) {
            if(isdigit(userInput[i])) calcStack.push(userInput[i] - '0');
        else {
                int firstNum = calcStack.top();
                    calcStack.pop();
                int secondNum = calcStack.top();
                    calcStack.pop();
            switch (userInput[i]) {
                case '+': calcStack.push(firstNum + secondNum); break;
                    case '-': calcStack.push(firstNum - secondNum); break;
                case '*': calcStack.push(firstNum * secondNum); break;
                    case '/': calcStack.push(firstNum / secondNum); break;
            }
        }
    }
        cout << "\nTHE ANSWER IS: " << calcStack.top();
    cout << endl;
        return 0;
}