//
// Created by enesk on 23.12.2017.
//
#include <iostream>
using namespace std;

#ifndef BP3PREOJECT2_USER_H
#define BP3PREOJECT2_USER_H


#include "Person.h"
#include "Card.h"

class User : public Person {
    Card* userCard1;
    Card* userCard2;
public:

    User(Card* , Card* , const char *, const char *, int , enum PersonType);
    void setCardType(cardType);
    void setCardBalance(int,int);
    int getUserCard1Balance();
    int getUserCard2Balance();
    Card* getCard1();
    Card* getCard2();
    void loadBalance(Card*,int);
    void readCard(Card*);
    int showCardState(Card*);

};


#endif //BP3PREOJECT2_USER_H
