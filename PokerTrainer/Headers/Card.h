//
//  card.h
//  Poker
//
//  Created by Fairchild on 10/12/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#ifndef __Poker__Card__
#define __Poker__Card__

#include <vector>
#include <string>

using namespace std;

enum Value {
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14,
};

enum Suit {
    SPADE = 1,
    HEART = 2,
    DIAMOND = 3,
    CLUB = 4
};

class Card {
    
private:
    Value _value;
    Suit _suit;

public:
    //Constructors
    Card();
    Card(Value, Suit);
    
    //Accessors
    void setValue(Value value_) {_value = value_;}
    void setSuit(Suit suit_) {_suit = suit_;}
    Value getValue() const {return _value;}
    Suit getSuit() const {return _suit;}
    
    //Methods
    string show() const;
    void print() const;
    
};

#endif /* defined(__Poker__Card__) */
