// Games.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Games.h"
#include "Deck.h"

int main()
{
    string gameChoice;
    do
    {
        string playAgain;
        cout << "Games List:\n";
        cout << "(B)lackjack\n";
        cout << "(C)raps\n";
        cout << "(H)angman\n";
        cout << "(T)icTacToe\n";
        cout << "(W)ar\n";
        cout << "(Q)uit\n";
        cout << "What game would you like to play? ";
        cin >> gameChoice;
        gameChoice[0] = toupper(gameChoice[0]);
        if (gameChoice[0] == 'B')
        {
            do
            {
                cout << endl;
                blackjack();
                cout << "Would you like to play again (Y or N)? ";
                cin >> playAgain;
                playAgain[0] = toupper(playAgain[0]);
            } while (playAgain[0] == 'Y');
        }
        else if (gameChoice[0] == 'C')
        {
            do
            {
                cout << endl;
                craps();
                cout << "Would you like to play again (Y or N)? ";
                cin >> playAgain;
                playAgain[0] = toupper(playAgain[0]);
            } while (playAgain[0] == 'Y');
            
        }
        else if (gameChoice[0] == 'H')
        {
            do
            {
                cout << endl;
                hangman();
                cout << "Would you like to play again (Y or N)? ";
                cin >> playAgain;
                playAgain[0] = toupper(playAgain[0]);
            } while (playAgain[0] == 'Y');
            
        }
        else if (gameChoice[0] == 'T')
        {
            do
            {
                cout << endl;
                ticTacToe();
                cout << "Would you like to play again (Y or N)? ";
                cin >> playAgain;
                playAgain[0] = toupper(playAgain[0]);
            } while (playAgain[0] == 'Y');
        }
        else if (gameChoice[0] == 'W')
        {
            do
            {
                try
                {
                    cout << endl;
                    warGame();
                }
                catch (exception err)
                {
                    cout << endl;
                    cout << err.what() << endl;
                }
                cout << "Would you like to play again (Y or N)? ";
                cin >> playAgain;
                playAgain[0] = toupper(playAgain[0]);
            } while (playAgain[0] == 'Y');
        }
        else if (gameChoice[0] == 'Q')
        {
            return 0; 
        }
        else
        {
            cout << endl;
            cout << "That is not a valid choice.\n";
        }
    } while (true);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
