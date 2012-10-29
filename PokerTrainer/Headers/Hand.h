//
//  Hand.h
//  Poker
//
//  Created by Fairchild on 10/13/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#ifndef __Poker__Hand__
#define __Poker__Hand__

#include <string>
#include <vector>
#include <iostream>
#include "Card.h"

using namespace std;

class Hand {
    
private:
    vector<Card> _cards, _bestCards;
    int _rank;
    
public:
    //Constructors
    Hand();
    
    //Set Variables
    void addCard(Card card_);
    void setRank(int rank_) {_rank = rank_;}
    
    //Get Variables
    Card getCard(int number_) {return _cards[number_];};
    Card getBestCard(int number_) {return _bestCards[number_];};
    
    vector<Card> getCards() {return _cards;};
    vector<Card> getBestCards() {return _bestCards;};
    
    int getRank() {return _rank;};
    
    //Helper Functions
    vector<Card> sort(vector<Card> cards_);
    
    bool isStraightFlush(vector<Card> cards_);
    bool isFourOfKind(vector<Card> cards_);
    bool isFullHouse(vector<Card> cards_);
    bool isFlush(vector<Card> cards_);
    bool isStraight(vector<Card> cards_);
    bool isThreeOfKind(vector<Card> cards_);
    bool isTwoPair(vector<Card> cards_);
    bool isPair(vector<Card> cards_);
    
    void evalRank();
    void evalRankFive(vector<Card> &potentialBestCards_, int &potentialBestRank_, vector<Card> cards_);
    void evalRankSeven(vector<Card> &potentialBestCards_, int &potentialBestRank_, vector<Card> cards_);
    
    int compare(vector<Card> firstCards_, int firstRank_, vector<Card> secondCards_);
    
    //Methods
    string showCard(int position_);
    string showPocket();
    string showBoard();
    string showAllCards();
    string showBestCards();
    string showHandValue();
    void printCard(int position_);
    void printPocket();
    void printBoard();
    void printAllCards();
    void printBestCards();
    void printRank();
    void printHandValue();
};

#endif /* defined(__Poker__Hand__) */
