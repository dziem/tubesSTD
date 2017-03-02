#include "list_siswa.h"

void createListSiswa(list_siswa &L){
    first(L) = nil;
    last(L) = nil;
}
address_siswa alokasiSiswa(infotype_siswa info){
    address_siswa q = new elmlist_siswa;
    infoNama(q) = info.nama;
    infoAlamat(q) = info.alamat;
    next(q) = nil;
    prev(q) = nil;
    return q;
}
address_siswa dealokasiSiswa(address_siswa P){
    delete P;
}
void insertSiswa(list_siswa &L, address_siswa P){
    if(first(L) != nil && last(L) != nil){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}
void deleteFirstSiswa(list_siswa &L){
    if(first(L) != nil && last(L) != nil){
        address_siswa P = first(L);
        first(L) = next(first(L));
        prev(first(L)) = nil;
        dealokasiSiswa(P);
    }else{
        cout << "Gagal delete siswa, list siswa kosong, di prosedur deletefirst" << endl;
    }
}
void deleteLastSiswa(list_siswa &L){
    if(first(L) != nil && last(L) != nil){
        address_siswa P = last(L);
        last(L) = prev(first(L));
        next(last(L)) = nil;
        dealokasiSiswa(P);
    }else{
        cout << "Gagal delete siswa, list siswa kosong, di prosedur deletelast" << endl;
    }
}
void deleteAfterSiswa(list_siswa &L, address_siswa Prec){
    if(first(L) != nil && last(L) != nil && Prec != nil){
        address_siswa P = first(L);
        while(next(P) != nil && infoNama(P) != infoNama(Prec) && infoAlamat(P) != infoAlamat(Prec)){
            P = next(P);
        }
        if(infoNama(P) == infoNama(Prec) && infoAlamat(P) == infoAlamat(Prec)){
            if(P == last(L)){
                cout << "Gagal delete siswa, elemen dicari berada paling belakang, di prosedur deleteafter" << endl;
            }else if(next(P) == last(L)){
                deleteLastSiswa(L);
            }else{
                address_siswa q = next(P);
                next(P) = next(next(P));
                prev(next(P)) = P;
                next(q) = nil;
                prev(q) = nil;
                dealokasiSiswa(q);
            }
        }else{
            cout << "Gagal delete siswa, elemen dicari tidak ketemu, di prosedur deleteafter" << endl;
        }
    }else{
        cout << "Gagal delete siswa, list siswa kosong, di prosedur deleteafter" << endl;
    }
}
void deleteSiswa(list_siswa &L, infotype_siswa R){
    if(first(L) != nil && last(L)!= nil && R.nama != "" && R.alamat != ""){
        address_siswa P = findSiswa(L,R);
        if(P != nil){
            if(P == first(L)){
                deleteFirstSiswa(L);
            }else if(P == last(L)){
                deleteLastSiswa(L);
            }else{
                address_siswa prec = prev(P);
                deleteAfterSiswa(L,prec);
            }
        }else{
            cout << "Gagal delete siswa, elemen yang akan dihapus tidak ada di list" << endl;
        }
    }else{
        cout << "Gagal delete siswa, list siswa kosong" << endl;
    }
}
void printSiswa(list_siswa L){
    if(first(L) != nil && last(L) != nil){
        address_siswa q = first(L);
        int i = 1;
        while(q != nil){
            cout << "Siswa " << i << "." << endl;
            cout << "Nama : " << infoNama(q) << endl;
            cout << "Alamat : " << infoAlamat(q) << endl;
            q = next(q);
            i++;
        }
    }else{
        cout << "List Siswa Kosong" << endl;
    }
}
address_siswa findSiswa(list_siswa L, infotype_siswa P){
    if(first(L) != nil && last(L) != nil && P.nama != "" && P.alamat != ""){
        address_siswa q = first(L);
        while(next(q) != nil && infoNama(q) != P.nama && infoAlamat(q) != P.alamat){
            q = next(q);
        }
        if(infoNama(q) == P.nama && infoAlamat(q) == P.alamat){
            return q;
        }else{
            return nil;
        }
    }else{
        return nil;
    }
}
