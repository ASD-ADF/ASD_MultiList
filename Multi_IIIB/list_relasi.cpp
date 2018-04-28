#include "list_relasi.h"

void createList_R(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi_R(address_child C) {
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst_R(List_relasi &L, address_relasi P) {
    if(first(L)==NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast_R(List_relasi &L, address_relasi P){
    if(first(L)==NULL){
        first(L)=P;
    }else{
        address_relasi Q = first(L);
        while(Q!=NULL){
            Q = next(Q);
        }
        next(Q) = P;

    }

}

void insertAfter_R(List_relasi &L, address_relasi Prec, address_relasi P){
    if(Prec!=NULL){
        if(next(Prec)==NULL){
            insertLast_R(L,P);
        }else{
            next(P)=next(Prec);
            next(Prec)=P;
        }
    }
}

void deleteFirst_R(List_relasi &L, address_relasi &P){
    if(next(first(L))==NULL){
        P = first(L);
        first(L)=NULL;
    }else{
        P = first(L);
        first(L) = next(first(L));
        next(P) = NULL;
    }
}

void deleteLast_R(List_relasi &L, address_relasi &P){
    if(next(first(L))==NULL){
        deleteFirst_R(L,P);
    }else{
        address_relasi Q //= first(L);
        ;
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        P = next(Q);
        next(Q)=NULL;
    }
}

void deleteAfter_R(List_relasi &L, address_relasi Prec, address_relasi &P){
    if(Prec!=NULL){
        if(next(Prec)==NULL){
            deleteLast_R(L,P);
        }else{
            P = next(Prec);
            next(Prec) = next(P);
            next(P) = NULL;
        }
    }
}

void printInfo_R(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<"============"<<endl;
        cout<<"Song : "<<P->info->info.name_song<<endl;
        P = next(P);
    }
    cout<<"============\n";
}

address_relasi findElm_R(List_relasi L, address_child C) {
    address_relasi P = NULL;
    //-------------your code here-------------
    P = first(L);
    if(first(L)!= NULL){
        while(P != NULL && P->info != C){
            if(P->info == C){
                return P;
            }else{
                P=next(P);
            }
        }
    }
    //----------------------------------------
    return P;

}
void dealokasi_R(address_relasi &P){
    delete P;
}


void insertAfter_R(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;

}
