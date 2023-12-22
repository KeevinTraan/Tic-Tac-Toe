#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// function to draw the grid
void drawGrid(char arr[3][3]){
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << " ";
        cout << '\n';
        if (i < 2)
            cout << "---+---+---" << endl;
    }
}

// checks all the possible positions in the Tic Tac Toe grid to see if there is a winner
bool checkWin(char array[3][3]){
    for(int i = 0; i < 3; i++){
        if(array[0][i] == array[1][i] && array[1][i] == array[2][i]){
            return true;
        }
    }
    
    for(int j = 0; j < 3; j++){
        if(array[j][0] == array[j][1] && array[j][1] == array[j][2]){
            return true;
        }
    }
    
    if((array[0][0] == array[1][1] && array[1][1] == array[2][2]) || (array[0][2] == array[1][1] && array[1][1] == array[2][0])){
        return true;
    }
    
    return false;
}

int main(){
    
    for(;;){
        // initialize the strings
        string p1Name;
        string p2Name;
        string finishGame;
        
        
        // intialize the booleans
        bool player1First = true;
        bool spotTaken = false;
        bool gameEnded = false;
        
        // initialize the integers
        int coin1;
        int coin2;
        int distance1;
        int distance2;
        int move;
        
        // initialize the characters
        char p1Char = 'O';
        char p2Char = 'X';
        
        // initialize the two dimensional array that will be manipulated with
        char grid[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };
        
        // initialize the vector that will include all of the moves that have been done
        vector<int> movesDone;
        
        // introduction
        cout << "This is a 1v1 Tic Tac Toe game. This game is played with two people!" << endl;
        
        for(;;){
            
            // player 1 information
            cout << "Player 1's name (O): ";
            getline(cin, p1Name);
            
            // error case for if the player 1 does not type anything
            if(p1Name == ""){
                cout << "Please input a name..." << endl;
                continue;
            }
            break;
        }
        
        // uppercase the first letter
        p1Name[0] = toupper(p1Name[0]);
        
        for(;;){
            
            // Player 2 information
            cout << "Player 2's name (X): ";
            getline(cin, p2Name);
            
            // error case for if the player 2 does not type anything
            if(p2Name == ""){
                cout << "Please input a name..." << endl;
                continue;
            }
            break;
        }
        
        // uppercase the first letter
        p2Name[0] = toupper(p2Name[0]);
        
        cout << endl;
        
        for(;;){
            for(;;){
                
                // loop until player 1 inputs a valid number
                for(;;){
                    cout << p1Name << " pick a number from 1 - 100: ";
                    
                    if(!(cin >> coin1)){
                        cout << "Please input a number..." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    if(coin1 <= 0 || coin1 > 100){
                        cout << "Please choose a number within the range..." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                
                // loop until player 2 inputs a valid number
                for(;;){
                    cout << p2Name << " pick a number from 1 - 100: ";
                    
                    if(!(cin >> coin2)){
                        cout << "Please input a number..." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    
                    if(coin2 <= 0 || coin2 > 100){
                        cout << "Please choose a number within the range..." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    break;
                }
                
                // makes sure that the second user does not copy the first user
                if(coin1 == coin2){
                    cout << "Please choose different numbers..." << endl;
                    continue;
                }
                break;
            }
            
            // random number generator from 1 to 100
            srand(static_cast<unsigned int>(time(0)));
            
            int result = rand() % 100 + 1;
            
            // calculate the distance from the numbers that the users inputted to the random number that was generated
            if(coin1 > result){
                distance1 = coin1 - result;
            } else{
                distance1 = result - coin1;
            }
            
            if(coin2 > result){
                distance2 = coin2 - result;
            } else{
                distance2 = result - coin2;
            }
            
            cout << endl;
            
            // determine which player goes first by the person who got closest to the randomized number
            if (distance1 < distance2) {
                cout << "The number is " << result << "!" << endl<< "------------------" << endl << p1Name << " goes first!" << endl;
            }
            
            else if (distance2 < distance1){
                cout << "The number is " << result << "!" << endl<< "------------------" << endl << p2Name << " goes first!" << endl;
                player1First = false;
            }
            
            // if both players have the same distance from the randomized number, both users will input new numbers
            else{
                cout << "The number is " << result << "!" << endl << "------------------" << endl << "TIE! Let's do this again..." << endl << endl;
                continue;
            }
            break;
        }
  
                for(;;){
                    
                    // draw the grid
                    cout << endl;
                    drawGrid(grid);
                    cout << endl;
                    
                    // prompts based on who makes the first move
                    if(player1First){
                        cout << p1Name << "'s move (" << p1Char << "): ";
                    } else{
                        cout << p2Name << "'s move (" << p2Char << "): ";
                    }
                    
                    // error message if the user does not input a number
                    if(!(cin >> move)){
                        cout << "Please input a number" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    
                    // error message if the user does not input a valid number
                    if(move < 1 || move > 9){
                        cout << "Please choose a valid number" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    
                    // error message if the user inputs a move to a spot that is already taken
                    if(movesDone.size() > 0){
                        // loop through all of the elements in the vector to see if a spot has been taken and if the vector has at least one element
                        for(int i = 0; i <= movesDone.size() - 1; i++){
                            if(movesDone[i] == move){
                                // error message for if the spot is taken
                                cout << endl << "**********************" << endl;
                                cout << "Spot is already taken!" << endl;
                                cout << "**********************" << endl;
                                spotTaken = true;
                                break;
                            }
                        }
                    }
                    // do not need to check if there are any spots taken if it the is first move
                    else{
                        // add the move to the vector
                        movesDone.push_back(move);
                    }
                
                // restart the loop if the spot is taken
                if(spotTaken){
                    spotTaken = false;
                    continue;
                }
                
                    // add the move to the vector if there is at least one move in the vector
                    if(movesDone.size() > 0){
                        movesDone.push_back(move);
                    }
                    
                    // switch cases that change the character in the grid based on the turn and move of the player
                    switch(move){
                        case 1:
                            if(player1First){
                                grid[0][0] = 'O';
                            } else{
                                grid[0][0] = 'X';
                            }
                            break;
                        case 2:
                            if(player1First){
                                grid[0][1] = 'O';
                            } else{
                                grid[0][1] = 'X';
                            }
                            break;
                        case 3:
                            if(player1First){
                                grid[0][2] = 'O';
                            } else{
                                grid[0][2] = 'X';
                            }
                            break;
                        case 4:
                            if(player1First){
                                grid[1][0] = 'O';
                            } else{
                                grid[1][0] = 'X';
                            }
                            break;
                        case 5:
                            if(player1First){
                                grid[1][1] = 'O';
                            } else{
                                grid[1][1] = 'X';
                            }
                            break;
                        case 6:
                            if(player1First){
                                grid[1][2] = 'O';
                            } else{
                                grid[1][2] = 'X';
                            }
                            break;
                        case 7:
                            if(player1First){
                                grid[2][0] = 'O';
                            } else{
                                grid[2][0] = 'X';
                            }
                            break;
                        case 8:
                            if(player1First){
                                grid[2][1] = 'O';
                            } else{
                                grid[2][1] = 'X';
                            }
                            break;
                        default:
                            if(player1First){
                                grid[2][2] = 'O';
                            } else{
                                grid[2][2] = 'X';
                            }
                            break;
                    }
                    
                    // switching turns
                    if(player1First){
                        player1First = false;
                    } else{
                        player1First = true;
                    }
                
                // if the amount of moves are more than 9, that means that there is a draw
                if(movesDone.size() > 9){
                    cout << endl;
                    drawGrid(grid);
                    cout << endl;
                    cout << "################" << endl;
                    cout << "DRAW" << endl;
                    cout << "################" << endl << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    for(;;){
                        cout << "Continue playing? (y/n): ";
                        getline(cin, finishGame);
                        
                        // uppercase the first letter of the input
                        finishGame[0] = toupper(finishGame[0]);
                        
                        // error message for an invalid input
                        if(finishGame != "Y" && finishGame != "N"){
                            cout << "Please enter a valid input";
                            continue;
                        }
                        
                        // used to stop the game later
                        if(finishGame == "N"){
                            gameEnded = true;
                        }
                        break;
                    }
                    break;
                }
                    
                if(checkWin(grid)){
                    
                    // clear the vector
                    movesDone.clear();
                    
                    // draw the grid one last time in the round
                    cout << endl;
                    drawGrid(grid);
                    cout << endl;
                    
                    // output the winner of the game
                    cout << "################" << endl;
                    if(player1First){
                        cout << p2Name << " WINS!" << endl;
                    } else{
                        cout << p1Name << " WINS!" << endl;
                    }
                    cout << "################" << endl << endl;
                    
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    for(;;){
                        cout << "Continue playing? (y/n): ";
                        getline(cin, finishGame);
                        
                        // uppercase the first letter of the input
                        finishGame[0] = toupper(finishGame[0]);
                        
                        if(finishGame != "Y" && finishGame != "N"){
                            cout << "Please enter a valid input";
                            continue;
                        }
                        if(finishGame == "N"){
                            gameEnded = true;
                        }
                        break;
                    }
                    
                    break;
                }
            }
        
        // stop the game
        if(gameEnded){
            break;
        }    
    }
    return 0;
}
