#include "operation.h"


void insertParent(List_parent &L){
    address_parent P = NULL;
    infotype_parent x;
    cout<<"Input ID Artist : ";cin>>x.id;
    P = findElm_P(L,x);
    if(P==NULL){
        cout<<"Input Name Artist : ";cin>>x.name;
        cout<<"input Genre Artis : ";cin>>x.genre;
        P = alokasi_P(x);
        insertFirst_P(L,P);
        cout<<"Artist Inserted ! \n";
    }else{
        cout<<"Artist is already Exist \n";
        getch();
        system("cls");
        insertParent(L);
    }
}

void DisplayParent(List_parent &L){
    if(first(L)==NULL){
        cout<<"List is Empty \n";
    }else{
        printInfo_P(L);
    }
}

void insertChild(List_child &L){
    address_child P = NULL;
    infotype_child x;
    cout<<"Input ID Music : ";cin>>x.id_song;
    P = findElm_C(L,x);
    if(P==NULL){
        cout<<"Input Song Name : ";cin>>x.name_song;
        x.name_loc = "asset/"+x.name_song+".wav";
        P = alokasi_C(x);
        insertFirst_C(L,P);
    }else{
        cout<<"Song is already exist ! "<<endl;
    }
}

void displayChild(List_child &L){
    if(first(L)==NULL){
        cout<<"List Kosong \n";
    }else{
        printInfo_C(L);
    }
}

void connectList(List_parent LP, List_child LC){
    infotype_child xc;
    address_child C;
    address_parent P;
    infotype_parent xp;
    address_relasi R;
    cout<<"Input id Artis : ";cin>>xp.id;
    P = findElm_P(LP,xp);
    if(P!=NULL){
        cout<<"input id Song : ";cin>>xc.id_song;
        C = findElm_C(LC,xc);
        if(C!=NULL){
            R = alokasi_R(C);
            insertFirst_R(child(P),R);
            cout<<info(P).name<<" is have a new song "<<info(C).name_song<<endl;
        }else{
            cout<<"Song is not Exist \n";
        }
    }else{
        cout<<"Artis is not exist \n";
    }
}

void checkConnection(List_parent LP, List_child LC){
    infotype_parent x;
    cout<<"Input Id Artist : ";cin>>x.id;
    address_parent P = findElm_P(LP,x);
    if(P!=NULL){
        cout<<info(P).name<<" Are connected with = ";
        address_relasi R = first(child(P));
        while(R != NULL){
            cout<<info(info(R)).name_song<<" - ";
            R = next(R);
        }
    }else{
        cout<<"Empty Parent \n";
    }
}

void disconnect(List_parent &LP, List_child LC){
    address_child C;
    address_parent P;
    address_relasi R;
    address_relasi AR;
    infotype_parent xp;
    infotype_child xc;
    cout<<"Input Id Artist : ";cin>>xp.id;
    P = findElm_P(LP,xp);
    if(P!=NULL){
        cout<<"Input Id Song   : ";cin>>xc.id_song;
        C = findElm_C(LC,xc);
        if(C!=NULL){
            R = findElm_R(child(P),C);
            if(R==first(child(P))){
                deleteFirst_R(child(P),AR);
            }else if(next(R)==NULL){
                deleteLast_R(child(P),AR);
            }else{
                deleteAfter_R(child(P),R,AR);
            }
            cout<<info(P).id<<", With song "<<info(info(AR)).id_song<<", are disconnected"<<endl;
        }else{
            cout<<"Song is not exist ! \n";
        }
    }else{
        cout<<"Artist is not exist ! \n";
    }
}

void printALL(List_parent L){
    address_parent Q = first(L);
    address_relasi R;
    if(first(L)!=NULL){
        while(Q!=NULL){
            cout<<info(Q).name<<" => ";
            R = first(child(Q));
            while(R!=NULL){
                cout<<info(info(R)).name_song<<" - ";
                R = next(R);
            }
            cout<<"\n";
            Q = next(Q);
        }
    }else{
        cout<<"Empty Parent \n";
    }
}

void printChildOfParent(List_parent L){
    infotype_parent x;
    cout<<"Input ID Artist : ";cin>>x.id;
    address_parent P = findElm_P(L,x);
    if(P!=NULL){
        address_relasi Q = first(child(P));
        while(Q!=NULL){
            cout<<info(info(Q)).name_song<<" - ";
            Q = next(Q);
        }
        cout<<"\n";
    }else{
        cout<<"Artist is not Exist \n";
    }
}

void deleteChild(List_parent &LP, List_child &LC){
    infotype_child xc;
    address_parent P = first(LP);
    address_relasi AR;
    address_child AC;
    cout<<"Input Song ID :";cin>>xc.id_song;
    address_child Target = findElm_C(LC,xc);
    if(Target!=NULL){
        while(P!=NULL){
            address_relasi R = first(child(P));
            while(R!=NULL){
                if(Target == R->info){
                    if(R==first(child(P))){
                        deleteFirst_R(child(P),AR);
                    }else if(next(R)==NULL){
                        deleteLast_R(child(P),AR);
                    }else{
                        address_relasi RT = first(child(P));
                        while(next(RT)!= R){
                            RT = next(RT);
                        }
                        deleteAfter_R(child(P),RT,AR);
                    }
                    if(AR!=NULL){
                        dealokasi_R(AR);
                    }
                }
                R=next(R);
            }
        }
    }
    if(Target!=NULL){
        if(Target==first(LC)){
            deleteFirst_C(LC,AC);
        }else if(Target == last(LC)){
            deleteLast_C(LC,AC);
        }else{
            deleteAfter_C(LC,prev(Target),AC);
        }
        cout<<info(AC).name_song<<", Deleted ! \n";
    }
}

void deleteParent(List_parent &L){

}

void MusicPlayer(address_child C){
    string filename = C->info.name_loc;
    cout<<"Playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}

void PlayArtist(List_parent LP){
    infotype_parent x;
    address_parent P;
    cout<<"Input Artist ID : ";cin>>x.id;
    P = findElm_P(LP,x);
    if(P!=NULL){
        address_relasi R = first(child(P));
        while(R!=NULL){
            //cout<<R->info<<endl;
           MusicPlayer(R->info);
           R=next(R);
        }
    }else{
        cout<<"id not found ! \n";
    }
}

void MusicById(List_child LC){
    infotype_child x;
    address_child P;
    cout<<"Input Artist ID : ";cin>>x.id_song;
    P = findElm_C(LC,x);
    if(P!=NULL){
        MusicPlayer(P);
    }else{
        cout<<"music not found \n";
    }
}


