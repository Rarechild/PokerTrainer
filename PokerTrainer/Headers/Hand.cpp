//
//  Hand.cpp
//  Poker
//
//  Created by Fairchild on 10/13/12.
//  Copyright (c) 2012 Fairchild. All rights reserved.
//

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include "Card.h"
#include "Hand.h"

/////Constructors/////

//Default constructor
Hand::Hand() {
    _cards.reserve(7);
    _bestCards.reserve(5);
    _rank = 0;
};

/////Methods/////

//Add a card to the hand
void Hand::addCard(Card card_){
    
    _cards.push_back(card_);        //Add card to hand
    
};

//Evaluate either five or seven cards to determine rank, best cards
void Hand::evalRank() {
    
    vector<Card> cards;
    cards.reserve(7);
    
    vector<Card> potentialBestCards;                                    //Setup temporary placeholder for best cards
    potentialBestCards.reserve(5);
    int potentialBestRank = 0;                                          //Setup temporary placeholder for rank
    
    cards = _cards;
    
    if (cards.size() == 5) {                                            //If hand size is 5
        evalRankFive(potentialBestCards, potentialBestRank, cards);     //Evaluate once
    } else if (cards.size() == 7) {                                     //If hand size is 7
        evalRankSeven(potentialBestCards, potentialBestRank, cards);    //Evaluate each combination of 5 card possibilities
    }
    
    _bestCards = potentialBestCards;                                    //Set potential best cards to best cards
    _rank = potentialBestRank;                                          //Set potential best rank to rank 
    
    potentialBestCards.clear();
};

//Evaluate seven cards to determine rank, best cards
void Hand::evalRankSeven(vector<Card> &potentialBestCards_, int &potentialBestRank_, vector<Card> cards_) {
    
    assert(cards_.size() == 7);     //Assert that exactly seven cards should be in the cards_ vector
    
    vector<Card> evalCards;         //Setup temporary placeholder for cards
    evalCards.reserve(5);
    
    vector<Card> tempBestCards;     //Setup temporary placeholder for best cards
    tempBestCards.reserve(5);
    int tempBestRank = 0;           //Setup temporary placeholder for rank
    
    for (int firstExclude = 0; firstExclude < cards_.size(); firstExclude++) {              //Iterate through first excluded card number
        for (int secondExclude = 0; secondExclude <  cards_.size(); secondExclude++) {      //Iterate through second excluded card number
            if (firstExclude != secondExclude) {                                            //Skip if first card number is equal to the second card number
                
                evalCards.clear();                                                          //Clear placeholder for new vector of cards
                
                for (int card = 0; card < 7; card++) {                                      //Add each card to the temporary placeholder except the two excluded cards
                    if (card != firstExclude && card != secondExclude) {
                        evalCards.push_back(cards_[card]);
                    }
                }
                
                evalRankFive(tempBestCards, tempBestRank, evalCards);                       //Evaluate vector of cards, returning sorted cards and rank by reference
                
                if (tempBestRank > potentialBestRank_) {                                    //If current iteration has a better rank than previous best
                    potentialBestCards_ = tempBestCards;                                    //Set as current best cards
                    potentialBestRank_ = tempBestRank;                                      //Set as current best rank
                } else if (tempBestRank == potentialBestRank_) {                            //Otherwise if rank is equal to best of previous iterations rank
                    for (int card = 0; card < 5; card++) {                                  //For each card position
                        if (tempBestCards[card] > potentialBestCards_[card]) {              //If current iteration card value has a higher value than previous best
                            potentialBestCards_ = tempBestCards;                            //Set as current best cards
                            potentialBestRank_ = tempBestRank;                              //Set as current best rank
                            break;                                                          //Break from loop immediately
                        }
                    }
                }
            }
        }
    }
};

