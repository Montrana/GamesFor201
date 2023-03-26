#include "Games.h"
#include "Deck.h"
#include "WarHand.h"
#include "BJ_Hand.h"

void showCards(list<card>& wonCards, WarHand& playerHand, WarHand& compHand, card& playerCard, card& compCard)
{
    if (playerHand.showCard(playerCard))
    {
        printCard(playerCard);
        //cout << setw(8) << "?";
    }
    else
    {
        throw runtime_error(PLAYER_LOST);
        return;
    }
    if (compHand.showCard(compCard))
    {
        printCard(compCard);
        cout << endl;
        //cout << setw(8) << "?\n";
    }
    else
    {
        throw runtime_error(PLAYER_WON);
        return;
    }
    wonCards.push_back(playerCard);
    wonCards.push_back(compCard);
}

void warInitiated(list<card>& wonCards, WarHand& playerHand, WarHand& compHand)
{
    cout << setw(15) << "WAR!!\n";
    card playerCard;
    card compCard;


    for (int i = 0; i < 3; i++)
    {
        showCards(wonCards, playerHand, compHand, playerCard, compCard);
    }
    if (playerHand.showCard(playerCard))
    {
        printCard(playerCard);
    }
    else
    {
        throw runtime_error(PLAYER_LOST);
        return;
    }
    if (compHand.showCard(compCard))
    {
        printCard(compCard);
        cout << endl;
    }
    else
    {
        throw runtime_error(PLAYER_WON);
        return;
    }

    int playerVal = playerCard.value;
    int compVal = compCard.value;
    wonCards.push_back(playerCard);
    wonCards.push_back(compCard);
    //std::shuffle(wonCards.begin(), wonCards.end(), rd);
    if (playerVal > compVal)
    {
        playerHand.addCards(wonCards);
        cout << "Player has " << playerHand.getTotalCards() << " cards.\n";
        cout << "Computer has " << compHand.getTotalCards() << " cards.\n";
        cout << endl;
        cout << "Player has " << playerHand.getTotalValue() << " totalValue.\n";
        cout << "Computer has " << compHand.getTotalValue() << " totalValue.\n";
        cout << endl;
    }
    else if (playerVal < compVal)
    {
        compHand.addCards(wonCards);
        cout << "Player has " << playerHand.getTotalCards() << " cards.\n";
        cout << "Computer has " << compHand.getTotalCards() << " cards.\n";
        cout << endl;
        cout << "Player has " << playerHand.getTotalValue() << " totalValue.\n";
        cout << "Computer has " << compHand.getTotalValue() << " totalValue.\n";
        cout << endl;
    }
    else
    {
        warInitiated(wonCards, playerHand, compHand);
    }
}

