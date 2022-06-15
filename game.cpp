#include <iostream>
#include "uno.hpp"
#include <string>
#include <vector>


//Game Class Methods

Game::Game(std::vector<Card> &deck) : g_deck(deck) {}

void Game::createPlayers() 
{
    std::cout << "How many players are playing the game?\n";
    while ((!(std::cin >> numPlayers)) or numPlayers == 0) // this loop checks for user error and makes sure numPlayers is an integer.
    {
        std::cout << "Please enter an integer greater than zero:\nHow many players are playing the game?\n";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }
    
    for (int deal = 0; deal < numPlayers; deal++)
    {
        //std::cout << "\ndealing\n";
        for (int handSize = 0; handSize < 7; handSize++)
        {
            //printAttributes(); // printAttributes() is defined later. prints every attribute of the class Hands.
            //std::cout << "\nSize: " << g_deck.size();
            int availableCards = g_deck.size(); // checks how many cards are still available to be dealt.
            int selection = rand() % (availableCards + 1); // stores the selection number that was randomly generated from the number of available cards. selection is between 0 and the h_deck size. I add one because the rand() function generates a number between 0 and one less than the number to the right of the %.
            hand.push_back(g_deck[selection]); // here the selected card is put into a hand.
            g_deck.erase(g_deck.begin() + (selection)); // the card put into the hand is then removed from the h_deck.   
        }
        hands.push_back(hand);
        hand.clear();
        //std::cout << "Hands dealt";
    }
    
    /*
        for (int handSize = 0; handSize < 7; handSize++) // 7 cards are dealt to each player, so a card is dealt to each hand 7 times.
        {
            std::vector<std::string> hand;
            printAttributes(); // printAttributes() is defined later. prints every attribute of the class Hands.
            availableCards = h_deck.size(); // checks how many cards are still available to be dealt.
            selection = rand() % (availableCards + 1); // stores the selection number that was randomly generated from the number of available cards. selection is between 0 and the h_deck size. I add one because the rand() function generates a number between 0 and one less than the number to the right of the %.
            card = h_deck[selection]; // gets the string for the card that was selected. for debugging to make sure an actual card is picked.
            hand.push_back(card); // here the selected card is put into a hand.
            h_deck.erase(h_deck.begin() + (selection - 1)); // the card put into the hand is then removed from the h_deck.
        */
    for (int p = 0; p < numPlayers; p++)
    {
        std::string playerName;
        std::cout << "Enter player name: ";
        std::cin >> playerName;
        playerNames.push_back(playerName);
        playerList.push(Player(playerNames[p], (p + 1), hands[p]));
    }
    std::cout << "\nSize: " << playerNames.size();

    int midS = rand() % (g_deck.size() + 1);
    middlePile.push(g_deck[midS]);
    g_deck.erase((g_deck.begin() + midS));

}

void Game::printHands()
{   
    //std::cout << "Type: " << typeid(hands[0][0]).name() << "\n";
    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "\nHand #" << (i + 1) << ":\n";
        for (int c = 0; c < 7; c++) // haha c++, like the name of the language
        {
            std::cout << hands[i][c].getName() << ", ";
        }
    }
}

void Game::printPlayerList()
{
    for (int i = 0; i < playerList.size(); i++)
    {
        std::cout << "Name: " << playerList.front().getName() << " Number: " << playerList.front().getNumber() << "\n";
        playerList.push(playerList.front());
        playerList.pop();
    }
}
/*
int Game::check()
{

}*/
void Game::updatePlayerList(std::queue<Player> anewplayerList)
{
    playerList = anewplayerList;
}

