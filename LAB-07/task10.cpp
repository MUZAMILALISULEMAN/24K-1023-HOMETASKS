#include <iostream>
#include <vector>
using namespace std;

int findLargest(int numbers[], int total) {
    int biggest = numbers[0];
        for (int i = 1; i < total; i++)
            if (numbers[i] > biggest) biggest = numbers[i];
    return biggest;
}

void sortByDigit(int numbers[], int total, int placeValue) {
        vector<int> tempResult(total);
    vector<int> digitFreq(10, 0);
    
        for (int i = 0; i < total; i++) 
            digitFreq[(numbers[i] / placeValue) % 10]++;
    
        for (int i = 1; i < 10; i++) 
            digitFreq[i] += digitFreq[i - 1];
    
        for (int i = total - 1; i >= 0; i--) {
            int digit = (numbers[i] / placeValue) % 10;
                tempResult[digitFreq[digit] - 1] = numbers[i];
            digitFreq[digit]--;
    }
    
        for (int i = 0; i < total; i++)
            numbers[i] = tempResult[i];
}

void radixSortWithSteps(int numbers[], int total) {
        int maxNum = findLargest(numbers, total);
    
    for (int place = 1; maxNum / place > 0; place *= 10) {
            sortByDigit(numbers, total, place);
        
        cout << "\nAFTER SORTING BY DIGIT " << place << ": \n";
            for (int i = 0; i < total; i++) 
                cout << numbers[i] << " ";
        cout << endl;
    }
}

int main() {
        int transactionList[] = {98765, 24680, 13579, 67890, 11111, 99999, 11223, 55555,
                                 33445, 77777, 22334, 88888, 54321, 66666, 12345, 44444,
                                 44556, 33333, 22222, 55667};
        int count = sizeof(transactionList) / sizeof(transactionList[0]);
    
    cout << "BEFORE SORTING:\n";
        for (int i = 0; i < count; i++) 
            cout << transactionList[i] << " ";
    cout << endl << endl;
    
    radixSortWithSteps(transactionList, count);
    
        cout << "\nAFTER FULL SORTING:\n";
            for (int i = 0; i < count; i++) 
                cout << transactionList[i] << " ";
    cout << endl;
    
        return 0;
}