#include <iostream>
#include "uno.hpp"
#include <string>
#include <vector>

//Hands Class Methods

Hands::Hands(std::vector<Card> card_deck, int persons, std::queue<Player> aplayerList) // constructor for class Hands. takes the game deck and # of players as arguments.
{
    deck = card_deck; // assigns the game deck to an attribute
    players = persons; // assigns the # of players as an attribute.
    playerList = aplayerList;
}

void Hands::testFunction() // testFunction() to check whether functions in class Hands are successfully being called.
{
    std::cout << "\nFunctions in Hands Class are Called...\n";
}

std::vector<std::vector<Card> > Hands::dealHands() // function that deals the Hands to each player.
{
    for (int deal = 0; deal < players; deal++)
    {
        for (int handSize = 0; handSize < 7; handSize++)
        {
            //printAttributes(); // printAttributes() is defined later. prints every attribute of the class Hands.
            availableCards = deck.size(); // checks how many cards are still available to be dealt.
            selection = rand() % (availableCards + 1); // stores the selection number that was randomly generated from the number of available cards. selection is between 0 and the deck size. I add one because the rand() function generates a number between 0 and one less than the number to the right of the %.
            hand.push_back(deck[selection]); // here the selected card is put into a hand.
            deck.erase(deck.begin() + (selection - 1)); // the card put into the hand is then removed from the deck.   
        }
        hands.push_back(hand);
        hand.clear();
        playerList.front().setHand(hands.front());
        playerList.push(playerList.front());
        playerList.pop();
    }
    
    /*
        for (int handSize = 0; handSize < 7; handSize++) // 7 cards are dealt to each player, so a card is dealt to each hand 7 times.
        {
            std::vector<std::string> hand;
            printAttributes(); // printAttributes() is defined later. prints every attribute of the class Hands.
            availableCards = deck.size(); // checks how many cards are still available to be dealt.
            selection = rand() % (availableCards + 1); // stores the selection number that was randomly generated from the number of available cards. selection is between 0 and the deck size. I add one because the rand() function generates a number between 0 and one less than the number to the right of the %.
            card = deck[selection]; // gets the string for the card that was selected. for debugging to make sure an actual card is picked.
            hand.push_back(card); // here the selected card is put into a hand.
            deck.erase(deck.begin() + (selection - 1)); // the card put into the hand is then removed from the deck.
        */
        
    return hands; // after the generation of the hand, each hand's vector is returned.
}

void Hands::printHands() // prints the hand. for debugging and making sure the hands are properly generated.
{
    for (int print_hand = 0; print_hand < hands.size(); print_hand++) // iterates through every indice in hands.
    {
        for (int print_subHand = 0; print_subHand < 7; print_subHand++)
        {
            std::cout << "Color: " << hands[print_hand][print_subHand].getColor() << " Number: " << hands[print_hand][print_subHand].getNumber() << ", "; // prints each indice, plus a comma and space for legibility.
        }
        
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
    for (int i = 0; i < players; i++)
    {
        std::cout << "\nHand #" << (i + 1) << ":\n";
        for (int c = 0; c < 7; c++) // haha c++, like the language
        {
            std::cout << "Color: " << hands[i][c].getColor() << " Number: " << hands[i][c].getNumber() << ", ";
        }
    }
}

void Hands::printAttributes() // print the attributes of Hands. every attribute is pulled and printed at once. this is for debugging.
{
    //std::cout << "\nPlayers: " << players << "\n"; // print # of players.
    std::cout << "\nAvailable Cards:  " << deck.size() << "\n"; // print available cards.
    //std::cout << "\nSelection #: " << selection << "\n"; // print which indice was selected.
    //std::cout << "\nSelection Name : " << card << "\n"; // print what the name of the selected indice is.
    //std::cout << "\nDeck Data Type: " << typeid(deck).name(); // prints what type of variable the deck is and the size of the deck. this confirms that the deck is a vector of strings that starts at a size of 108 and ends at (108 - # of players * 7).
    //std::cout << "\nHands Data Type: " << typeid(hands).name();
    std::cout << "\nHands Size: " << hands.size() << "\n"; // prints what type of variable hand is and the size of hand. makes sure hand is a vector of strings that is 7 big.
    //std::cout << "\nEach Hand Data Type: " << typeid(hand).name();
    std::cout << "\nEach Hand Size: " << hand.size() << "\n============\n";
}

std::vector< std::vector<Card> > Hands::getHands()
{
    return hands;
}
