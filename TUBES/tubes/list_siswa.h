#ifndef LIST_SISWA_H_INCLUDED
#define LIST_SISWA_H_INCLUDED

#include <iostream>

using namespace std;

#define nil NULL
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define infoNama(P) P->info.nama
#define infoAlamat(P) P->info.alamat

typedef struct infotype_siswa{
    string nama;
    string alamat;
};
typedef struct elmlist_siswa *address_siswa;

struct elmlist_siswa{
    infotype_siswa info;
    address_siswa next;
    address_siswa prev;
};

struct list_siswa{
    address_siswa first;
    address_siswa last;
};

void createListSiswa(list_siswa &L);
address_siswa alokasiSiswa(infotype_siswa info);
address_siswa dealokasiSiswa(address_siswa P);
void insertSiswa(list_siswa &L, address_siswa P);
void deleteFirstSiswa(list_siswa &L);
void deleteLastSiswa(list_siswa &L);
void deleteAfterSiswa(list_siswa &L, address_siswa Prec);
void deleteSiswa(list_siswa &L, infotype_siswa P);
void printSiswa(list_siswa L);
address_siswa findSiswa(list_siswa L, infotype_siswa P);

#endif // LIST_SISWA_H_INCLUDED
