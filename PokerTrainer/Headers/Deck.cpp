//
//  deck.cpp
//  Poker
//
//  Created by Fairchild on 10/12/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

/////Constructors/////

//Default Constructor
Deck::Deck() {
    
    _size = 52;
    _deck.reserve(_size);
    _position = 0;

    //Add each possible card ot the deck, starting with Spades, 2 through Ace
    for (Suit suit = SPADE; suit < 5; suit++) {             //For each possible suit
        _deck.push_back(Card(ACE, suit));                   //First, add the ace for the suit
        for (Value value = TWO; value < 14; value++) {      //Then, add a card for each possible value, 2 - King
            _deck.push_back(Card(value, suit));
        }
    }
    
};

/////Methods/////

//Shuffle the deck at random
void Deck::shuffle() {

    for(int card = 0; card < 5; card++) {       //For five separate iterations...
        for (int j = 0; j < _size; j++) {       //For each card position in the deck
            int k = rand() % _size;             //Generate a random number from 0 - 51
            swap(_deck[j], _deck[k]);           //Swap the current card position with the random number
        }
    }
        
};

//Return card and shift position by one
Card Deck::dealCard() {
    
    Card card;
    card = _deck[_position];        //Set value for current card in the deck
    _position++;                    //Shift to next card in deck
    return card;                    //Return current card
    
};

//Shift position by one without returning card
void Deck::burnCard() {
    
    _position++;        //Shift to next card in deck with no additional action
    
};

/////Display Functions/////

//Create string of all cards in the deck, in shorthand
string Deck::show() {
    
    string stringOfCards;
    
    for (int card = 0; card < _size; card++) {                  //For each card
        stringOfCards = stringOfCards + _deck[card].show();     //Add current card to string of cards

        if (card + 1 != _size) {                                //Add space after each card, except the last one
            stringOfCards = stringOfCards + " ";
        }
        
        if ((card + 1) % 13 == 0) {                             //Add new line after each group of 13 cards
            stringOfCards = stringOfCards + "\n";
        }
    }
    
    return stringOfCards;                                       //Return all cards

};

//Print string of all cards in the deck, in shorthand
void Deck::print() {
  
    cout << show() << endl;     //Print all cards to standard output
        
};

