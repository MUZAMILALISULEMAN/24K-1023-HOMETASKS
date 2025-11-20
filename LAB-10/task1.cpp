#include <iostream>
#include <vector>
using namespace std;

class PackageHeap {
public:
    vector<int> heap;

    void insert(int p) {
        heap.push_back(p);
        int i = heap.size() - 1;


        while (i > 0) {

            int parent = (i - 1) / 2;

            if (heap[i] < heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }

        }
    }

    void display() {
        for (int p : heap) {

            cout << p << " ";
        }
        cout << endl;
    }
};

int main() {
    PackageHeap courier;

    courier.insert(4);
    courier.insert(1);
    courier.insert(5);
    courier.insert(3);
    courier.insert(4);

    cout << "Before inserting p 2:" << endl;
    courier.display();

    cout << "\nInserting new package with p 2" << endl;
    courier.insert(2);

    cout << "\nUpdated min-heap after insertion:" << endl;
    courier.display();

    return 0;
}