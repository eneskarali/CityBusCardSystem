//
// Created by enesk on 23.12.2017.
//

#ifndef BP3PREOJECT2_CARD_H
#define BP3PREOJECT2_CARD_H
typedef enum cardType{
    normal,student,retired
}cardType;

class Card {
    int balance;
    cardType type;
public:
    void setCardType(cardType);
    void setBalance(int);
    int getBalance();
    cardType getCardType(Card*);

};


#endif //BP3PREOJECT2_CARD_H
