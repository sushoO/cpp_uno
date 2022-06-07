#include <iostream>
#include <string>
#include <vector>
#include <array>

class Card
{
    int color; // color property of each Card.
    int number; // number of each card. Action cards have a number greater than 9. 

    public:
        Card(int acolor, int anumber); // constructor of Card. Used to make every Card needed in Uno. 
        int getColor();
        int getNumber();
};

class Deck // creates a class Deck for the generation of the game deck. This deck is the standard Uno deck with 108 cards.
{
    std::vector<Card> deck; // private vector of strings for the deck.

public:
    void testFunction(); // test to check if the class's functions are successfully being called.
    std::vector<Card> createDeck(); // the function to generate the game deck.
    void printDeck(); // function to print the game deck, for debugging and checking if the code works.
    std::vector<Card> shuffleDeck();
};

class Hands // creates a class Hands for the generation of each hand's vector. Each hand will be of 7 cards.
{       
        std::vector<Card> deck; // a vector of strings to hold the game deck. the game deck is passed as an argument from createHand() in the class Deck.
        std::vector<Card> hand; // a vector of strings for each hand.
        std::vector< std::vector<Card> > hands; // a vector of vectors of strings that holds each hand. this is the return value of dealHand() which generates the hands. 
        int availableCards; // checks how many cards are still available in the game deck to make sure the code doesn't try taking too many cards from the game deck. also keeps track of how big the middle pile is. 
        int players; // the int value for how many players are playing. also an argument for this class, to determine how many cards to deal. 
        int selection; // variable that dynamically changes to hold whichever number has been randomly generated in the dealHand() function. Used for debugging.

    public:
        Hands(std::vector<Card> card_deck, int persons); // constructor to take the arguments for the class. takes in the game deck and the number of people playing.
        void testFunction(); // testFunction() to check that the functions within the class Hands are successfully being called.
        std::vector< std::vector<Card> > dealHand(); // the function to deal the hands that returns a vector of the hand. 
        void printHands();
        void printHand(); // function to print the hand generated. used to debug and make sure the hands are properly generated.
        void printAttributes(); // function to print every attribute of the Hands class. for debugging and making sure the values are correct.
        std::vector< std::vector<Card> > getHands();
};


class Player
{
    std::string name;
    int number;
    std::vector<std::string> playerList;
    std::vector< std::vector<Card> > hand;

    public:
    Player(std::string anom, int playerNumber);
    std::string getName();
    int getNumber();
    std::vector<std::string> getPlayers(); 
    void addPlayers();
    std::vector < std::vector<Card> > createHand(); 

};