#include <iostream>
#include <string>
using namespace std;

class CartNode {
public:
    int itemId;
    string itemName;
    float itemPrice;
    CartNode* nextNode;
    CartNode* prevNode;

    CartNode(int id, string name, float price) {
        itemId = id;
        itemName = name;
        itemPrice = price;
        nextNode = nullptr;
        
        prevNode = nullptr;
    }
};

class CartList {
private:
    CartNode* headNode;
    CartNode* tailNode;

public:
    CartList() {
        headNode = nullptr;
        tailNode = nullptr;
    }

    void insertAtEnd(int id, string name, float price) {
        CartNode* fresh = new CartNode(id, name, price);
        if (tailNode == nullptr) {
            headNode = tailNode = fresh;
            
            
        } else {
            tailNode->nextNode = fresh;
            fresh->prevNode = tailNode;
            
            tailNode = fresh;
        }
        cout << "ITEM ADDED AT END" << endl;
    }

    void insertAtFront(int id, string name, float price) {
        CartNode* fresh = new CartNode(id, name, price);
        if (headNode == nullptr) {
            headNode = tailNode = fresh;
        } else {
            fresh->nextNode = headNode;
            headNode->prevNode = fresh;
            headNode = fresh;
        }
        cout << "ITEM ADDED AT FRONT" << endl;
    }



    void removeFront() {
        if (headNode == nullptr) {
            cout << "CART IS EMPTY" << endl;
            return;
        }
        CartNode* temp = headNode;
        headNode = headNode->nextNode;
        if (headNode != nullptr) {
            headNode->prevNode = nullptr;
        } else {
            tailNode = nullptr;
        }
        delete temp;
        cout << "FIRST ITEM REMOVED" << endl;
    }

    void removeEnd() {
        if (tailNode == nullptr) {
            cout << "CART IS EMPTY" << endl;
            return;
        }
        CartNode* temp = tailNode;
        tailNode = tailNode->prevNode;
        if (tailNode != nullptr) {
            tailNode->nextNode = nullptr;
        } else {
            headNode = nullptr;
        }
        delete temp;
        cout << "LAST ITEM REMOVED" << endl;
    }

    void searchById(int id) {
        CartNode* walk = headNode;
        while (walk != nullptr) {
            if (walk->itemId == id) {
            	
                cout << "ITEM FOUND: ID=" << walk->itemId 
                     << ", NAME=" << walk->itemName 
                     
                     << ", PRICE=$" << walk->itemPrice << endl;
                return;
            }
            walk = walk->nextNode;
        }
        cout << "ITEM NOT FOUND" << endl;
    }

    void updatePrice(int id, float newPrice) {
        CartNode* walk = headNode;
        while (walk != nullptr) {
            if (walk->itemId == id) {
                walk->itemPrice = newPrice;
                
                cout << "PRICE UPDATED FOR ITEM ID " << id << endl;
                
                return;
            }
            walk = walk->nextNode;
            
        }
        cout << "ITEM NOT FOUND" << endl;
    }

    void displayForward() {
        if (headNode == nullptr) {
            cout << "CART IS EMPTY" << endl;
            return;
        }
        cout << "CART (FRONT TO END):" << endl;
        CartNode* walk = headNode;
        while (walk != nullptr) {
            cout << "[ID=" << walk->itemId 
                 << ", NAME=" << walk->itemName 
                 << ", PRICE=$" << walk->itemPrice << "]" << endl;
            walk = walk->nextNode;
        }
    }

    void displayBackward() {
        if (tailNode == nullptr) {
            cout << "CART IS EMPTY" << endl;
            return;
        }
        cout << "CART (END TO FRONT):" << endl;
        CartNode* walk = tailNode;
        while (walk != nullptr) {
            cout << "[ID=" << walk->itemId 
                 << ", NAME=" << walk->itemName 
                 << ", PRICE=$" << walk->itemPrice << "]" << endl;
            walk = walk->prevNode;
        }
    }

    int countItems() {
        int cnt = 0;
        CartNode* walk = headNode;
        while (walk != nullptr) {
            cnt++;
            walk = walk->nextNode;
        }
        return cnt;
    }

    void mostExpensive() {
        if (headNode == nullptr) {
            cout << "CART IS EMPTY" << endl;
            return;
        }
        CartNode* walk = headNode;
        CartNode* mx = headNode;
        while (walk != nullptr) {
            if (walk->itemPrice > mx->itemPrice) {
                mx = walk;
            }
            walk = walk->nextNode;
        }
        cout << "MOST EXPENSIVE ITEM: ID=" << mx->itemId 
             << ", NAME=" << mx->itemName 
             << ", PRICE=$" << mx->itemPrice << endl;
    }
};

int main() {
    CartList cart;
   
    cart.insertAtEnd(1, "Laptop", 1000);
    
	cart.insertAtEnd(2, "Phone", 700); 
    
    cart.insertAtFront(3, "Tablet", 400);
    cart.insertAtEnd(4, "Headphones", 150);
    cart.displayForward();
    cart.removeFront();
    cart.removeEnd();
    
    cart.displayBackward();
    
    cart.searchById(2);
    cart.updatePrice(2, 750);
    cout << "TOTAL ITEMS: " << cart.countItems() << endl;
    
    
    cart.mostExpensive();
    return 0;
}
