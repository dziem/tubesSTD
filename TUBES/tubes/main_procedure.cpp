#include "main_procedure.h"

/* Basic Main Function */
void clearscreen(){
    system ("CLS");
}
int menu(){
    bool stop = false;
    int i;
    clearscreen();
    cout << "Pilih operasi list" << endl;
    cout << "1. Insert / Add" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Find / search" << endl;
    cout << "4. Print" << endl;
    cout << "0. Exit" << endl;
    do{
        cout << "Pilih menu : ";
        cin >> i;
        if(i >= 0 && i <= 4){
            stop = true;
        }else{
            cout << "Input salah" << endl;
        }
    }while(stop != true);
    return i;
}
int submenu(){
    bool stop = false;
    int i;
    clearscreen();
    cout << "Pilih list yang akan dioperasi" << endl;
    cout << "1. List Instruktur" << endl;
    cout << "2. List Siswa" << endl;
    cout << "3. List Relasi" << endl;
    cout << "0. Back" << endl;
    do{
        cout << "Pilih menu : ";
        cin >> i;
        if(i >= 0 && i <= 3){
            stop = true;
        }else{
            cout << "Input salah" << endl;
        }
    }while(stop != true);
    return i;
}
void aksimenu(int menu, int sub, list_instruktur &l_ins, list_siswa &l_sis, list_relasi &l_rel){
    switch(menu){
    case 1:
        switch(sub){
        case 1:
            addInstruktur(l_ins);
            getch();
        break;
        case 2:
            addSiswa(l_sis);
            getch();
        break;
        case 3:
            addRelasi(l_rel,l_ins,l_sis);
            getch();
        break;
        }
    break;
    case 2:
        switch(sub){
        case 1:
            delInstruktur(l_ins, l_rel);
            getch();
        break;
        case 2:
            delSiswa(l_sis, l_rel);
            getch();
        break;
        case 3:
            delRelasi(l_rel, l_ins, l_sis);
            getch();
        break;
        }
    break;
    case 3:
        switch(sub){
        case 1:
            findIns(l_ins);
            getch();
        break;
        case 2:
            findSis(l_sis);
            getch();
        break;
        case 3:
            findRel(l_rel, l_ins, l_sis);
            getch();
        break;
        }
    break;
    case 4:
        switch(sub){
        case 1:
            clearscreen();
            cout << "Print list instruktur" << endl;
            printInstruktur(l_ins);
            getch();
        break;
        case 2:
            clearscreen();
            cout << "Print list siswa" << endl;
            printSiswa(l_sis);
            getch();
        break;
        case 3:
            clearscreen();
            cout << "Print list relasi" << endl;
            printRelasi(l_rel);
            getch();
        break;
        }
    break;
    }
}
void tampilmenu(){
    list_instruktur l_ins;
    list_siswa l_sis;
    list_relasi l_rel;
    createListInstruktur(l_ins);
    createListSiswa(l_sis);
    createListRelasi(l_rel);
    int i,j;
    bool stop = false;
    do{
        i = menu();
        if(i != 0){
            j = submenu();
            if(j != 0){
                aksimenu(i,j,l_ins,l_sis,l_rel);
            }
        }else{
            stop = true;
        }
    }while(stop != true);
}

/* Insert to list function */
void addInstruktur(list_instruktur &L){
    infotype_instruktur p;
    clearscreen();
    cout << "Insert list instruktur" << endl;
    cout << "Masukkan nama instruktur : ";
    cin >> p.nama;
    cout << "Masukkan nomor telepon instruktur : ";
    cin >> p.telp;
    insertInstruktur(L,alokasiInstruktur(p));
    cout << endl << "Berhasil insert ke list instruktur" << endl;
}
void addSiswa(list_siswa &L){
    infotype_siswa p;
    clearscreen();
    cout << "Insert list siswa" << endl;
    cout << "Masukkan nama siswa : ";
    cin >> p.nama;
    cout << "Masukkan alamat siswa : ";
    cin >> p.alamat;
    insertSiswa(L,alokasiSiswa(p));
    cout << endl << "Berhasil insert ke list siswa" << endl;
}
void addRelasi(list_relasi &LR, list_instruktur LI, list_siswa LS){
    clearscreen();
    cout << "Menambahkan relasi antara instruktur dan siswa" << endl;
    infotype_instruktur i;
    cout << "Masukkan nama instruktur : ";
    cin >> i.nama;
    cout << "Masukkan nomor telepon instruktur : ";
    cin >> i.telp;
    address_instruktur adr_i = findInstruktur(LI,i);
    infotype_siswa s;
    cout << "Masukkan nama siswa : ";
    cin >> s.nama;
    cout << "Masukkan alamat siswa : ";
    cin >> s.alamat;
    address_siswa adr_s = findSiswa(LS, s);
    if(adr_i != nil && adr_s != nil){
        infotype_relasi r;
        r.instruktur = adr_i;
        r.siswa = adr_s;
        insertRelasi(LR, alokasiRelasi(r));
        cout << endl << "Berhasil menambahkan relasi" << endl;
    }else{
        cout << endl << "Gagal menambahkan relasi" << endl;
    }
}

