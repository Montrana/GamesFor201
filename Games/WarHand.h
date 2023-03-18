#pragma once
#include "Games.h"

class WarHand
{
private:
	list<card> hand;
	int totalCards;

public:
	WarHand(list<card> _cards);

	void addCard(card _card);
	bool showCard(card& cardToShow);
	void wonCards(list<card> _cardsWon);
};

