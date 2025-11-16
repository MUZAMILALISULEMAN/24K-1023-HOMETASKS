#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node {
    string playerName;
    int playerScore;
    node* nextPtr;
};

void addToEnd(node*& listHead, string nameVal, int scoreVal) {
    node* freshNode = new node{nameVal, scoreVal, NULL};
        if (!listHead) {
            listHead = freshNode;
        return;
    }
    node* walker = listHead;
        while (walker->nextPtr)
            walker = walker->nextPtr;
    walker->nextPtr = freshNode;
}

int findMaxScore(node* listHead) {
    int highest = listHead->playerScore;
        node* walker = listHead->nextPtr;
    while (walker) {
            if (walker->playerScore > highest)
                highest = walker->playerScore;
        walker = walker->nextPtr;
    }
    return highest;
}

void radixSortList(node*& listHead) {
        if (!listHead || !listHead->nextPtr)
            return;
    int maxScore = findMaxScore(listHead);
        for (int place = 1; maxScore / place > 0; place *= 10) {
            node* bucketHeads[10] = {NULL};
                node* bucketEnds[10] = {NULL};
            node* current = listHead;
                while (current) {
                    int digitVal = (current->playerScore / place) % 10;
                        node* savedNext = current->nextPtr;
                    current->nextPtr = NULL;
                        if (!bucketHeads[digitVal]) {
                            bucketHeads[digitVal] = current;
                        bucketEnds[digitVal] = current;
                    } else {
                            bucketEnds[digitVal]->nextPtr = current;
                        bucketEnds[digitVal] = current;
                    }
                    current = savedNext;
                }
            listHead = NULL;
                node* globalTail = NULL;
            for (int i = 0; i < 10; i++) {
                    if (bucketHeads[i]) {
                        if (!listHead) {
                                listHead = bucketHeads[i];
                            globalTail = bucketEnds[i];
                        } else {
                            globalTail->nextPtr = bucketHeads[i];
                                globalTail = bucketEnds[i];
                        }
                    }
            }
        }
}

void printRecords(node* listHead) {
        while (listHead) {
            cout << listHead->playerName << " - " << listHead->playerScore << endl;
                listHead = listHead->nextPtr;
        }
}

int main() {
        node* headNode = NULL;
    int totalStudents;
    
        cout << "HOW MANY STUDENTS DO YOU WANT TO ENTER? ";
    cin >> totalStudents;
    
    cout << "ENTER STUDENT NAME AND SCORE (0-100) FOR EACH:\n";
        for (int i = 0; i < totalStudents; i++) {
            string inputName;
            int inputScore;
                cout << "STUDENT " << (i + 1) << " NAME: ";
            cin >> inputName;
                cout << "STUDENT " << (i + 1) << " SCORE: ";
            cin >> inputScore;
                addToEnd(headNode, inputName, inputScore);
        }
    
    cout << "\nORIGINAL STUDENT RECORDS:\n";
        printRecords(headNode);
    
    radixSortList(headNode);
    
        cout << "\nSORTED STUDENT RECORDS (ASCENDING BY SCORE):\n";
    printRecords(headNode);
    
        return 0;
}