#pragma once
#include "Games.h"

#include "WarHand.h"
#include "BJ_Hand.h"

/// <summary>
/// Deck class that has the deck of cards that will be dealt to player's hands
/// </summary>
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

