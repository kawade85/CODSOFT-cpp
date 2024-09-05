#include <iostream>

using namespace std;

int main() 
{
    double num1, num2;     // Declare variables
    char opp;

    cout << "***** Easy Calci-Use *****";

    cout << "\n\nEnter an operator (+, -, *, /): ";
    cin >> opp;

    cout << "Enter first number: ";     // Prompt user for input
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    

    // Perform the operation based on user input

    switch(opp) 
    {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':

            // Check for division by zero

            if (num2 != 0) 
            {
                cout << "Result: " << num1 / num2 << endl;
            } 
            else 
            {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;

        default:
            cout << "Error! Invalid operator." << endl;
            break;
    }

    return 0;
}
