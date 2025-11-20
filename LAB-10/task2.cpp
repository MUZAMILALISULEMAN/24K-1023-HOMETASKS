#include <iostream>
#include <vector>
using namespace std;

class EmergencyHeap {
public:
    vector<int> array;

    void insert(int severity) {
        array.push_back(severity);
        int i = array.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (array[i] > array[parent]) {
                swap(array[i], array[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void removeMax() {
        if (array.empty()) return;

        array[0] = array.back();
        array.pop_back();

        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < array.size() && array[left] > array[largest])
                largest = left;
            if (right < array.size() && array[right] > array[largest])
                largest = right;

            if (largest != i) {
                swap(array[i], array[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    void display() {
        for (int s : array)
            cout << s << " ";
        cout << endl;
    }
};

int main() {
    EmergencyHeap er;

    
    er.insert(7);
    er.insert(9);
    er.insert(5);
    er.insert(8);
    er.insert(6);

    cout << "Before adding severity 10:" << endl;
    er.display();

    cout << "\nAdding patient with severity 10" << endl;
    er.insert(10);

    cout << "Heap after inserting 10:" << endl;
    er.display();

    cout << "\nTreating the most severe patient (removing max)" << endl;
    er.removeMax();

    cout << "Heap after treatment:" << endl;
    er.display();

    return 0;
}