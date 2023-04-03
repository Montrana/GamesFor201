#include "BJ_Hand.h"

/// <summary>
/// A default hand that initiallizes a hand value to 0
/// </summary>
BJ_Hand::BJ_Hand() {
	handValue = 0;
}

/// <summary>
/// Sets the hand and with the total hand value
/// </summary>
/// <param name="_cards">the cards that are put put into the hand</param>
BJ_Hand::BJ_Hand(vector<card> _cards) {
	hand = _cards;
	handValue = 0;
	for (card _card : hand)
	{
		handValue += _card.value;
	}
}

/// <summary>
/// Gets the value of the hand
/// </summary>
/// <returns>the value of the hand</returns>
int BJ_Hand::getHandValue()
{
	return handValue;
}

/// <summary>
/// adds a card into the deck
/// </summary>
/// <param name="_card">the card to add</param>
void BJ_Hand::addCard(card _card) {
	handValue += _card.value;
	hand.push_back(_card);
}

/// <summary>
/// shows the cards in their deck
/// </summary>
void BJ_Hand::showCards()
{
	cout << "\t";
	for (int i = 0; i < hand.size(); i++)
	{
		printCard(hand[i]);
	}
	
}

/// <summary>
/// Shows the first card, and has a question mark for the second
/// </summary>
/// <returns></returns>
int BJ_Hand::showFirstCard()
{
	cout << "\t";
	printCard(hand[0]);
	cout << setw(7) << " ?";
	return hand[0].value;
}

/// <summary>
/// recalculates the hand value
/// </summary>
void BJ_Hand::resetValue()
{
	handValue = 0;
	for (card _card : hand)
	{
		handValue += _card.value;
	}
}

/// <summary>
/// changes the ace to be low
/// </summary>
void BJ_Hand::makeAceLow()
{
    for (int i = 0; i < hand.size(); i++)
    {
        if (hand[i].value > 10)
        {
            hand[i].value = 1;
			resetValue();
        }
    }
    
}