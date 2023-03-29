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
	hand.push_back(_card);
}

void BJ_Hand::showCards()
{
	for (int i = 0; i < hand.size(); i++)
	{
        string face;
        if (hand[i].faceNum <= 10)
        {
            face = to_string(hand[i].faceNum);
        }
        else
        {
            if (hand[i].faceNum == 11)
            {
                face = "J";
            }
            else if (hand[i].faceNum == 12)
            {
                face = "Q";
            }
            else if (hand[i].faceNum == 13)
            {
                face = "K";
            }
            else if (hand[i].faceNum == 14)
            {
                face = "A";
            }
        }
        if (hand[i].suit == HEART || hand[i].suit == DIAMOND)
        {
            cout << setw(10) << "\033[31m" << hand[i].suit << " " << face << "\033[0m"; //prints red
        }
        else
        {
            cout << setw(10) << "\033[97m" << hand[i].suit << " " << face << "\033[0m"; //prints white
        }
	}
}