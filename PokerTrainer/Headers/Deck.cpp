//
//  deck.cpp
//  Poker
//
//  Created by Fairchild on 10/12/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

Deck::Deck() {
    
    _size = 52;
    _deck.reserve(_size);
    _position = 0;
    
    for (Suit suit = SPADE; suit < 5; suit++) {
        for (Value value = TWO; value < 15; value++) {
            _deck.push_back(Card(value, suit));
        }
    }
    
};

void Deck::shuffle() {

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < _size; j++) {
            int k = rand() % _size;
            swap(_deck[j], _deck[k]);
        }
    }
        
};

Card Deck::dealCard() {
    
    Card card;
    card = _deck[_position];
    _position++;
    return card;
    
};

void Deck::burnCard() {
    
    _position++;
    
};

string Deck::show() {
    
    string stringOfCards;
    
    for (int i = 0; i < _size; i++) {
        stringOfCards = stringOfCards + _deck[i].show();

        if (i + 1 != _size) {
            stringOfCards = stringOfCards + " ";
        }
        
        if ((i + 1) % 13 == 0) {
            stringOfCards = stringOfCards + "\n";
        }
    }
    
    return stringOfCards;

};

void Deck::print() {
  
    cout << show() << endl;
        
};

