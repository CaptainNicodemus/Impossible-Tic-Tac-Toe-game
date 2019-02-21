//  main.cpp
//  Tic Tac Toe impossible
//
//  Created by Nico on 10/9/18, Updated on 2/21/2019
//  Copyright © 2018 Nicodemus Robles. All rights reserved.
//
// This is a C++ program that runs a tic tac toe game that is impossible
// to beat
//*****************************************************************

#include <iostream>
#include <iomanip>
#include <limits> // Needed for stoping balance input error
#include <cstdlib>

using namespace std;

int winConditions[8][3] = {
    {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}
};
int numOfLosses = 0;
int numOfTies = 0;

//*****************************************************************
// Function: welcome
// Purpose: welcomes the user
//*****************************************************************
void welcome ()
{
    cout << endl;
    cout << setw(10) << " " <<"Welcome to the" << endl;
    cout << setw(4) << " " << "Impossible Tic Tac Toe Game" << endl << endl;
}

//*****************************************************************
// Function: goodBye
// Purpose: Tells the user Good Bye
//*****************************************************************
void goodBye ()
{
    cout << endl << endl << "Have a good day!" << endl << "Good Bye" << endl << endl;
}

//*****************************************************************
// Function: Play decides X or O
// param-1: the bool "player 1st"
// Returns: 0 if player wants to quit or 1 to end
//*****************************************************************
int whoGoes1st(bool &player1st)
{
    char choice;
    cout << "Do you want to go first or second?" << endl;
    cout << "1 for first or 2 for second or Q to quit" << endl;
    cin >> choice;
    while(choice != '1' && choice != '2' && choice != 'q' && choice != 'Q')
    {
        cin.clear(); // clear the error flags is user put in somthing other than a number
        cin.ignore( numeric_limits <streamsize> :: max(), '\n'); // discard the row
        cout << "Invalid input! Try again" << endl;
        cin >> choice;
    }
    if (choice == 'q' or choice == 'Q')
        return 0;
    
    if(choice == '1'){
        player1st = true;
    }
    if (choice == '2'){
        player1st = false;
    }
    cout <<endl;
    return 1;
}

//*****************************************************************
// Function: Display board
// param-1: the positions of the board
//*****************************************************************
void displayBoard(string positions[])
{
    int x = 0;
    for(int i = 0; i < 3; i++){
        cout << setw(9) << "";
        cout << positions[x] << " | ";
        x++;
        cout << positions[x] << " | ";
        x++;
        cout << positions[x];
        x++;
        cout << endl;
        
        if(i < 2){
            cout << setw(8) << "";
            cout << "------------------" << endl;
        }
    }
    cout << endl;
}

//*****************************************************************
// Function: Changes the position
// param-1: arry of positions
// param-2: which player to change
// param-3: location to change
//*****************************************************************
void changePos(string position[], bool player, int location)
{
    if(player == true)
        position[location] = " X ";
    if(player == false)
        position[location] = " O ";
}

//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
//*****************************************************************
bool possTaken(string position[], int location){
    if (position[location] == " X " || position[location] == " O ")
        return true;
    else
        return false;
}

//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
//*****************************************************************
void playerLost(){
    
    cout << setw(14) << " " << "You lost :(" << endl << endl;
    numOfLosses++;
}

//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
//*****************************************************************
void playerTied(){
    
    cout << setw(14) << " " << "You tied, good job" << endl << endl;
    numOfTies++;
}

//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
//*****************************************************************
int playerTurn(string positions[], bool player1st)
{
    displayBoard(positions);
    char location;
    cout << "pick where you want you go or Q to surrender" << endl;
    cin >> location;
    if (location == 'q' or location == 'Q'){
        numOfLosses++;
        return 0;
    }
    location -= 97;
    while (possTaken(positions, location) == true) {
        cout << endl << "That spot is all ready taken try another or Q to surrender.." << endl;
        cin >> location;
        if (location == 'q' or location == 'Q'){
            numOfLosses++;
            return 0;
        }
        location -= 97;
    }
    changePos(positions, player1st, location);
    return 1;
}



