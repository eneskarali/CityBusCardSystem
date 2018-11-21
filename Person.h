//
// Created by enesk on 23.12.2017.
//

#include <iostream>
#include "Card.h"

using namespace std;

#ifndef BP3PREOJECT2_PERSON_H
#define BP3PREOJECT2_PERSON_H




enum PersonType {

    user,admin

};


class Person {
    char name[20];
    char surname[20];
    enum PersonType pType;




public:
    int tcNo;
    int personNo=0;
    Person(const char *, const char *, int, enum PersonType);
    void setName(const char *);
    string getName();
    void setSurname(const char *);
    string getSurname();
    int getTc();
    void setTc(int);
    void setPersonalType( enum PersonType);
    enum PersonType getPersonelType();


};


#endif //BP3PREOJECT2_PERSON_H
