//
//  Player.cpp
//  Poker
//
//  Created by Fairchild on 10/28/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#include <string>
#include "Card.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

/////Constructors/////

//Default constructor
Player::Player() {
    _name = "Player";
    _hand = Hand();
}

//Constructor for a given name
Player::Player(string name_) {
    _name = name_;
    _hand = Hand();
}