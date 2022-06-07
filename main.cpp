#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <random>
#include <stdlib.h>
#include "uno.hpp"

// compiled with g++ main.cpp uno.cpp
// run with ./a.out

int main(){
    
    Deck game_deck; //creates an object from the Deck class.

    std::vector<Card> generatedDeck = game_deck.createDeck(); //creates a vector of strings called generatedDeck that is the return value of the function createDeck() found within the class Deck. This vector is unaltered.
    
    //std::vector<Card> shuffledDeck = game_deck.shuffleDeck(); //takes the created vector of strings and shuffles it, allowing for the hand dealing to begin.
    
    //game_deck.printDeck();
    
    /* Print out generatedDeck's value for debugging.
    std::cout << "\nPrinting Variable Deck\n";
    for (int i = 0; i < generatedDeck.size();i++)
    {
        std::cout << "Color: " << generatedDeck[i].getColor() << " Number: " << generatedDeck[i].getNumber() << ", ";
    }
    */

    srand (time(NULL)); //this line is for seeding the random number generator used to shuffle and deal hands. 
    int players;
    std::cout << "\nHow many players are playing the game?\n"; //Ask the player count, then take the response as a variable.
    std::cin << players;
    for (int p = 0, p < players, p++)
    {
        
    }



    //std::cout << "\n" << typeid(players).name() << "\n"; // this checks what data type "players" is. For debugging and testing whether it returns as an int.

    Hands sample(generatedDeck, players); //Create an object from class Hands.

    std::vector< std::vector<Card> > player_hand = sample.dealHand(); //Creates a vector of strings from the returned value of dealHand(), which generated different vectors for each player.
    //sample.printHand(); //printHand() is a function in the class Hands that checks how the hands look (for debugging).
    //sample.printAttributes(); //printAttributed() prints each private variable in Hands (for debugging)
    sample.printHands();
    std::vector< std::vector<Card> > handTest = sample.getHands();
    std::cout << "\n" <<  handTest.size() << "\n" << typeid(handTest).name() << "\n";