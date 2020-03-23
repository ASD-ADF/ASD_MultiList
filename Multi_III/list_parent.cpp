#include "list_parent.h"

void createList(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasi(address_parent &P) {
    /**
    * FS : delete element pointed by P
    */
    delete(P);
}

void insertFirst(List_parent &L, address_parent P) {
    /**
    * FS : element pointed by P became the first element in List L
    */
    if (first(L)==NULL){
        first(L)=P;
    }else{
        next(P)= first(L);
        first(L)=P;
    }
}

void insertLast(List_parent &L, address_parent P) {
    /**
    * FS : element pointed by P became the last element in List L
    */
    address_parent(Q)=first(L);
    if (first(L)==NULL){
        first(L)=P;
    }else{
        while (next(Q)!= NULL) {
            Q=next(Q);
        }
        next(Q)=P;
    }
}

void insertAfter_P(List_parent &L, address_parent Prec, address_parent P){
    if(Prec != NULL){
        if(next(Prec)==NULL){
            insertLast(L,P);
        }else{
            next(P)=next(Prec);
            next(Prec)=P;
        }
    }
}

void deleteFirst(List_parent &L, address_parent &P) {
    /**
    * FS : first element in List L is removed and is pointed by P
    */
    if (first(L)==NULL){}
    else{
        P=first(L);
        first(L) = next(first(L));
        next(P)=NULL;
    }
}

void deleteFirst_P(List_parent &L, address_parent &P){

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

void deleteLast_P(List_parent &L, address_parent &P){
    if(first(L)!=NULL){
        if(next(first(L))==NULL){
            P = first(L);
            first(L)=NULL;
        }else{
            address_parent Q = first(L);
            while(Q != NULL){
                Q = next(Q);
            }
            P = Q;
            Q = NULL;
        }
    }
}

void deleteAfter(address_parent Prec, address_parent &P) {
    /**
    *      is removed and pointed by pointer P
    */
    if (Prec!=NULL){
        P=next(Prec);
        next(Prec)=next(next(Prec));
        next(P)=NULL;
    }
}

void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        while(P!=NULL){
            cout<<"Book ID : "<<P->info.idb<<endl;
            cout<<"Book Name : "<<P->info.name<<endl;
            cout<<"Book Genre : "<<P->info.genre<<endl;
            P = next(P);
            cout<<endl;
        };
    }
}

address_parent findElm(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    if(first(L)!=NULL){
        while(P!=NULL && P->info.idb!=x.idb){
            if(P->info.idb==x.idb){
                return P;
            } else{
                P=next(P);
            }
        }
    }
    return P;
}
