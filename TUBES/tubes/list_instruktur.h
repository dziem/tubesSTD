#ifndef LIST_INSTRUKTUR_H_INCLUDED
#define LIST_INSTRUKTUR_H_INCLUDED

#include <iostream>

using namespace std;

#define nil NULL
#define first(L) L.first
#define next(P) P->next
#define infoNama(P) P->info.nama
#define infoTelp(P) P->info.telp

typedef struct infotype_instruktur{
    string nama;
    string telp;
};

typedef struct elmlist_instruktur *address_instruktur;

struct elmlist_instruktur{
    infotype_instruktur info;
    address_instruktur next;
};

struct list_instruktur{
    address_instruktur first;
};

void createListInstruktur(list_instruktur &L);
address_instruktur alokasiInstruktur(infotype_instruktur info);
address_instruktur dealokasiInstruktur(address_instruktur P);
void insertInstruktur(list_instruktur &L, address_instruktur P);
void deleteFirstInstruktur(list_instruktur &L);
void deleteLastInstruktur(list_instruktur &L);
void deleteAfterInstruktur(list_instruktur &L, address_instruktur prec);
void deleteInstruktur(list_instruktur &L, infotype_instruktur R);
void printInstruktur(list_instruktur L);
address_instruktur findInstruktur(list_instruktur L, infotype_instruktur P);

#endif // LIST_INSTRUKTUR_H_INCLUDED
