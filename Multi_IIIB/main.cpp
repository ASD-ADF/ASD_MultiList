#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<windows.h>

using namespace std;

#include "list_child.h"
#include "list_parent.h"
#include "operation.h"

int main(){
    List_child LC;
    List_parent LP;
    int i;

    createList_P(LP);
    createList_C(LC);

    cout<<"       Final Task ASD 2018        \n";
    cout<<" Muhamad Fajar Rivaldy (1301164476) \n";
    cout<<" Muhamad Rizky Anugrah Sakti (1301164489) \n";

    menu:
    cout<<"             MENU                   \n";
    cout<<"=================================== \n";
    cout<<"         1. add new Artist   \n";
    cout<<"         2. add new Song     \n";
    cout<<"         3. add Song to Artist \n";
    cout<<"         4. delete Song from Artis \n";
    cout<<"         5. delete Artis  \n";
    cout<<"         5. show all Artist \n";
    cout<<"         6. show all Song    \n";
    cout<<"         7. show all Artist and Song  \n";
    cout<<"         8. Check connection  \n ";
    cout<<"         9. Disconnect connection  \n ";
    cout<<"        10. Play Artis \n";
    cout<<"        11. show child of parent \n";
    cout<<"        12. Play Music  \n";
    cout<<"------------------------------------ \n";
    getch();
    cout<<"     INPUT : ";cin>>i;
        switch(i){
            case 1:{
                system("cls");
                insertParent(LP);
                getch();
                system("cls");
                goto menu;
            }
            case 2:{
                system("cls");
                insertChild(LC);
                getch();
                system("cls");
                goto menu;
            }
            case 3:{
                system("cls");
                connectList(LP,LC);
                getch();
                system("cls");
                goto menu;
            }
            case 4:{
                system("cls");
                deleteChild(LP,LC);
                getch();
                system("cls");
                goto menu;
            }
            case 5:{
                system("cls");
                DisplayParent(LP);
                getch();
                system("cls");
                goto menu;
            }
            case 6:{
                system("cls");
                displayChild(LC);
                getch();
                system("cls");
                goto menu;
            }
            case 7:{
                system("cls");
                printALL(LP);
                getch();
                system("cls");
                goto menu;
            }
            case 8:{
                system("cls");
                checkConnection(LP,LC);
                getch();
                system("cls");
                goto menu;
            }
            case 9:{
                system("cls");
                disconnect(LP,LC);
                getch();
                system("cls");
                goto menu;
            }
            case 10:{
                system("cls");
                PlayArtist(LP);
                getch();
                system("cls");
                goto menu;
            }
            case 11:{
                system("cls");
                printChildOfParent(LP);
                getch();
                system("cls");
                goto menu;
            }
            case 12:{
                system("cls");
                MusicById(LC);
                getch();
                system("cls");
                goto menu;
            }
            default :{
                system("cls");
                goto menu;
            }
        }

}
