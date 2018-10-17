//  main.cpp
//  Tic Tac Toe impossible
//
//  Created by Nico on 10/9/18.
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
// Purpose: Tells the user goodBye
//*****************************************************************
void goodBye ()
{
    cout << endl << endl << "Have a good day!" << endl << "Good Bye" << endl << endl;
}

//*****************************************************************
// Function: Play decides X or O
// param-1: the array
// param-2: size of the array
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
// param-1: the array
// param-2: size of the array
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
// param-1: the array
// param-2: size of the array
//*****************************************************************
void changePos(string position[], bool player, char location)
{
    int numLocation = location - 97;
    if(player == true)
        position[numLocation] = " X ";
    if(player == false)
        position[numLocation] = " O ";
}

//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
//*****************************************************************
int gamePlay(string positions[], bool player1st)
{
    displayBoard(positions);
    char location;
    cout << "pick where you want you go or Q surrender" << endl;
    cin >> location;
    if (location == 'q' or location == 'Q')
        return 0;
    
    changePos(positions, player1st, location);
    displayBoard(positions);
    return 1;
}


//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
//*****************************************************************
int allwayWin(string positions[], bool player1st, int numOfturns)
{
    bool compSy = !player1st;
    if (positions[4] == "(e)") {
            changePos(positions, compSy, 4);
            return 0;
        }
  //  rand() % 4;


    return 1;
}

//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the arra
// Returns
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
        
        if (x == 2 && positions[winConditions[i][a]] != c)
            return winConditions[i][a];

        if (x == 3)
            return 1;
    }
    return -1;
}


//*****************************************************************
// Function: Displays Score
// param-1: the array
// param-2: size of the array
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
    string positions[] = { "(a)", "(b)", "(c)", "(d)", "(e)", "(f)", "(g)", "(h)", "(i)"};
    int numOfLosses = 0;
    int numOfTies = 0;
    bool player1st; // if ture player gose first
    
    char choice = 'y';
    

    while (choice != 'q' or choice != 'Q') {
        if(whoGoes1st(player1st) == 0)
            break;
        while (choice != 'q' or choice != 'Q') {
            if(gamePlay(positions, player1st) == 0)
                numOfLosses++;
            break;
        }
        cout << winConCheck(positions, player1st);
        
    }
    
    
    

    
    scoreDis(numOfTies, numOfLosses);
    goodBye();
    
}
