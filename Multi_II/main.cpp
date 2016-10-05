#include <iostream>
#include "list_parent.h"
#include "list_child.h"

using namespace std;

int main()
{
    cout << "Bentuk II - Contoh Relasi 1-N dan M-N" << endl;

    List_parent LP;
    address_parent P;
    address_child C;

    createList(LP);

    /** insert parent */
    P = alokasi(3);
    insertFirst(LP, P);
    P = alokasi(7);
    insertFirst(LP, P);
    P = alokasi(2);
    insertFirst(LP, P);
    P = alokasi(4);
    insertFirst(LP, P);

    cout<<"list parent"<<endl;
    printInfo(LP);

    /** insert child */
    P = findElm(LP, 7);
    C = alokasi("X");
    insertFirst(child(P),C);
    C = alokasi("Q");
    insertFirst(child(P),C);

    P = findElm(LP, 4);
    C = alokasi("A");
    insertFirst(child(P),C);

    P = findElm(LP, 2);
    C = alokasi("A");
    insertFirst(child(P),C);


    P = findElm(LP, 7);
    C = findElm(child(P),"Q");
    address_child R = alokasi("O");
    insertAfter(C, R);

    cout<<"\n";
    cout<<"list parent setelah diisi child"<<endl;
    printInfo(LP);

    return 0;
}
