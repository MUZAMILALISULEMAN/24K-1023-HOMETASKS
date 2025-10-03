#include<iostream>
using namespace std;

class IceCreamMaze {
    int mazeGrid[7][7];
    int solutionGrid[7][7];
    int gridSize;

public:
    IceCreamMaze() {
        gridSize = 7;
        int initialMaze[7][7] = {
            {1,0,1,1,1,0,1},
            {1,1,1,0,1,1,1},
            {0,1,0,1,0,1,0},
            {1,1,1,1,1,0,1},
            {0,0,0,0,1,1,1},
            {1,1,1,0,1,0,1},
            {0,0,1,1,1,1,1}
        };
        
        for(int i = 0; i < gridSize; i++) {
            for(int j = 0; j < gridSize; j++) {
                mazeGrid[i][j] = initialMaze[i][j];
                solutionGrid[i][j] = 0;
            }
        }
    }

    bool checkPosition(int x, int y) {
        if(x >= 0 && x < gridSize && y >= 0 && y < gridSize && mazeGrid[x][y] == 1) {
            return true;
        }
        return false;
    }

    bool findIceCreamPath(int x, int y) {
        // Reached ice cream shop (destination)
        if(x == gridSize-1 && y == gridSize-1) {
            solutionGrid[x][y] = 1;
            return true;
        }

        if(checkPosition(x, y)) {
            solutionGrid[x][y] = 1;

    
            if(findIceCreamPath(x + 1, y)) {
                return true;
            }

    
            if(findIceCreamPath(x, y + 1)) {
                return true;
            }

      
            if(findIceCreamPath(x - 1, y)) {
                return true;
            }

    
            if(findIceCreamPath(x, y - 1)) {
                return true;
            }

          
            solutionGrid[x][y] = 0;
            return false;
        }
        return false;
    }

    void displayPath() {
        cout << "PATH TO ICE CREAM SHOP:" << endl;
        for(int i = 0; i < gridSize; i++) {
            for(int j = 0; j < gridSize; j++) {
                cout << solutionGrid[i][j] << " ";
            }
            cout << endl;
        }
    }

    void findSolution() {
        if(findIceCreamPath(0, 0)) {
            displayPath();
        } else {
            cout << "NO PATH TO ICE CREAM FOUND" << endl;
        }
    }
};

int main() {
    IceCreamMaze maze;
    maze.findSolution();
    
    return 0;
}