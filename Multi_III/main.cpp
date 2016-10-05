#include <iostream>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main()
{
    cout << "Bentuk III - Contoh Relasi M-N" << endl;

    List_parent LP;
    List_child LC;
    address_child C;
    address_parent P;
    address_relasi R;

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

    /** RELASIKAN PARENT DENGAN CHILD **/
    P = findElm(LP, 4);
    C = findElm(LC, "E");
    R = alokasi(C);
    insertFirst(child(P),R );
    C = findElm(LC, "D");
    R = alokasi(C);
    insertFirst(child(P),R );


    P = findElm(LP, 2);
    C = findElm(LC, "E");
    R = alokasi(C);
    insertFirst(child(P),R );

    P = findElm(LP, 3);
    C = findElm(LC, "A");
    R = alokasi(C);
    insertFirst(child(P),R );

    cout<<endl<<"Setelah Direlasikan"<<endl;
    cout<<"list parent"<<endl;
    printInfo(LP);

    cout<<endl<<"list child"<<endl;
    printInfo(LC);


    /** KELEBIHAN DARI BENTUK III: jika salah satu child diedit **/
    C = findElm(LC, "E");
    info(C) = "X";

    cout<<endl<<"Setelah Child Diedit"<<endl;
    cout<<"list parent"<<endl;
    printInfo(LP);

    cout<<endl<<"list child"<<endl;
    printInfo(LC);

    return 0;
}
