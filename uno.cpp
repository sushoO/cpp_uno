#include <iostream>
#include "uno.hpp"
#include <string>
#include <vector>
#include <tuple>
#include <array>
#include <algorithm>
#include <queue>

//Card Class Methods

/*
Card::Card(std::string nom, int col, int num) // defines the constructor of the class Card. takes the arguments and assigns them to attributes.
{
    name = nom; // assigns "nom" argument to name attribute.
    color = col; // assigns "col" argument to color attribute.
    number = num; // assigns "num" argument to "number" attribute.
}

void Card::printCard() // function to print the card. not defined because class Card is not used.
{

}
void Card::testFunction() // function to check if functions within class Card are successully called.
{
    std::cout << "\nFunctions in Deck Class are Called...\n";
}
*/

//Card Class Methods

Card::Card(int acolor, int anumber)
{
    color = acolor;
    number = anumber;
}

int Card::getColor()
{
    return color;
}
int Card::getNumber()
{
    return number;
}

//Deck Class Methods


std::vector<Card> Deck::createDeck() // function to generate the game deck.
{
    std::array<int, 5> color = {0 /*Wild*/, 1 /*Red*/, 2 /*Green*/, 3 /*Blue*/, 4 /*Yellow*/};
    std::array<int, 13> number = {0 /*Card #0 or Wild Card if Color = 0*/, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 /*Skip*/, 11 /*Reverse*/, 12 /*Plus 2 or Plus 4 if color = 0*/};

    for (int assignColor = 1; assignColor < color.size(); assignColor++)
    {
        deck.push_back(Card(0, 0));
        deck.push_back(Card(0, 12));
        deck.push_back(Card(color[assignColor], 0));

        for (int twice = 0; twice < 2; twice++)
        {
            for (int assignNum = 1; assignNum < number.size(); assignNum++)
            {
                deck.push_back(Card(color[assignColor], number[assignNum]));
            }
        }
    }
    return deck;
}


void Deck::printDeck() // printDeck() to see the deck that was generated. for debugging
{
    for (int deckIndice = 0; deckIndice < deck.size(); deckIndice++)
    {
        std::cout << "Color: " << deck[deckIndice].getColor() << " Number: " << deck[deckIndice].getNumber() << ", ";
    }
}
std::vector<Card> Deck::shuffleDeck()
{
    std::random_shuffle(deck.begin(), deck.end());
    return deck;
}
    /*
    for (int col = 0; col < 4; col++) // for loop, creates a set of cards for each color, 0 = Red, 1 = Green, 2 = Blue, 3 = Yellow.
    {
        deck.push_back("Wild Card"); // there are 4 Wild and Plus 4 cards in each uno deck, so I just make 1 of each per every color.
        deck.push_back("Plus 4"); // 1 Plus 4 per every color, 4 in total.
        switch (col) // switch statement to make a set of cards for each color. 
        {
        case 0: // if the color is red:
            deck.push_back("Red 0"); // add "Red 0" (only one of this card) to the deck
            for (int duo = 0; duo < 2; duo++) // then make two each of:
            {
                for (int num = 1; num <= 9; num++) // add the cards "Red" + the number of the card between 1 and 9. the for loop above repeats this because each Uno color has 2 sets of cards between 1 and 9.
                {
                    deck.push_back("Red " + std::to_string(num)); // add "Red" and the card's face number
                }
                deck.push_back("Red Skip"); // adds a Red Skip twice 
                deck.push_back("Red Plus 2"); // adds a Red Plus 2 twice
                deck.push_back("Red Reverse"); // adds a Red Reverse twice

            }
            break; // break as needed for a switch case statement

         for each case, the same code repeats. an Uno deck calls for one 0 card of each color,
         two sets of cards numbered between 1-9 for each color, and 2 each of a skip, plus 2, and reverse of each color.
         the first for loop in this entire function generates the wild and plus 4 cards. 


        case 1: 
            deck.push_back("Green 0"); 
            for (int duo = 0; duo < 2; duo++)
            {
                for (int num = 1; num <= 9; num++)
                {
                    deck.push_back("Green " + std::to_string(num));
                }
                deck.push_back("Green Skip");
                deck.push_back("Green Plus 2");
                deck.push_back("Green Reverse");
            }
            break;
        case 2:
            deck.push_back("Blue 0");
            for (int duo = 0; duo < 2; duo++)
            {
                for (int num = 1; num <= 9; num++)
                {
                    deck.push_back("Blue " + std::to_string(num));
                }
                deck.push_back("Blue Skip");
                deck.push_back("Blue Plus 2");
                deck.push_back("Blue Reverse");
            }
            break;
        case 3:
            deck.push_back("Yellow 0");
            for (int duo = 0; duo < 2; duo++)
            {
                for (int num = 1; num <= 9; num++)
                {
                    deck.push_back("Yellow " + std::to_string(num));
                }
                deck.push_back("Yellow Skip");
                deck.push_back("Yellow Plus 2");
                deck.push_back("Yellow Reverse");
            }
            break;
        }
    }
    return deck; // returns the vector that these for loops generate. this is the game deck.
    */



void Deck::testFunction() // testFunction that prints a statement to check if the functions in a class are successfully called.
{
    std::cout << "\nFunctions in Deck Class are Called...\n";
}

//Hands Class Methods

Hands::Hands(std::vector<Card> card_deck, int persons) // constructor for class Hands. takes the game deck and # of players as arguments.
{
    deck = card_deck; // assigns the game deck to an attribute
    players = persons; // assigns the # of players as an attribute.
}

void Hands::testFunction() // testFunction() to check whether functions in class Hands are successfully being called.
{
    std::cout << "\nFunctions in Hands Class are Called...\n";
}

std::vector<std::vector<Card> > Hands::dealHand() // function that deals the Hands to each player.
{
    for (int deal = 0; deal < players; deal++)
    {
        for (int handSize = 0; handSize < 7; handSize++)
        {
            printAttributes(); // printAttributes() is defined later. prints every attribute of the class Hands.
            availableCards = deck.size(); // checks how many cards are still available to be dealt.
            selection = rand() % (availableCards + 1); // stores the selection number that was randomly generated from the number of available cards. selection is between 0 and the deck size. I add one because the rand() function generates a number between 0 and one less than the number to the right of the %.
            hand.push_back(deck[selection]); // here the selected card is put into a hand.
            deck.erase(deck.begin() + (selection - 1)); // the card put into the hand is then removed from the deck.   
        }
        hands.push_back(hand);
        hand.clear();
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
    for (int overV = 0; overV < players; overV++)
    {
        for (int subV = 0; subV < 8; subV++)
        {
            std::cout << "Color: " << hands[overV][subV].getColor() << " Number: " << hands[overV][subV].getNumber() << ", ";
        }
    }
    std::cout << "\n\nDone\n";
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

Player::Player(std::string anom, int playerNumber)
{
    name = anom;
    number = playerNumber;

}

std::string Player::getName()
{
    return name;
}

std::vector<std::string> Player::getPlayers()
{
    return playerList;
}

int Player::getNumber()
{
    return number; 
}

int Game::askPlayerCount()
{
    std::cout << "How many players are playing?\n";
    std::cin >> numPlayers;

    for (int p = 1; p < (numPlayers + 1); p++)
    {
        playerList.push
        std::cout << "Enter the first player's name: ";
        
    }
}