/* Delete from list function */
void delInstruktur(list_instruktur &L, list_relasi &LR){
    infotype_instruktur p;
    infotype_relasi rel;
    clearscreen();
    cout << "Delete list instruktur" << endl;
    cout << "Masukkan nama instruktur yang akan dihapus : ";
    cin >> p.nama;
    cout << "Masukkan nomor telepon instruktur yang akan dihapus : ";
    cin >> p.telp;
    address_relasi q = first(LR);
    while(q != nil){
        if(infoNama(addressInstruktur(q)) == p.nama && infoTelp(addressInstruktur(q)) == p.telp){
            rel.instruktur = addressInstruktur(q);
            rel.siswa = addressSiswa(q);
            deleteRelasi(LR, rel);
        }
        q = next(q);
    }
    deleteInstruktur(L,p);
    cout << endl << "Berhasil delete " << p.nama << " dari list instruktur" << endl;
}
void delSiswa(list_siswa &L, list_relasi &LR){
    infotype_siswa p;
    infotype_relasi rel;
    clearscreen();
    cout << "Delete list siswa" << endl;
    cout << "Masukkan nama siswa yang akan dihapus : ";
    cin >> p.nama;
    cout << "Masukkan alamat siswa yang akan dihapus : ";
    cin >> p.alamat;
    address_relasi q = first(LR);
    while(q != nil){
        if(infoNama(addressSiswa(q)) == p.nama && infoAlamat(addressSiswa(q)) == p.alamat){
            rel.instruktur = addressInstruktur(q);
            rel.siswa = addressSiswa(q);
            deleteRelasi(LR, rel);
        }
        q = next(q);
    }
    deleteSiswa(L,p);
    cout << endl << "Berhasil delete " << p.nama << " dari list siswa" << endl;
}
void delRelasi(list_relasi &LR, list_instruktur LI, list_siswa LS){
    clearscreen();
    cout << "Menghapus relasi antara instruktur dan siswa" << endl;
    infotype_instruktur i;
    cout << "Masukkan nama instruktur yang akan dihapus relasinya : ";
    cin >> i.nama;
    cout << "Masukkan nomor telepon insatruktur yang akan dihapus relasinya : ";
    cin >> i.telp;
    address_instruktur adr_i = findInstruktur(LI,i);
    infotype_siswa s;
    cout << "Masukkan nama siswa yang akan dihapus relasinya : ";
    cin >> s.nama;
    cout << "Masukkan alamat siswa yang akan dihapus relasinya : ";
    cin >> s.alamat;
    address_siswa adr_s = findSiswa(LS, s);
    if(adr_i != nil && adr_s != nil){
        infotype_relasi r;
        r.instruktur = adr_i;
        r.siswa = adr_s;
        deleteRelasi(LR,r);
        cout << endl << "Berhasil menghapus relasi" << endl;
    }else{
        cout << endl << "Gagal menghapus relasi" << endl;
    }
}

/* Find element from list function */
void findIns(list_instruktur L){
    infotype_instruktur p;
    clearscreen();
    cout << "Find element from list instruktur" << endl;
    cout << "Masukkan nama instruktur yang akan dicari : ";
    cin >> p.nama;
    cout << "Masukkan nomor telepon instruktur yang akan dicari : ";
    cin >> p.telp;
    address_instruktur q = findInstruktur(L, p);
    if(q != nil){
        cout << "Instruktur " << p.nama << " ada di dalam list" << endl;
    }else{
        cout << "Instruktur " << p.nama << " tidak ada di dalam list" << endl;
    }
}
void findSis(list_siswa L){
    infotype_siswa p;
    clearscreen();
    cout << "Find element from list siswa" << endl;
    cout << "Masukkan nama siswa yang akan dicari : ";
    cin >> p.nama;
    cout << "Masukkan alamat siswa yang akan dicari : ";
    cin >> p.alamat;
    address_siswa q = findSiswa(L, p);
    if(q != nil){
        cout << "Siswa " << p.nama << " ada di dalam list" << endl;
    }else{
        cout << "Siswa " << p.nama << " tidak ada di dalam list" << endl;
    }
}
void findRel(list_relasi LR, list_instruktur LI, list_siswa LS){
    clearscreen();
    cout << "Find element from list relasi" << endl;
    infotype_instruktur i;
    cout << "Masukkan nama instruktur : ";
    cin >> i.nama;
    cout << "Masukkan nomor telepon instruktur : ";
    cin >> i.telp;
    address_instruktur adr_i = findInstruktur(LI,i);
    infotype_siswa s;
    cout << "Masukkan nama siswa : ";
    cin >> s.nama;
    cout << "Masukkan alamat siswa : ";
    cin >> s.alamat;
    address_siswa adr_s = findSiswa(LS, s);
    if(adr_i != nil && adr_s != nil){
        infotype_relasi r;
        r.instruktur = adr_i;
        r.siswa = adr_s;
        address_relasi rel = findRelasi(LR, r);
        if(rel != nil){
            cout << "Relasi antara instruktur " << i.nama << " dan siswa " << s.nama << " ada di dalam list" << endl;
        }else{
            cout << "Relasi antara instruktur " << i.nama << " dan siswa " << s.nama << " tidak ada di dalam list" << endl;
        }
    }else{
        cout << "Relasi antara instruktur " << i.nama << " dan siswa " << s.nama << " tidak ada di dalam list" << endl;
    }
}
