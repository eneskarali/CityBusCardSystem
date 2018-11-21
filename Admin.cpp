//
// Created by enesk on 23.12.2017.
//

#include "Admin.h"

Admin::Admin(const char *n, const char *s, int t, enum PersonType type) : Person(n, s, t, type){
    setName(n);
    setSurname(s);
    setTc(t);
    setPersonalType(type);
    personNo++;
}

int Admin::getPersonNo() {

    return personNo;
}

void Admin::createUser(Person** array, const char *adi, const char *soyadi, int tc, enum PersonType type) {
    User *user1User;
    Card *uc1,*uc2;
    uc1= new Card;
    uc2 = new Card;
    user1User= new User(uc1,uc2,adi,soyadi,tc,type);
    array[personNo]=user1User;
    personNo++;
}

void Admin::deleteUser(Person** array, int userTc) {
    for (int i = 0; i <personNo; ++i) {
        if (array[i]->getTc()==userTc){
            delete array[i];
            for (int j = i; j < personNo-1; ++j) {
                array[j]=array[j+1];
            }
            array[personNo]= nullptr;
            personNo--;
            break;
        }
    }
}

User* Admin::findUser(Person ** array, int tcN) {
    for (int i = 0; i < personNo; ++i) {
        if(tcN == array[i]->getTc()){
            return (User*)array[i];
        }
    }
    return nullptr;
}

void Admin::showPersonState(Person* p) {
    cout<<"- MEVCUT PERSONEL BILGILEDI -"<<endl;
    cout<<"Adi: "<< p->getName()<<endl;
    cout<<"Soy Adi: "<< p->getSurname()<<endl;
    cout<<"TC: "<<p->getTc()<<endl;
}

void Admin::showUserState(User * u) {
    cout<<"- KULLANICI BILGILARI -"<<endl;
    cout<<"Adi: "<< u->getName()<<endl;
    cout<<"Soy Adi: "<< u->getSurname()<<endl;
    cout<<"TC: "<<u->getTc()<<endl;

}

void Admin::combineUserCards(User * u) {
    u->setCardBalance(u->getUserCard1Balance()+u->getUserCard2Balance(),0);
}


