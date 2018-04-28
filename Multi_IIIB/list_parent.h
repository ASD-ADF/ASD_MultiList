#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#include "list_relasi.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child

struct artist{
    int id;
    string name;
    string genre;
};

typedef artist infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    List_relasi child;
    address_parent next;

};

struct List_parent {
    address_parent first;
};

/** TIDAK PERLU MODIFIKASI */
void createList_P(List_parent &L);
void insertFirst_P(List_parent &L, address_parent P);
void insertAfter_P(List_parent &L, address_parent Prec, address_parent P);
void insertLast_P(List_parent &L, address_parent P);
void deleteFirst_P(List_parent &L, address_parent &P);
void deleteLast_P(List_parent &L, address_parent &P);
void deleteAfter_P(List_parent &L, address_parent Prec, address_parent &P);
address_parent findElm_P(List_parent L, infotype_parent x);


/** PERLU MODIFIKASI */
address_parent alokasi_P(infotype_parent x);
void dealokasi_P(address_parent &P);
address_parent findElm_P(List_parent L, infotype_parent x);
void printInfo_P(List_parent L);

address_parent findElmName_P(List_parent L, infotype_parent x);

#endif // LIST_PARENT_H_INCLUDED
