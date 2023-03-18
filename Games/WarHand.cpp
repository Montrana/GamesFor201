#include "WarHand.h"

WarHand::WarHand(list<card> _cards) {
	hand = _cards;
	totalCards = hand.size();
	for (card _card : hand)
	{
		_card.value = _card.faceNum;
	}
}

void WarHand::addCard(card _card) {
	_card.value = _card.faceNum;
	hand.push_back(_card);
	totalCards++;
}
bool WarHand::showCard(card& cardToShow) {
	if (!hand.empty())
	{
		cardToShow = hand.front();
		hand.pop_front();
		totalCards--;
		return true;
	}
	else
	{
		return false;
	}
}

void WarHand::wonCards(list<card> _cardsWon) {
	for (card cardWon : _cardsWon) {
		hand.push_back(cardWon);
		totalCards++;
	}
}