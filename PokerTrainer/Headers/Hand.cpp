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

Hand::Hand() {
    _cards.reserve(7);
    _bestCards.reserve(5);
    _rank = 0;
};

void Hand::addCard(Card card_){
    
    _cards.push_back(card_);
    
};

vector<Card> Hand::sort(vector<Card> cards_) {
    
    assert(cards_.size() == 5);
    
    for (int startIndex = 0; startIndex < cards_.size(); startIndex++)
    {
        int largestIndex = startIndex;
        
        for (int currentIndex = startIndex + 1; currentIndex < cards_.size(); currentIndex++)
        {
            if (cards_[currentIndex].getValue() > cards_[largestIndex].getValue())
                largestIndex = currentIndex;
        }
        
        swap(cards_[startIndex], cards_[largestIndex]);
        
    }

    int firstCardPosition = 0;
    int firstCardCount = 0;
    
    for(firstCardPosition = 0; firstCardPosition < cards_.size() - 1; firstCardPosition++) {
        
        firstCardCount = 1;
        
        for (int nextCard = firstCardPosition + 1; nextCard < cards_.size(); nextCard++) {
            if (cards_[firstCardPosition].getValue() == cards_[nextCard].getValue()) {
                firstCardCount++;
            } else {
                break;
            }
        }
    }
        
    int secondCardPosition = 0;
    int secondCardCount = 0;
    
    for (secondCardPosition = firstCardPosition + firstCardCount;  secondCardPosition < cards_.size() - 1; secondCardPosition++) {
                
        secondCardCount = 1;
        
        for (int nextCard = secondCardPosition + 1; nextCard < cards_.size(); nextCard++) {
            if (cards_[secondCardPosition].getValue() == cards_[nextCard].getValue()) {
                secondCardCount++;
            } else {
                break;
            }
        }
    }
    
    int thirdCardPosition = 0;
    int thirdCardCount = 0;
        
    for (thirdCardPosition = secondCardPosition + secondCardCount;  thirdCardPosition < cards_.size() - 1; thirdCardPosition++) {
                
        thirdCardCount = 1;
        
        for (int nextCard = thirdCardPosition + 1; nextCard < cards_.size(); nextCard++) {
            if (cards_[thirdCardPosition].getValue() == cards_[nextCard].getValue()) {
                thirdCardCount++;
            } else {
                break;
            }
        }
    }
    
    int fourthCardPosition = 0;
    int fourthCardCount = 0;

    for (fourthCardPosition = thirdCardPosition + thirdCardCount;  fourthCardPosition < cards_.size() - 1; fourthCardPosition++) {
                
        fourthCardCount = 1;
                
        for (int nextCard = fourthCardPosition + 1; nextCard < cards_.size(); nextCard++) {
            if (cards_[fourthCardPosition].getValue() == cards_[nextCard].getValue()) {
                fourthCardCount++;
            } else {
                break;
            }
        }
    }
        
    if (thirdCardCount > firstCardCount && secondCardCount > firstCardCount) {
        for (int i = 0; i < secondCardCount; i++) {
            for (int j = secondCardPosition; j > firstCardPosition; j--) {
                swap(cards_[j+i], cards_[j+i-1]);
            }
        }
        for (int i = 0; i < thirdCardCount; i++) {
            for (int j = thirdCardPosition; j > secondCardCount; j--) {
                swap(cards_[j+i], cards_[j+i-1]);
            }
        }
    } else if (secondCardCount > firstCardCount) {
        for (int i = 0; i < secondCardCount; i++) {
            for (int j = secondCardPosition; j > firstCardPosition; j--) {
                swap(cards_[j+i], cards_[j+i-1]);
            }
        }
    } else if (thirdCardCount > secondCardCount) {
        for (int i = 0; i < thirdCardCount; i++) {
            for (int j = thirdCardPosition; j > secondCardPosition; j--) {
                swap(cards_[j+i], cards_[j+1-1]);
            }
        }
    } else if (thirdCardCount > firstCardCount) {
        for (int i = 0; i < thirdCardCount; i++) {
            for (int j = thirdCardPosition; j > firstCardPosition; j--) {
                swap(cards_[j+i], cards_[j+1-1]);
            }
        }
    } else if (fourthCardCount > firstCardCount) {
        for (int i = 0; i < thirdCardCount; i++) {
            for (int j = fourthCardPosition; j > firstCardPosition; j--) {
                swap(cards_[j+i], cards_[j+1-1]);
            }
        }
    } else if (cards_[0].getValue() == 14 &&
               cards_[1].getValue() == 5 &&
               cards_[2].getValue() == 4 &&
               cards_[3].getValue() == 3 &&
               cards_[4].getValue() == 2) {
        for (int i = 0; i < cards_.size() - 1; i++) {
            swap(cards_[i], cards_[i+1]);
        }
        cards_[4].setValue(ONE);
    }

/*
    Possibilities
    ABBBB 1 4
    AABBB 2 3
    ABBBC 1 3 1
    ABCCC 1 1 3
    ABBCC 1 2 2
    AABCC 2 1 2
    ABBCD 1 2 1 1
    ABCCD 1 1 2 1
    ABCDD 1 1 1 2
    2345A
*/
    
    return cards_;
                                                                          
};

