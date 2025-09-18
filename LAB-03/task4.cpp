#include <iostream>
#include <string>
using namespace std;

class TicketNode {
public:
    int ticketId;
    string customerName;
    string rideName;
    TicketNode* nextNode;

    TicketNode(int id, string cname, string rname) {
        ticketId = id;
        customerName = cname;
        rideName = rname;
        nextNode = nullptr;
    }
};

class TicketCircle {
private:
    TicketNode* tailNode;

public:
    TicketCircle() {
        tailNode = nullptr;
    }

    void issueAtEnd(int id, string cname, string rname) {
        TicketNode* fresh = new TicketNode(id, cname, rname);
        if (tailNode == nullptr) {
            tailNode = fresh;
            fresh->nextNode = fresh;
        } else {
            fresh->nextNode = tailNode->nextNode;
            tailNode->nextNode = fresh;
            tailNode = fresh;
        }
        cout << "TICKET ISSUED AT END" << endl;
    }

    void issueAtFront(int id, string cname, string rname) {
        TicketNode* fresh = new TicketNode(id, cname, rname);
        if (tailNode == nullptr) {
        	
            tailNode = fresh;
            fresh->nextNode = fresh;
            
        } else {
            fresh->nextNode = tailNode->nextNode;
            tailNode->nextNode = fresh;
        }
        cout << "PRIORITY TICKET ISSUED AT FRONT" << endl;
    }


    		void cancelById(int id) {
        if (tailNode == nullptr) {
            cout << "NO TICKETS BOOKED" << endl;
            return;
        }
        TicketNode* curr = tailNode->nextNode;
        TicketNode* prev = tailNode;
        do {
            if (curr->ticketId == id)
			 {
                if (curr == tailNode && curr == tailNode->nextNode) {
                    delete curr;
                    tailNode = nullptr;
                } else {
                    prev->nextNode = curr->nextNode;
                    if (curr == tailNode) tailNode = prev;
                    delete curr;
                }
                
                cout << "TICKET ID " << id << " CANCELLED" << endl;
                return;
            }
            prev = curr;
            curr = curr->nextNode;
        } while (curr != tailNode->nextNode);
        cout << "TICKET NOT FOUND" << endl;
    }

    void cancelFirst() {
        if (tailNode == nullptr) {
            cout << "NO TICKETS BOOKED" << endl;
            return;
        }
        TicketNode* first = tailNode->nextNode;
        
        if (first == tailNode) {
        	
        	
            delete first;
            tailNode = nullptr;
        } else {
            tailNode->nextNode = first->nextNode;
            delete first;
        }
        cout << "FIRST TICKET CANCELLED" << endl;
    }

    void searchById(int id) {
        if (tailNode == nullptr) {
            cout << "NO TICKETS BOOKED" << endl;
            return;
            
        }
        TicketNode* curr = tailNode->nextNode;
        do {
            if (curr->ticketId == id) {
                cout << "TICKET FOUND: ID=" << curr->ticketId 
                     << ", CUSTOMER=" << curr->customerName 
                     << ", RIDE=" << curr->rideName << endl;
                return;
            }
            curr = curr->nextNode;
            
        } while (curr != tailNode->nextNode);
        cout << "TICKET NOT FOUND" << endl;
    }

    void displayTickets() {
        if (tailNode == nullptr) {
            cout << "NO TICKETS BOOKED" << endl;
            return;
        }
        cout << "ALL TICKETS (CIRCULAR ORDER):" << endl;
        TicketNode* curr = tailNode->nextNode;
        do {
            cout << "[ID=" << curr->ticketId 
                 << ", CUSTOMER=" << curr->customerName 
                 << ", RIDE=" << curr->rideName << "]" << endl;
            curr = curr->nextNode;
        } while (curr != tailNode->nextNode);
    }

    int countTickets()
	 {
        if (tailNode == nullptr) return 0;
        int cnt = 0;
        TicketNode* curr = tailNode->nextNode;
        do {
            cnt++;
            curr = curr->nextNode;
        } while (curr != tailNode->nextNode);
        return cnt;
        
    }

    void nextAfterId(int id) {
        if (tailNode == nullptr) {
            cout << "NO TICKETS BOOKED" << endl;
            return;
        }
        TicketNode* curr = tailNode->nextNode;
        do {
            if (curr->ticketId == id) {
                TicketNode* nxt = curr->nextNode;
                cout << "NEXT TICKET AFTER " << id << ": ID=" << nxt->ticketId 
                     << ", CUSTOMER=" << nxt->customerName 
                     << ", RIDE=" << nxt->rideName << endl;
                return;
            }
            curr = curr->nextNode;
        } while (curr != tailNode->nextNode);
        cout << "TICKET NOT FOUND" << endl;
    }
};

int main() {
    TicketCircle system;
    system.issueAtEnd(1, "Ali", "RollerCoaster");
    system.issueAtEnd(2, "Sara", "FerrisWheel");
    
    system.issueAtFront(3, "Omar", "HauntedHouse");
    
    system.displayTickets();
    system.searchById(2);
    
    system.nextAfterId(2);
    
    system.cancelFirst();
    
    
    system.cancelById(3);
    
    system.displayTickets();
    cout << "TOTAL TICKETS: " << system.countTickets() << endl;
    return 0;
}
