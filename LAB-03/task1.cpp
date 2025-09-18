#include <iostream>
#include <string>
using namespace std;

class CartItem {
public:
	
	
    string itemTitle;
    int itemCost;
    CartItem* nextItem;

    CartItem(string t, int c) : itemTitle(t), itemCost(c), nextItem(nullptr) {}
};

class OnlineCart {
private:
	
    CartItem* headItem;

public:
    OnlineCart() : headItem(nullptr) {}

    void addToFront(string t, int c) {
        CartItem* freshItem = new CartItem(t, c);
        freshItem->nextItem = headItem;
        headItem = freshItem;
    }

    void addToEnd(string t, int c) {
        CartItem* freshItem = new CartItem(t, c);
        if (headItem == nullptr) {
            headItem = freshItem;
            return;
        }
        
        CartItem* walker = headItem;
        while (walker->nextItem != nullptr) {
            walker = walker->nextItem;
        }
        walker->nextItem = freshItem;
    }

    void insertAfter(string target, string t, int c) {
        CartItem* walker = headItem;
        while (walker != nullptr) {
            if (walker->itemTitle == target) {
                CartItem* freshItem = new CartItem(t, c);
                freshItem->nextItem = walker->nextItem;
                walker->nextItem = freshItem;
                return;
                
            }
            walker = walker->nextItem;
        }
    }

    void searchItem(string t) {
        CartItem* walker = headItem;
        while (walker != nullptr) {
            if (walker->itemTitle == t) {
                cout << t << " IS AVAILABLE WITH PRICE $" << walker->itemCost << endl;
                return;
            }
            walker = walker->nextItem;
        }
        cout << t << " IS NOT IN THE CART" << endl;
    }

    void showCart() {
        cout << "=== ONLINE SHOPPING CART ===" << endl;
        CartItem* walker = headItem;
        while (walker != nullptr) {
            cout << walker->itemTitle << " - $" << walker->itemCost << endl;
            walker = walker->nextItem;
        }
    }
};

int main() {
    OnlineCart cart;
    cart.addToEnd("Laptop", 1000);
    cart.addToEnd("Phone", 700);
    cart.addToEnd("Tablet", 400);
    cart.addToEnd("Headphones", 150);
    

    cart.addToFront("Smartwatch", 200);
    
    cart.addToEnd("Keyboard", 80);
    cart.insertAfter("Phone", "Monitor", 300);

    cart.searchItem("Tablet");
    cart.showCart();

    return 0;
}

