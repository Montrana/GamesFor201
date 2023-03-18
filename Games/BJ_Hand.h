#pragma once
#include "Games.h"

class BJ_Hand
{
private:
	vector<card> hand;
	int handValue;

public:
	BJ_Hand();
	BJ_Hand(vector<card> _cards);

	void addCard(card _card);
};

