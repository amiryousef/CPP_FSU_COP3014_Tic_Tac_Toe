/*
tttdriver.cpp 
Amir Yousef
COP3014-Summer 2010
Project-3 Solution
*/

#include <iostream>
#include <ctime>
#include "ttt.h"
using namespace std;

int main()  
{
size_t x, y;                                           //define x and y as static constants.                                          
char winner;                                           //define winner as a character. 

cout << "\n*** Welcome to Tic-Tac-Toe ***\n" << endl;  //print *** Welcome to Tic-Tac-Toe *** on screen. 

TicTacToe game;                                        //create an object game.

int players,turn;                                      //define players and turn as integers. 
bool human[ 2 ] = { true, true };                      //define human[ 2 ] as a bool. 
char token[ 2 ] = { 'X', 'O' };                        //define token[ 2 ] as a character.
srand( time( 0 ) );                                    //seedes random numbers. 
turn = rand() %3;                                      //generates random turns. 
 
do                                              
{                                                      //start do while loop.                   
cout << "\nHow many players will be playing?";         //ask the user how many players will be playing. 
cin >> players;                                        //get the input from the user {0, or 1, or 2}
cout << endl;
if ( players < 0 || players > 2 )                      //if the players is less than 1 or greater than 2.
cout << "\nInvalid entry\n\n";                         //print Invalid entry and back to the loop.
}while ( players <0 || players > 2 );                  //end of do while loop. 

if ( players == 0 )                                    //if players are 0 means no human and the computer will play.
{
human[ 0 ]=false;
human[ 1 ]=false;
}
if ( players == 1 )                                    //if players are 1 means one human and the computer will play.
{
human[ 0 ]=false;
human[ 1 ]=true;
}
if ( players == 2 )                                    //if players are 2 means both are human and no computer will play.
{
human[ 0 ]=true;
human[ 1 ]=true;
}
      
while(true)                                            //when the user is human.                           
{ 
game.getInput( 'X', x, y, human[ turn ] );             //call getInput( char, size_t &x, size_t &y, bool ).
game.PrintBoard( human[ turn ], x, y );                //call PrintBoard( char, size_t x, size_t y ).
if ( turn == 0 )                                                                          
turn = 1;
else
turn = 0; 
game.CheckForWinner();                                 //call CheckForWinner().
winner = game.CheckForWinner();                       
if ( winner != ' ' )                                   //if player wins break the loop.
break;
game.getInput( 'O', x, y, human[ turn ] );             //call getInput( char, size_t &x, size_t &y, bool ).
game.PrintBoard( human[ turn ], x, y );                //call PrintBoard( char, size_t x, size_t y ).
if ( turn == 0 )
turn = 1;
else
turn = 0; 
game.CheckForWinner();                                  //call CheckForWinner().
winner = game.CheckForWinner();                        
if ( winner != ' ' )                                    //if player wins break the loop.
break;
}

while(false)                                            //when the user is the computer. 
{ 
game.getInput( 'X', x, y, token[ turn ] );              //call getInput( char, size_t &x, size_t &y, bool ).
game.PrintBoard( token[ turn ], x, y );                 //call PrintBoard( char, size_t x, size_t y ).
game.CheckForWinner();                                  //call CheckForWinner().
winner = game.CheckForWinner();
if ( winner != ' ' )                                    //if player wins break the loop.
break;
game.getInput( 'O', x, y, token[ turn ] );              //call getInput( char, size_t &x, size_t &y, bool ).
game.PrintBoard( token[ turn ], x, y );                 //call PrintBoard( char, size_t x, size_t y ).
game.CheckForWinner();                                  //call CheckForWinner().
winner = game.CheckForWinner();
if ( winner != ' ' )                                    //if player wins break out the loop.
break;                                    
}

game.printWinner( winner );                             //call printWinner( char ) to print the winner on screen.      
return 0;
}