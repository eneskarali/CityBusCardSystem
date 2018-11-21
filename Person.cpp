//
// Created by enesk on 23.12.2017.
//
#include <iostream>
#include <cstring>
#include "Person.h"
#include "User.h"

using namespace std;




Person::Person(const char *n, const char *s, int tc, enum PersonType t) {
    strcpy(name,n);
    strcpy(surname, s);
    tcNo=tc;
    pType=t;
}

string Person::getName() {
    return name;
}

void Person::setName(const char *newName) {
    strcpy(name,newName);
}

string Person::getSurname() {
    return surname;
}

void Person::setSurname(const char *newSurname) {
    strcpy(surname, newSurname);
}

enum PersonType Person::getPersonelType() {
    return pType;
}

void Person::setPersonalType(enum  PersonType newType) {
    pType=newType;
}

int Person::getTc() {
    return tcNo;
}
void Person::setTc(int nT) {
    tcNo=nT;

}
