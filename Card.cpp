//
// Created by enesk on 23.12.2017.
//

#include "Card.h"


void Card::setCardType(cardType t) {
    type=t;
}
void Card::setBalance(int b) {
    balance=b;
}

int Card::getBalance() {
    return balance;
}

cardType Card::getCardType(Card*  c) {
    return c->type;
}