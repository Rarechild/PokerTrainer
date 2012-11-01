//
//  Round.cpp
//  Poker
//
//  Created by Fairchild on 10/18/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Round.h"

/////Constructors/////

//Default constructor
Round::Round() {
    
    _board.reserve(5);                                          //Setup vector of cards for board
    
    _playerCount = 8;                                           //Define number of players
    _players.reserve(_playerCount);                             //Setup vector of players
    
    for (int player = 0; player < _playerCount; player++) {     //For each player
        string name = "Player ";
        stringstream number;
        number << player + 1;
        _players[player] = Player(name + number.str());         //Setup name as "Player" and a consecutive number
    }

    _deck = Deck();                                             //Create a deck
    
    _deck.shuffle();                                            //Shuffle the deck
    
};

/////Methods/////

//Deal pockets to all players
void Round::dealPockets() {
    
    for (int player = 0; player < _playerCount; player++) {     //For each player
            _players[player].addCard(_deck.dealCard());         //Deal a pocket card
    }
    
};

//Burn card and deal flop for the hand
void Round::dealFlop() {
    
    _deck.burnCard();                                               //Increment deck iterator without dealing a card
    
    for (int card = 0; card < 3; card++) {                          //For each of three cards
        _board.push_back(_deck.dealCard());                         //Deal a board card
        for (int player = 0; player < _playerCount; player++) {     //For each player
            _players[player].addCard(_board[card]);                 //Add that card to their hand
        }
    }
     
};

//Burn card and deal turn for the hand
void Round::dealTurn() {
    
    _deck.burnCard();                                               //Increment deck iterator without dealing a card
    
    _board.push_back(_deck.dealCard());                             //Deal a board card
    for (int player = 0; player < _playerCount; player++) {         //For each player
        _players[player].addCard(_board[3]);                        //Add that card to their hand
    }
    
};

//Burn card and deal river for the hand
void Round::dealRiver() {
    
    _deck.burnCard();                                               //Increment deck iterator without dealing a card
    
    _board.push_back(_deck.dealCard());                             //Deal a board card
    for (int player = 0; player < _playerCount; player++) {         //For each player
        _players[player].addCard(_board[4]);                        //Add that card to their hand
    }
    
};

//Evaluate the hand best cards and rank for each player
void Round::evalHands() {
    
    for (int player = 0; player < _playerCount; player++) {         //For each player
        _players[player].evalRank();                                //Evaluate their best cards and rank
    }
    
};

/////Display Functions/////

//Create string of board cards in _board vector
string Round::showBoard() {
    
    string stringOfCards;
    
    for (int card = 0; card < _board.size(); card++) {              //For each board card
        stringOfCards = stringOfCards + _board[card].show();        //Add current card to string of cards
        if (card + 1 != _board.size()) {
            stringOfCards = stringOfCards + " ";                    //Add space after each card, except the last one
        }
    }
    
    return stringOfCards;                                           //Return cards
    
};

//Print string of board cards in _board vector
void Round::printBoard() {
    cout << "Board: " << showBoard() << endl << endl;
};

//Print string of pocket values for each player
void Round::printHands() {
    
    for (int player = 0; player < _playerCount; player++) {                     //For each player
        cout << _players[player].getName() << ": "                              //Print the name, pockets, best hand, and hand value
             << _players[player].showPocket() << " " << endl
             << "Best: " << _players[player].showBestCards() << " "
        << "Hand Value: " << _players[player].showHandValue() << endl << endl;
    }
    
};