//Evaluate five cards to determine rank, best cards
void Hand::evalRankFive(vector<Card> &potentialBestCards_, int &potentialBestRank_, vector<Card> cards_) {
    
    assert(cards_.size() == 5);             //Assert that exactly five cards should be in the cards_ vector
    
    int rank = 0;                           //Set to 0 by default
    
    cards_ = sort(cards_);                  //Sort cards
    
    if (isStraightFlush(cards_)) {
        rank = 9;                           //Straight Flush    = 9
    } else if (isFourOfKind(cards_)) {
        rank = 8;                           //Four of a Kind    = 8
    } else if (isFullHouse(cards_)) {
        rank = 7;                           //Full House        = 7
    } else if (isFlush(cards_)) {
        rank = 6;                           //Flush             = 6
    } else if (isStraight(cards_)) {
        rank = 5;                           //Straight          = 5
    } else if (isThreeOfKind(cards_)) {
        rank = 4;                           //Three of a Kind   = 4
    } else if (isTwoPair(cards_)) {
        rank = 3;                           //Two Pair          = 3
    } else if (isPair(cards_)) {
        rank = 2;                           //Pair              = 2
    } else {
        rank = 1;                           //High Card         = 1
    }
    
    potentialBestCards_ = cards_;
    potentialBestRank_ = rank;
};

//Sort five cards and return
vector<Card> Hand::sort(vector<Card> cards_) {
    
    assert(cards_.size() == 5);     //Assert that exactly five cards should be in the cards_ vector
    
    cards_ = sortByGroup(cards_);   //Sort cards by group count
    
    return cards_;
    
};

//Sort cards by group count and return
vector<Card> Hand::sortByGroup(vector<Card> cards_) {
    
    assert(cards_.size() == 5);                                     //Assert that exactly five cards should be in the cards_ vector
    
    cards_ = sortByValue(cards_);                                   //Sort cards by value
    
    int firstCardPosition, secondCardPosition, thirdCardPosition, fourthCardPosition = 0;
    int firstCardCount, secondCardCount, thirdCardCount, fourthCardCount = 0;
    
    firstCardPosition = 0;                                          //Set first position at beginning of hand
    firstCardCount = countCards(cards_, firstCardPosition);         //Count instances of first card
    
    secondCardPosition = firstCardPosition + firstCardCount;        //Set second position at end of first group of cards
    if (secondCardPosition < cards_.size()) {                       //If the second position is not past the end of the hand
        secondCardCount = countCards(cards_, secondCardPosition);   //Count instances of second card
    } else {
        secondCardCount = 0;                                        //Or set to zero
    }
    
    thirdCardPosition = secondCardPosition + secondCardCount;       //Set third position at end of first group of cards
    if (thirdCardPosition < cards_.size()) {                        //If the third position is not past the end of the hand
        thirdCardCount = countCards(cards_, thirdCardPosition);     //Count instances of third card
    } else {
        thirdCardCount = 0;                                         //Or set to zero
    }
    
    fourthCardPosition = thirdCardPosition + thirdCardCount;        //Set fourth position at end of first group of cards
    if (fourthCardPosition < cards_.size()) {                       //If the fourth position is not past the end of the hand
        fourthCardCount = countCards(cards_, fourthCardPosition);   //Count instances of fourth card
    } else {
        fourthCardCount = 0;                                        //Or set to zero
    }

    /*
     Possibilities of groupings that need to be re-sorted, for 5 cards
        Z Y Y X X | 1 2 2 0 0 | Type 1
        Z Y Y Y Y | 1 4 0 0 0 | Type 2
        Z Z Y Y Y | 2 3 0 0 0 | Type 2
        Z Y Y Y X | 1 3 1 0 0 | Type 2
        Z Y Y X W | 1 2 1 1 0 | Type 2
        Z Y X X X | 1 1 3 0 0 | Type 3
        Z Y X X W | 1 1 2 1 0 | Type 3
        Z Y X W W | 1 1 1 2 0 | Type 4
        Z Z Y X X | 2 1 2 0 0 | Type 5
        2 3 4 5 A | 1 1 1 1 1 | Type 6 (Ace low straight)
        Z Y X W V | 1 1 1 1 1 | No additional sorting necessary
     */
    
    if (thirdCardCount > firstCardCount && secondCardCount > firstCardCount) {                                  //If Type 1
        
        cards_ = moveCards(cards_, secondCardCount, secondCardPosition, firstCardPosition);                     //Move the first point to the front
        cards_ = moveCards(cards_, thirdCardCount, thirdCardPosition, firstCardPosition + secondCardCount);    //Move the second pair behind the first pair
        
    } else if (secondCardCount > firstCardCount) {                                                              //If Type 2
    
        cards_ = moveCards(cards_, secondCardCount, secondCardPosition, firstCardPosition);                     //Move the pair in the second position to the front
        
    } else if (thirdCardCount > firstCardCount) {                                                               //If Type 3
        
        cards_ = moveCards(cards_, thirdCardCount, thirdCardPosition, firstCardPosition);                       //Move the pair in the third position to the front
        
    } else if (fourthCardCount > firstCardCount) {                                                              //If Type 4
        
        cards_ = moveCards(cards_, fourthCardCount, fourthCardPosition, firstCardPosition);                     //Move the pair in the fourth position to the front

    } else if (thirdCardCount > secondCardCount) {                                                              //If Type 5
        
        cards_ = moveCards(cards_, thirdCardCount, thirdCardPosition, secondCardPosition);                      //Move the pair in the third position behind the first pair
        
    } else if (cards_[0] == 14 &&                                                                    //If Type 6
               cards_[1] == 5 &&
               cards_[2] == 4 &&
               cards_[3] == 3 &&
               cards_[4] == 2) {
        
        cards_ = moveCard(cards_, 0, 4);                                                                        //Move the ace to the back
        
        cards_[4].setValue(ONE);                                                                                //Set the value of the ace to 1
        
    }
    
    return cards_;

};

