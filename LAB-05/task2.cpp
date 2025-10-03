#include<iostream>
using namespace std;

class MazeSolver {
    int mazeGrid[5][5];
    int solutionGrid[5][5];
    int gridSize;

public:
    MazeSolver() {
        gridSize = 5;
    
        int initialMaze[5][5] = {
            {1,0,1,0,1},
            {1,1,1,1,1},
            {0,1,0,1,1},
            {1,0,0,1,1},
            {1,1,1,0,1}
        };
        
        for(int i = 0; i < gridSize; i++) {
            for(int j = 0; j < gridSize; j++) {
                mazeGrid[i][j] = initialMaze[i][j];
                solutionGrid[i][j] = 0;
            }
        }
    }

    bool checkSafety(int x, int y) {
        if(x < gridSize && y < gridSize && mazeGrid[x][y] == 1) {
            return true;
        }
        return false;
    }

    bool findPath(int x, int y) {
        // Reached destination
        if(x == gridSize-1 && y == gridSize-1) {
            solutionGrid[x][y] = 1;
            return true;
        }

        if(checkSafety(x, y)) {
            solutionGrid[x][y] = 1;

            // Move down
            if(findPath(x + 1, y)) {
                return true;
            }

            // Move right
            if(findPath(x, y + 1)) {
                return true;
            }
            solutionGrid[x][y] = 0;
            return false;
        }
        return false;
    }

    void displaySolution() {
        cout << "PATH FOUND (1 shows the path):" << endl;
        for(int i = 0; i < gridSize; i++) {
            for(int j = 0; j < gridSize; j++) {
                cout << solutionGrid[i][j] << " ";
            }
            cout << endl;
        }
    }

    void solveMaze() {
        if(findPath(0, 0)) {
            displaySolution();
        } else {
            cout << "NO PATH EXISTS" << endl;
        }
    }
};

int main() {
    MazeSolver solver;
    solver.solveMaze();
    
    return 0;
}