/*
int Game::check(Card apick, Card atop)
{
    Card pick = apick;
    Card top = atop;

    if ((pick.getColor() == top.getColor()) || (pick.getNumber() == top.getNumber()))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
*/
void Game::playGame()
{
    bool picking = true;
    std::string pickColor = "";
    std::string pickNumber = "";

    while (picking == true)
    {
    int currentPlayer = (playerList.front().getNumber() - 1); 

    std::cout << playerNames[currentPlayer] << "'s Turn. Pass the computer to them. \n";

    for (int show = 0; show < (hands[currentPlayer].size() - 1); show++)
    {
        std::cout << hands[currentPlayer][show].getName() << ", ";
    }
    std::cout << hands[currentPlayer].back().getName() << "\n";

    std::cout << "\nThe card in the middle is " << middlePile.top().getName() << "\n";

    if (hands[currentPlayer].size() == 0)
        {
            std::cout << "Empty Hand\n";
        }
        std::cout << "\nPlease pick the color of the card you want to play. Type exactly what is shown on the screen:\n";
        std::cin >> pickColor >> pickNumber;
        std::string pick = pickColor + " " + pickNumber;
        //std::cout << "\nInput Type: " << typeid(pick).name() << "\n";

        for (int check = 0; check < hands[currentPlayer].size(); check++)
        {
            //std::cout << "\nCard Name Type: " << typeid(playerList.front().getHand()[check].getName()).name();

            std::cout << "Compare Result: " << pick.compare(hands[currentPlayer][check].getName()) <<"\nPick Value: " << pick << "\nCard Value: " << hands[currentPlayer][check].getName() << "\n";
            
            if (((pick.compare(hands[currentPlayer][check].getName()))) == 0)
            {
                checkCard(hands[currentPlayer][check], currentPlayer, check);
                //std::cout << "\nStarted found process\n";
                //std::cout << "\nCard selection found. (x" << check + 1 << ")\n";
                //std::cout << "\nErased Successfully\n";
                /*
                for (int print = 0; print < hands[currentPlayer].size(); print++)
                {
                    std::cout << hands[currentPlayer][print].getName() << ", ";
                }
                std::cout << "\n\n";
                */
                //std::cout << "\nMiddle Pile Top: " << middlePile.top().getName();
                //std::cout << "\nDone - Indice #: " << check << "\n";
            }
            else if (pick == "end game")
            {
                picking = false;
                break;
            }
            else if (pick == "draw card")
            {
                int drawn = rand() & (g_deck.size() + 1);
                hands[currentPlayer].push_back(g_deck[drawn]);
                pick = " "; 
                playerList.push(playerList.front());
                playerList.pop();
            }
            else
            {
                std::cout << "\nInvalid Input. Please type the name of the card exactly as printed. \n\n";
            }

        }
    }
    /*
    if ( (playerList.front().getHand()[check].getColor() == middlePile.top().getColor()) || (playerList.front().getHand()[check].getNumber() == middlePile.top().getNumber()) )
    {
        middlePile.push(playerList.front().getHand()[check]);
        playerList.front().getHand().erase(playerList.front().getHand().begin() + (check - 1));
        playing = false;
    }
    else1
    {
        playedCard = NULL;
        playing = true;
    }
    */
}

void Game::checkCard(Card pickedCard, int acurrentPlayer, int aindice)
{
    int indice = aindice;
    int currentPlayer = acurrentPlayer;
    Card top = middlePile.top();

    if (pickedCard.getNumber() == 12)
    {
        middlePile.push(hands[currentPlayer][indice]);
        hands[currentPlayer].erase(hands[currentPlayer].begin() + indice);
        draw(pickedCard);
        skip();
    }
    else if (pickedCard.getNumber() == 11)
    {
        middlePile.push(hands[currentPlayer][indice]);
        hands[currentPlayer].erase(hands[currentPlayer].begin() + indice);
        reverse();
    }
    else if (pickedCard.getNumber() == 10)
    {
        middlePile.push(hands[currentPlayer][indice]);
        hands[currentPlayer].erase(hands[currentPlayer].begin() + indice);
        skip();
    }
    else if ((pickedCard.getColor() == top.getColor()) || (pickedCard.getNumber() == top.getNumber()) || (top.getColor() == 0) || (pickedCard.getColor() == 0))
    {
        middlePile.push(hands[currentPlayer][indice]);
        hands[currentPlayer].erase(hands[currentPlayer].begin() + indice);
        playerList.push(playerList.front());
        playerList.pop();
    }
}
void Game::skip()
{
    for (int rep = 0; rep < 2; rep++)
        {
        playerList.push(playerList.front());
        playerList.pop();
        }
}

void Game::reverse()
{
    std::vector<Player> temp;
    while (!(playerList.empty()))
    {
        temp.push_back(playerList.front()); 
        playerList.pop();
    }
    while (!(temp.empty()))
    {
    playerList.push(temp[0]);
    temp.erase(temp.begin());
    }
}

void Game::draw(Card playedDrawCard)
{
    int currentPlayer = (playerList.front().getNumber() - 1);
    if (playedDrawCard.getColor() != 0)
    {
        for (int draw = 0; draw < 2; draw++)
        {
            int drawn = rand() % (g_deck.size() + 1);
            hands[currentPlayer + 1].push_back(g_deck[drawn]);
            g_deck.erase(g_deck.begin() + drawn);
        }
    }
    else if (playedDrawCard.getColor() == 0)
    {
        for (int draw = 0; draw < 4; draw++)
        {
            int drawn = rand() % (g_deck.size() + 1);
            hands[currentPlayer + 1].push_back(g_deck[drawn]);
            g_deck.erase(g_deck.begin() + drawn);
        }
    }
    else
    {
        std::cout << "\nError.";
    }

}