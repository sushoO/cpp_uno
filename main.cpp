#include <iostream>
#include "uno.hpp"

// compiled with g++ main.cpp uno.cpp
// ran with ./a.out

int main(){
    bool play = true;

    Deck game_deck; //creates an object from the Deck class.
    Game game(game_deck.deck);
    //creates a vector of strings called generatedDeck that is the return value of the function createDeck() found within the class Deck. This vector is unaltered.
    
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
    game_deck.createDeck();
    game.createPlayers();
    //std::cout << game.playerList.size() << "\n";
    
    //game_deck.printDeck();

    

    //Hands hands(game_deck.deck, game.numPlayers, game.playerList); //Create an object from class Hands.
    //hands.dealHands(); //Creates a vector of strings from the returned value of dealHand(), which generated different vectors for each player.
    //std::cout << "\n" << typeid(players).name() << "\n"; // this checks what data type "players" is. For debugging and testing whether it returns as an int.
    //hands.printHands();
    //hands.printHand();
    game.printHands();
    game_deck.printDeck();
    //hands.printHand(); //printHand() is a function in the class Hands that checks how the hands look (for debugging).
    //hands.printAttributes(); //printAttributes() prints each private variable in Hands (for debugging)
    //hands.printHand();
    //hands.printHands();
    
    //std::vector< std::vector<Card> > handTest = hands.getHands();
    //std::cout << "\n" <<  handTest.size() << "\n" << typeid(handTest).name() << "\n";
    game.playGame();        
}