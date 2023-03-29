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

struct coordinate {
	int x, y;
};

//the coordinates of all the corners
const coordinate CORNERS[4] = {{0,0}, {2,0}, {0,2}, {2,2}};
//the coordinates of the center of the tic tac toe board
const coordinate CENTER = { 1, 1 };

const coordinate SIDES[4] = {{0,1}, {1,0}, {2,1}, {1,2}};

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

coordinate playerMove(char theBoard[3][3]);
void computerMove(char theBoard[3][3], vector<vector<coordinate>>const& winningCombos, coordinate playerLastMove);
bool validMove(char theBoard[3][3], coordinate moveChoice);
void generateWinningCombos(vector<vector<coordinate>>& winningCombos);
void printWinningCombos(vector<vector<coordinate>>& winningCombos);
void printBoard(char theBoard[3][3]);
bool checkCenterMove(char theBoard[3][3], coordinate& play);
bool checkCornerMove(char theBoard[3][3], coordinate& play, coordinate playerLastMove);
bool checkSideMove(char theBoard[3][3], coordinate& play);
bool checkWinningMove(char theBoard[3][3], vector<vector<coordinate>>const &winningCombos, coordinate& play);
bool checkWin(char theBoard[3][3], vector<vector<coordinate>>const &winningCombos, int& playerWon);

void printCard(card _card);