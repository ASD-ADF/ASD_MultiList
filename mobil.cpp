#include <iostream>
#include "mobil.h"
#include <windows.h>

using namespace std;


adr_pelanggan alokasi_pelanggan (infotype_pelanggan x) //alokasi parent / entitas 1
{
    adr_pelanggan Q;
    Q = new elm_pelanggan;
    info(Q) = x;
    next(Q) = NULL;
    prev(Q) = NULL;
    first_history(Q) = NULL;
    last_history(Q) = NULL;
    return Q;
}

adr_car alokasi_car (infotype_car x) //alokasi entitas 2
{
    adr_car Q;
    Q = new elm_car;
    info(Q) = x;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}

adr_history alokasi_history (infotype_history x) //alokasi child
{
    adr_history Q;
    Q = new elm_history;
    info(Q) = x;
    next(Q) = NULL;
    car(Q) = NULL;
    return Q;
}

adr_terbanyak1 alokasi_terbanyak1 (infotype_terbanyak1 x) //alokasi list report
{
    adr_terbanyak1 Q;
    Q = new elm_terbanyak1;
    info(Q) = x;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}

//adr_terbanyak2 alokasi_terbanyak2 (int x)
//{
//    adr_terbanyak2 Q;
//    Q = new elm_terbanyak2;
//    info(Q) = x;
//    next(Q) = NULL;
//    prev(Q) = NULL;
//    return Q;
//}

bool isEmpty_pelanggan (list_pelanggan L) //cek list pelanggan
{
    if ((first(L) == NULL) && (last(L) == NULL) )
        return true;
    else
        return false;
}

bool isEmpty_car (list_car L) //cek list mobil
{
    if ((first(L) == NULL) && (last(L) == NULL) )
        return true;
    else
        return false;
}

bool isInteger(int x) //validasi integer
{
    if ( !cin )
    {
        cin.clear();
        cin.ignore();
        return false;
    }
    else
    return true;
}

void menu ()
{
    cout << endl;
    cout << "================================Tenant Car================================" << endl;
    cout << "Menu:" <<endl;
    cout << "1. Insert Customer Data" << endl; //V
    cout << "2. Insert Car Data" << endl; //V
    cout << "3. Insert Tenant Data" << endl; //V
    cout << "4. Delete Customer Data" << endl; //V
    cout << "5. Delete Car Data" << endl; //V
    cout << "6. Delete Tenant Data" << endl; //V
    cout << "7. Update Customer Data" << endl; //V
    cout << "8. View Customer Data" << endl; //V
    cout << "9. View Car Data" << endl; //V
    cout << "10. Find Customer Data" << endl; //V
    cout << "11. Report " << endl; //V
    cout << "12. View Car that used by customer" << endl; //V
    cout << "13. View Customer that have rented car" << endl; //V
    cout << "0. Finish" << endl;
    cout << endl;
}

void createList_pelanggan (list_pelanggan &L) //buat list pelanggan
{
    first(L) = NULL;
    last(L) = NULL;
}

void createList_car (list_car &L) //buat list mobil
{
    first(L) = NULL;
    last(L) = NULL;
}

void createList_terbanyak1 (list_terbanyak1 &L) //buat list report
{
    first(L) = NULL;
    last(L) = NULL;
}

//void createList_terbanyak2 (list_terbanyak2 &L)
//{
//    first(L) = NULL;
//    last(L) = NULL;
//\}

void insert_pelanggan (list_pelanggan &L, adr_pelanggan Q) //insert pelanggan (insert teruurut ascending)
{
    adr_pelanggan P;
    P = first(L);
    if ( !isEmpty_pelanggan(L) )
    {
        if ( info(P).id_pelanggan > info(Q).id_pelanggan )
        {
            next(Q) = P;
            prev(P) = Q;
            first(L) = Q;
        }

        else if ( info(P).id_pelanggan < info(Q).id_pelanggan )
        {
            if ( next(P) == NULL )
            {
                next(P) = Q;
                prev(Q) = P;
                next(Q) = NULL;
                last(L) = Q;
            }

            else
            {
                while ( (next(P) != NULL) && (info(P).id_pelanggan < info(Q).id_pelanggan) )
                {
                    P = next(P);
                }
                    if ( (next(P) == NULL) && (info(P).id_pelanggan < info(Q).id_pelanggan) )
                    {
                        next(P) = Q;
                        prev(Q) = P;
                        last(L) = Q;
                    }

                    else if ( info(P).id_pelanggan == info(Q).id_pelanggan )
                    {
                        cout << "The ID is Exist";
                    }

                    else
                    {
                        prev(Q) = prev(P);
                        next(prev(P)) = Q;
                        prev(P) = Q;
                        next(Q) = P;
                    }
            }
        }

        else
        {
            cout << "The ID and Data is already used";
        }
    }

    else
    {
        next(Q) = NULL;
        prev(Q) = NULL;
        first(L) = Q;
        last(L) = Q;
    }
}

