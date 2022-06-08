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
    Game game;
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
    
    game.askPlayerCount();
    int playerCount = game.getPlayerCount();
    std::queue<Player> playerList = game.getPlayerList();
    //std::cout << playerList.size() << "\n";
   
    game.printPlayerList();

    //std::cout << "\n" << typeid(players).name() << "\n"; // this checks what data type "players" is. For debugging and testing whether it returns as an int.

    Hands sample(generatedDeck, playerCount); //Create an object from class Hands.

    std::vector< std::vector<Card> > player_hand = sample.dealHands(); //Creates a vector of strings from the returned value of dealHand(), which generated different vectors for each player.
    //sample.printHand(); //printHand() is a function in the class Hands that checks how the hands look (for debugging).
    //sample.printAttributes(); //printAttributes() prints each private variable in Hands (for debugging)
    //sample.printHand();
    //sample.printHands();
    
    //std::vector< std::vector<Card> > handTest = sample.getHands();
    //std::cout << "\n" <<  handTest.size() << "\n" << typeid(handTest).name() << "\n";
    game.playTurn();
}