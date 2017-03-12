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
            addSiswa(l_rel, l_ins, l_sis);
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
            printRel(l_rel);
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
    address_instruktur i = findInstruktur(L, p);
    if(i != nil){
        cout << endl << "Gagal insert ke list instruktur, data sudah ada" << endl;
    }else{
        insertInstruktur(L,alokasiInstruktur(p));
        cout << endl << "Berhasil insert ke list instruktur" << endl;
    }
}
void addSiswa(list_relasi &LR, list_instruktur LI, list_siswa &LS){
    infotype_siswa p;
    clearscreen();
    bool stop = false;
    bool stopYN = false;
    string q;
    cout << "Insert list siswa" << endl;
    cout << "Masukkan nama siswa : ";
    cin >> p.nama;
    cout << "Masukkan alamat siswa : ";
    cin >> p.alamat;
    address_siswa s = findSiswa(LS, p);
    if(s != nil){
        cout << endl << "Gagal insert ke list siswa, data sudah ada" << endl;
    }else{
        insertSiswa(LS,alokasiSiswa(p));
        do{
            clearscreen();
            cout << "Menambahkan relasi antara instruktur dan siswa yang baru di insert" << endl;
            infotype_instruktur i;
            cout << "Masukkan nama instruktur dari siswa " << p.nama << " : ";
            cin >> i.nama;
            cout << "Masukkan nomor telepon instruktur dari siswa " << p.nama << " : ";
            cin >> i.telp;
            address_instruktur adr_i = findInstruktur(LI,i);
            address_siswa adr_s = findSiswa(LS, p);
            if(adr_i != nil && adr_s != nil){
                infotype_relasi r;
                r.instruktur = adr_i;
                r.siswa = adr_s;
                address_relasi rel = findRelasi(LR, r);
                if(rel != nil){
                    cout << endl << "Gagal menambahkan relasi, relasi sudah ada" << endl;
                }else{
                    int j = countSiswaFromInst(LR, i);
                    if(j < 5){
                        insertRelasi(LR, alokasiRelasi(r));
                        stop = true;
                        cout << endl << "Berhasil insert ke list siswa dan menambahkan relasi" << endl << endl;
                        getch();
                    }else{
                        cout << endl << "Gagal menambahkan relasi, kuota siswa instruktur sudah penuh" << endl;
                        do{
                            cout << "Input lagi ? (y/n) : ";
                            cin >> q;
                            if(q == "y" || q == "Y"){
                                stopYN = true;
                            }else if(q == "n" || q == "N"){
                                stopYN = true;
                                stop = true;
                                deleteSiswa(LS, p);
                            }else{
                                cout << "Input salah, harus y atau n" << endl;
                                stopYN = false;
                            }
                        }while(stopYN != true);
                    }
                }
            }else{
                cout << endl << "Gagal menambahkan relasi, instruktur tidak ada" << endl;
                do{
                    cout << "Input lagi ? (y/n) : ";
                    cin >> q;
                    if(q == "y" || q == "Y"){
                        stopYN = true;
                    }else if(q == "n" || q == "N"){
                        stopYN = true;
                        stop = true;
                        deleteSiswa(LS, p);
                    }else{
                        cout << "Input salah, harus y atau n" << endl;
                        stopYN = false;
                    }
                }while(stopYN != true);
            }
        }while(stop != true);
    }
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
        address_relasi rel = findRelasi(LR, r);
        if(rel != nil){
            cout << endl << "Gagal menambahkan relasi, relasi sudah ada" << endl;
        }else{
            int j = countSiswaFromInst(LR, i);
            if(j < 5){
                insertRelasi(LR, alokasiRelasi(r));
                cout << endl << "Berhasil menambahkan relasi" << endl;
            }else{
                cout << endl << "Gagal menambahkan relasi, kuota siswa instruktur sudah penuh" << endl;
            }
        }
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

/* Print from list function */
void printRel(list_relasi LR){
    bool stop = false;
    int i;
    clearscreen();
    cout << "Pilih apa yang akan ditampilkan dari list relasi" << endl;
    cout << "1. Tampilkan semua relasi" << endl;
    cout << "2. Tampilkan siswa berdasarkan instruktur tertentu" << endl;
    cout << "3. Tampilkan instruktur berdasarkan siswa tertentu" << endl;
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
    switch(i){
    case 1:
        cout << "Print semua relasi" << endl;
        clearscreen();
        printRelasi(LR);
    break;
    case 2:
        clearscreen();
        printSiswaFromIns(LR);
    break;
    case 3:
        clearscreen();
        printInsFromSiswa(LR);
    break;
    }
}
void printSiswaFromIns(list_relasi LR){
    infotype_instruktur ins;
    cout << "Print siswa berdasarkan instruktur tertentu" << endl;
    cout << "Masukkan nama instruktur : ";
    cin >> ins.nama;
    cout << "Masukkan nomor telepon instruktur : ";
    cin >> ins.telp;
    if(first(LR) != nil && last(LR) != nil){
        address_relasi q = first(LR);
        int j = 1;
        while(q != nil){
            if(infoNama(addressInstruktur(q)) == ins.nama && infoTelp(addressInstruktur(q)) == ins.telp){
                cout << "Siswa " << j << "." << endl;
                cout << "Nama siswa : " << infoNama(addressSiswa(q)) << endl;
                cout << "Alamat siswa : " << infoAlamat(addressSiswa(q)) << endl;
                j++;
            }
            q = next(q);
        }
        if(j == 1){
            cout << "Instruktur " << ins.nama << " tidak memiliki siswa" << endl;
        }
    }else{
        cout << "List relasi kosong" << endl;
    }
}
void printInsFromSiswa(list_relasi LR){
    infotype_siswa sis;
    cout << "Print instruktur berdasarkan siswa tertentu" << endl;
    cout << "Masukkan nama siswa : ";
    cin >> sis.nama;
    cout << "Masukkan alamat siswa : ";
    cin >> sis.alamat;
    if(first(LR) != nil && last(LR) != nil){
        address_relasi q = first(LR);
        int j = 1;
        while(q != nil){
            if(infoNama(addressSiswa(q)) == sis.nama && infoAlamat(addressSiswa(q)) == sis.alamat){
                cout << "Instruktur " << j << "." << endl;
                cout << "Nama instruktur : " << infoNama(addressInstruktur(q)) << endl;
                cout << "Nomor telepon instruktur : " << infoTelp(addressInstruktur(q)) << endl;
                j++;
            }
            q = next(q);
        }
        if(j == 1){
            cout << "Siswa " << sis.nama << " tidak memiliki instruktur" << endl;
        }
    }else{
        cout << "List relasi kosong" << endl;
    }
}

/* Fungsi operasi list relasi */
int countSiswaFromInst(list_relasi L, infotype_instruktur p){
    if(first(L) != nil && last(L) != nil){
        address_relasi q = first(L);
        int i = 0;
        while(q != nil){
            if(infoNama(addressInstruktur(q)) == p.nama && infoTelp(addressInstruktur(q)) == p.telp){
                i++;
            }
            q = next(q);
        }
        return i;
    }else{
        return 0;
    }
}
int countInstFromSiswa(list_relasi L, infotype_siswa p){
    if(first(L) != nil && last(L) != nil){
        address_relasi q = first(L);
        int i = 0;
        while(q != nil){
            if(infoNama(addressSiswa(q)) == p.nama && infoAlamat(addressSiswa(q)) == p.alamat){
                i++;
            }
            q = next(q);
        }
        return i;
    }else{
        return 0;
    }
}
