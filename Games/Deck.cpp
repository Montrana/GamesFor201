#include "Deck.h"

random_device rd;

Deck::Deck() {
    card tempCard;
    for (int s = 0; s < 4; s++) {
        tempCard.suit = SUITS[s];
        for (int f = 2; f <= 14; f++) {
            tempCard.faceNum = f;
            tempCard.value = f;
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


void Deck::dealWar(int cardsToDeal, list<card>& hand)
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

void Deck::deal_BJ(int cardsToDeal, vector<card>& hand)
{
    if (cardsToDeal <= deckOfCards.size())
    {
        for (int i = 0; i < cardsToDeal; i++)
        {
            card cardToDeal = deckOfCards.back();
            if (cardToDeal.faceNum > 10 && cardToDeal.faceNum < 14)
            {
                cardToDeal.value = 10;
            }
            else if (cardToDeal.faceNum == 14)
            {
                cardToDeal.value = 11;
            }
            hand.push_back(cardToDeal);
            deckOfCards.pop_back();
        }
    }
    else
    {
        throw runtime_error("Not enough cards in deck.");
    }
}