void blackjack() {

}
void craps() {
    int dieSum = rollDie();
    if (dieSum == 7 || dieSum == 11)
        cout << PLAYER_WON << endl;
    else if (dieSum == 2 || dieSum == 3 || dieSum == 12)
        cout << PLAYER_LOST << endl;
    else
    {
        int point = dieSum;
        dieSum = rollDie();
        while (dieSum != 7 && dieSum != point)
        {
            dieSum = rollDie();
        }
        if (dieSum == 7)
        {
            cout << PLAYER_LOST << endl;
        }
        else if (dieSum == point)
        {
            cout << PLAYER_WON << endl;
        }
    }
}
void hangman() {
    string correctWord = setRandomWord();
    int guessesLeft = 6;
    vector <char> lettersGuessed;
    string guessWord = correctWord;
    for (int i = 0; i < correctWord.size(); i ++)
    {
        guessWord[i] = '?';
    }
    cout << "This is the word you need to guess: " << guessWord << endl;
    cout << "You have " << guessesLeft << " guesses left.\n";

    do
    {
        string guessInput;
        cout << "What is your guess? ";
        cin >> guessInput;
        char guess = tolower(guessInput[0]);
        if (!isalpha(guess))
        {
            cout << "Invalid input, please enter a letter.\n";
            continue;
        }
        for (char guessTried : lettersGuessed)
        {
            if (guess == guessTried)
            {
                cout << "You have already guessed that letter, please enter a different one.\n";
                continue;
            }
        }
        lettersGuessed.push_back(guess);
        if (correctWord.find(guess) != string::npos)
        {
            for (int i = 0; i < correctWord.size(); i++)
            {
                if (guess == correctWord[i])
                {
                    guessWord[i] = guess;
                }
            }
            cout << "Correct!\n";
        }
        else
        {
            cout << "Incorrect!\n";
            guessesLeft--;
        }
        cout << "This is the word you need to guess: " << guessWord << endl;
        cout << "You have " << guessesLeft << " guesses left.\n";
    } while (guessesLeft > 0 && correctWord != guessWord);
    if (guessesLeft == 0)
    {
        cout << PLAYER_LOST << " The word was: " << correctWord << endl;
    }
    else
    {
        cout << PLAYER_WON << endl;
    }
}
void ticTacToe() {
    srand(time(0));
    
    char theBoard[3][3] = { {'1', '2', '3'},
                            {'4', '5', '6'},
                            {'7', '8', '9'}};
    vector<vector<coordinates>> winningCombos;
    generateWinningCombos(winningCombos);
    bool playerWin;
    bool coinFlip = rand() % 2;
    while (!checkWin(theBoard, winningCombos, playerWin))
    {
        printBoard(theBoard);
        playerMove(theBoard);
    }
    printBoard(theBoard);
    if (playerWin)
    {
        cout << PLAYER_WON << endl;
    }
    else
    {
        cout << PLAYER_LOST << endl;
    }
}
void warGame() {
    Deck deck;
    list<card> tempPlayerHand, tempCompHand;
    //random_device rand;

    deck.shuffle();
    deck.deal(STANDARD_DECK_SIZE / 2, tempPlayerHand);
    deck.deal(STANDARD_DECK_SIZE / 2, tempCompHand);

    WarHand playerHand(tempPlayerHand);
    WarHand compHand(tempCompHand);

    card playerCard;
    card compCard;

    while (playerHand.showCard(playerCard) && compHand.showCard(compCard))
    {
        cout << setw(10) << "Player";
        cout << setw(10) << "Computer" << endl;
        cout << endl;

        printCard(playerCard);
        printCard(compCard);
        cout << endl;

        list<card> wonCards;
       
        double playerVal = playerCard.value;
        double compVal = compCard.value;

        wonCards.push_back(playerCard);
        wonCards.push_back(compCard);
        //std::shuffle(wonCards.begin(), wonCards.end(), rand);
        if (playerVal > compVal)
        {
            playerHand.addCards(wonCards);
            cout << "Player has " << playerHand.getTotalCards() << " cards.\n";
            cout << "Computer has " << compHand.getTotalCards() << " cards.\n";
            cout << endl;
            cout << "Player has " << playerHand.getTotalValue() << " totalValue.\n";
            cout << "Computer has " << compHand.getTotalValue() << " totalValue.\n";
            cout << endl;
        }
        else if (playerVal < compVal)
        {
            compHand.addCards(wonCards);
            cout << "Player has " << playerHand.getTotalCards() << " cards.\n";
            cout << "Computer has " << compHand.getTotalCards() << " cards.\n";
            cout << endl;
            cout << "Player has " << playerHand.getTotalValue() << " total value.\n";
            cout << "Computer has " << compHand.getTotalValue() << " total value.\n";
            cout << endl;
        }
        else if (playerVal == compVal)
        {
            warInitiated(wonCards, playerHand, compHand);
        }
        //string confirmation;
        //cout << "Type \"Y\" to continue: ";
        //cin >> confirmation;
    }
}


//For Craps:
int rollDie()
{
    srand(time(0));
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int dieSum = die1 + die2;
    cout << die1 << " + " << die2 << " = " << dieSum << endl;
    return dieSum;
}

//For Hangman:
string setRandomWord()
{
    srand(time(0));
    ifstream inFile;
    inFile.open("words.txt");
    if (!inFile.is_open())
    {
        cout << "Unable to open input file\n";
        return " ";
    }
    string word;
    vector<string> wordList;

    while (inFile >> word) {
        wordList.push_back(word);
    }
    int wordNum = rand() % wordList.size();
    inFile.close();
    return wordList[wordNum];
}

//For Tic Tac Toe:
void playerMove(char theBoard[3][3])
{
    int moveNum;
    coordinates moveCoord;
    do{
        cout << "Where would you like to move? ";
        cin >> moveNum;
        try
        {
            moveCoord.x = (moveNum - 1) % 3;
            moveCoord.y = (moveNum - 1) / 3;
            if (validMove(theBoard, moveCoord))
            {
                theBoard[moveCoord.y][moveCoord.x] = 'X';
                break;
            }
            else
            {
                throw runtime_error("That is not a valid move, please choose a position that hasn't played in.");
            }
        }
        catch (exception err)
        {
            cout << err.what() << endl;
            continue;
        }
        catch (...)
        {
            cout << "That is not a valid move, please select a number from the board.\n";
            continue;
        }
    } while (!validMove(theBoard, moveCoord));
}

