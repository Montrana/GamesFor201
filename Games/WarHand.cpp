#include "WarHand.h"

/// <summary>
/// Initializes the hand and adds the total value
/// </summary>
/// <param name="_cards">the list of cards that will be put in the hand</param>
WarHand::WarHand(list<card> _cards) {
	hand = _cards;
	totalCards = hand.size();
	totalValue = 0;
	for (card _card : hand)
	{
		totalValue += _card.value;
	}
}

/// <summary>
/// gets the total amount of cards
/// </summary>
/// <returns>the total amount of cards</returns>
int WarHand::getTotalCards() 
{
	return totalCards;
}

/// <summary>
/// gets the total value of all the cards
/// </summary>
/// <returns>the total value of all the cards</returns>
int WarHand::getTotalValue() {
	return totalValue;
}

/// <summary>
/// Adds cards into the hand
/// </summary>
/// <param name="_cards">The cards that will be added</param>
void WarHand::addCards(list<card> _cards) {
	for (card _card : _cards) {
		_card.value = _card.faceNum;
		hand.push_back(_card);
		totalCards++;
		totalValue += _card.value;
	}
}

/// <summary>
/// shows the top card of the hand
/// </summary>
/// <param name="cardToShow">card that is being showed</param>
/// <returns>if there's a card that can be shown</returns>
bool WarHand::showCard(card& cardToShow) {
	if (!hand.empty())
	{
		cardToShow = hand.front();
		hand.pop_front();
		totalValue -= cardToShow.value;
		totalCards--;
		return true;
	}
	else
	{
		return false;
	}
}