bool Hand::isStraightFlush(vector<Card> cards_) {
    
    assert(cards_.size() == 5);

    bool result = false;
    
    if ((cards_[0].getValue() - cards_[1].getValue() == 1 &&
         cards_[1].getValue() - cards_[2].getValue() == 1 &&
         cards_[2].getValue() - cards_[3].getValue() == 1 &&
         cards_[3].getValue() - cards_[4].getValue() == 1) &&
        (cards_[0].getSuit() == cards_[1].getSuit() &&
         cards_[1].getSuit() == cards_[2].getSuit() &&
         cards_[2].getSuit() == cards_[3].getSuit() &&
         cards_[3].getSuit() == cards_[4].getSuit())) {
            result = true;
    }
    
    if ((cards_[0].getValue() == 14 &&
         cards_[1].getValue() == 5 &&
         cards_[2].getValue() == 4 &&
         cards_[3].getValue() == 3 &&
         cards_[4].getValue() == 2) &&
        (cards_[0].getSuit() == cards_[1].getSuit() &&
         cards_[1].getSuit() == cards_[2].getSuit() &&
         cards_[2].getSuit() == cards_[3].getSuit() &&
         cards_[3].getSuit() == cards_[4].getSuit())) {
            
            result = true;
            
    }
    
    return result;
    
};

bool Hand::isFourOfKind(vector<Card> cards_) {
    
    assert(cards_.size() == 5);

    bool result = false;
    
    for (int i = 0; i < 2; i++) {
        if (cards_[i].getValue() == cards_[i+1].getValue() &&
            cards_[i+1].getValue() == cards_[i+2].getValue() &&
            cards_[i+2].getValue() == cards_[i+3].getValue()) {
            
            result = true;
            
        }
    }
    
    return result;
    
};

bool Hand::isFullHouse(vector<Card> cards_) {
    
    assert(cards_.size() == 5);

    bool result = false;
    
    if ((cards_[0].getValue() == cards_[1].getValue() &&
          cards_[1].getValue() == cards_[2].getValue()) &&
         (cards_[3].getValue() == cards_[4].getValue())) {
            result = true;
    } else if ((cards_[2].getValue() == cards_[3].getValue() &&
          cards_[3].getValue() == cards_[4].getValue()) &&
         (cards_[0].getValue() == cards_[1].getValue())) {
            result = true;
    }
    
    return result;
    
};

bool Hand::isFlush(vector<Card> cards_) {
    
    assert(cards_.size() == 5);

    bool result = false;
    
    if (!isStraightFlush(cards_)) {
        
        if (cards_[0].getSuit() == cards_[1].getSuit() &&
            cards_[1].getSuit() == cards_[2].getSuit() &&
            cards_[2].getSuit() == cards_[3].getSuit() &&
            cards_[3].getSuit() == cards_[4].getSuit()) {

            result = true;

        }
    }
    
    return result;
    
};

