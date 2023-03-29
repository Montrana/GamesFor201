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
	void dealWar(int cardsToDeal, list<card>& hand);
	void deal_BJ(int cardsToDeal, vector<card>& hand);
};

