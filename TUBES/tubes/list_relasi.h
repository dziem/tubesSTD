#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "list_instruktur.h"
#include "list_siswa.h"

#define nil NULL
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define addressSiswa(P) P->info.siswa
#define addressInstruktur(P) P->info.instruktur

typedef struct infotype_relasi{
    address_instruktur instruktur;
    address_siswa siswa;
};

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    infotype_relasi info;
    address_relasi next;
    address_relasi prev;
};

struct list_relasi{
    address_relasi first;
    address_relasi last;
};

void createListRelasi(list_relasi &L);
address_relasi alokasiRelasi(infotype_relasi P);
address_relasi dealokasiRelasi(address_relasi P);
void insertRelasi(list_relasi &L, address_relasi P);
void deleteFirstRelasi(list_relasi &L);
void deleteLastRelasi(list_relasi &L);
void deleteAfterRelasi(list_relasi &L, address_relasi Prec);
void deleteRelasi(list_relasi &L, infotype_relasi R);
void printRelasi(list_relasi L);
address_relasi findRelasi(list_relasi L, infotype_relasi P);

#endif // LIST_RELASI_H_INCLUDED
