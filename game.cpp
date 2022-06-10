#include <iostream>
#include "uno.hpp"
#include <string>
#include <vector>


//Game Class Methods

void Game::askPlayerCount()
{
    std::cout << "How many players are playing the game?\n";
    while ((!(std::cin >> numPlayers)) or numPlayers == 0) // this loop checks for user error and makes sure numPlayers is an integer.
    {
        std::cout << "Please enter an integer greater than zero:\nHow many players are playing the game?\n";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    for (int p = 1; p < (numPlayers + 1); p++)
    {
        std::string playerName;
        std::cout << "Enter player name: ";
        std::cin >> playerName;
        playerNames.push_back(playerName);
    }

    for (int instantiatePlayers = 0; instantiatePlayers < playerNames.size(); instantiatePlayers++)
    {
        playerList.push(Player(playerNames[instantiatePlayers], (instantiatePlayers + 1)));
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

void Game::playTurn()
{
    bool playing = true;
    std::string pick;

    std::cout << playerList.front().getName() << "'s Turn. Pass the computer to them. \n";

    for (int show = 0; show < (playerList.front().getHand().size() - 1); show++)
    {
        std::cout << playerList.front().getHand()[show].getName() << ", ";
    }
    std::cout << playerList.front().getHand().back().getName() << "\n";

    if (playerList.front().getHand().size() == 0)
        {
            std::cout << "Empty Hand\n";
        }
    while (playing == true)
    {
        std::cout << "\nPlease pick a card to play. Use the name of the card as shown on the screen:\n";
        std::cin >> pick;
        //std::cout << "\nInput Type: " << typeid(pick).name() << "\n";


        for (int check = 0; check < playerList.front().getHand().size(); check++)
        {
            //std::cout << "\nCard Name Type: " << typeid(playerList.front().getHand()[check].getName()).name();
            if (pick.compare(playerList.front().getHand()[check].getName()) == 0)
            {
                std::cout << "\nCard selection found. (x" << check + 1 << ")\n";
                break;
            }
            else
            {
                std::cout << "\nCard selection failed. (x" << check + 1 << ")\n";
            }
            std::cout << "\n";
        }
        break;
    }
    /*
    if ( (playerList.front().getHand()[check].getColor() == middlePile.top().getColor()) || (playerList.front().getHand()[check].getNumber() == middlePile.top().getNumber()) )
    {
        middlePile.push(playerList.front().getHand()[check]);
        playerList.front().getHand().erase(playerList.front().getHand().begin() + (check - 1));
        playing = false;
    }
    else
    {
        playedCard = NULL;
        playing = true;
    }
    */
}