void insert_car (list_car &L, adr_car Q) //insert mobil (insert first)
{
    adr_car P;
    P = first(L);

    if (!isEmpty_car(L))
    {
        next(Q) = P;
        prev(P) = Q;
        first(L) = Q;
    }

    else
    {
        first(L) = Q;
        last(L) = Q;
    }
}

void insert_history (list_pelanggan &L, list_car L2, infotype_history x, int id_car, int id) //insert history (insert last)
{
    adr_pelanggan P;
    P = first(L);
    adr_car R;
    R = first(L2);
    adr_history Q;
    Q = alokasi_history(x);
    bool found;
    found = false;

    while ( P != NULL )
    {
        if ( info(P).id_pelanggan == id )
        {
            while ( ( info(R).id_car != id_car ) && ( next(R) != NULL ) )
            {
                R = next(R);
            }
            if ( info(R).id_car == id_car )
            {
                car(Q) = R;
            }
            if ( first_history(P) == NULL )
            {
                first_history(P) = Q;
                last_history(P) = Q;
            }
            else
            {
                next(last_history(P)) = Q;
                last_history(P) = Q;
            }
            found = true;
        }
        P = next(P);
    }
    if ( ( found == false ) && ( next(P) == NULL ) )
    {
        cout << "Customer Data Not Found";
    }
}

void delete_pelanggan (list_pelanggan &L, int id)
{
    adr_pelanggan P,Q,R;
    P = first(L);

    if ( !isEmpty_pelanggan(L) )
    {
        while ( ( info(P).id_pelanggan != id ) && ( next(P) != NULL ) )
        {
            P = next(P);
        }
        if ( info(P).id_pelanggan == id )
        {
            if ( ( prev(P) != NULL ) && ( next(P) != NULL ) )
            {
                Q = prev(P); R = next(P);
                next(Q) = R;
                prev(R) = Q;
                next(P) = NULL;
                prev(P) = NULL;
            }
            else if ( ( prev(P) == NULL ) && ( next(P) == NULL ) )
            {
                first(L) = NULL;
                last(L) = NULL;
            }
            else if ( prev(P) == NULL )
            {
                first(L) = next(P);
                prev(next(P)) = NULL;
                next(P) = NULL;
            }
            else if ( next(P) == NULL )
            {
                last(L) = prev(P);
                next(prev(P)) = NULL;
                prev(P) = NULL;
            }
            cout << endl;
            cout << "Delete Process is Done";
        }
        else
        {
            cout << endl;
            cout << "The data is empty or already deleted";
        }
    }
    else
    {
        cout << endl;
        cout << "Empty List";
    }
}

void delete_car (list_car &L, int id)
{
    adr_car P,Q,R;
    P = first(L);

    if ( !isEmpty_car(L) )
    {
        while ( ( info(P).id_car != id ) && ( next(P) != NULL ) )
        {
            P = next(P);
        }
        if ( info(P).id_car == id )
        {
            if ( ( prev(P) != NULL ) && ( next(P) != NULL ) )
            {
                Q = prev(P); R = next(P);
                next(Q) = R;
                prev(R) = Q;
                next(P) = NULL;
                prev(P) = NULL;
            }
            else if ( ( prev(P) == NULL ) && ( next(P) == NULL ) )
            {
                first(L) = NULL;
                last(L) = NULL;
            }
            else if ( prev(P) == NULL )
            {
                first(L) = next(P);
                prev(next(P)) = NULL;
                next(P) = NULL;
            }
            else if ( next(P) == NULL )
            {
                last(L) = prev(P);
                next(prev(P)) = NULL;
                prev(P) = NULL;
            }
            cout << endl;
            cout << "Delete Process is Done";
        }
        else
        {
            cout << endl;
            cout << "The data is empty or already deleted";
        }
    }
    else
    {
        cout << endl;
        cout << "Empty List";
    }
}

