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
    
    /////Data Members/////
    vector<Card> _cards, _bestCards;
    int _rank;
    
public:
    
    /////Constructors/////
    Hand();     //Default constructor
    
    /////Accessors/////
    void setRank(int rank_) {_rank = rank_;}                        //Set _rank data member
    
    vector<Card> getCards() {return _cards;};                       //Return all cards in _cards as vector of cards
    vector<Card> getBestCards() {return _bestCards;};               //Return all cards in _bestCards as vector of cards
    int getRank() {return _rank;};                                  //Return _rank data member
    
    Card getCard(int number_) {return _cards[number_];};            //Return one specified card in _cards as card type
    Card getBestCard(int number_) {return _bestCards[number_];};    //Return one specified card in _bestCard as card type
    
    /////Methods/////
    void addCard(Card card_);           //Add a card to the hand
    
    void evalRank();                    //Evaluate either five or seven cards to determine rank, best cards
    void evalRankSeven(vector<Card> &potentialBestCards_, int &potentialBestRank_, vector<Card> cards_);    //Evaluate seven cards to determine rank, best cards
    void evalRankFive(vector<Card> &potentialBestCards_, int &potentialBestRank_, vector<Card> cards_);     //Evaluate five cards to determine rank, best cards
    
    vector<Card> sort(vector<Card> cards_);         //Sort five cards and return
    vector<Card> sortByGroup(vector<Card> cards_);  //Sort five cards by group count and return
    vector<Card> sortByValue(vector<Card> cards_);  //Sort cards by value and return
    
    int countCards(vector<Card> cards_, int position);                                              //Count the number of instances of a card at a given position
    vector<Card> moveCard(vector<Card> cards_, int fromPosition, int toPosition);                   //Move one card from one position to another position
    vector<Card> moveCards(vector<Card> cards_, int fromPosition, int toPosition, int groupSize);   //Move group of cards from one position to another position
    
    bool isStraightFlush(vector<Card> cards_);      //Evaluate five cards to detect straight flush, return bool
    bool isFourOfKind(vector<Card> cards_);         //Evaluate five cards to detect four of a kind, return bool
    bool isFullHouse(vector<Card> cards_);          //Evaluate five cards to detect full house, return bool
    bool isFlush(vector<Card> cards_);              //Evaluate five cards to detect flush, return bool
    bool isStraight(vector<Card> cards_);           //Evaluate five cards to detect straight, return bool
    bool isThreeOfKind(vector<Card> cards_);        //Evaluate five cards to detect three of a kind, return bool
    bool isTwoPair(vector<Card> cards_);            //Evaluate five cards to detect two pair, return bool
    bool isPair(vector<Card> cards_);               //Evaluate five cards to detect pair, return bool
        
    /////Display Functions/////
    string showCard(int position_);     //Create string of one card in _cards vector
    string showPocket();                //Create string of first two cards in _cards vector
    string showBoard();                 //Create string of third through seventh card in _cards vector
    string showAllCards();              //Create string of all cards in _cards vector
    string showBestCards();             //Create string of all cards in _bestCards vector
    string showHandValue();             //Create string of the hand value
    
    void printCard(int position_);      //Print string of one card in _cards vector
    void printPocket();                 //Print string of first two cards in _cards vector
    void printBoard();                  //Print string of third through seventh card in _cards vector
    void printAllCards();               //Print string of all cards in _cards vector
    void printBestCards();              //Print string of all cards in _bestCards vector
    void printHandValue();              //Print hand value
    void printRank();                   //Print rank value
};

#endif /* defined(__Poker__Hand__) */
