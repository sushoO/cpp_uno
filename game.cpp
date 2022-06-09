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

void Game::playTurn()
{
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
    std::cout << "\nPlease pick a card to play. Use the name of the card as shown on the screen:\n";
    std::cin >> pick;
    auto picked = std::find(playerList.front().getHand().begin(), playerList.front().getHand().end(), pick);
    if (picked != playerList.front().getHand().end())
    {
        middlePile.push(playerList.front().getHand()[picked - playerList.front().getHand().begin()]);
        playerList.front().getHand().erase(playerList.front().getHand().begin() + ((picked - playerList.front().getHand().begin()) - 1));
        for (int newPrint = 0; newPrint < playerList.front().getHand().size(); newPrint++)
        {
            std::cout << playerList.front().getHand()[newPrint].getName() << ", ";
        }
        playerList.push(playerList.front());
        playerList.pop();
        playTurn();
    }
    else
    {
        std::cout << "\nCard selection failed.\n";
    }
}

void Game::updatePlayerList(std::queue<Player> anewplayerList)
{
    playerList = anewplayerList;
}