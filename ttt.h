/*
ttt.h 
Amir Yousef
COP3014-Summer 2010
Project-3 Solution
*/
                                                                                                        
class TicTacToe                                       //create a class called TicTacToe.
{
public:                                                          
TicTacToe();                                          //This is the default constructor for the class.                                           
void InitializeBoard();                               //This function will initialize the board to blank spaces.
void PrintBoard( char, size_t x, size_t y );          //This function will print the Tic-Tac-Toe board. 
void getInput( char, size_t &x, size_t &y, bool );    //This function will get the user's input.  
bool OccupySquare(size_t x, size_t y, char );         //This function will occupy a square on the board. 
char CheckForWinner();                                //This function will check the board for a winner.
bool checkHorizontal( char );                         //This function will check the board for a winner horizontally.
bool checkVertical( char );                           //This function will check the board for a winner verticaly.
bool checkDiagonal( char );                           //This function will check the board for a winner diagonaly. 
void printWinner(char);                               //This function will print the winner name. 
static const size_t rows = 3;                         //static constants to represent the number of rows.
static const size_t cols = 3;                         //static constants to represent the number of columns. 
private:
bool IsValidLocation(size_t x, size_t y);             //This function will take in two coordinates and decide if they are valid.
bool IsScratch();                                     //This function will decide if the game is a scratch.
char board[rows][cols];                               //This is a two-dimensional character array to represent the board. 
};                                                  