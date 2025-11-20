    #include <iostream>
#include <vector>
using namespace std;

class OrderBook {
public:
    vector<int> arr;

    void insert(int price) {
        arr.push_back(price);
        int i = arr.size() - 1;


        while (i > 0) {

            int parent = (i - 1) / 2;
            if (arr[i] < arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void removeMin() {
        if (arr.empty()) return;


        cout << "Executing best buy order: price " << arr[0] << endl;

        arr[0] = arr.back();
        arr.pop_back();

        int i = 0;
        while (true) 
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;


            int smallest = i;

            if (left < arr.size() && arr[left] < arr[smallest])
                smallest = left;
            if (right < arr.size() && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

    void display() {

        for (int p : arr)
            cout << p << " ";
        cout << endl;
    }
};

int main() {
    OrderBook buys;

    cout << "1. Initial orders: 100, 50, 75, 60" << endl;
    buys.insert(100);


     buys.insert(50);
     buys.insert(75);
    buys.insert(60);

    cout << "Min-arr (lowest price = highest priority):" << endl;
        buys.display();

    cout << "\n2. New buy order arrives: 55" << endl;

    buys.insert(55);
    
    cout << "Heap after inserting 55:" << endl;

    buys.display();

    
    cout << "\n3. Executing best (lowest) price order" << endl;
    buys.removeMin();
    cout << "Heap after execution:" << endl;
    buys.display();

    return 0;
}