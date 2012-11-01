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
    
    /////Data Members/////
    string _name;
    Hand _hand;
    
public:
    
    /////Constructors/////
    Player();                   //Default constructor
    Player(string name_);       //Constructor for a given name
    
    //Accessors
    void setName(string name_) {_name = name_;}
    
    string getName() const {return _name;}
    int getRank() {return _hand.getRank();};
    
    /////Methods/////
    void addCard(Card card_) {_hand.addCard(card_);}        //Add card to player's hand
    void evalRank() {_hand.evalRank();};                    //Evaluate player's best cards and rank
    
    /////Display Functions/////
    string showCard(int position_) {return _hand.showCard(position_);};     //Create string of one card in _cards vector
    string showPocket() {return _hand.showPocket();};                       //Create string of first two cards in _cards vector
    string showBoard() {return _hand.showBoard();};                         //Create string of board cards, three through seven, in _cards vector
    string showAllCards() {return _hand.showAllCards();};                   //Create string of all card in _cards vector
    string showBestCards() {return _hand.showBestCards();};                 //Create string of all card in _bestCards vector
    string showHandValue() {return _hand.showHandValue();};                 //Create string of hand value
    
    void printCard(int position_) {return _hand.printCard(position_);};     //Print string of one card in _cards vector
    void printPocket() {return _hand.printPocket();};                       //Print string of first two cards in _cards vector
    void printBoard() {return _hand.printBoard();};                         //Print string of board cards, three through seven, in _cards vector
    void printAllCards() {return _hand.printAllCards();};                   //Print string of all card in _cards vector
    void printBestCards() {return _hand.printBestCards();};                 //Print string of all card in _bestCards vector
    void printRank() {return _hand.printRank();};                           //Print string of one card in _cards vector
    void printHandValue() {return _hand.printHandValue();};                 //Print hand value
    
};


#endif /* defined(__Poker__Player__) */
