#pragma once
#include "Games.h"

#include "WarHand.h"
#include "BJ_Hand.h"

class Deck {
private: 
	vector<card> deckOfCards;

public:
	Deck();

	void shuffle();
	void print();
	void deal(int cardsToDeal, list<card>& hand);
};

