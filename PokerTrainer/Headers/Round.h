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
    int _playerCount;
    vector<Card> _board;
    vector<Player> _players;
    Deck _deck;
    
public:
    //Constructors
    Round();
    
    //Methods
    void dealPockets();
    void dealFlop();
    void dealTurn();
    void dealRiver();
    void evalHands();
    string showBoard();
    void printBoard();
    void printPockets();
    void printHands();
    
};


#endif /* defined(__Poker__Round__) */