bool Hand::isStraight(vector<Card> cards_) {
    
    assert(cards_.size() == 5);

    bool result = false;
    
    if (!isStraightFlush(cards_)) {
        
        if (cards_[0].getValue() - cards_[1].getValue() == 1 &&
            cards_[1].getValue() - cards_[2].getValue() == 1 &&
            cards_[2].getValue() - cards_[3].getValue() == 1 &&
            cards_[3].getValue() - cards_[4].getValue() == 1) {
        
            result = true;
        
        }
            
        if (cards_[0].getValue() == 14 &&
            cards_[1].getValue() == 5 &&
            cards_[2].getValue() == 4 &&
            cards_[3].getValue() == 3 &&
            cards_[4].getValue() == 2) {

            result = true;
            
        }
    }
    
    return result;
    
};

bool Hand::isThreeOfKind(vector<Card> cards_) {
    
    assert(cards_.size() == 5);

    bool result = false;
    
    if (!isFourOfKind(cards_) && !isFullHouse(cards_)) {
        
        for (int i = 0; i < 3; i++) {
            if (cards_[i].getValue() == cards_[i+1].getValue() &&
                cards_[i+1].getValue() == cards_[i+2].getValue()) {
                
                result = true;
                
            }
        }
    }
    
    return result;

};

bool Hand::isTwoPair(vector<Card> cards_) {

    assert(cards_.size() == 5);

    bool result = false;

    if (!isFourOfKind(cards_) && !isFullHouse(cards_)) {
        
        if (cards_[0].getValue() == cards_[1].getValue() &&
            cards_[2].getValue() == cards_[3].getValue()) {
        
            result = true;
 
        }

        if (cards_[0].getValue() == cards_[1].getValue() &&
            cards_[3].getValue() == cards_[4].getValue()) {
            
            result = true;

        }

        if (cards_[1].getValue() == cards_[2].getValue() &&
            cards_[3].getValue() == cards_[4].getValue()) {
            
            result = true;

        }
    }

    return result;
    
}

bool Hand::isPair(vector<Card> cards_) {
    
    assert(cards_.size() == 5);

    bool result = false;
    
    if (!isFourOfKind(cards_) && !isFullHouse(cards_) && !isThreeOfKind(cards_) && !isTwoPair(cards_)) {
        
        for (int i = 0; i < 4; i++) {
            if (cards_[i].getValue() == cards_[i+1].getValue()) {
                
                result = true;
                                
             }
        }
    }
    
    return result;
    
};

void Hand::evalRankFive(vector<Card> &potentialBestCards_, int &potentialBestRank_, vector<Card> cards_) {
    
    assert(cards_.size() == 5);

    int rank = 0;

    cards_ = sort(cards_);
    
    if (isStraightFlush(cards_)) {
        rank = 9;
    } else if (isFourOfKind(cards_)) {
        rank = 8;
    } else if (isFullHouse(cards_)) {
        rank = 7;
    } else if (isFlush(cards_)) {
        rank = 6;
    } else if (isStraight(cards_)) {
        rank = 5;
    } else if (isThreeOfKind(cards_)) {
        rank = 4;
    } else if (isTwoPair(cards_)) {
        rank = 3;
    } else if (isPair(cards_)) {
        rank = 2;
    } else {
        rank = 1;
    }
    
    potentialBestCards_.clear();
    for (int card = 0; card < 5; card++) {
        potentialBestCards_.push_back(cards_[card]);
    }
    potentialBestRank_ = rank;
};

