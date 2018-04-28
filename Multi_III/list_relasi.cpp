#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_parent P, address_child C) {
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
    if(first(L)==NULL){
        first(L)=P;
    }else{
        next(P)=first(L);
        first(L)=P;
    }
}

void insertLast(List_relasi &L, address_relasi P){
    if(first(L)==NULL){
        first(L)=P;
    }else{
        address_relasi Q =first(L);
        while(Q != NULL){
            Q = next(Q);
        }
        next(Q)=P;
    }
}

void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P){
    if(Prec != NULL){
        if(next(Prec)==NULL){
            insertLast(L,P);
        }else{
            next(P)=next(Prec);
            next(Prec)=P;
        }
    }
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<P->child->info.name<<"   <->   "<<P->parent->info.name<<endl;
        P = next(P);
    }
}

void deleteFirst(List_relasi &L, address_relasi &P) {
    /**
    * FS : first element in List L is removed and is pointed by P
    */
    if(first(L)!=NULL){
        if(next(first(L))==NULL){
            P = first(L);
            first(L) = NULL;
        }else{
            P = first(L);
            first(L)= next(first(L));
            P = NULL;
        }
    }else{}
}

void deleteLast(List_relasi &L, address_relasi &P){
    if(first(L)!=NULL){
        if(next(first(L))==NULL){
            P = first(L);
            first(L)=NULL;
        }else{
            address_relasi Q = first(L);
            while(Q != NULL){
                Q = next(Q);
            }
            P = Q;
            Q = NULL;
        }
    }
}

void deleteAfter(address_relasi Prec, address_relasi &P) {
    /**
    *      is removed and pointed by pointer P
    */
    if (Prec!=NULL){
        P=next(Prec);
        next(Prec)=next(next(Prec));
        next(P)=NULL;
    }
}


address_relasi findElm(List_relasi L, address_parent P, address_child C) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)==P && child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}


void connectList(List_relasi &LR, List_parent LP, List_child LC){
    address_parent P;
    address_child C;
    address_relasi R;

    infotype_child xc;
    infotype_parent xp;

    cout<<"Input id Book      : ";cin>>xp.idb;
    P = findElm(LP,xp);
    if(P!=NULL){
        cout<<"input id Member    : ";cin>>xc.id;
        C = findElm(LC,xc);
        if(C!=NULL){
            R = alokasi(P,C);
            insertFirst(LR,R);
            cout<<info(P).name<<" borrowed by "<<info(C).name<<endl;
        }else{
            cout<<"Song is not Exist \n";
        }
    }else{
        cout<<"Artis is not exist \n";
    }
}
