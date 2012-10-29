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

//Constructors
Card::Card() {

    _value = ACE;
    _suit = SPADE;

};

Card::Card(Value value_, Suit suit_) {

    _value = value_;
    _suit = suit_;

};

//Methods
string Card::show() const {
    
    string valueName;
    string suitName;
    
    switch (_value)
    {
        case 1:
            valueName = "1";
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
            valueName = "T";
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
            valueName = "A";
            break;
    }
    
    switch (_suit)
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
    
    return valueName + "|" + suitName;
    
};

void Card::print() const {

    cout << show() << endl;

};