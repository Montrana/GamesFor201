#include "Games.h"
#include "Deck.h"
#include "WarHand.h"
#include "BJ_Hand.h"

void showCards(list<card>& wonCards, WarHand& playerHand, WarHand& compHand, card& playerCard, card& compCard)
{
    if (playerHand.showCard(playerCard))
    {
        printCard(playerCard);
        //cout << setw(8) << "?";
    }
    else
    {
        throw runtime_error("Player Lost");
        return;
    }
    if (compHand.showCard(compCard))
    {
        printCard(compCard);
        cout << endl;
        //cout << setw(8) << "?\n";
    }
    else
    {
        throw runtime_error("Computer Lost");
        return;
    }
    wonCards.push_back(playerCard);
    wonCards.push_back(compCard);
}

void warInitiated(list<card>& wonCards, WarHand& playerHand, WarHand& compHand)
{
    cout << setw(15) << "WAR!!\n";
    card playerCard;
    card compCard;


    for (int i = 0; i < 3; i++)
    {
        showCards(wonCards, playerHand, compHand, playerCard, compCard);
    }
    if (playerHand.showCard(playerCard))
    {
        printCard(playerCard);
    }
    else
    {
        throw runtime_error("Player Lost");
        return;
    }
    if (compHand.showCard(compCard))
    {
        printCard(compCard);
        cout << endl;
    }
    else
    {
        throw runtime_error("Computer Lost");
        return;
    }

    int playerVal = playerCard.value;
    int compVal = compCard.value;
    wonCards.push_back(playerCard);
    wonCards.push_back(compCard);
    //std::shuffle(wonCards.begin(), wonCards.end(), rd);
    if (playerVal > compVal)
    {
        playerHand.addCards(wonCards);
        cout << "Player has " << playerHand.getTotalCards() << " cards.\n";
        cout << "Computer has " << compHand.getTotalCards() << " cards.\n";
        cout << endl;
        cout << "Player has " << playerHand.getTotalValue() << " totalValue.\n";
        cout << "Computer has " << compHand.getTotalValue() << " totalValue.\n";
        cout << endl;
    }
    else if (playerVal < compVal)
    {
        compHand.addCards(wonCards);
        cout << "Player has " << playerHand.getTotalCards() << " cards.\n";
        cout << "Computer has " << compHand.getTotalCards() << " cards.\n";
        cout << endl;
        cout << "Player has " << playerHand.getTotalValue() << " totalValue.\n";
        cout << "Computer has " << compHand.getTotalValue() << " totalValue.\n";
        cout << endl;
    }
    else
    {
        warInitiated(wonCards, playerHand, compHand);
    }
}

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
void warGame() {
    Deck deck;
    list<card> tempPlayerHand, tempCompHand;
    //random_device rand;

    deck.shuffle();
    deck.deal(STANDARD_DECK_SIZE / 2, tempPlayerHand);
    deck.deal(STANDARD_DECK_SIZE / 2, tempCompHand);

    WarHand playerHand(tempPlayerHand);
    WarHand compHand(tempCompHand);

    /*cout << "Player: " << playerHand.getTotalValue() << endl;
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
    }*/

    card playerCard;
    card compCard;

    while (playerHand.showCard(playerCard) && compHand.showCard(compCard))
    {
        cout << setw(10) << "Player";
        cout << setw(10) << "Computer" << endl;
        cout << endl;

        printCard(playerCard);
        printCard(compCard);
        cout << endl;

        list<card> wonCards;
       
        double playerVal = playerCard.value;
        double compVal = compCard.value;

        wonCards.push_back(playerCard);
        wonCards.push_back(compCard);
        //std::shuffle(wonCards.begin(), wonCards.end(), rand);
        if (playerVal > compVal)
        {
            playerHand.addCards(wonCards);
            cout << "Player has " << playerHand.getTotalCards() << " cards.\n";
            cout << "Computer has " << compHand.getTotalCards() << " cards.\n";
            cout << endl;
            cout << "Player has " << playerHand.getTotalValue() << " totalValue.\n";
            cout << "Computer has " << compHand.getTotalValue() << " totalValue.\n";
            cout << endl;
        }
        else if (playerVal < compVal)
        {
            compHand.addCards(wonCards);
            cout << "Player has " << playerHand.getTotalCards() << " cards.\n";
            cout << "Computer has " << compHand.getTotalCards() << " cards.\n";
            cout << endl;
            cout << "Player has " << playerHand.getTotalValue() << " total value.\n";
            cout << "Computer has " << compHand.getTotalValue() << " total value.\n";
            cout << endl;
        }
        else if (playerVal == compVal)
        {
            warInitiated(wonCards, playerHand, compHand);
        }
        //string confirmation;
        //cout << "Type \"Y\" to continue: ";
        //cin >> confirmation;
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
        cout << setw(10) << "\033[31m" << _card.suit << " " << face << "\033[0m"; //prints red
    }
    else
    {
        cout << setw(10) << "\033[97m" << _card.suit << " " << face << "\033[0m"; //prints white
    }
}