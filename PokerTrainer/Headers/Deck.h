//
//  deck.h
//  Poker
//
//  Created by Fairchild on 10/12/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#ifndef __Poker__Deck__
#define __Poker__Deck__

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Deck {
    
private:
	
    /////Data Members/////
    vector<Card> _deck;
    int _size, _position;
    
public:
    
    /////Constructors/////
    Deck();                 //Default constructor
    
    /////Accessors/////
    
    /////Methods/////
    void shuffle();         //Shuffle deck
    Card dealCard();        //Take next card from deck and return it
    void burnCard();        //Take next card from deck and discard it
    
    /////Display Functions/////
    string show();          //Create string of all cards in the deck, in shorthand
    void print();           //Print string of all cards in the deck, in shorthand

};

#endif /* defined(__Poker__Deck__) */
