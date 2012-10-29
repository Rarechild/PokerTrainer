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
    vector<Card> _deck;
    int _size, _position;
    
public:
    //Constructors
    Deck();
    
    //Methods
    void shuffle();
    Card dealCard();
    void burnCard();
    string show();
    void print();

};

#endif /* defined(__Poker__Deck__) */
