#include <iostream>
using namespace std;

struct node {
    int value;
    node* nextPtr;
};

void addToEnd(node*& listHead, int numVal) {
    node* freshNode = new node{numVal, nullptr};
        if (!listHead)
            listHead = freshNode;
    else {
            node* walker = listHead;
        while (walker->nextPtr)
                walker = walker->nextPtr;
            walker->nextPtr = freshNode;
    }
}

void showList(node* listHead) {
        while (listHead) {
            cout << listHead->value << " ";
                listHead = listHead->nextPtr;
    }
        cout << endl;
}

void exchange(node* first, node* second) {
        int tempVal = first->value;
    first->value = second->value;
        second->value = tempVal;
}

node* splitList(node* begin, node* finish) {
        if (begin == finish || !begin || !finish)
            return begin;
    node* pivotNode = finish;
        node* pivotIndex = begin;
    node* current = begin;
    
        while (current != finish) {
            if (current->value < pivotNode->value) {
                    exchange(current, pivotIndex);
                pivotIndex = pivotIndex->nextPtr;
            }
                current = current->nextPtr;
    }
        exchange(pivotIndex, pivotNode);
    return pivotIndex;
}

void quickSortHelper(node* startNode, node* endNode) {
        if (!startNode || startNode == endNode || startNode == endNode->nextPtr)
            return;
    
    node* pivotPos = splitList(startNode, endNode);
        node* tempWalker = startNode;
    
        while (tempWalker->nextPtr != pivotPos && tempWalker->nextPtr)
            tempWalker = tempWalker->nextPtr;
    
        if (tempWalker != pivotPos)
            quickSortHelper(startNode, tempWalker);
    
        quickSortHelper(pivotPos->nextPtr, endNode);
}

node* findLast(node* listHead) {
        while (listHead && listHead->nextPtr)
            listHead = listHead->nextPtr;
    return listHead;
}

void quickSortList(node*& listHead) {
        node* lastNode = findLast(listHead);
    quickSortHelper(listHead, lastNode);
}

int main() {
        node* headNode = nullptr;
    int inputData[] = {10, 7, 8, 9, 1, 5, 3};
        int total = 7;
    
        for (int i = 0; i < total; i++) {
            addToEnd(headNode, inputData[i]);
    }
    
    cout << "ORIGINAL LIST: ";
        showList(headNode);
    
    quickSortList(headNode);
    
        cout << "SORTED LIST: ";
    showList(headNode);
    
        return 0;
}