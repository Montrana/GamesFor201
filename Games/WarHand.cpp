#include "WarHand.h"

WarHand::WarHand(list<card> _cards) {
	hand = _cards;
	totalCards = hand.size();
	totalValue = 0;
	for (card _card : hand)
	{
		totalValue += _card.value;
	}
}

int WarHand::getTotalCards() 
{
	return totalCards;
}

int WarHand::getTotalValue() {
	return totalValue;
}

void WarHand::addCards(list<card> _cards) {
	for (card _card : _cards) {
		_card.value = _card.faceNum;
		hand.push_back(_card);
		totalCards++;
		totalValue += _card.value;
	}
}
bool WarHand::showCard(card& cardToShow) {
	if (!hand.empty())
	{
		cardToShow = hand.front();
		hand.pop_front();
		totalValue -= cardToShow.value;
		totalCards--;
		return true;
	}
	else
	{
		return false;
	}
}