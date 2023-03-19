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


void Deck::deal(int cardsToDeal, list<card>& hand)
{
    if (cardsToDeal <= deckOfCards.size())
    {
        for (int i = 0; i < cardsToDeal; i++)
        {
            hand.push_front(deckOfCards.back());
            deckOfCards.pop_back();
        }
    }
    else
    {
        throw runtime_error("Not enough cards in deck.");
    }
}