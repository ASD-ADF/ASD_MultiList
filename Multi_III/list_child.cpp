#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address_child &P) {
    /**
    * FS : delete element pointed by P
    */
    delete(P);
}

void insertFirst(List_child &L, address_child P) {
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

void insertLast(List_child &L, address_child P){
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

void insertAfter(List_child &L, address_child &Prec, address_child P){
       if(first(L)!=NULL){
            if(Prec!=NULL){
                if(Prec==last(L)){
                    insertLast(L,P);
                }else{
                    next(P)=next(Prec);
                    prev(next(P))=P;
                    next(Prec)=P;
                    prev(P)=Prec;
                }
            }
        }
}

void deleteFirst(List_child &L, address_child &P){
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
    }
}

void deleteLast(List_child &L, address_child &P){
    if(first(L)!=NULL){
        if(next(first(L))==first(L)){
            deleteFirst(L,P);
        }else{
            P = last(L);
            prev(first(L))=prev(P);
            next(prev(P))=first(L);
            prev(P)=NULL;
            next(P)=NULL;

        }
    }
}
void deleteAfter(List_child &L, address_child Prec, address_child &P){
    if(first(L)!=NULL){
        if(Prec!=NULL){
            if(Prec==last(L)){
                deleteFirst(L,P);
            }else if(next(Prec)==last(L)){
                deleteLast(L,P);
            }else{
                P=next(Prec);
                next(Prec)=next(P);
                prev(next(P))=Prec;
                next(P)=NULL;
                prev(P)=NULL;
            }
        }
    }else{}
}

void printInfo(List_child L) {
    address_child P = first(L);
    do{
        cout<<"Customer ID      : "<<P->info.id<<endl;
        cout<<"Customer Name    : "<<P->info.name<<endl;
        P = next(P);
        cout<<endl;
    }while(P != first(L));
}



address_child findElm(List_child L, infotype_child x) {
    address_child P;
    P = first(L);
    if(first(L)!=NULL){
        do{
            if(P->info.id == x.id){
                return P;
            }else{
                P = next(P);
            }
        }while(next(P)!=first(L) && P->info.id != x.id);

    }else{
        return NULL;
    }
    if(P->info.id!=x.id){
        return NULL;
    }
    return P;
}
