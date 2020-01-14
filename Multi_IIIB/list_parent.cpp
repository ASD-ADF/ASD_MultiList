#include "list_parent.h"

void createList_P(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi_P(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    List_relasi LR;
    createList_R(LR);
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList_R(child(P));
    return P;
}

void insertFirst_P(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    if(first(L)==NULL){
        first(L)=P;
    }else{
        next(P)=first(L);
        first(L)=P;
    }
}

void insertLast_P(List_parent &L, address_parent P){
    address_parent Q = first(L);
    if(first(L)!=NULL){
        while(Q!=NULL){
            Q = next(Q);
        }
        next(Q)=P;
    }else{
        first(L)=P;
    }
}

void insertAfter_P(List_parent &L, address_parent Prec, address_parent P){
    if(Prec != NULL){
        if(next(Prec)==NULL){
            insertLast_P(L,P);
        }else{
            next(P)=next(Prec);
            next(Prec)=P;
        }
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
    }else{
        cout<<"List Kosong \n";
    }
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

void deleteAfter_P(List_parent &L, address_parent Prec, address_parent &P){
    if(Prec!=NULL){
        if(next(next(Prec))){
            deleteLast_P(L,P);
        }else{
            P = next(Prec);
            if(next(P)==NULL){
                P = NULL;
            }else{
                next(Prec)=next(P);
                P = NULL;
            }
        }
    }
}

int countSong(address_parent P){
    int i = 0;
    if(first(child(P)) == NULL){
        return 0;
    }else{
        address_relasi Q = first(child(P));
        while(Q!=NULL){
            i++;
            Q = next(Q);
        }
    }
    return i;
}

void printInfo_P(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        while(P!=NULL){
            cout<<"ID : "<<P->info.id<<endl;
            cout<<"Artist Name : "<<P->info.name<<endl;
            cout<<"Artist Genre : "<<P->info.genre<<endl;
            cout<<"Song(s) : "<<countSong(P)<<endl;
            P = next(P);
        };
    }
}

address_parent findElm_P(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = NULL;
    //-------------your code here-------------
    P = first(L);
    if(first(L)!= NULL){
        while(P != NULL && P->info.id != x.id){
            if(P->info.id == x.id){
                return P;
            }else{
                P=next(P);
            }
        }
    }else{
        return NULL;
    }
    //----------------------------------------
    return P;
}


/** ==========Ditambah========== */

address_parent findElmName_P(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    do {
        if(P->info.name == x.name) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
