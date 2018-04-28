#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED

#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define car(P) P->car
#define first_history(P) P->first_history
#define last_history(P) P->last_history

#define first(L) L.first
#define last(L) L.last

using namespace std;

typedef struct elm_car *adr_car;
typedef struct elm_history *adr_history;
typedef struct elm_pelanggan *adr_pelanggan;
typedef struct elm_terbanyak1 *adr_terbanyak1;
typedef struct elm_terbanyak2 *adr_terbanyak2;

struct infotype_pelanggan
{
    int id_pelanggan;
    string nama;
    string hp;
};

struct elm_pelanggan
{
    infotype_pelanggan info;
    adr_pelanggan next;
    adr_pelanggan prev;
    adr_history first_history;
    adr_history last_history;
};

struct infotype_history
{
    int id_history;
    string date;
    string lama;
};

struct elm_history
{
    infotype_history info;
    adr_history next;
    adr_car car;
};

struct infotype_car
{
    string merek;
    string tahun;
    int id_car;
};

struct elm_car
{
    infotype_car info;
    adr_car next;
    adr_car prev;
};

struct infotype_terbanyak1
{
    int id_pelanggan,jumlah;
    string nama;
};

struct elm_terbanyak1
{
    infotype_terbanyak1 info;
    adr_terbanyak1 next;
    adr_terbanyak1 prev;
};

//struct elm_terbanyak2
//{
//    int info;
//    adr_terbanyak2 next;
//    adr_terbanyak2 prev;
//};

struct list_pelanggan
{
    adr_pelanggan first;
    adr_pelanggan last;
};

struct list_car
{
    adr_car first;
    adr_car last;
};

struct list_terbanyak1
{
    adr_terbanyak1 first;
    adr_terbanyak1 last;
};

//struct list_terbanyak2
//{
//    adr_terbanyak2 first;
//    adr_terbanyak2 last;
//};


adr_pelanggan alokasi_pelanggan (infotype_pelanggan x);
adr_car alokasi_car (infotype_car x);
adr_terbanyak1 alokasi_terbanyak1 (int x);
adr_terbanyak2 alokasi_terbanyak2 (int x);
bool isInteger(int x);
void menu();
void createList_pelanggan (list_pelanggan &L);
void createList_car (list_car &L);
void createList_terbanyak1 (list_terbanyak1 &L);
//void createList_terbanyak2 (list_terbanyak2 &L);
void insert_pelanggan (list_pelanggan &L, adr_pelanggan Q);
void insert_car (list_car &L, adr_car Q);
void insert_history (list_pelanggan &L, list_car L2, infotype_history x, int id_car, int id);
void delete_pelanggan (list_pelanggan &L, int id);
void delete_car (list_car &L, int id);
void delete_history (list_pelanggan &L, int id, int id_history);
void update (list_pelanggan &L, adr_pelanggan Q);
void view_pelanggan (list_pelanggan L);
void view_car (list_car L);
void view_mobilpelanggan (list_pelanggan L);
void view_pelangganmobil (list_pelanggan L, list_car L2);
void cari (list_pelanggan L, int x);
void report (list_pelanggan L, list_terbanyak1 &L2);

#endif // MOBIL_H_INCLUDED
