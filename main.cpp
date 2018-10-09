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
using namespace std;

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
void whoGoes1st()
{
    char userSelection;o
    cout << "Do you want to go first or second?" << endl;
    cout << "type 1 for first or 2 for second" << endl;
    cin >> userSelection;
}


//*****************************************************************
// Function: Display board
// param-1: the array
// param-2: size of the array
//*****************************************************************
void displayBoard(string position[])
{
    int x = 0;
    for(int i = 0; i < 3; i++)
    {
        cout << setw(9) << "";
        cout << position[x] << " | ";
        x++;
        cout << position[x] << " | ";
        x++;
        cout << position[x];
        x++;
        cout << endl;
        
        if(i < 2)
        {
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
void scoreDis()
{
    cout << endl << "Times you won:  0";
    cout << endl << "Times you ties: " << numOfTies;
    cout << endl << "And you lost... " << numOfLosses;
}

int main()
{
    string position[] = { "(a)", "(b)", "(c)", "(d)", "(e)", "(f)", "(g)", "(h)", "(i)"};

    
    welcome();
    whoGoes1st();
    
    
    
    displayBoard(position);
    

    
    scoreDis();
    goodBye();
    
}
