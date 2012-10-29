//
//  Player.h
//  Poker
//
//  Created by Fairchild on 10/28/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#ifndef __Poker__Player__
#define __Poker__Player__

#include <string>
#include <iostream>
#include "Card.h"
#include "Hand.h"

class Player {
    
private:
    string _name;
    Hand _hand;
    
public:
    //Constructors
    Player();
    Player(string name_);
    
    //Accessors
    void setName(string name_) {_name = name_;}

    string getName() const {return _name;}
    int getRank() {return _hand.getRank();};
    
    void addCard(Card card_) {_hand.addCard(card_);}
    void evalRank() {_hand.evalRank();};
    
    string showCard(int position_) {return _hand.showCard(position_);};
    string showPocket() {return _hand.showPocket();};
    string showBoard() {return _hand.showBoard();};
    string showAllCards() {return _hand.showAllCards();};
    string showBestCards() {return _hand.showBestCards();};
    string showHandValue() {return _hand.showHandValue();};
    void printCard(int position_) {return _hand.printCard(position_);};
    void printPocket() {return _hand.printPocket();};
    void printBoard() {return _hand.printBoard();};
    void printAllCards() {return _hand.printAllCards();};
    void printBestCards() {return _hand.printBestCards();};
    void printRank() {return _hand.printRank();};
    void printHandValue() {return _hand.printHandValue();};
    
};


#endif /* defined(__Poker__Player__) */
