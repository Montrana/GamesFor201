#pragma once
#include "Games.h"
#include "WarHand.h"

class Deck {
private: 
	vector<card> deckOfCards;

public:
	Deck();

	void shuffle();
	void print();
	void warDeal(int cardsToDeal, WarHand& playerHand, WarHand& compHand);
	void bjDeal(int cardsToDeal, WarHand& playerHand, WarHand& compHand);
};

