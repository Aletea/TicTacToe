#include <iostream>

using namespace std;

//Aletea vanVeldhuisen
//9-25-2017
//This program runs a two-player tic-tac-toe



//this is my board
struct C {
  char board[3][3];
};

//methods
void makeBoard(C S);
void Turn(C &S, char value);
bool checkWin(C S, char value);
bool checkPosition(char xVal, char yVal, C &S);
bool checkTie (C S);



int main() {
  //keep track of X wins, O wins, and whether you're still playing
  int xWins = 0;
  int oWins = 0;
  bool stillPlaying = true;
  //while still playing
  while (stillPlaying == true) {
    //initialize board as object
    C isBoard;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j ++) {
	char space = ' ';
	isBoard.board[i][j] = space;
      }
    }
    makeBoard(isBoard);
    //keep track of whether the game has ended and turn
    bool win = false;
    bool xTurn = true;
    cout << "X wins: " << xWins << endl;
    cout << "O wins: " << oWins << endl;
    //while no win/tie
  while (win == false) {
    char val = ' ';
    //run the proper turn
    if (xTurn == true) {
      val = 'X';
      Turn(isBoard, val);
      xTurn = false;
    }
    else {
      val = 'O';
      Turn(isBoard, val);
      xTurn = true;
    }
    //remake board
    makeBoard(isBoard);
    //if won, print and end
    if (checkWin(isBoard, val) == true) {
      cout << "\n" << val << " wins!" << endl;
      win = true;
      //add to proper winner
      if (val == 'X') {
	xWins++;
      }
      else {
	oWins++;
      }
    }
    //if tie end game
    if (checkTie(isBoard) == true) {
      cout << "It's a tie!" << endl;
      win = true;
    }
  }
  //ask if play again, reset board and print out wins if yes, print out wins and exit if no
  cout << "Play again? Y or N" << endl;
  char play;
  cin >> play;
  while (!(play == 'Y' || play == 'N')) {
    cout << "Enter a 'Y' to play again, or a 'N' to exit" << endl;
    cin >> play;
  }
  if (play == 'N') {
    cout << "Total X wins: " << xWins << endl;
    cout << "Total O wins: " << oWins << endl;
    stillPlaying = false;
  }
  }
  return 0;
}

//print out board
void makeBoard(C S) {
  cout << "\t1\t2\t3" << endl;
  for (int i = 0; i < 3; i++) {
    if (i == 0) {
      cout << "a\t";
    }
    else if (i == 1) {
      cout << "b\t";
    }
    else {
      cout << "c\t";
    }
    for (int j = 0; j < 3; j++) {
      cout << S.board[i][j] << "\t";
    }
    cout << endl;
  }
}

//enter a column and row, check if it's free, and then return it
void Turn(C &S, char turn) {
  cout << turn << " Turn: enter a column (1, 2, or 3)" << endl;
  char xPosition;
  cin >> xPosition;
  //make sure is valid input
  while (!(xPosition == '1' || xPosition == '2' || xPosition == '3')) {
    cout << "Invalid Input! Please enter a 1, 2, or 3" << endl;
    cin >> xPosition;
  }
  cout << "enter a row (a, b, or c)" << endl;
  char yPosition;
  cin >> yPosition;
  //^^valid input
  while (!(yPosition == 'a' || yPosition == 'b' || yPosition == 'c')) {
    cout << "Invalid input! Please enter a, b, or c" << endl;
    cin >> yPosition;
  }
  //check to be sure the spot isn't taken
  if (checkPosition(yPosition, xPosition, S) == true) {
    S.board[yPosition-97][xPosition-49] = turn;
  }
  else {
    //rerun method if spot is taken
    cout << "This spot is already taken!" << endl;
    Turn(S, turn); 
  }
}


//checks to see if the board has a space as x,y
bool checkPosition(char xVal, char yVal, C &S) {
  int x = yVal-49;
  int y = 0;
  if (xVal == 'a') {
     y = 0;
  }
  else if (xVal == 'b') {
    y = 1;
  }
  else {
    y = 2;
  }
  if (S.board[y][x] == ' ') {
    return true;
  }
  else {
    return false;
  }
  
}

//check for columns, rows, and diagonals
bool checkWin(C S, char value) {
  //rows
  for (int i = 0; i < 3; i++) {
    if (S.board[i][0] == value && S.board[i][1] == value && S.board[i][2] == value) {
      return true;
    }
  }
  //columns
  for (int i = 0; i < 3; i++) {
    if (S.board[0][i] == value && S.board[1][i] == value && S.board[2][i] == value) {
      return true;
    }
  }
  //diagonals
  if (S.board[0][0] == value && S.board[1][1] == value && S.board[2][2] == value) {
    return true;
  }
  if (S.board[0][2] == value && S.board[1][1] == value && S.board[2][0] == value) {
    return true;
  }
  return false;
}

//if all board spaces are filled, it's a tie!
bool checkTie(C S) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (S.board[i][j] == ' ') {
	return false;
      }
    }
  }
  return true;
}
