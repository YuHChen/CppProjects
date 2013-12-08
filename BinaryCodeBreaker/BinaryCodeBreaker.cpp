//Game: Binary Code Breaker
//Player must guess the code in five tries or less.
//Computer will tell how many digits are correct after each guess.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  //setting debug on(1) or off(0)
  const int DEBUG = 0;
  if(DEBUG)
    cout << "DEBUGGING ON" << endl;

  //Generate 4-digit code of 1's and 0's

  //seed random generator
  srand(static_cast<unsigned int>(time(0)));
  //generate secretcode
  int secretCode[4];
  for(int i = 0; i < 4; i++)
    {
      secretCode[i] = (rand() % 2);
    }
  if(DEBUG)
    {
      for(int i = 0; i < 4; i++)
	  cout << secretCode[i];
      cout << endl;
    }

  //Welcome player
  cout << "\t\t\tWelcome to Binary Code Breaker!" << endl << endl;
  cout << "Guess the secret code in under 5 tries to win." << endl;
  cout << "Enter 'quit' to quit the game." << endl << endl;

  //Gameplay
  string guess;
  int numMatched = 0;
  int tries = 0;
  
  //guessing loop
  do
    {
      //Player submits guess
      cout << "What is your guess? ";
      cin >> guess;
      tries++;
      if(DEBUG){
	cout << "guess is " << guess << endl;
	cout << "tries: " << tries << endl;
      }
      
      //Computer tells how many digits match
      numMatched = 0;
      for(int i = 0; i < 4; i++)
	if(guess != "quit")
	  {
	    char temp = guess[i];
	    if(DEBUG)
	      cout << "temp: " << temp << endl;
	    if((temp - '0') == secretCode[i])
	      numMatched++;
	  }
      if((numMatched < 4) && (guess != "quit"))
	cout << "Your guess matched " << numMatched << " digits in the secret code" << endl << endl;
      
    } while((numMatched != 4) && (guess != "quit") && (tries < 5));
      
  //End game if over five tries or player guesses correctly

  if(numMatched == 4)
	cout << endl << "Congratulations! You guessed right in 5 tries or less." << endl;
  else
    {
      cout << endl << "Sorry, but you did not guess correctly in 5 tries or less." << endl;
      cout << "The secret code was ";
      for(int i = 0; i<4; i++)
	cout << secretCode[i];
      cout << endl;
    }

  cout << endl << "THANKS FOR PLAYING!" << endl;
  
  return 0;
}