//Sort cards by value and return
vector<Card> Hand::sortByValue(vector<Card> cards_) {
    
    for (int startCard = 0; startCard < cards_.size(); startCard++)                         //For each position in the hand
    {
        int highCard = startCard;
        
        for (int currentCard = startCard + 1; currentCard < cards_.size(); currentCard++)   //For each card from the card after starting position to last
        {
            if (cards_[currentCard] > cards_[highCard])                                     //If current card is higher than the high card
                highCard = currentCard;                                                     //Make current card the new high card
        }
        
        swap(cards_[startCard], cards_[highCard]);                                          //Swap high card with the current starting position
        
    }
    
    return cards_;
    
};



//Count the number of instances of a card at a given position
int Hand::countCards(vector<Card> cards_, int position) {
    
    int count = 1;
    
    for (int nextCard = position + 1; nextCard < cards_.size(); nextCard++) {       //For the next card
        if (cards_[position] == cards_[nextCard]) {                                 //Check if next card is equal to first
            count++;                                                                //If same, increase count and go to next card
        } else {
            break;                                                                  //If different, break from loop
        }
    }
    
    return count;
    
};

//Move group of cards from one position to another position
vector<Card> Hand::moveCards(vector<Card> cards_, int groupSize_, int fromPosition_, int toPosition_) {
    
    for (int card = 0; card < groupSize_; card++) {                                 //For each card in the group
        cards_ = moveCard(cards_, fromPosition_ + card, toPosition_ + card);        //Move the from a position to another another
    }
    
    return cards_;
    
};

//Move one card from one position to another position
vector<Card> Hand::moveCard(vector<Card> cards_, int fromPosition_, int toPosition_) {
    
    if (fromPosition_ < toPosition_) {                                              //If moving from the top to the bototm of the hand
        for (int position = fromPosition_; position < toPosition_; position++) {    //For each position until to position
            swap(cards_[position], cards_[position+1]);                             //Move card down one position
        }
    } else if (fromPosition_ > toPosition_) {                                       //If moving from the bottom to the top of the hand
        for (int position = fromPosition_; position > toPosition_; position--) {    //For each position until to position
            swap(cards_[position], cards_[position-1]);                             //Move card up one position
        }
    }
    
    return cards_;
    
};

