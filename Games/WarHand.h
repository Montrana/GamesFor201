#pragma once
#include "Games.h"

/// <summary>
/// The hand that is used for the war game
/// </summary>
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

