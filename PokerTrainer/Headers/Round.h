//
//  Round.h
//  Poker
//
//  Created by Fairchild on 10/18/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#ifndef __Poker__Round__
#define __Poker__Round__

#include <vector>
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

class Round {
    
private:
    
    /////Data Members/////
    int _playerCount;
    vector<Card> _board;
    vector<Player> _players;
    Deck _deck;
    
public:
    
    /////Constructors/////
    Round();                //Default constructor
    
    //Methods
    void dealPockets();     //Deal pockets to all players
    void dealFlop();        //Burn card and deal flop for the hand
    void dealTurn();        //Burn card and deal turn for the hand
    void dealRiver();       //Burn card and deal river for the hand
    
    void evalHands();       //Evaluate the hand best cards and rank for each player
    
    /////Display Functions/////
    string showBoard();     //Create string of board cards in _board vector
    void printBoard();      //Print string of board cards in _board vector
    void printHands();      //Print string of hand values for each player
    
};


#endif /* defined(__Poker__Round__) */