//Evaluate five cards to detect straight flush, return bool; assumes vector of cards is sorted by group
bool Hand::isStraightFlush(vector<Card> cards_) {
    
    assert(cards_.size() == 5);                         //Assert that exactly five cards should be in the cards_ vector
    
    bool result = false;                                //Set to false by default
    
    if ((isFlush(cards_)) && (isStraight(cards_))) {    //If both flush and straight
        result = true;                                  //Set to true
    }
    
    return result;
    
};

//Evaluate five cards to detect four of a kind, return bool; assumes vector of cards is sorted by group
bool Hand::isFourOfKind(vector<Card> cards_) {
    
    assert(cards_.size() == 5);         //Assert that exactly five cards should be in the cards_ vector

    bool result = false;                //Set to false by default
    
    if (countCards(cards_, 0) == 4) {   //If first four cards are the same value
        result = true;                  //Set to true
    }
    
    return result;
    
};

//Evaluate five cards to detect full house, return bool; assumes vector of cards is sorted by group
bool Hand::isFullHouse(vector<Card> cards_) {
    
    assert(cards_.size() == 5);                                             //Assert that exactly five cards should be in the cards_ vector

    bool result = false;                                                    //Set to false by default
    
    if ((countCards(cards_, 0) == 3) && (countCards(cards_, 3) == 2)) {     //If first group's size is 3 and second group's size is 2
        result = true;                                                      //Set to true
    }
        
    return result;
    
};

//Evaluate five cards to detect flush, return bool; assumes vector of cards is sorted by group
bool Hand::isFlush(vector<Card> cards_) {
    
    assert(cards_.size() == 5);                         //Assert that exactly five cards should be in the cards_ vector

    bool result = false;                                //Set to false by default
    
    if (cards_[0].getSuit() == cards_[1].getSuit() &&   //If all cards are the same suit
        cards_[1].getSuit() == cards_[2].getSuit() &&
        cards_[2].getSuit() == cards_[3].getSuit() &&
        cards_[3].getSuit() == cards_[4].getSuit()) {
        result = true;                                  //Set to true
    }
    
    return result;
    
};

//Evaluate five cards to detect straight, return bool; assumes vector of cards is sorted by group
bool Hand::isStraight(vector<Card> cards_) {
    
    assert(cards_.size() == 5);                                 //Assert that exactly five cards should be in the cards_ vector

    bool result = false;                                        //Set to false by default
    
    if (cards_[0] - cards_[1] == 1 &&     //If all cards are sequential
        cards_[1] - cards_[2] == 1 &&
        cards_[2] - cards_[3] == 1 &&
        cards_[3] - cards_[4] == 1) {     //Set to true
        result = true;
    } else if (cards_[0] == 14 &&                    //If an ace-low straight
               cards_[1] == 5 &&
               cards_[2] == 4 &&
               cards_[3] == 3 &&
               cards_[4] == 2) {
        result = true;
    }
    
    return result;
    
};

//Evaluate five cards to detect three of a kind, return bool; assumes vector of cards is sorted by group
bool Hand::isThreeOfKind(vector<Card> cards_) {
    
    assert(cards_.size() == 5);                                             //Assert that exactly five cards should be in the cards_ vector

    bool result = false;                                                    //Set to false by default
    
    if ((countCards(cards_, 0) == 3) && (countCards(cards_, 3) == 1)) {     //If the first group's size is 3 and the second group's size is 1
        result = true;                                                      //Set to true
    }
    
    return result;

};

//Evaluate five cards to detect two pair, return bool; assumes vector of cards is sorted by group
bool Hand::isTwoPair(vector<Card> cards_) {

    assert(cards_.size() == 5);                                             //Assert that exactly five cards should be in the cards_ vector

    bool result = false;                                                    //Set to false by default

    if ((countCards(cards_, 0) == 2) && (countCards(cards_, 2) == 2)) {     //If the first group's size is 2 and the second group's size is 2
        result = true;                                                      //Set to true
    }
    
    return result;
    
}