void Hand::evalRankSeven(vector<Card> &potentialBestCards_, int &potentialBestRank_, vector<Card> cards_) {
    
    assert(cards_.size() == 7);

    vector<Card> evalCards;
    evalCards.reserve(5);
    
    vector<Card> tempBestCards;
    tempBestCards.reserve(5);
    int tempBestRank = 0;
    
    for (int i = 7 - 1; i > 0; i--) {
        for (int j = 7 - 1; j > 0; j--) {
            if (i != j) {
                
                evalCards.clear();
                
                for (int k = 0; k < 7; k++) {
                    if (k != i && k != j) {
                        evalCards.push_back(cards_[k]);
                    }
                }
                
                evalRankFive(tempBestCards, tempBestRank, evalCards);
                
                if (tempBestRank > potentialBestRank_) {
                    potentialBestCards_.clear();
                    for (int card = 0; card < 5; card++) {
                        potentialBestCards_.push_back(tempBestCards[card]);
                    }
                    potentialBestRank_ = tempBestRank;
                } else if (tempBestRank == potentialBestRank_) {
                    for (int card = 0; card < 5; card++) {
                        if (tempBestCards[i].getValue() > potentialBestCards_[i].getValue()) {
                            potentialBestCards_.clear();
                            for (int card = 0; card < 5; card++) {
                                potentialBestCards_.push_back(tempBestCards[card]);
                            }
                            potentialBestRank_ = tempBestRank;
                            break;
                        }
                    }
                }
            }
        }
    }
};

void Hand::evalRank() {

    vector<Card> cards;
    cards.reserve(7);
   
    vector<Card> potentialBestCards;
    potentialBestCards.reserve(5);
    int potentialBestRank = 0;
    
    for (int card = 0; card < 7; card++) {
        cards.push_back(_cards[card]);
    }
 
    if (_cards.size() == 5) {
        evalRankFive(potentialBestCards, potentialBestRank, cards);
    } else if (_cards.size() == 7) {
        evalRankSeven(potentialBestCards, potentialBestRank, cards);
    }
    _bestCards.clear();
    for (int card = 0; card < 5; card++) {
        _bestCards.push_back(potentialBestCards[card]);
    }
        _rank = potentialBestRank;
};

/*
int Hand::compare(vector<Card> firstCards_, int firstRank_, vector<Card> secondCards_) {
    
    int result = 0;
    
    if (firstRank_ > 2) {
        result = 1;
    } else if (firstRank_ < evaluateRank(second_)) {
        result = 2;
    } else {
        for (int i = 0; i < 5; i++) {
            if (first_.getBestCard(i).getValue() > second_.getBestCard(i).getValue()) {
                result = 1;
            } else if (first_.getBestCard(i).getValue() < second_.getBestCard(i).getValue()) {
                result = -1;
            }
        }
    }
    
    return 5;
    
};
 */

string Hand::showCard(int position_) {
    
    return getCard(position_).show();
    
}

string Hand::showPocket() {
    
    string stringOfCards;
    
    for (int card = 0; card < 2; card++) {
        stringOfCards = stringOfCards + getCard(card).show();
        if (card + 1 != 2) {
            stringOfCards = stringOfCards + " ";
        }
        
    }
    
    return stringOfCards;
    
};

string Hand::showBoard() {
    
    string stringOfCards;
    
    for (int card = 2; card < 7; card++) {
        stringOfCards = stringOfCards + getCard(card).show();
        if (card + 1 != 7) {
            stringOfCards = stringOfCards + " ";
        }
    }
    
    return stringOfCards;
    
}

string Hand::showAllCards() {
    
    string stringOfCards;
    
    stringOfCards = showPocket() + " " + showBoard();
    
    return stringOfCards;
    
};

string Hand::showBestCards() {
    
    string stringOfCards;
    
    for (int i = 0; i < 5; i++) {
        stringOfCards = stringOfCards + getBestCard(i).show();
        
        if (i + 1 != 5) {
            stringOfCards = stringOfCards + " ";
        }
    }
    
    return stringOfCards;
    
};


string Hand::showHandValue() {
    
    string value;
    
    switch (_rank) {
        case 9:
            value = "Royal Flush";
            break;
        case 8:
            value = "Four of a Kinda";
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
            
        default:
            value = "Unknown Value";
            break;
    }
    
    return value;
    
};

void Hand::printCard(int position_) {
    cout << showCard(position_) << endl;
}
    
void Hand::printPocket() {
    cout << showPocket() << endl;
}

void Hand::printBoard() {
    cout << showBoard() << endl;
}

void Hand::printAllCards() {
    cout << showAllCards() << endl;
}

void Hand::printBestCards() {
    cout << showBestCards() << endl;
}

void Hand::printRank() {
    cout << getRank() << endl;
}

void Hand::printHandValue() {
    cout << showHandValue() << endl;
}