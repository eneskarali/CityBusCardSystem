//
// Created by enesk on 23.12.2017.
//

#include "User.h"

User::User(Card* uc1, Card* uc2, const char *n, const char *s, int tc , enum PersonType type) : Person(n, s, tc, type){
    userCard1=uc1;
    userCard2=uc2;
    setName(n);
    setSurname(s);
    setTc(tc);
    setPersonalType(type);
}

void User::setCardType(cardType card) {
    userCard1->setCardType(card);
    userCard2->setCardType(card);
}

void User::setCardBalance(int one, int two) {
    userCard1->setBalance(one);
    userCard2->setBalance(two);
}

int User::getUserCard1Balance() {
    return userCard1->getBalance();
}

int User::getUserCard2Balance() {
    return userCard2->getBalance();
}

void User::loadBalance(Card * c,int cost) {
    c->setBalance(c->getBalance()+cost);
}

void User::readCard(Card* c) {
    if(c->getCardType(c)==student){
        if(c->getBalance()<1000){
            cout<<"Yetersiz Bakiye!"<<endl;
        }
        else{
            c->setBalance(c->getBalance()-1000);
            cout<<"Tutar: 1000"<<endl;
            cout<<"Kalan Bakiye: "<<c->getBalance()<<endl;
        }
    }
    else if(c->getCardType(c)==normal){
        if(c->getBalance()<2000){
            cout<<"Yetersiz Bakiye!"<<endl;
        }
        else{
            c->setBalance(c->getBalance()-2000);
            cout<<"Tutar: 2000"<<endl;
            cout<<"Kalan Bakiye: "<<c->getBalance()<<endl;
        }
    }
    else{
        cout<<"Tutar: 0";
    }
}

int User::showCardState(Card*  c) {
return c->getBalance();
}

Card* User::getCard1() {
    return userCard1;
}

Card* User::getCard2() {
    return userCard2;
}