//Evaluate five cards to detect pair, return bool; assumes vector of cards is sorted by group
bool Hand::isPair(vector<Card> cards_) {
    
    assert(cards_.size() == 5);                                             //Assert that exactly five cards should be in the cards_ vector

    bool result = false;                                                    //Set to false by default
    
    if ((countCards(cards_, 0) == 2) && (countCards(cards_, 2) == 1)) {     //If the first group's size is 2 and the second group's size is 1
        result = true;                                                      //Set to true
    }
    
    return result;
    
};

/////Display Functions/////

//Create string of one card in _cards vector
string Hand::showCard(int position_) {
    
    return getCard(position_).show();
    
}

//Create string of first two cards in _cards vector
string Hand::showPocket() {
    
    string stringOfCards;
    
    for (int card = 0; card < 2; card++) {                          //For each of first two cards
        stringOfCards = stringOfCards + getCard(card).show();       //Add current card to string of cards
        if (card + 1 != 2) {
            stringOfCards = stringOfCards + " ";                    //Add space after each card, except the last one
        }
        
    }
    
    return stringOfCards;                                           //Return cards
    
};

//Create string of third through seventh card in _cards vector
string Hand::showBoard() {
    
    string stringOfCards;

    for (int card = 2; card < 7; card++) {                          //For each of cards three through seven
        stringOfCards = stringOfCards + getCard(card).show();       //Add current card to string of cards
        if (card + 1 != 7) {
            stringOfCards = stringOfCards + " ";                    //Add space after each card, except the last one
        }
    }
    
    return stringOfCards;                                           //Return cards
    
}

//Create string of all cards in _cards vector
string Hand::showAllCards() {
    
    string stringOfCards;
    
    stringOfCards = showPocket() + " " + showBoard();               //Add string of pocket cards to string of board cards
    
    return stringOfCards;                                           //Return cards
    
};

//Create string of all cards in _bestCards vector
string Hand::showBestCards() {
    
    string stringOfCards;
        
    for (int i = 0; i < 5; i++) {                                   //For each of cards three through seven
        stringOfCards = stringOfCards + getBestCard(i).show();      //Add current card to string of cards
        if (i + 1 != 5) {
            stringOfCards = stringOfCards + " ";                    //Add space after each card, except the last one
        }
    }
    
    return stringOfCards;                                           //Return best cards
    
};

//Create string of the hand value
string Hand::showHandValue() {
    
    string value;
    
    switch (_rank) {                        //For the value of data member _rank, print spoken hand value
        case 9:
            value = "Straight Flush";
            break;
        case 8:
            value = "Four of a Kind";
            break;
        case 7:
            value = "Full House";
            break;
        case 6:
            value = "Flush";
            break;
        case 5:
            value = "Straight";
            break;
        case 4:
            value = "Three of a Kind";
            break;
        case 3:
            value = "Two Pair";
            break;
        case 2:
            value = "Pair";
            break;
        case 1:
            value = "High Card";
            break;
            
        default:                            //If value is equal to 0 or another undefined value, print "Unknown Value"
            value = "Unknown Value";
            break;
    }
    
    return value;
    
};

//Print string of one card in _cards vector
void Hand::printCard(int position_) {
    cout << showCard(position_) << endl;
}

//Print string of first two cards in _cards vector
void Hand::printPocket() {
    cout << showPocket() << endl;
}

//Print string of third through seventh card in _cards vector
void Hand::printBoard() {
    cout << showBoard() << endl;
}

//Print string of all cards in _cards vector
void Hand::printAllCards() {
    cout << showAllCards() << endl;
}

//Print string of all cards in _bestCards vector
void Hand::printBestCards() {
    cout << showBestCards() << endl;
}

//Print hand value
void Hand::printHandValue() {
    cout << showHandValue() << endl;
}

//Print rank value
void Hand::printRank() {
    cout << getRank() << endl;
}