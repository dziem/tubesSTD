#ifndef MAIN_PROCEDURE_H_INCLUDED
#define MAIN_PROCEDURE_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "list_relasi.h"
using namespace std;

void clearscreen();
int menu();
int submenu();
void aksimenu(int menu, int sub, list_instruktur &l_ins, list_siswa &l_sis, list_relasi &l_rel);
void tampilmenu();
void addInstruktur(list_instruktur &L);
void addSiswa(list_siswa &L);
void addRelasi(list_relasi &LR, list_instruktur LI, list_siswa LS);
void delInstruktur(list_instruktur &L, list_relasi &LR);
void delSiswa(list_siswa &L, list_relasi &LR);
void delRelasi(list_relasi &LR, list_instruktur LI, list_siswa LS);
void findIns(list_instruktur L);
void findSis(list_siswa L);
void findRel(list_relasi LR, list_instruktur LI, list_siswa LS);

#endif // MAIN_PROCEDURE_H_INCLUDED
