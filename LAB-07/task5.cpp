#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int totalComparisons = 0;

int splitArray(int data[], int start, int end, int pivotIdx) {
        swap(data[pivotIdx], data[end]);
    int pivotValue = data[end];
        int storePos = start - 1;
    
    for (int current = start; current < end; current++) {
            totalComparisons++;
        if (data[current] < pivotValue) {
                storePos++;
            swap(data[storePos], data[current]);
        }
    }
        swap(data[storePos + 1], data[end]);
    return storePos + 1;
}

int choosePivot(int data[], int lowBound, int highBound, int strategy) {
        switch (strategy) {
        case 1:
            return lowBound;
        case 2:
            return lowBound + rand() % (highBound - lowBound + 1);
            case 3:
                return (lowBound + highBound) / 2;
        case 4: {
                int middle = (lowBound + highBound) / 2;
            int first = data[lowBound], midVal = data[middle], last = data[highBound];
                if ((first > midVal) != (first > last))
                    return lowBound;
                else if ((midVal > first) != (midVal > last))
                    return middle;
                else
                    return highBound;
        }
        default:
            return lowBound;
    }
}

void quickSortArray(int data[], int low, int high, int pivotType) {
        if (low < high) {
            int pivotIndex = choosePivot(data, low, high, pivotType);
                int partitionPos = splitArray(data, low, high, pivotIndex);
            quickSortArray(data, low, partitionPos - 1, pivotType);
                quickSortArray(data, partitionPos + 1, high, pivotType);
    }
}

void displayArray(int data[], int size) {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
    cout << endl;
}

int testPivotStrategy(int original[], int count, int pivotKind, const string &label) {
        int tempArray[100];
    for (int i = 0; i < count; i++)
            tempArray[i] = original[i];
    
    totalComparisons = 0;
        quickSortArray(tempArray, 0, count - 1, pivotKind);
    
        cout << label << " PIVOT SORTED: ";
    displayArray(tempArray, count);
        cout << "COMPARISONS: " << totalComparisons << endl << endl;
    
    return totalComparisons;
}

int main() {
    srand(time(0));
        int baseData[] = {10, 7, 8, 9, 1, 5, 3, 15, 12, 6};
    int totalElements = sizeof(baseData) / sizeof(baseData[0]);
    
        cout << "ORIGINAL ARRAY: ";
    displayArray(baseData, totalElements);
        cout << endl;
    
        int compFirst = testPivotStrategy(baseData, totalElements, 1, "FIRST ELEMENT");
    int compRandom = testPivotStrategy(baseData, totalElements, 2, "RANDOM ELEMENT");
        int compMiddle = testPivotStrategy(baseData, totalElements, 3, "MIDDLE ELEMENT");
    int compMedian = testPivotStrategy(baseData, totalElements, 4, "MEDIAN OF THREE");
    
        cout << "COMPARISON SUMMARY\n";
    cout << "FIRST ELEMENT PIVOT: " << compFirst << " COMPARISONS\n";
        cout << "RANDOM ELEMENT PIVOT: " << compRandom << " COMPARISONS\n";
    cout << "MIDDLE ELEMENT PIVOT: " << compMiddle << " COMPARISONS\n";
        cout << "MEDIAN OF THREE PIVOT: " << compMedian << " COMPARISONS\n";
    
        cout << "\nMORE BALANCED PIVOT SELECTIONS (RANDOM / MEDIAN OF THREE) GIVES FEWER COMPARISONS AND BETTER PERFORMANCE." << endl;
    
        return 0;
}