/*
#include <iostream>
#include "uno.hpp"
#include <string>
#include <vector>

//Hands Class Methods

Hands::Hands(std::vector<Card> &h_deck, int &h_players, std::queue<Player> &h_playerList)
: h_deck(h_deck), h_players(h_players), h_playerList(h_playerList) {}

void Hands::testFunction() // testFunction() to check whether functions in class Hands are successfully being called.
{
    std::cout << "\nFunctions in Hands Class are Called...\n";
}

void Hands::dealHands() // function that deals the Hands to each player.
{
    std::cout << "\n" << h_playerList.size() << "\n";
    for (int deal = 0; deal < h_playerList.size(); deal++)
    {
        for (int handSize = 0; handSize < 7; handSize++)
        {
            //printAttributes(); // printAttributes() is defined later. prints every attribute of the class Hands.
            availableCards = h_deck.size(); // checks how many cards are still available to be dealt.
            selection = rand() % (availableCards + 1); // stores the selection number that was randomly generated from the number of available cards. selection is between 0 and the h_deck size. I add one because the rand() function generates a number between 0 and one less than the number to the right of the %.
            hand.push_back(h_deck[selection]); // here the selected card is put into a hand.
            h_deck.erase(h_deck.begin() + (selection)); // the card put into the hand is then removed from the h_deck.   
        }
        hands.push_back(hand);
        hand.clear();
        h_playerList.front().setHand(hands.front());
        h_playerList.push(h_playerList.front());
        h_playerList.pop();
        //std::cout << "Hands dealt";
    }
    
    / - *
        for (int handSize = 0; handSize < 7; handSize++) // 7 cards are dealt to each player, so a card is dealt to each hand 7 times.
        {
            std::vector<std::string> hand;
            printAttributes(); // printAttributes() is defined later. prints every attribute of the class Hands.
            availableCards = h_deck.size(); // checks how many cards are still available to be dealt.
            selection = rand() % (availableCards + 1); // stores the selection number that was randomly generated from the number of available cards. selection is between 0 and the h_deck size. I add one because the rand() function generates a number between 0 and one less than the number to the right of the %.
            card = h_deck[selection]; // gets the string for the card that was selected. for debugging to make sure an actual card is picked.
            hand.push_back(card); // here the selected card is put into a hand.
            h_deck.erase(h_deck.begin() + (selection - 1)); // the card put into the hand is then removed from the h_deck.

}

void Hands::printHands() // prints the hand. for debugging and making sure the hands are properly generated.
{
    for (int print_hand = 0; print_hand < hands.size(); print_hand++) // iterates through every indice in hands.
    {
        for (int print_subHand = 0; print_subHand < 7; print_subHand++)
        {
            std::cout << hands[print_hand][print_subHand].getName() << ", ";
        }
        std::cout << "\n";

    }
    std::cout << "\nDone\n";
    if (hands.empty()) // if the hand vector is empty, on a new line print that it's empty.
    {
        std::cout << "\nHand vector is empty!\n";
    }
}

void Hands::printHand()
{   
    //std::cout << "Type: " << typeid(hands[0][0]).name() << "\n";
    for (int i = 0; i < h_players; i++)
    {
        std::cout << "\nHand #" << (i + 1) << ":\n";
        for (int c = 0; c < 7; c++) // haha c++, like the language
        {
            std::cout << hands[i][c].getName() << ", ";
        }
    }
}

void Hands::printAttributes() // print the attributes of Hands. every attribute is pulled and printed at once. this is for debugging.
{
    //std::cout << "\nh_players: " << h_players << "\n"; // print # of h_players.
    std::cout << "\nAvailable Cards:  " << h_deck.size() << "\n"; // print available cards.
    //std::cout << "\nSelection #: " << selection << "\n"; // print which indice was selected.
    //std::cout << "\nSelection Name : " << card << "\n"; // print what the name of the selected indice is.
    //std::cout << "\nh_deck Data Type: " << typeid(h_deck).name(); // prints what type of variable the h_deck is and the size of the h_deck. this confirms that the h_deck is a vector of strings that starts at a size of 108 and ends at (108 - # of h_players * 7).
    //std::cout << "\nHands Data Type: " << typeid(hands).name();
    std::cout << "\nHands Size: " << hands.size() << "\n"; // prints what type of variable hand is and the size of hand. makes sure hand is a vector of strings that is 7 big.
    //std::cout << "\nEach Hand Data Type: " << typeid(hand).name();
    std::cout << "\nEach Hand Size: " << hand.size() << "\n============\n";
}

std::vector< std::vector<Card> > Hands::getHands()
{
    return hands;
}
*/