void computerMove(char theBoard[3][3])
{

}

bool validMove(char theBoard[3][3], coordinates moveChoice)
{
    if (theBoard[moveChoice.y][moveChoice.x] >= '1' &&
        theBoard[moveChoice.y][moveChoice.x] <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void generateWinningCombos(vector<vector<coordinates>>& winningCombos)
{
    vector<coordinates> tempRow;
    // Generating winning combinations for the rows
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            coordinates tempCoords{};
            tempCoords.x = i;
            tempCoords.y = j;
            tempRow.push_back(tempCoords);
        }
        winningCombos.push_back(tempRow);
        tempRow.clear();
    }

    // Generating winning combinations for the columns
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            coordinates tempCoords{};
            tempCoords.x = j;
            tempCoords.y = i;
            tempRow.push_back(tempCoords);
        }
        winningCombos.push_back(tempRow);
        tempRow.clear();
    }

    // Generating winning combinations for the diagonals
    for (int i = 0; i < 3; i++)
    {
        coordinates tempCoords{};
        tempCoords.x = i;
        tempCoords.y = i;
        tempRow.push_back(tempCoords);
    }
    winningCombos.push_back(tempRow);
    tempRow.clear();
    for (int i = 0; i < 3; i++)
    {
        coordinates tempCoords{};
        tempCoords.x = i;
        tempCoords.y = 2 - i;
        tempRow.push_back(tempCoords);
    }
    winningCombos.push_back(tempRow);
    tempRow.clear();
}

void printWinningCombos(vector<vector<coordinates>>& winningCombos)
{
    for (int i = 0; i < winningCombos.size(); i++)
    {
        for (int j = 0; j < winningCombos[i].size(); j++)
        {
            cout << winningCombos[i][j].x << ", " << winningCombos[i][j].y << " ";
        }
        cout << endl;
    }
}

void printBoard(char theBoard[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << theBoard[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWinningMove(char theBoard[3][3], vector<vector<coordinates>>& winningCombos, coordinates& play)
{
    for (vector<coordinates> combo : winningCombos)
    {
        if (theBoard[combo[0].y][combo[0].x] == theBoard[combo[1].y][combo[1].x])
        {
            play.x = combo[2].x;
            play.y = combo[2].y;
            return true;
        }
        if (theBoard[combo[1].x][combo[1].y] == theBoard[combo[2].x][combo[2].y])
        {
            play.x = combo[0].x;
            play.y = combo[0].y;
            return true;
        }
        if (theBoard[combo[0].x][combo[0].y] == theBoard[combo[2].x][combo[2].y])
        {
            play.x = combo[1].x;
            play.y = combo[1].y;
            return true;
        }
    }
    return false;
}

bool checkWin(char theBoard[3][3], vector<vector<coordinates>>& winningCombos, bool& playerWon)
{
    for (vector<coordinates> combo : winningCombos)
    {
        if (theBoard[combo[0].y][combo[0].x] == theBoard[combo[1].y][combo[1].x] &&
            theBoard[combo[1].y][combo[1].x] == theBoard[combo[2].y][combo[2].x])
        {
            if (theBoard[combo[0].y][combo[0].x] == 'X')
            {
                playerWon = true;
            }
            else
            {
                playerWon = false;
            }
            return true;
        }
    }
    return false;
}

/// <summary>
/// Prints a card with the appropriate suit, value and color. 
/// reference: https://www.codeproject.com/Tips/5255355/How-to-Put-Color-on-Windows-Console
/// </summary>
/// <param name="_card"></param>
void printCard(card _card)
{
    string face;
    if (_card.faceNum <= 10)
    {
        face = to_string(_card.faceNum);
    }
    else
    {
        if (_card.faceNum == 11)
        {
            face = "J";
        }
        else if(_card.faceNum == 12)
        {
            face = "Q";
        }
        else if (_card.faceNum == 13)
        {
            face = "K";
        }
        else if (_card.faceNum == 14)
        {
            face = "A";
        }
    }
    if (_card.suit == HEART || _card.suit == DIAMOND)
    {
        cout << setw(10) << "\033[31m" << _card.suit << " " << face << "\033[0m"; //prints red
    }
    else
    {
        cout << setw(10) << "\033[97m" << _card.suit << " " << face << "\033[0m"; //prints white
    }
}