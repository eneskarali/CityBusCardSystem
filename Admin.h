//
// Created by enesk on 23.12.2017.
//

#ifndef BP3PREOJECT2_ADMIN_H
#define BP3PREOJECT2_ADMIN_H


#include "User.h"



class Admin : public Person {



public:
    Admin(const char *, const char *, int, enum PersonType);
    int getPersonNo();
    void createUser(Person**, const char *, const char *, int , enum  PersonType);
    void deleteUser(Person**, int);
    void showPersonState(Person*);
    void showUserState(User*);
    User* findUser(Person**,int);
    void combineUserCards(User*);
};




#endif //BP3PREOJECT2_ADMİN_H
