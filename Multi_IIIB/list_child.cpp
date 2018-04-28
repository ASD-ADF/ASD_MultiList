#include "list_child.h"
#include "list_relasi.h"

void createList_C(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi_C(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst_C(List_child &L, address_child P) {
    if(first(L)==NULL){
        first(L)=P;
        last(L)=P;
        next(last(L))=first(L);
        prev(first(L))=last(L);
    }else{
        next(P)=first(L);
        first(L)=P;
        next(last(L))=first(L);
        prev(first(L))=last(L);
    }
}

void insertLast_C(List_child &L, address_child P){
    if(first(L)==NULL){
        first(L)=P;
        last(L)=P;
        next(last(L))=first(L);
        prev(first(L))=last(L);
    }else{
        next(last(L))=P;
        next(P)=first(L);
        prev(P)=last(L);
        prev(first(L))=P;
        last(L)=P;
    }
}

void insertAfter_C(List_child &L, address_child &Prec, address_child P){
       if(first(L)!=NULL){
            if(Prec!=NULL){
                if(Prec==last(L)){
                    insertLast_C(L,P);
                }else{
                    next(P)=next(Prec);
                    prev(next(P))=P;
                    next(Prec)=P;
                    prev(P)=Prec;
                }
            }
        }
}

void deleteFirst_C(List_child &L, address_child &P){
    if(first(L)!=NULL){
        if(next(first(L))==first(L)){
            P = first(L);
            first(L)=NULL;
            last(L)=NULL;
        }else{
            P = first(L);
            prev(next(P))=last(L);
            next(last(L))=next(P);
            first(L)=next(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    //----------------------------------------
    }
}

void deleteLast_C(List_child &L, address_child &P){
    if(first(L)!=NULL){
        if(next(first(L))==first(L)){
            deleteFirst_C(L,P);
        }else{
            P = last(L);
            prev(first(L))=prev(P);
            next(prev(P))=first(L);
            prev(P)=NULL;
            next(P)=NULL;

        }
    }
}
void deleteAfter_C(List_child &L, address_child Prec, address_child &P){
    if(first(L)!=NULL){
        if(Prec!=NULL){
            if(Prec==last(L)){
                deleteFirst_C(L,P);
            }else if(next(Prec)==last(L)){
                deleteLast_C(L,P);
            }else{
                P=next(Prec);
                next(Prec)=next(P);
                prev(next(P))=Prec;
                next(P)=NULL;
                prev(P)=NULL;
            }
        }
    }else{
        cout<<"List Kosong"<<endl;
    }
}


void printInfo_C(List_child L) {
    address_child P = first(L);
    do{
        cout<<"==================="<<endl;
        cout<<"Id song : "<<P->info.id_song<<endl;
        cout<<"Song : "<<P->info.name_song<<endl;
        cout<<"Location : "<<P->info.name_loc<<endl;
        cout<<"==================="<<endl;
        P = next(P);
    }while(P != first(L));
}


address_child findElm_C(List_child L, infotype_child x) {
    address_child P;
    //-------------your code here-------------
    P = first(L);
    if(first(L)!=NULL){
        do{
            if(P->info.id_song == x.id_song){
                return P;
            }else{
                P = next(P);
            }
        }while(next(P)!=first(L) && P->info.id_song != x.id_song);

    }else{
        return NULL;
    }
    if(P->info.id_song!=x.id_song){
        return NULL;
    }


    //----------------------------------------
    return P;
}

address_child findNameSong(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(P->info.name_song==x.name_song) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter_C(address_child &Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}
