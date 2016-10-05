#include <iostream>
using namespace std;

#include "list_child.h"

void connect(address_parent P, address_child &C);
void disconnect(address_child &C);

int main() {
    cout << "Bentuk I - Contoh Relasi 1-N" << endl;

    List_parent LP;
    List_child LC;
    address_child C;
    address_parent P;

    createList(LP);
    createList(LC);

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
    C = alokasi("A");
    insertFirst(LC, C);
    C = alokasi("D");
    insertFirst(LC, C);
    C = alokasi("E");
    insertFirst(LC, C);
    C = alokasi("O");
    insertFirst(LC, C);

    cout<<"list child"<<endl;
    printInfo(LC);

    /** RELASIKAN CHILD DENGAN PARENT */
    P = findElm(LP,2);
    C = findElm(LC, "D");
    connect(P,C);
    C = findElm(LC, "O");
    connect(P,C);

    P = findElm(LP,3);
    C = findElm(LC, "E");
    connect(P,C);

    P = findElm(LP,7);
    C = findElm(LC, "A");
    connect(P,C);

    cout<<"list child setelah direlasikan"<<endl;
    printInfo(LC);

    return 0;
}

void connect(address_parent P, address_child &C) {
    parent(C) = P;
}

void disconnect(address_child &C) {
    parent(C) = NULL;
}
