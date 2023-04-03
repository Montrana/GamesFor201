/// Name: Montana Nicholson
/// Date: 3/17/2023
/// This project is a combination of 5 games, Blackjack, Craps, Hangman, Tictactoe, and War

#include "Games.h"
#include "Deck.h"

/// <summary>
/// Plays one of 5 games, blackjack, craps, hangman, and tictactoe;
/// </summary>
/// <returns>An exit integer</returns>
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