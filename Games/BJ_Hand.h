#pragma once
#include "Games.h"

/// <summary>
/// The hand that is used for Blackjack
/// </summary>
class BJ_Hand
{
private:
	vector<card> hand;
	int handValue;

public:
	BJ_Hand();
	BJ_Hand(vector<card> _cards);

	int getHandValue();

	void addCard(card _card);
	void showCards();
	int showFirstCard();
	void resetValue();
	bool makeAceLow();
};

