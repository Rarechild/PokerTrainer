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

//Create enumerated type for card value
enum Value {        
    ONE = 1,        //ONE is low Ace
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
    ACE = 14,       //ACE is high Ace
};

//Create enumerated type for card suit
enum Suit {
    SPADE = 1,
    HEART = 2,
    DIAMOND = 3,
    CLUB = 4
};

class Card {
    
private:
    
    /////Data Members/////
    Value _value;
    Suit _suit;

public:
    
    /////Constructors/////
    Card();                 //Default constructor
    Card(Value, Suit);      //Constructor for given value and suit values
    
    /////Operator Overloads/////
    friend int operator+ (Card firstCard_, Card secondCard_);       //Add card values, ignore suit 
    friend int operator- (Card firstCard_, Card secondCard_);       //Subtract card values, ignore suit
    friend bool operator== (Card firstCard_, int value_);           //Compare card value to int, ignore suit
    friend bool operator== (Card firstCard_, Card secondCard_);     //Compare card values, ignore suit
    friend bool operator!= (Card firstCard_, Card secondCard_);     //Compare card values, ignore suit
    friend bool operator< (Card firstCard_, Card secondCard_);      //Compare card values, ignore suit
    friend bool operator<= (Card firstCard_, Card secondCard_);     //Compare card values, ignore suit
    friend bool operator> (Card firstCard_, Card secondCard_);      //Compare card values, ignore suit
    friend bool operator>= (Card firstCard_, Card secondCard_);     //Compare card values, ignore suit
    
    /////Accessors///
    void setValue(Value value_) {_value = value_;}
    void setSuit(Suit suit_) {_suit = suit_;}
    Value getValue() const {return _value;}
    Suit getSuit() const {return _suit;}
    
    /////Methods/////
    
    
    /////Display Functions/////
    string show() const;    //Create string of value and suit in compact format e.g. "A|S"
    void print() const;     //Print string of value and suit in compact format e.g. "A|S"
    
};

#endif /* defined(__Poker__Card__) */
