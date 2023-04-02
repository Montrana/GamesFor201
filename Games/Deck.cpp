#include "Deck.h"

random_device rd;

/// <summary>
/// Initializes the deck of 52 cards
/// </summary>
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

/// <summary>
/// Shuffles the deck
/// </summary>
void Deck::shuffle() {
    std::shuffle(deckOfCards.begin(), deckOfCards.end(), rd);
}

/// <summary>
/// Prints the deck
/// </summary>
void Deck::print() {
    for (card _card : deckOfCards) {
        printCard(_card);
        cout << endl;
    }
}

/// <summary>
/// Deals for war
/// </summary>
/// <param name="cardsToDeal">Number of cards that are dealt</param>
/// <param name="hand">The hand the cards are dealt to</param>
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

/// <summary>
/// Deal for blackjack
/// </summary>
/// <param name="cardsToDeal">Number of cards that are dealt</param>
/// <param name="hand">The hand the cards are dealt to</param>
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