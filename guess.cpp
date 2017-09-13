#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  //bool to keep track of whether someone is playing
  bool playAgain = true;
  //run through the game once, then continue if needed
  do {
    //generate a random number
  srand (time(NULL));
  int guess = rand()%101;
  //let user input an integer
  cout << "Welcome to the guessing game! Pick a number between 1 and 100" << endl;
  int input = 0;
  cin >> input;
  //they have guessed once, this number will keep track of tries
  int guessNum = 1;
  //keep having the guess while it's not the number
  while (input != guess) {
    if (input > guess) {
      cout << "That number is too high! Try again" << endl;
      guessNum++;
      cin >> input;
    }
    else {
      cout << "That number is too low! Try again" << endl;
      guessNum++;
      cin >> input;
    }

  }
  //if it's correct, print out total tries, and ask to play again
  cout << "Your guess is correct!" << endl;
  cout << "Total tries: " << guessNum << endl;
  cout << "Would you like to play again? Y for yes, N for no" << endl;
  char answer = 0;
  cin >> answer;
  //make sure they enter a "Y" or "N"
  while (answer != 89 && answer != 78) {
    answer = 0;
    cout << "Invalid response. Type a 'Y' to play again, or 'N' to exit" << endl;
    cin >> answer;
  }
  //if they're not gonna play again, set bool to false
  //otherwise, keep going
  if (answer == 78) {
    playAgain = false;
  }
  
  } while (playAgain == true);
  return 0;
}


