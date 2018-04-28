#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

int main()
{
    List_child LC;
    List_parent LP;
    List_relasi LR;

    int i;

    infotype_child xc;
    infotype_parent xp;

    createList(LC);
    createList(LP);
    createList(LR);

    cout<<"       Final Task ASD 2018               \n";
    cout<<" Aditya Ramadhan Moesya - 1301160471     \n";
    cout<<" Muhamad Rikbal Ikhsani - 1301163598     \n";

    menu:
    cout<<"===============Library Organizer==============   \n";
    cout<<"==============================================   \n";
    cout<<"         1. Add new Book                         \n";
    cout<<"         2. Add new Member                       \n";
    cout<<"         3. Add book to cart of a member         \n";
    cout<<"         4. Delete book from cart                \n";
    cout<<"         5. Delete Book                          \n";
    cout<<"         6. Delete Member                        \n";
    cout<<"         7. Show all Book                        \n";
    cout<<"         8. Show all Member                      \n";
    cout<<"         9. Show all Member with Borrowed Book   \n";
    cout<<"         0. Exit                                 \n";
    cout<<"-----------------------------------------------  \n";
    cout<<endl;
    cout<<"         INPUT : ";cin>>i;

    switch(i){
            case 1:{
                system("cls");
                cout<<"<====Input Book=====> \n";
                cout<<"===================== \n";
                address_parent P = NULL;
                cout<<"Input Book ID            : ";cin>>xp.idb;
                P = findElm(LP,xp);
                if(P==NULL){
                    cout<<"Input Book Name          : ";cin>>xp.name;
                    cout<<"input Book Genre         : ";cin>>xp.genre;
                    P = alokasi(xp);
                    insertLast(LP,P);
                    cout<<"Done! \n";
                }else{
                    cout<<"Book ID is already exist!";
                }
                getch();
                system("cls");
                goto menu;
            }

            case 2:{
                system("cls");
                cout<<"<====Input Member===> \n";
                cout<<"===================== \n";
                address_child Q = NULL;
                cout<<"Input Member ID            : ";cin>>xc.id;
                Q = findElm(LC,xc);
                if(Q==NULL){
                    cout<<"Input Member Name          : ";cin>>xc.name;
                    Q = alokasi(xc);
                    insertFirst(LC,Q);
                    cout<<"Done! \n";
                }else{
                    cout<<"Member ID is already exist!";
                }
                getch();
                system("cls");
                goto menu;
            }

            case 3:{
                system("cls");
                connectList(LR,LP,LC);
                getch();
                system("cls");
                goto menu;

            }

            case 4:{

            }

            case 5:{

            }

            case 6:{

            }

            case 7:{
                system("cls");
                cout<<"<=====Book List=====> \n";
                cout<<"===================== \n";
                cout<<endl;
                printInfo(LP);
                getch();
                system("cls");
                goto menu;
            }

            case 8:{
                system("cls");
                cout<<"<=====Member List=====> \n";
                cout<<"======================= \n";
                cout<<endl;
                printInfo(LC);
                getch();
                system("cls");
                goto menu;
            }

            case 9:{
                system("cls");
                cout<<"<========List=========> \n";
                cout<<"======================= \n";
                cout<<endl;
                printInfo(LR);
                getch();
                system("cls");
                goto menu;
            }


    }


    return 0;
}
