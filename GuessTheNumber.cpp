#include <iostream>

using namespace std;

int main()
{
  int number = 55;
  int guessNumber;  // Declare the guessNumber variable

  cout << "Guess the number between 0-100: ";
  cin >> guessNumber;

  if (number == guessNumber)
  {
    cout << "You guessed the right number." << endl;
   }
  else
     {
        cout << "Try again!" << endl; // Added feedback for incorrect guess
     }

    return 0;
}
