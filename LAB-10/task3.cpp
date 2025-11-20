#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TaskHeap {
public:
    vector<int> arr;
    vector<string> names;

    void insert(int p, string name) {
        arr.push_back(p);

        names.push_back(name);


        int i = arr.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);

                swap(names[i], names[parent]);

                i = parent;
            } else 
            {
                break;
            }
        }
    }

    void removeMax() {
        if (arr.empty()) return;

        cout << "Executing highest p task: " << names[0]
             << " (p " << arr[0] << ")" << endl;

        arr[0] = arr.back();


        names[0] = names.back();
        arr.pop_back();
        names.pop_back();

        int i = 0;
        while (true) {

        int left = 2 * i + 1;

            int right = 2 * i + 2;
            int largest = i;

            if (left < arr.size() && arr[left] > arr[largest])
                largest = left;
            if (right < arr.size() && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                swap(names[i], names[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    void display() {
        cout << "Current max-heap: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << names[i] << "(" << arr[i] << ") ";
        }
        cout << endl;
    }
};

int main() {
    TaskHeap scheduler;

    scheduler.insert(5, "A");
    scheduler.insert(3, "B");
    scheduler.insert(8, "C");

    cout << "1. After inserting A(5), B(3), C(8):" << endl;
    scheduler.display();

    cout << "\n2. Removing highest p task:" << endl;
    scheduler.removeMax();

    cout << "Heap after removal:" << endl;
    scheduler.display();

    cout << "\n3. Inserting new task D(6)" << endl;
    scheduler.insert(6, "D");

    cout << "Final heap:" << endl;
    scheduler.display();

    return 0;
}