#include <iostream>
#include <stack>
using namespace std;

struct node {
    string webUrl;
    node* nextPtr;
    node(string urlVal) : webUrl(urlVal), nextPtr(NULL) {}
};

void insertAtFront(node*& listHead, string siteUrl) {
    node* newNode = new node(siteUrl);
        newNode->nextPtr = listHead;
    listHead = newNode;
}

void deleteFront(node*& listHead) {
        if (!listHead) return;
    node* tempPtr = listHead;
        listHead = listHead->nextPtr;
    delete tempPtr;
}

int main() {
    stack<string> browserHistory;
    node* headNode = NULL;
    
    string webSites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
        for (string site : webSites) {
            insertAtFront(headNode, site);
        browserHistory.push(site);
    }
    
        browserHistory.pop();
    deleteFront(headNode);
        browserHistory.pop();
    deleteFront(headNode);
    
    cout << "CURRENT PAGE: " << browserHistory.top() << endl;
        cout << "LINKED LIST FROM MOST RECENT:\n";
            for (node* current = headNode; current; current = current->nextPtr)
                cout << current->webUrl << " ";
    
    cout << endl;
        return 0;
}