//*****************************************************************
// Function: winConCheck
// Info: Checks to see if there is a win condition for the user you check
// Returns: the posstion in the arry if there is a "win con", -1 if there isnt one,
// or -2 if theres a win
//*****************************************************************
int winConCheck(string positions[], bool player1st)
{
    string b , c;
    
    if(player1st == true){
        b = " X ";
        c = " O ";
    }
    else{
        b = " O ";
        c = " X ";
    }
    
    int returnValue = -1;
    
    for (int i = 0; i < 8; i++) {
       
        int a = 0; // used to give back the position "0,1,2" of the array
        int x = 0; // used to track if the player/computer is within striking distance
        
        if (positions[winConditions[i][0]] == b && positions[winConditions[i][0]] != c)
            x++;
        else
            a = 0;
        
        if (positions[winConditions[i][1]] == b && positions[winConditions[i][1]] != c)
            x++;
        else
            a = 1;
        
        if (positions[winConditions[i][2]] == b && positions[winConditions[i][2]] != c)
            x++;
        else
            a = 2;
        
        if (x == 2 && positions[winConditions[i][a]] != c && x != 3){
            returnValue = winConditions[i][a];
        }
        
        if (x == 3){
            returnValue = -2;
        }
    }
    return returnValue;
}

//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
//*****************************************************************
int allwayWin(string positions[], bool player1st)
{
    bool compSy = !player1st;
    
    if(winConCheck(positions, compSy) != -1 && winConCheck(positions, compSy) != -2){
        changePos(positions, compSy, winConCheck(positions, compSy));
        return 0;
    }
    
    if(winConCheck(positions, player1st) != -1 && winConCheck(positions, compSy) != -2){
        changePos(positions, compSy, winConCheck(positions, player1st));
        return 0;
    }
    
    if(player1st == true){
        if (positions[4] == "(e)") {
            changePos(positions, compSy, 4);
            return 0;
        }
        if (positions[4] == " X ") {
            int arry[] = {0, 2, 6, 8};
            while (1 == 1) {
                int i = arry[rand() % 4];
                if(possTaken(positions, i) == false){
                    changePos(positions, compSy, i);
                    return 0;
                }
            }
        }
        
        int arry[] = {1, 3, 5, 7};
        while (1 == 1) {
            int i = arry[rand() % 4];
            if(possTaken(positions, i) == false){
                changePos(positions, compSy, i);
                return 0;
            }
        }
    }
    else{
        if ((positions[1] == " O " || positions[3] == " O "
            || positions[5] == " O " || positions[7] == " O ") && positions[4] == "(e)") {
            changePos(positions, compSy, 4);
            return 0;
        }
        int arry[] = {0, 2, 6, 8};
        while (1 == 1) {
            int i = arry[rand() % 4];
            if(possTaken(positions, i) == false){
                changePos(positions, compSy, i);
                return 0;
            }
        }
        
    }
    
    return 1;
}

//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
//*****************************************************************
int gamePlay(string positions[], bool player1st)
{
    int tiedCheck = 0;
    
    if (player1st == true) {
        while (1 == 1) {
            if(playerTurn(positions, player1st) == 0)
                break;
            
            tiedCheck++;
            if (tiedCheck == 5){
                displayBoard(positions);
                playerTied();
                break;
            }

            allwayWin(positions, player1st);
            
             
        }
        return 0;
        
    }
    else{
        while (1 == 1) {
            allwayWin(positions, player1st);
            
            if (winConCheck(positions, !player1st) == -2){
                displayBoard(positions);
                playerLost();
                break;
            }
            tiedCheck++;
            if (tiedCheck == 5){
                displayBoard(positions);
                playerTied();
                break;
            }
            if(playerTurn(positions, player1st) == 0)
                break;
        }
        return 0;
    }
}

//*****************************************************************
// Function: Displays Score
//*****************************************************************
void scoreDis(int numOfTies, int numOfLosses)
{
    cout << endl << "Times you won:  0";
    cout << endl << "Times you ties: " << numOfTies;
    cout << endl << "And you lost... " << numOfLosses;
}

int main()
{

    
    welcome();
    bool player1st; // if ture player gose first

    while (1 == 1) {
        string positions[] = { "(a)", "(b)", "(c)", "(d)", "(e)", "(f)", "(g)", "(h)", "(i)"};
        if(whoGoes1st(player1st) == 0)
            break; // break out if user quits.
        gamePlay(positions, player1st);
        }
    
    scoreDis(numOfTies, numOfLosses);
    goodBye();
    
}
