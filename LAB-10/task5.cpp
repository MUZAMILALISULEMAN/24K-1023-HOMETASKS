#include <iostream>
#include <vector>
using namespace std;

class Matchmaking {
public:
    vector<int> arr;

    void insert(int r) {
        arr.push_back(r);
        int i = arr.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;

            } else {
                break;
            }
        }
    }

    void removeMax() {
        if (arr.empty()) return;

        cout << "Matching highest rated player: " << arr[0] << endl;

        arr[0] = arr.back();

        arr.pop_back();

        int i = 0;
        while (true) 
        {
            int left = 2 * i + 1;


            int right = 2 * i + 2;
            int largest = i;

            if (left < arr.size() && arr[left] > arr[largest])

                largest = left;
            if (right < arr.size() && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    void display() {
        for (int r : arr)
            cout << r << " ";
        cout << endl;
    }
};

int main() {
    Matchmaking queue;

    cout << "1. Initial queue: 1500, 1200, 1800, 1600" << endl;

        
    queue.insert(1500);
        queue.insert(1200);
        queue.insert(1800);
        
        queue.insert(1600);


    cout << "Max-arr (higher r = higher priority):" << endl;
    queue.display();

    cout << "\n2. New player 1700 joins" << endl;
    queue.insert(1700);
    cout << "Queue after inserting 1700:" << endl;
    queue.display();

    cout << "\n3. Matching the highest rated player" << endl;
    queue.removeMax();
    cout << "Queue after match:" << endl;
    queue.display();

    return 0;
}