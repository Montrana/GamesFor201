#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <windows.h>
#include <list>
#include <algorithm>
#include <random>
#include <fstream>

//#include "WarHand.h"
using namespace std;

struct card {
	char suit;
	int faceNum; //the number identifier of the face. Jacks are 11, Queens 12, etc.
	int value; //the value the card holds. In Black Jack, the face cards are all 10, the Aces may be 1 or 11.
			   //In war, they're the same as the face number;
};

struct coordinates {
	int x, y;
};

//the coordinates of all the corners
const coordinates CORNERS[4] = {{0,0}, {0,2}, {2,0}, {2,2}};
//the coordinates of the center of the tic tac toe board
const coordinates CENTER = { 1, 1 };

//Christian, during class
const char HEART = '\x03';
const char DIAMOND = '\x04';
const char CLUB = '\x05';
const char SPADE = '\x06';

const char SUITS[4] = { HEART, DIAMOND, CLUB, SPADE };

const int STANDARD_DECK_SIZE = 52;

const string PLAYER_LOST = "You Lost!";
const string PLAYER_WON = "You Won!";

void blackjack();
void craps();
void hangman();
void ticTacToe();
void warGame();

int rollDie();

string setRandomWord();

void playerMove(char theBoard[3][3]);
void computerMove(char theBoard[3][3]);
bool validMove(char theBoard[3][3], coordinates moveChoice);
void generateWinningCombos(vector<vector<coordinates>>& winningCombos);
void printWinningCombos(vector<vector<coordinates>>& winningCombos);
void printBoard(char theBoard[3][3]);
bool checkWinningMove(char theBoard[3][3], vector<vector<coordinates>>& winningCombos, coordinates& play);
bool checkWin(char theBoard[3][3], vector<vector<coordinates>>& winningCombos, bool& playerWon);

void printCard(card _card);