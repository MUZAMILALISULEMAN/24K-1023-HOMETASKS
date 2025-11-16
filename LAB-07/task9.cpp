#include <iostream>
#include <vector>
using namespace std;

int findMax(int data[], int size) {
    int maxVal = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > maxVal) maxVal = data[i];
    return maxVal;
}

void countingSortByDigit(int data[], int size, int placeValue) {
        vector<int> tempOutput(size);
    vector<int> digitCount(10, 0);
    
        for (int i = 0; i < size; i++) 
            digitCount[(data[i] / placeValue) % 10]++;
    
        for (int i = 1; i < 10; i++) 
            digitCount[i] += digitCount[i - 1];
    
        for (int i = size - 1; i >= 0; i--) {
            int digit = (data[i] / placeValue) % 10;
                tempOutput[digitCount[digit] - 1] = data[i];
            digitCount[digit]--;
    }
    
        for (int i = 0; i < size; i++)
            data[i] = tempOutput[i];
}

void radixSortArray(int data[], int size) {
        int largest = findMax(data, size);
    for (int place = 1; largest / place > 0; place *= 10)
            countingSortByDigit(data, size, place);
}

int main() {
        int transactions[] = {1800, 750, 2900, 4200, 1100, 950, 3300, 1800, 600, 2700};
        int totalCount = sizeof(transactions) / sizeof(transactions[0]);
    
    radixSortArray(transactions, totalCount);
    
        cout << "SORTED TRANSACTIONS:\n";
            for (int i = 0; i < totalCount; i++) 
                cout << transactions[i] << " ";
        cout << endl;
    
        return 0;
}