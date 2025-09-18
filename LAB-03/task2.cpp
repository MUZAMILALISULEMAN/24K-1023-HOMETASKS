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

    void addToTail(string t, int c) {
    	
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

    void deleteFromFront() {
        if (headItem == nullptr) {
            cout << "CART IS EMPTY, NOTHING TO DELETE" << endl;
            return;
        }
        
        
        CartItem* temp = headItem;
        headItem = headItem->nextItem;
        delete temp;
        cout << "FRONT ITEM REMOVED" << endl;
    }

    void searchByName(string t) {
        CartItem* walker = headItem;
        
        while (walker != nullptr) {
            if (walker->itemTitle == t) {
                cout << t << " FOUND WITH PRICE $" << walker->itemCost << endl;
                return;
            }
            walker = walker->nextItem;
        }
        cout << t << " NOT PRESENT IN CART" << endl;
    }

    void searchByPosition(int pos) {
    	
        if (pos <= 0) {
         
		    cout << "INVALID POSITION" << endl;
            return;
        }
        CartItem* walker = headItem;
        int index = 1;
        while (walker != nullptr) {
            if (index == pos) {
                cout << "ITEM AT POSITION " << pos << ": " << walker->itemTitle << " - $" << walker->itemCost << endl;
                return;
                
            }
            walker = walker->nextItem;
            
            index++;
        }
        cout << "NO ITEM AT POSITION " << pos << endl;
    }

    void displayCart() {
    	
        if (headItem == nullptr) {
           
		    cout << "CART IS EMPTY" << endl;
            return;
        }
      
	       cout << "=== CURRENT CART CONTENT ===" << endl;
        CartItem* walker = headItem;
        while (walker != nullptr) 
		{
            cout << walker->itemTitle << " - $" << walker->itemCost << endl;
            walker = walker->nextItem;
        }
    }
};

int main() {
    OnlineCart cart;
    cart.addToTail("Laptop", 1000);
    cart.addToTail("Phone", 700);
    
    cart.addToTail("Tablet", 400);
   	 cart.addToTail("Headphones", 150);


    cart.displayCart();
    cart.deleteFromFront();
    cart.displayCart();

    cart.searchByName("Tablet");
    cart.searchByPosition(2);
    cart.searchByPosition(10);

    return 0;
}
