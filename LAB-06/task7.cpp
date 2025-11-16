#include <iostream>
#include <queue>
using namespace std;

class patronInfo {
    string patronName;
public:
    patronInfo(string name = "") : patronName(name) {}
    string getPatronName() const { return patronName; }
};

int main() {
    queue<patronInfo> waitingLine;
    int userChoice = 0;
    
        while (userChoice != -1) {
            cout << "\n1 TO ADD PATRON\n2 TO SERVE PATRON\n3 TO SHOW QUEUE\n-1 TO EXIT\n";
        cin >> userChoice;
        
        switch (userChoice) {
            case 1: {
                    string name;
                cout << "ENTER PATRON NAME: ";
                    cin >> name;
                waitingLine.push(patronInfo(name));
                    break;
            }
            case 2: {
                if (!waitingLine.empty()) {
                        cout << "SERVING: " << waitingLine.front().getPatronName() << endl;
                    waitingLine.pop();
                } else cout << "NO PATRONS IN QUEUE\n";
                    break;
            }
            case 3: {
                    if (waitingLine.empty()) cout << "NO PATRONS WAITING\n";
                else {
                    queue<patronInfo> tempQueue = waitingLine;
                        cout << "CURRENT QUEUE:\n";
                    while (!tempQueue.empty()) {
                            cout << tempQueue.front().getPatronName() << endl;
                        tempQueue.pop();
                    }
                }
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