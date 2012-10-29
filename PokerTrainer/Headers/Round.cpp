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

Round::Round() {
    
    _board.reserve(5);
    
    _playerCount = 8;
    _players.reserve(_playerCount);
    
    for (int player = 0; player < _playerCount; player++) {
        string name;
        stringstream number;
        name = "Player ";
        number << player + 1;
        _players[player] = Player(name + number.str());
    }

    _deck = Deck();
    
    _deck.shuffle();
    
};

void Round::dealPockets() {
    
    for (int player = 0; player < _playerCount; player++) {
            _players[player].addCard(_deck.dealCard());
    }
    
};

void Round::dealFlop() {
    
    _deck.burnCard();
    
    for (int card = 0; card < 3; card++) {
        _board.push_back(_deck.dealCard());
        for (int player = 0; player < _playerCount; player++) {
            _players[player].addCard(_board[card]);
        }
    }
     
};

void Round::dealTurn() {
    
    _deck.burnCard();
    
    _board.push_back(_deck.dealCard());
    for (int player = 0; player < _playerCount; player++) {
        _players[player].addCard(_board[3]);
    }
    
};

void Round::dealRiver() {
    
    _deck.burnCard();
    
    _board.push_back(_deck.dealCard());
    for (int player = 0; player < _playerCount; player++) {
        _players[player].addCard(_board[4]);
    }
    
};

void Round::evalHands() {
    
    for (int player = 0; player < _playerCount; player++) {
        _players[player].evalRank();
    }
    
};

string Round::showBoard() {
    
    string stringOfCards;
    
    for (int card = 0; card < _board.size(); card++) {
        stringOfCards = stringOfCards + _board[card].show();
        if (card + 1 != _board.size()) {
            stringOfCards = stringOfCards + " ";
        }
    }
    
    return stringOfCards;
    
};

void Round::printBoard() {
    
    cout << "Board: " << showBoard() << endl;
    cout << endl;
};

void Round::printHands() {
    
    for (int player = 0; player < _playerCount; player++) {
        cout << _players[player].getName() << ": "
             << _players[player].showPocket() << " " << endl
             << "Best: " << _players[player].showBestCards() << " "
             << "Hand Value: " << _players[player].showHandValue() << endl;
        cout << endl;
    }
    
};

