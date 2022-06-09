#include <iostream>
#include "uno.hpp"
#include <string>
#include <vector>
#include <array>
#include <algorithm>

//Deck Class Methods

std::vector<Card> Deck::createDeck() // function to generate the game deck.
{
    std::array<int, 5> color = {0 /*Wild*/, 1 /*Red*/, 2 /*Green*/, 3 /*Blue*/, 4 /*Yellow*/};
    std::array<int, 13> number = {0 /*Card #0 or Wild Card if Color = 0*/, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 /*Skip*/, 11 /*Reverse*/, 12 /*Plus 2 or Plus 4 if color = 0*/};
    std::array<std::string, 5> colorNames = {"Wild", "Red", "Green", "Blue", "Yellow"};
    std::array<std::string, 13> numberNames = {" 0", " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", " Skip", " Reverse", " Plus 2"};


    for (int assignColor = 1; assignColor < color.size(); assignColor++)
    {
        deck.push_back(Card(0, 0, colorNames[0]));
        deck.push_back(Card(0, 12, (colorNames[0] + " Plus 4")));
        deck.push_back(Card(color[assignColor], number[0], colorNames[assignColor] + numberNames[0]));

        for (int twice = 0; twice < 2; twice++)
        {
            for (int assignNum = 1; assignNum < number.size(); assignNum++)
            {

                deck.push_back(Card(color[assignColor], number[assignNum], colorNames[assignColor] + numberNames[assignNum]));
            }
        }
    }
    return deck;
}

void Deck::printDeck() // printDeck() to see the deck that was generated. for debugging
{
    for (int deckIndice = 0; deckIndice < deck.size(); deckIndice++)
    {
        std::cout << "Name: " << deck[deckIndice].getName() << "\n";
    }
    std::cout << "\n\n\n";
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