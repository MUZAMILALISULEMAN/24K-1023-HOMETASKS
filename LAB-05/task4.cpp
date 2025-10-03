#include <iostream>
#include <cmath>
using namespace std;

class NQueensSolver {
    int boardSize;
    int *queenPositions;
    int totalSolutions;

public:
    NQueensSolver() {
        boardSize = 0;
        totalSolutions = 0;
        queenPositions = nullptr;
    }

    void setSize(int size) {
        boardSize = size;
        queenPositions = new int[size];
        for(int i = 0; i < size; i++) {
            queenPositions[i] = -1;
        }
    }

    bool isSafe(int row, int col) {
        for(int i = 0; i < row; i++) {
            if(queenPositions[i] == col || abs(queenPositions[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    void displayBoard() {
        for(int i = 0; i < boardSize; i++) {
            for(int j = 0; j < boardSize; j++) {
                if(queenPositions[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    void solve(int currentRow, bool &firstSolutionPrinted) {
        if(currentRow == boardSize) {
            totalSolutions++;
            if(!firstSolutionPrinted) {
                cout << "ONE VALID BOARD CONFIGURATION FOR N = " << boardSize << ":\n";
                displayBoard();
                firstSolutionPrinted = true;
            }
            return;
        }

        for(int col = 0; col < boardSize; col++) {
            if(isSafe(currentRow, col)) {
                queenPositions[currentRow] = col;
                solve(currentRow + 1, firstSolutionPrinted);
            }
        }
    }

    void findSolutions() {
        totalSolutions = 0;
        bool firstPrinted = false;
        solve(0, firstPrinted);
        
        cout << "TOTAL DISTINCT SOLUTIONS FOR N = " << boardSize << ": " << totalSolutions << endl;
    }

    ~NQueensSolver() {
        delete[] queenPositions;
    }
};

int main() {
    NQueensSolver solver;
    int n;

    cout << "ENTER THE VALUE OF N: ";
    cin >> n;

    if(n <= 0) {
        cout << "INVALID BOARD SIZE!" << endl;
        return 1;
    }

    solver.setSize(n);
    solver.findSolutions();


    cout << endl<<"--- DEMONSTRATION WITH N = 4 ---" << endl;
    NQueensSolver demo;
    demo.setSize(4);
    demo.findSolutions();

    return 0;
}