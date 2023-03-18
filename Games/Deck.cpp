#include "Deck.h"

random_device rd;

Deck::Deck() {
    card tempCard;
    for (int s = 0; s < 4; s++) {
        tempCard.suit = SUITS[s];
        for (int f = 2; f <= 14; f++) {
            tempCard.faceNum = f;
            deckOfCards.push_back(tempCard);
        }
    }
}

void Deck::shuffle() {
    std::shuffle(deckOfCards.begin(), deckOfCards.end(), rd);
}

void Deck::print() {
    for (card _card : deckOfCards) {
        printCard(_card);
        cout << endl;
    }
}

void Deck::warDeal(int cardsToDeal, WarHand& playerHand, WarHand& compHand)
{

}
void Deck::bjDeal(int cardsToDeal, WarHand& playerHand, WarHand& compHand)
{

}