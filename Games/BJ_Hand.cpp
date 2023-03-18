#include "BJ_Hand.h"

BJ_Hand::BJ_Hand() {
	handValue = 0;
}

BJ_Hand::BJ_Hand(vector<card> _cards) {
	hand = _cards;
}

void BJ_Hand::addCard(card _card) {
	hand.push_back(_card);
}