void delete_history (list_pelanggan &L, int id, int id_history)
{
    adr_pelanggan P;
    P = first(L);
    adr_history Q,R;

    if ( !isEmpty_pelanggan(L) )
    {
        while ( ( info(P).id_pelanggan != id ) && ( next(P) != NULL ) )
        {
            P = next(P);
        }
        if ( info(P).id_pelanggan == id )
        {
            if ( first_history(P) != NULL )
            {
                Q = first_history(P);
                while ( ( info(Q).id_history != id_history ) && ( next(Q) != NULL ) )
                {
                    R = Q;
                    Q = next(Q);
                }
                if ( info(Q).id_history == id_history )
                {
                    if ( first_history(P) == Q )
                    {
                        first_history(P) = next(Q);
                        next(Q) = NULL;
                    }
                    else if ( next(Q) == NULL )
                    {
                        last_history(P) = R;
                    }
                    else
                    {
                        next(R) = next(Q);
                        next(Q) = NULL;
                    }
                }
                cout << endl;
                cout << "Delete Process is Done";
            }
            else
            {
                cout << endl;
                cout << "Tenant data is Empty";
            }
        }
        else
        {
            cout << endl;
            cout << "Customer Data NOT FOUND";
        }
    }
    else
    {
        cout << endl;
        cout << "Empty List";
    }
}

void update (list_pelanggan &L, adr_pelanggan Q)
{
    adr_pelanggan P;
    P = first(L);

    if ( !isEmpty_pelanggan(L) )
    {
        while ( ( info(P).id_pelanggan != info(Q).id_pelanggan ) && ( P != NULL ) )
        {
            P = next(P);
        }
        if ( info(P).id_pelanggan == info(Q).id_pelanggan )
        {
            info(P) = info(Q);
        }
        else
        {
            cout << "Data NOT FOUND";
        }
    }
    else
    {
        cout << "Empty List";
    }
}


void view_pelanggan (list_pelanggan L)
{
    adr_pelanggan P;
    P = first(L);
    if ( P != NULL )
    {
        cout << "==Customer data that already inputed==";
        cout << endl;
        cout << endl;
        while ( next(P) != NULL )
        {
            cout << "Name   :";
            cout << info(P).nama; cout << endl;
            cout << "ID     :";
            cout << info(P).id_pelanggan; cout << endl;
            cout << "No. Hp :";
            cout << info(P).hp; cout << endl;
            cout << endl;
            P = next(P);
        }
        cout << "Name   :";
        cout << info(P).nama; cout << endl;
        cout << "ID     :";
        cout << info(P).id_pelanggan; cout << endl;
        cout << "No. Hp :";
        cout << info(P).hp; cout << endl;
        cout << endl;
    }
    else
    {
        cout << "Empty List";
    }
}

void view_car (list_car L)
{
    adr_car P;
    P = first(L);
    infotype_car x;

    if ( !isEmpty_car(L) )
    {
        cout << "==Car Data that already inputed==";
        cout << endl;
        cout << endl;
        while ( next(P) != NULL )
        {
            cout << "The Brand of The Car    : ";
            cout << info(P).merek; cout << endl;
            cout << "Production Year         : ";
            cout << info(P).tahun; cout << endl;
            cout << "Car ID                  : ";
            cout << info(P).id_car; cout << endl;
            cout << endl;
            P = next(P);
        }
        cout << "The Brand of The Car    : ";
        cout << info(P).merek; cout << endl;
        cout << "Production Year         : ";
        cout << info(P).tahun; cout << endl;
        cout << "Car ID                  : ";
        cout << info(P).id_car; cout << endl;
        cout << endl;
    }
    else
    {
        cout << "Empty List";
    }
}

void view_mobilpelanggan (list_pelanggan L)
{//clear
    adr_pelanggan P;
    adr_history Q;
    adr_car R;
    P = first(L);

    if ( !isEmpty_pelanggan(L) )
    {
        cout << "==Data pelanggan dan mobil yang di sewa==";
        cout << endl; cout << endl;
        while ( P != NULL )
        {
            if ( first_history(P) != NULL )
            {
                cout << endl;
                cout << "Customer Data : " << endl;
                cout << "Name : "; cout << info(P).nama << endl;
                cout << "ID   : "; cout << info(P).id_pelanggan << endl;
                cout << "No.Hp: "; cout << info(P).hp << endl;
                cout << endl;
                cout << "The car that rented : " << endl; cout << endl;
                Q = first_history(P);

                while ( Q != NULL )
                {
                    R = car(Q);
                    cout << "Brand    : "; cout << info(R).merek << endl;
                    cout << "Car ID : "; cout << info(R).id_car << endl;
                    cout << endl;
                    Q = next(Q);

                }
            }
            else
            {
                cout << endl;
                cout << "Customer Data : " << endl;
                cout << "Name : "; cout << info(P).nama << endl;
                cout << "ID   : "; cout << info(P).id_pelanggan << endl;
                cout << "No.Hp: "; cout << info(P).hp << endl;
                cout << endl;
                cout << "The rented car that not returned yet : ";
                cout << endl; cout << endl;
            }
            cout << "========================================";
            cout << endl; cout << endl;
            P = next(P);
        }
    }
    else
    {
        cout << "Customer List is Empty";
        cout << endl;
    }
}

