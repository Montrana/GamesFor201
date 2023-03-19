#pragma once
#include "Games.h"

class WarHand
{
private:
	list<card> hand;
	int totalCards;
	int totalValue;

public:
	WarHand(list<card> _cards);

	int getTotalCards();
	int getTotalValue();

	void addCards(list<card> _cardsWon);
	bool showCard(card& cardToShow);
};

