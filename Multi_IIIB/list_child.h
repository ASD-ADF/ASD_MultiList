#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED


#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct song{
    int id_song;
    string name_song;
    string name_loc;
};

typedef song infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child{
    address_child first;
    address_child last;
};

/** TIDAK PERLU MODIFIKASI */
void createList_C(List_child &L);
void insertFirst_C(List_child &L, address_child P);
void insertLast_C(List_child &L, address_child P);
void insertAfter_C(List_child &L, address_child &Prec, address_child P);
void deleteFirst_C(List_child &L, address_child &P);
void deleteLast_C(List_child &L, address_child &P);
void deleteAfter_C(List_child &L, address_child Prec, address_child &P);


/** PERLU MODIFIKASI */
address_child alokasi_C(infotype_child x);
void dealokasi_C(address_child &P);
address_child findElm_C(List_child L, infotype_child x);
void printInfo_C(List_child L);


#endif // LIST_CHILD_H_INCLUDED
