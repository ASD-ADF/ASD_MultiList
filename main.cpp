#include <iostream>
#include "mobil.h"
#include <windows.h>
using namespace std;

int main()
{
    int a,c;
    list_pelanggan L1;
    list_car L2;
    list_terbanyak1 L3;
    createList_pelanggan(L1);
    createList_car(L2);
    createList_terbanyak1(L3);
    menu();
    cout << "Choose : "; cin >> c;
    while ( !isInteger(c) )
    {
                cout << "Wrong Format, Fill Again : "; cin >> c;
    }
    a = c;

    do
    {
        if ( a == 1 )
        {
            system("cls");
            infotype_pelanggan x;
            adr_pelanggan P;
            cout << "==Input Customer ID==" << endl;
            cout << "Customer ID : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : ";
                cin >> c;
            }
            x.id_pelanggan = c;
            cout << "Nam3         : ";
            cin >> x.nama;
            cout << "No. Hp       : ";
            cin >> x.hp;
            cout << endl;
            P = alokasi_pelanggan(x);
            insert_pelanggan(L1,P);
            system("cls");
            cout << "Customer Data with Name : ";
            cout << info(P).nama;
            cout << "Input data Success";
            cout << endl;
            menu();
            cout << "Choose Menu : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : ";
                cin >> c;
            }
            a = c;
        }
        else if ( a == 2 )
        {
            system("cls");
            infotype_car x;
            adr_car P;
            cout << "==Input Car Data==" << endl;
            cout << "Car ID       : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            x.id_car = c;
            cout << "Car Brand   : ";
            cin >> x.merek;
            cout << "Production Year : ";
            cin >> x.tahun;
            P = alokasi_car(x);
            insert_car(L2,P);
            system("cls");
            cout << "Car data with Brand";
            cout << x.merek;
            cout << "Success to be Inputed";
            cout << endl;
            menu();
            cout << "Choose menu : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 3 )
        {
            system("cls");
            infotype_history x;
            int id_car, z;
            cout << "==Input Tenant Data==" << endl;
            cout << "Tenant ID     : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            z = c;
            cout << "Tenant ID        : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            x.id_history = c;
            cout << "Car ID       : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            id_car = c;
            cout << "Rent Date   : "; cin >> x.date;
            cout << "how long tenant will rent the car : "; cin >> x.lama;
            insert_history(L1,L2,x,id_car,z);
            system("cls");
            cout << "Tenants Data with Tenant ID : "; cout << x.id_history; cout << " Success to be Inputed";
            cout << endl;
            menu();
            cout << "Choose menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 4 )
        {
            system("cls");
            int id;
            cout << "==Delete Customer Data==" << endl;
            cout << "Input ID that will be deleted : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            id = c;
            delete_pelanggan(L1,id);
            cout << endl;
            menu();
            cout << "Choose menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 5 )
        {
            system("cls");
            int id;
            cout << "==Delete Car Data==" << endl;
            cout << "Input Car ID that will be deleted : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            id = c;
            delete_car(L2,id);
            cout << endl;
            menu();
            cout << "Choose menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 6 )
        {
            system("cls");
            int id, id_history;
            cout << "==Delete Tenant Data==" << endl;
            cout << "Input Tenant ID that will be deleted      : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            id = c;
            cout << "Input History ID that will be deleted :"; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            id_history = c;
            delete_history(L1,id,id_history);
            cout << endl;
            menu();
            cout << "Choose menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 7 )
        {
            system("cls");
            infotype_pelanggan x; adr_pelanggan Q;
            cout << "==Update Customer Data==" << endl;
            cout << "Customer ID : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            x.id_pelanggan = c;
            cout << "=Input New Data=" << endl;
            cout << "Name   : "; cin >> x.nama;
            cout << "No. Hp : "; cin >> x.hp;
            Q = alokasi_pelanggan(x);
            update(L1,Q);
            system("cls");
            cout << "Update Process Finished";
            cout << endl;
            menu();
            cout << "Choose Menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 8 )
        {
            system("cls");
            view_pelanggan(L1);
            menu();
            cout << "Choose Menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 9 )
        {
            system("cls");
            view_car(L2);
            menu();
            cout << "Choose Menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 10 )
        {
            system("cls");
            cout << "==Find Customer Data=="; cout << endl;
            int x; cout << "Input ID : ";
            cin >> x;
            cout << endl;
            cari(L1,x);
            cout << endl;
            cout << "Find Process Finished"; cout << endl;
            menu();
            cout << "Choose Menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 11 )
        {
            system("cls");
            cout << "==Customer that often rent car==" << endl;
            cout << endl;
            report(L1,L3);
            menu();
            cout << "Choose Menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 12 )
        {
            system("cls");
            view_mobilpelanggan(L1);
            menu();
            cout << endl;
            cout << "Choose Menu : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else if ( a == 13 )
        {
            system("cls");
            view_pelangganmobil(L1,L2);
            menu();
            cout << endl;
            cout << "Choose Menu  : "; cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
        else
        {
            cout << "Menu Input is False, Input Again : ";
            cin >> c;
            while ( !isInteger(c) )
            {
                cout << "Wrong Format, Fill Again : "; cin >> c;
            }
            a = c;
        }
    }
    while ( a != 0);
}
