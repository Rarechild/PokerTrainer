//
//  card.cpp
//  Poker
//
//  Created by Fairchild on 10/12/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

/////Constructors/////

//Default constructor
Card::Card() {

    _value = ACE;
    _suit = SPADE;

};

//Constructor for given value and suit values
Card::Card(Value value_, Suit suit_) {

    _value = value_;
    _suit = suit_;

};

/////Operator Overloads/////

int operator+ (Card firstCard_, Card secondCard_) {             //Addition, Card to Card
    return (firstCard_.getValue() + secondCard_.getValue());    //Add card values, ignore suit
};

int operator- (Card firstCard_, Card secondCard_) {             //Subtraction, Card to Card
    return (firstCard_.getValue() - secondCard_.getValue());    //Subtract card values, ignroe suit
};

bool operator== (Card firstCard_, int value_) {                 //Equality, Card to int
    return (firstCard_.getValue() == value_);                   //Compare card value to int, ignroe suit
};

bool operator== (Card firstCard_, Card secondCard_) {           //Equality, Card to Card
    return (firstCard_.getValue() == secondCard_.getValue());   //Compare card values, ignore suit
};

bool operator!= (Card firstCard_, Card secondCard_) {           //Non-Equality, Card to Card
    return !(firstCard_ == secondCard_);                        //Compare card values, ignore suit
};

bool operator< (Card firstCard_, Card secondCard_) {            //Less Than, Card to Card
    return firstCard_.getValue() < secondCard_.getValue();      //Compare card values, ignore suit
};

bool operator<= (Card firstCard_, Card secondCard_) {           //Less Than or Equal To, Card to Card
    return firstCard_.getValue() <= secondCard_.getValue();     //Compare card values, ignore suit
};

bool operator> (Card firstCard_, Card secondCard_) {            //Greater Than, Card to Card
    return firstCard_.getValue() > secondCard_.getValue();      //Compare card values, ignore suit
};

bool operator>= (Card firstCard_, Card secondCard_) {           //Greater Than or Equal To, Card to Card
    return firstCard_.getValue() >= secondCard_.getValue();     //Compare card values, ignore suit
};

/////Methods/////


/////Display Functions/////

//Create string of value and suit in compact format e.g. "A|S"
string Card::show() const {     
    
    string valueName;
    string suitName;
    
    //Convert integer of value to shorthand
    switch (_value)
    {
        case 1:
            valueName = "1";            //Ace is only considered '1' when low end of straight
            break;
        case 2:
            valueName = "2";
            break;
        case 3:
            valueName = "3";
            break;
        case 4:
            valueName = "4";
            break;
        case 5:
            valueName = "5";
            break;
        case 6:
            valueName = "6";
            break;
        case 7:
            valueName = "7";
            break;
        case 8:
            valueName = "8";
            break;
        case 9:
            valueName = "9";
            break;
        case 10:
            valueName = "T";            //Shorthand for 10 is T to keep to one character
            break;
        case JACK:
            valueName = "J";
            break;
        case QUEEN:
            valueName = "Q";
            break;
        case KING:
            valueName = "K";
            break;
        case ACE:
            valueName = "A";            //Ace is considered 'A' in most cases
            break;
    }
    
    switch (_suit)                      //Convert integer of suit to shorthand
    {
        case SPADE:
            suitName = "S";
            break;
        case HEART:
            suitName = "H";
            break;
        case DIAMOND:
            suitName = "D";
            break;
        case CLUB:
            suitName = "C";
            break;
    }
    
    return valueName + "|" + suitName;  //Return shorthand of value and suit, separated by a pipe '|'
    
};

//Print string of value and suit in compact format e.g. "A|S"
void Card::print() const {      

    cout << show() << endl;

};