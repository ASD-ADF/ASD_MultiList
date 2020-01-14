#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"

#include <iostream>

using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child info;
};

struct List_relasi{
    address_relasi first;
};

/** TIDAK PERLU MODIFIKASI */
void createList_R(List_relasi &L);
void insertFirst_R(List_relasi &L, address_relasi P);
void insertLast_R(List_relasi &L, address_relasi P);
void insertAfter_R(List_relasi &L, address_relasi Prec, address_relasi P);
void deleteFirst_R(List_relasi &L, address_relasi &P);
void deleteLast_R(List_relasi &L, address_relasi &P);
void deleteAfter_R(List_relasi &L, address_relasi Prec, address_relasi &P);


/** PERLU MODIFIKASI */
address_relasi alokasi_R( address_child C);
void dealokasi_R(address_relasi &P);
address_relasi findElm_R(List_relasi L, address_child C);
void printInfo_R(List_relasi L);


#endif // LIST_RELASI_H_INCLUDED
