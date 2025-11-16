#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPrecedence(char operatorChar) {
    if (operatorChar == '^') return 3;
    if (operatorChar == '*' || operatorChar == '/') return 2;
        if (operatorChar == '+' || operatorChar == '-') return 1;
    return 0;
}

bool isRightAssoc(char opChar) {
        return opChar == '^';
}

string convertInfixToPostfix(string inputExpr) {
    stack<char> opStack;
    string postfixResult;
    
    for (char currentChar : inputExpr) {
            if (isalnum(currentChar)) postfixResult += currentChar;
        else if (currentChar == '(') opStack.push(currentChar);
            else if (currentChar == ')') {
                while (!opStack.empty() && opStack.top() != '(') {
                    postfixResult += opStack.top();
                        opStack.pop();
                }
                opStack.pop();
            } else {
                while (!opStack.empty() && getPrecedence(opStack.top()) > 0 &&
                      ((getPrecedence(currentChar) < getPrecedence(opStack.top())) ||
                       (getPrecedence(currentChar) == getPrecedence(opStack.top()) && !isRightAssoc(currentChar)))) {
                    postfixResult += opStack.top();
                        opStack.pop();
                }
                    opStack.push(currentChar);
            }
    }
    
    while (!opStack.empty()) {
            postfixResult += opStack.top();
        opStack.pop();
    }
        return postfixResult;
}

int main() {
    string testExpression = "a+b*(c^d-e)^(f+g*h)-i";
        cout << "POSTFIX RESULT: " << convertInfixToPostfix(testExpression);
    cout << endl;
        return 0;
}