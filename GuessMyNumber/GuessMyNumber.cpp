//Game: Guess My Number
//Player tries to guess a random number from 1 to 100

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  //setting debug on(1) or off(0)
  const int DEBUG = 0;
  if(DEBUG)
    cout << "Debugging on" << endl;

  //seed random number generator
  srand(static_cast<unsigned int>(time(0)));

  //max possible secret number
  //const int MAX_NUMBER = 100;
  cout << "Initializing game..." << endl;
  cout << "Please input the max number. ";
  int maxNumber;
  cin >> maxNumber;
  cout << endl;

  //random number between 1-100
  //int secretNumber = (rand() % MAX_NUMBER) + 1; 
  int secretNumber = (rand() % maxNumber) + 1;

  if(DEBUG)
    cout << "The number generated is: " << secretNumber << endl;

  //Welcome the player
  int tries = 0;
  int guess;

  cout << "\tWelcome to Guess My Number" << endl << endl;
  cout << "Guess my secret number between 1 and ";
  //cout << MAX_NUMBER << "." << endl << endl;
  cout << maxNumber << "." << endl << endl;

  //Player's Guess
  do
    {
      cout << "Enter a guess: ";
      cin >> guess;
      if(DEBUG)
	cout << "Player's guess is: " << guess << endl;
      tries++; 
      
      if(guess > secretNumber)
	cout << "Too high!" << endl << endl;
      if(guess < secretNumber)
	cout << "Too low!" << endl << endl;
      if(guess == secretNumber)
	break;
    }while ((guess != secretNumber) && (tries < 5));
  
  if(tries < 5)
    {
      //Congratulate Player
      cout << endl;
      cout << "You win! You guess my number in " << tries << " tries!" << endl;
    }
  else
    {
      // 5 tries used up
      cout << "Too bad, you couldn't guess my number in 5 tries! " << endl;
    }

  return 0;
}