void view_pelangganmobil (list_pelanggan L, list_car L2)
{
    adr_pelanggan P;
    adr_car Q,S;
    adr_history R,T;
    Q = first(L2);
    infotype_history x;
    infotype_pelanggan y;

    while ( Q != NULL )
        {
            cout << "==Car Data=="; cout << endl;
            cout << "The Brand of The Car      : "; cout << info(Q).merek; cout << endl;
            cout << "Production Year           : "; cout << info(Q).tahun; cout << endl;
            cout << "Car ID                    : "; cout << info(Q).id_car; cout << endl;
            cout << endl;
            cout << "This Car is Rented by : "<<endl;
            P = first(L);
            while ( P != NULL )
            {
                int idx = 0, z = 0;
                string tmp[20];
                R = first_history(P);

                if ( R != NULL )
                {
                    do
                    {
                        T = R;
                        S = car(T);
                        if ( info(S).id_car == info(Q).id_car )
                        {
                            tmp[idx] = info(P).nama;
                            idx = idx+1;
                        }

                        if (next(R) != NULL) {
                            R = next(R);
                        }
                    } while ( next(R) != NULL );

                        while ( z < idx )
                        {
                            cout << " : ";
                            cout << tmp[z];
                            cout << endl;
                            z = z+1;
                        }
                }
                else
                {
                    cout << "Not Rented yet";
                    cout << endl;
                }
                P = next(P);
            }
            Q = next(Q);
        }

}

void cari (list_pelanggan L, int x)
{
    adr_pelanggan P;
    P = first(L);

    if ( !isEmpty_pelanggan(L) )
    {
        while ( ( info(P).id_pelanggan != x ) && ( next(P) != NULL ) )
        {
            P = next(P);
        }
        cout << "Find Result : ";
        if ( info(P).id_pelanggan == x )
        {
            cout << "Data is FOUND" << endl; cout << endl;
            cout << "Name   : ";
            cout << info(P).nama << endl;
            cout << "ID     : ";
            cout << info(P).id_pelanggan << endl;
            cout << "No. Hp : ";
            cout << info(P).hp << endl;
        }
        else
        {
            cout << "The Data NOT FOUND" << endl; cout << endl;
        }
    }
    else
    {
        cout << "Empty List" << endl;
    }
}

void report (list_pelanggan L, list_terbanyak1 &L2)
{
    int mx,tmp,tmp2;
    infotype_terbanyak1 x;
    adr_pelanggan P,R;
    adr_history Q;
    adr_terbanyak1 S,T;
    P = first(L);
    T = first(L2);
    mx,tmp2 = 0;
    tmp = 1;

    if ( !isEmpty_pelanggan(L))
    {
        while ( P != NULL )
        {
            if ( first_history(P) != NULL )
            {
                Q = first_history(P);
                while ( next(Q) != NULL)
                {
                    Q = next(Q);
                    tmp = tmp+1;
                }
                S = alokasi_terbanyak1(x);
                info(S).jumlah = tmp;
                info(S).id_pelanggan = info(P).id_pelanggan;
                info(S).nama = info(P).nama;

                if ( first(L2) == NULL )
                {
                    first(L2) = S;
                    last(L2) = S;
                }
                else
                {
                    T = first(L2);
                    if ( info(T).jumlah < info(S).jumlah )
                    {
                        prev(T) = S;
                        next(S) = T;
                        first(L2) = S;
                    }
                    else if ( info(T).jumlah == info(S).jumlah )
                    {
                        prev(T) = S;
                        next(S) = T;
                        first(L2) = S;
                        tmp2 = tmp2+1;
                    }
                    else
                    {
                        T = last(L2);
                        prev(S) = T;
                        next(T) = S;
                    }
                }
            }
            else
            {
                cout << "no car tenant yet" << endl;
            }
            P = next(P);
        }
        T = first(L2);
        if ( tmp2 != 0 )
        {
            int i; i = 1;
            while ( i <= tmp2 )
            {
                cout << "Customer ID               : ";
                cout << info(T).id_pelanggan << endl;
                cout << "Name                      : ";
                cout << info(T).nama << endl;
                cout << "The total of car that rented : ";
                cout << info(T).jumlah << endl;
                cout << endl;
                i = i+1;
                T = next(T);
            }
        }
        else
        {
            cout << "Customer ID              : ";
            cout << info(T).id_pelanggan << endl;
            cout << "Name                      : ";
            cout << info(T).nama << endl;
            cout << "The total of car that rented : ";
            cout << info(T).jumlah << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "Empty List"; cout << endl;
    }
}
