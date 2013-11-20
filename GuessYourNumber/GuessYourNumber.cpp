//Game: Guess Your Number
//Player chooses random number
//Computer will guess

#include <iostream>

using namespace std;

int main()
{
  //Debugging on(1) or off(0)
  const int DEBUG = 0;
  if(DEBUG)
    cout << "Debugging on" << endl;
  
  //variables
  int rangeLow, rangeHigh;
  int low, high, guess; 
  int secretNumber, option;
  int tries = 0;
  bool gameFinished = false;
  bool optionValid = false;

  //Welcome the player
  cout << "\tWelcome to Guess Your Number!" << endl << endl;
  
  //Facilitator will ask for range of secret number
  cout << "Hello, I will be the facilitator of this game." << endl;
  cout << "Please input the low end of the range of numbers." << endl;
  cout << "Must be greater than or equal to 0." << endl;
  cout << "Low end: " ;
  cin >> rangeLow;
  if(DEBUG)
    cout << "rangeLow is: " << rangeLow << endl;
  cout << "\nPlease input the high end of the range of numbers." << endl;
  cout << "High end: " ;
  cin >> rangeHigh;
  if(DEBUG)
    cout << "rangeHigh is: " << rangeHigh << endl;

  //Facilitator will ask for the secret number to prevent cheating
  cout << "Now you may choose a number: ";
  cin >> secretNumber;
  if(DEBUG)
    cout << "secretNumber is: " << secretNumber << endl;
  while(!((secretNumber <= rangeHigh) && (secretNumber >= rangeLow)))
    {
      cout << "That is an invalid number. Please choose one within the range." << endl;
      cout << "New number: ";
      cin >> secretNumber;
      if(DEBUG)
	cout << "secretNumber is: " << secretNumber << endl;	
    }

  //Facilitator hands over to computer to guess
  cout << "\nAll preparations are complete. Let the guessing begin!" << endl;
  
  low = rangeLow;
  high = rangeHigh;
  
  do
    {
      //Computer guesses
      guess = (low + high) / 2;
      tries++;
      cout << "\nMy guess is " << guess << "." << endl;  
      if(DEBUG)
	cout << "tries is " << tries << endl;
      
      //Player tells if the number was low,high, or correct
      //Facilitator will make sure there is no cheating
      do
	{
	optionIncorrect:
	  cout << "\nIs this guess..." << endl;
	  cout << "1.Too Low " << endl;
	  cout << "2.Too High " << endl;
	  cout << "3.CORRECT! " << endl;
	  cout << "Please input the number corresponding to the option: ";
	  cin >> option;

	  switch(option)
	    {
	    case 1:
	      if(DEBUG)
		cout << "option " << option << " choosen" << endl;
	      if(guess < secretNumber)
		{
		  low = guess;
		  optionValid = true;
		}
	      else
		{
		  cout << "STOP LYING!" << endl;
		  goto optionIncorrect;
		}
		break;
	    case 2:
	      if(DEBUG)
		cout << "option " << option << " choosen" << endl;
	      if(guess > secretNumber)
		{
		  high = guess;
		  optionValid = true;
		}
	      else
		{
		  cout << "STOP LYING!" << endl;
		  goto optionIncorrect;
		}
	      break;
	    case 3:
	      if(DEBUG)
		cout << "option " << option << " choosen" << endl;
	      if(guess == secretNumber)
		{
		  optionValid = true;
		  gameFinished = true;
		}
	      else
		{
		  cout << "STOP LYING!" << endl;
		  goto optionIncorrect;
		}
	      break;
	    default:
	      if(DEBUG)
		cout << "option " << option << " choosen" << endl;
	      cout << "Choose a valid option." << endl;
	    }
	} while(!optionValid);
      
      optionValid = false;
      
    } while(!gameFinished);
  
  cout << "I guessed your number in " << tries << " tries." << endl;
    
    return 0;
}
