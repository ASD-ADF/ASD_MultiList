#include "control.h"

void addArtist(List_parent LP, int i){
    infotype_parent x;
    cout<<"Artis Name : ";cin>>x.name;
    cout<<"Artist Genre : ";cin>>x.genre;
    x.id = i++;
    insertFirst(LP,alokasi(x));
}

void addSong(List_parent &LP, List_child &LC, List_relasi &LR){
    infotype_parent xp;
    address_parent P = findElmName(LP,xp);
    cout<<"Name Artist : ";cin>>xp.name;

    if(P==NULL){
        cout<<"Artist Not Exist"<<endl;
    }else{
        infotype_child xc;
        cout<<"Artis name "<<P->info.name<<" founded. \n";
        cout<<"\n";
        cout<<"input name Song : ";cin>>xc.name_song;
        cout<<"input location Song : ";cin>>xc.name_loc;
        xc.id_song++;
        address_child Pc = alokasi(xc);
        address_relasi Pr = alokasi(Pc);
        insertLast(LC,Pc);
        insertLast(LR,Pr);
    }

}
