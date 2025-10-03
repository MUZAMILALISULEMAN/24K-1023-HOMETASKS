#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class GuessGame{
int *target;
int *player;

public:
GuessGame(){
    target = new int(0);
    player = new int(1);
}

void initialize(){
    srand(time(0));
    *target = rand() % 100 + 1;
}

int playRound(){
    cout << "PLAYER " << *player << " GUESS: ";
    int guess;
    cin >> guess;

    if(guess == *target){
        cout << "CORRECT!" << endl;
        return *player;
    }
    else if(guess > *target){
        cout << "TOO HIGH" << endl;
    }
    else{
        cout << "TOO LOW" << endl;
    }

    if(*player == 1) *player = 2;
    else *player = 1;

    return playRound();
}

void printResult(int winner){
    cout << "PLAYER " << winner << " WINS!" << endl;
}
};

int main(){
    GuessGame game;
    game.initialize();
    
    int winner = game.playRound();
    game.printResult(winner);

    return 0;
}