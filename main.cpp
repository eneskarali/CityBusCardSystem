#include <iostream>
#include "Person.h"
#include "User.h"
#include "Admin.h"



using namespace std;

Person** persons  = new Person*[10] ;


int main() {

    //istenilen bilgi tanımlamaları=
    Admin* admin1;
    admin1 = new Admin("hakki", "hakli",1234,admin);
    persons[0]=admin1;

    User* u;
    admin1->createUser(persons,"selin","sakli",4321,user);
    u=admin1->findUser(persons,4321);
    u->setCardType(student);
    u->setCardBalance(10000,200);



    //Menu yapisi=
    int exitState2=1;
    do {
        system("cls");
        int choice;
        cout << "           IETT" << endl;
        cout << " 1 -  Yonetici Islemleri   " << endl;
        cout << " 2 -  Kullanici Islemleri" << endl;
        cout << " 3 -  Cikis" << endl;
        cout << "\nYapilacak Islem Numarasini Giriniz:";
        cin >> choice;
        system("cls");
        if (choice == 1) {
            bool itt= false;
            newQuaryForSign:
            system("cls");
            cout << "- IETT YOTETICI GIRISI -" << endl;
            int tcNo;
            cout << "TC:";
            cin >> tcNo;
            system("cls");
            for (int i = 0; i < admin1->getPersonNo(); ++i) {
                if (persons[i]->getTc() == tcNo && persons[i]->getPersonelType() == admin) {
                    int exitState = 1;
                    itt= true;
                    do {
                        system("cls");
                        cout << "     - YONETICI ISLEMLERI -" << endl;
                        cout << " 1 -  Kullanici Olustur" << endl;
                        cout << " 2 -  Kullanici Sil" << endl;
                        cout << " 3 -  Kisi Durumumu Goster" << endl;
                        cout << " 4 -  Kullanici Bul" << endl;
                        cout << " 5 -  Kullanici Kartlarini Birlestir" << endl;
                        cout << " 6 -  Kullanici Isim Soyisim Degistir" << endl;
                        cout << " 7 -  Ana Menuye Don" << endl;
                        cout << "\nYapilacak Islem Numarasini Giriniz: ";
                        cin >> choice;
                        system("cls");
                        if (choice == 1) {
                            cout << "- YENI KULLANICI BILGILERI -" << endl;
                            char name[20];
                            cout << "Adi: ";
                            cin >> name;
                            char surname[20];
                            cout << "Soyadi: ";
                            cin >> surname;
                            int tc;
                            cout << "TC: ";
                            cin >> tc;
                            admin1->createUser(persons, name, surname, tc, user);
                            char cType[10];
                            cout << "Kullanici Kart Tipi Rakami: [normal=0/student=1/retired=2]  :";
                            cin >> cType;
                            User *u;
                            u = admin1->findUser(persons, tc);
                            u->setCardType((cardType) 0);
                            u->setCardBalance(0, 0);
                            system("cls");
                            cout << "\n" << name << " " << surname << " "
                                 << " Kullanicisi Basariyla Kayit Edilmistir. Menuye Donmek Icin Bir Tusa Basiniz..."
                                 << endl;
                            system("pause");

                        } else if (choice == 2) {
                            cout << "Silinecek Kullanici TC No:";
                            cin >> tcNo;
                            if (admin1->findUser(persons, tcNo) == nullptr) {
                                cout
                                        << "\nGirdiginiz TC ye Ait Kullanici Bulunamadi! Menuye Donmek Icin Bir Tusa Basiniz... "
                                        << endl;
                                system("pause");
                            } else {
                                cout << admin1->findUser(persons, tcNo)->getName() << " "
                                     << admin1->findUser(persons, tcNo)->getSurname()
                                     << " Kullanicisi silinsin mi?  [y/n]  :";
                                string yesNo;
                                cin >> yesNo;
                                if (yesNo == "y") {
                                    admin1->deleteUser(persons, tcNo);
                                    system("cls");
                                    cout << "\nKullanici SILINDI! Menuye Donmek Icin Bir Tusa Basiniz..." << endl;
                                    system("pause");
                                } else if (yesNo == "n") {
                                    system("cls");
                                    cout << "\nKullanici SILINMEDI, Menuye Donmek Icin Bir Tusa Basiniz..." << endl;
                                    system("pause");
                                } else {
                                    cout << "\ny veya n olarak giris yapiniz! Menuye Donmek Icin Bir Tusa Basiniz..."
                                         << endl;
                                    system("pause");
                                }
                            }

                        } else if (choice == 3) {
                            admin1->showPersonState(persons[i]);
                            cout << "\nMenuye Donmek Icin Bir Tusa Basiniz..." << endl;
                            system("pause");
                        } else if (choice == 4) {
                            newQuery:
                            cout << "- KULLANICI ARAMA -" << endl;
                            cout << "Aranan Kisi TC: ";
                            cin >> tcNo;

                            if (admin1->findUser(persons, tcNo) == nullptr) {
                                system("cls");
                                string state;
                                cout
                                        << "Girdiğiniz TC ye Ait Kullanici Bulunamadi! Menuye Donmek Icin y, Yeni Sorgu Icin n Yaziniz: ";
                                cin >> state;
                                if (state == "n") {
                                    system("cls");
                                    goto newQuery;
                                }
                            } else {
                                User *u;
                                u = admin1->findUser(persons, tcNo);
                                system("cls");
                                cout << "- BULUNAN KULLANICI BILGILARI -" << endl;
                                cout << "Adi: " << u->getName() << endl;
                                cout << "Soy Adi: " << u->getSurname() << endl;
                                cout << "TC: " << u->getTc() << endl;
                                string si;
                                cout << "Menuye donmek icin y, yeni bir arama yapmak icin n yaziniz:";
                                cin >> si;
                                if (si == "n") {
                                    system("cls");
                                    goto newQuery;
                                }
                            }
                        } else if (choice == 5) {
                            newQueryforCombine:
                            cout << "- KART BIRLESTIRME YAPILACAK KISI BILGISI -" << endl;
                            cout << "Kisi TC: ";
                            cin >> tcNo;
                            User *u;
                            if (admin1->findUser(persons, tcNo) == nullptr) {
                                system("cls");
                                string state;
                                cout
                                        << "Girdiğiniz TC ye Ait Kullanici Bulunamadi! Menuye Donmek Icin y, Yeni Sorgu Icin n Yaziniz: ";
                                cin >> state;
                                if (state == "n") {
                                    system("cls");
                                    goto newQueryforCombine;
                                }
                            } else {
                                u = admin1->findUser(persons, tcNo);
                                cout << "- ONCEKI DURUM -" << endl;
                                cout << "1. Kart: " << u->getUserCard1Balance() << endl;
                                cout << "2. Kart: " << u->getUserCard2Balance() << endl;
                                cout << "\nBirlestirme isleminin yapilmasi icin bir tusa basiniz..." << endl;
                                system("pause");
                                admin1->combineUserCards(u);
                                cout << "\n- ISLEM BASARILI! YENI DURUM -" << endl;
                                cout << "1. Kart: " << u->getUserCard1Balance() << endl;
                                cout << "2. Kart: " << u->getUserCard2Balance() << endl;
                                cout << "\nMenuye Donmek Icin Bir Tusa Basiniz..." << endl;
                                system("pause");
                            }

                        } else if (choice == 6) {
                            newQueryforSet:
                            cout << "- BILGI DEGISIKLIGI YAPILACAK KULLANICI -" << endl;
                            cout << "Kisi TC: ";
                            cin >> tcNo;
                            User *u;
                            if (admin1->findUser(persons, tcNo) == nullptr) {
                                system("cls");
                                string state;
                                cout
                                        << "Girdiğiniz TC ye Ait Kullanici Bulunamadi! Menuye Donmek Icin y, Yeni Sorgu Icin n Yaziniz: ";
                                cin >> state;
                                if (state == "n") {
                                    system("cls");
                                    goto newQueryforSet;
                                }
                            } else {
                                u = admin1->findUser(persons, tcNo);
                                cout << "- ESKI BILGILER -" << endl;
                                admin1->showUserState(u);
                                cout << "\n- YENI BILGILER -" << endl;
                                char newName[20];
                                cout << "Ad: ";
                                cin >> newName;
                                char newSurname[20];
                                cout << "Soyadi: ";
                                cin >> newSurname;
                                u->setName(newName);
                                u->setSurname(newSurname);
                                system("cls");
                                cout << "Yeni Bilgiler Kayit Edildi! Menuye Donmek Icin Bir Tusa Basiniz..." << endl;
                                system("pause");
                            }

                        } else if (choice == 7) {
                            system("cls");
                            exitState = 0;
                        }
                    } while (exitState);
                    break;
                }
            }
            if(!itt){
                char yesNo;
                cout << "Giris Yetkisi Yok! Yeni TC Girmek Icin y, Ana Menuye Donmek Icin n Yaziniz  [y/n] :" << endl;
                cin>>yesNo;
                if(yesNo=='y'){
                    system("cls");
                    goto newQuaryForSign;
                }
            }
        }
        else if(choice==2) {
            bool itt = false;
            newQuaryForUserSign:
            system("cls");
            cout << "- IETT KULLANICI GIRISI -" << endl;
            int tcNo;
            cout << "TC:";
            cin >> tcNo;
            system("cls");
            for (int i = 0; i < admin1->getPersonNo(); ++i) {
                if (persons[i]->getTc() == tcNo && persons[i]->getPersonelType() == user) {
                    int exitState = 1;
                    itt = true;
                    do {
                    system("cls");
                    cout << "     - KULLANICI ISLEMLERI -" << endl;
                    cout << " 1 -  Bakiye Yukle" << endl;
                    cout << " 2 -  Kart Okut" << endl;
                    cout << " 3 -  Kart Durumu Goster" << endl;
                    cout << " 4 -  Ana Menuye Don" << endl;
                    cout << "\nYapilacak Islem Numarasini Giriniz: ";
                    cin >> choice;
                    system("cls");
                    if (choice == 1) {
                        system("cls");
                        int operate;
                        cout<<"Kart 1 Bakiye: "<<((User*)persons[i])->getUserCard1Balance()<<endl;
                        cout<<"Kart 2 Bakiye: "<<((User*)persons[i])->getUserCard2Balance()<<endl;
                        cout<<"Islem Yapilacak Karti Seciniz  [1/2]  :";
                        cin>>operate;
                        if(operate==1){
                            int cost;
                            system("cls");
                            cout<<"BAKIYE YUKLEME"<<endl;
                            cout<<"Kart 1 Icin Yuklenecek Tutari Giriniz: ";
                            cin>>cost;
                            ((User*)persons[i])->loadBalance(((User*)persons[i])->getCard1(),cost);
                            cout<<"\nYUKLEME BASARILI! YUKLEME SONRASI DURUM"<<endl;
                            cout<<"Kart 1 Bakiye: "<<((User*)persons[i])->getUserCard1Balance()<<endl;
                            cout<<"Kart 2 Bakiye: "<<((User*)persons[i])->getUserCard2Balance()<<endl;
                            cout<<"\nMenuye Donmek Icin Bir Tusa Basiniz..."<<endl;
                            system("pause");
                        }
                        else if(operate==2){
                            int cost;
                            system("cls");
                            cout<<"BAKIYE YUKLEME"<<endl;
                            cout<<"Kart 2 Icin Yuklenecek Tutari Giriniz: ";
                            cin>>cost;
                            ((User*)persons[i])->loadBalance(((User*)persons[i])->getCard2(),cost);
                            cout<<"\nYUKLEME BASARILI! YUKLEME SONRASI DURUM"<<endl;
                            cout<<"Kart 1 Bakiye: "<<((User*)persons[i])->getUserCard1Balance()<<endl;
                            cout<<"Kart 2 Bakiye: "<<((User*)persons[i])->getUserCard2Balance()<<endl;
                            cout<<"\nMenuye Donmek Icin Bir Tusa Basiniz..."<<endl;
                            system("pause");
                        }
                        else{
                            system("cls");
                            cout<<"Kart Numarasina Gore 1 Veya 2 Olarak Giris Yapmalisiniz! Ana Menuye Donmek Icin Bir Tusa Basiniz..."<<endl;
                            system("pause");
                        }
                    }
                    else if(choice==2){
                        system("cls");
                        int operate;
                        cout<<"Kart 1 Mevcut Bakiye: "<<((User*)persons[i])->showCardState(((User*)persons[i])->getCard1())<<endl;
                        cout<<"Kart 2 Mevcut "<<((User*)persons[i])->showCardState(((User*)persons[i])->getCard2())<<endl;
                        cout<<"Islem Yapilacak Karti Seciniz  [1/2]  :";
                        cin>>operate;
                        if(operate==1){
                            system("cls");
                            cout<<"Kart 1 Onceki Bakiye: "<<((User*)persons[i])->showCardState(((User*)persons[i])->getCard1())<<endl;
                            cout<<"BASARIYLA OKUTULDU!"<<endl;
                            ((User*)persons[i])->readCard(((User*)persons[i])->getCard1());
                            cout<<"\nAna Menuye Donmek Icin Bir Tusa Basiniz..."<<endl;
                            system("pause");
                        }
                        else if(operate==2){
                            system("cls");
                            cout<<"Kart 2 Mevcut "<<((User*)persons[i])->showCardState(((User*)persons[i])->getCard2())<<endl;
                            cout<<"BASARIYLA OKUTULDU!"<<endl;
                            ((User*)persons[i])->readCard(((User*)persons[i])->getCard2());
                            cout<<"\nAna Menuye Donmek Icin Bir Tusa Basiniz..."<<endl;
                            system("pause");
                        }
                        else{
                            cout<<"\nKart Numarasina Gore 1 Veya 2 Olarak Giris Yapmalisiniz! Ana Menuye Donmek Icin Bir Tusa Basiniz..."<<endl;
                            system("pause");
                        }
                    }
                    else if(choice==3){
                        cout<<"Kart 1 : "<<((User*)persons[i])->showCardState(((User*)persons[i])->getCard1())<<endl;
                        cout<<"Kart 2 : "<<((User*)persons[i])->showCardState(((User*)persons[i])->getCard2())<<endl;
                        cout<<"\nMenuye Donmek Icin Bir Tusa Basiniz..."<<endl;
                        system("pause");
                    }
                    else if(choice==4){
                        system("cls");
                        exitState=0;
                    }
                    }while(exitState);
                    break;
                }
            }
            if(!itt){
                char yesNo;
                cout << "Girilen TC Kullanici Tipinde Degil Veya Sistemde Kayitli Degil! Yeni TC Girmek Icin y, Ana Menuye Donmek Icin n Yaziniz  [y/n] :" << endl;
                cin>>yesNo;
                if(yesNo=='y'){
                    system("cls");
                    goto newQuaryForUserSign;
                }
            }
        }
        else if(choice==3){
            system("cls");
            exitState2=0;
        }
    }while(exitState2);

    return 0;
}
