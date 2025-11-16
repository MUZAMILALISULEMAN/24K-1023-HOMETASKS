#include <iostream>
#include <stack>
using namespace std;

class callRecord {
    string callerName;
    int phoneNumber;
public:
    callRecord(string name = "", int num = 0) : callerName(name), phoneNumber(num) {}
    string getCallerName() const { return callerName; }
    int getPhoneNumber() const { return phoneNumber; }
};

int main() {
    stack<callRecord> callStack;
    int userChoice = 0;
    
    while (userChoice != -1) {
        cout << "\n1 TO ADD CALL\n2 TO SEE LAST CALL\n3 TO REMOVE LAST CALL\n4 TO CHECK IF EMPTY\n-1 TO EXIT\n";
        cin >> userChoice;
        
        switch (userChoice) {
            case 1: {
                string name;
                int num;
                    cout << "ENTER NAME OF CALLER: ";
                cin >> name;
                    cout << "ENTER NUMBER OF CALLER: ";
                cin >> num;
                callRecord newCall(name, num);
                    callStack.push(newCall);
                break;
            }
            case 2: {
                    if (!callStack.empty()) {
                        callRecord lastCall = callStack.top();
                        cout << "LAST CALL FROM: " << lastCall.getCallerName() << " (" << lastCall.getPhoneNumber() << ")\n";
                    } else cout << "NO CALLS IN STACK\n";
                break;
            }
            case 3: {
                if (!callStack.empty()) {
                    callStack.pop();
                        cout << "LAST CALL REMOVED\n";
                } else cout << "NO CALLS TO REMOVE\n";
                    break;
            }
            case 4: {
                    if (callStack.empty()) cout << "STACK IS EMPTY\n";
                else cout << "STACK IS NOT EMPTY\n";
                break;
            }
            case -1:
                cout << "EXITING...\n";
                break;
            default:
                cout << "INVALID INPUT\n";
        }
    }
    return 0;
}