#include "BJ_Hand.h"

BJ_Hand::BJ_Hand() {
	handValue = 0;
}

BJ_Hand::BJ_Hand(vector<card> _cards) {
	hand = _cards;
	handValue = 0;
	for (card _card : hand)
	{
		handValue += _card.value;
	}
}

int BJ_Hand::getHandValue()
{
	return handValue;
}

void BJ_Hand::addCard(card _card) {
	handValue += _card.value;
	hand.push_back(_card);
}

void BJ_Hand::showCards()
{
	cout << "\t";
	for (int i = 0; i < hand.size(); i++)
	{
		printCard(hand[i]);
	}
	
}
int BJ_Hand::showFirstCard()
{
	cout << "\t";
	printCard(hand[0]);
	cout << setw(7) << " ?";
	return hand[0].value;
}

void BJ_Hand::resetValue()
{
	handValue = 0;
	for (card _card : hand)
	{
		handValue += _card.value;
	}
}

bool BJ_Hand::makeAceLow()
{
    for (int i = 0; i < hand.size(); i++)
    {
        if (hand[i].value > 10)
        {
            hand[i].value = 1;
			resetValue();
            return true;
        }
    }
    return false;
}