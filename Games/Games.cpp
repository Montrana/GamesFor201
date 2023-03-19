#include "Games.h"
#include "Deck.h"
#include "WarHand.h"
#include "BJ_Hand.h"

void blackjack() {

}
void craps() {
    int dieSum = rollDie();
    if (dieSum == 7 || dieSum == 11)
        cout << "You win!\n";
    else if (dieSum == 2 || dieSum == 3 || dieSum == 12)
        cout << "You lose!\n";
    else
    {
        int point = dieSum;
        dieSum = rollDie();
        while (dieSum != 7 && dieSum != point)
        {
            dieSum = rollDie();
        }
        if (dieSum == 7)
        {
            cout << "You lose!\n";
        }
        else if (dieSum == point)
        {
            cout << "You win!\n";
        }
    }
}
void hangman() {

}
void ticTacToe() {

}
void war() {
    Deck deck;
    list<card> tempPlayerHand, tempCompHand;

    deck.shuffle();
    deck.deal(STANDARD_DECK_SIZE / 2, tempPlayerHand);
    deck.deal(STANDARD_DECK_SIZE / 2, tempCompHand);

    WarHand playerHand(tempPlayerHand);
    WarHand compHand(tempCompHand);

    cout << "Player: " << playerHand.getTotalValue() << endl;
    card tempCard;
    while (playerHand.showCard(tempCard))
    {
        printCard(tempCard);
        cout << endl;
    }
    cout << endl;
    cout << "Computer: " << compHand.getTotalValue() << endl;
    while (compHand.showCard(tempCard))
    {
        printCard(tempCard);
        cout << endl;
    }
}

//For Craps:
int rollDie()
{
    srand(time(0));
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int dieSum = die1 + die2;
    cout << die1 << " + " << die2 << " = " << dieSum << endl;
    return dieSum;
}
/// <summary>
/// Prints a card with the appropriate suit, value and color. 
/// reference: https://www.codeproject.com/Tips/5255355/How-to-Put-Color-on-Windows-Console
/// </summary>
/// <param name="_card"></param>
void printCard(card _card)
{
    string face;
    if (_card.faceNum <= 10)
    {
        face = to_string(_card.faceNum);
    }
    else
    {
        if (_card.faceNum == 11)
        {
            face = "J";
        }
        else if(_card.faceNum == 12)
        {
            face = "Q";
        }
        else if (_card.faceNum == 13)
        {
            face = "K";
        }
        else if (_card.faceNum == 14)
        {
            face = "A";
        }
    }
    if (_card.suit == HEART || _card.suit == DIAMOND)
    {
        cout << "\033[31m" << _card.suit << " " << face << "\033[0m"; //prints red
    }
    else
    {
        cout << "\033[97m" << _card.suit << " " << face << "\033[0m"; //prints white
    }
}