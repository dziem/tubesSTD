#include "list_relasi.h"

void createListRelasi(list_relasi &L){
    first(L) = nil;
    last(L) = nil;
}
address_relasi alokasiRelasi(infotype_relasi P){
    address_relasi q = new elmlist_relasi;
    addressSiswa(q) = P.siswa;
    addressInstruktur(q) = P.instruktur;
    next(q) = nil;
    prev(q) = nil;
    return q;
}
address_relasi dealokasiRelasi(address_relasi P){
    delete P;
}
void insertRelasi(list_relasi &L, address_relasi P){
    if(first(L) != nil && last(L) != nil){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}
void deleteFirstRelasi(list_relasi &L){
    if(first(L) != nil && last(L) != nil){
        address_relasi P = first(L);
        first(L) = next(first(L));
        prev(first(L)) = nil;
        dealokasiRelasi(P);
    }else{
        cout << "Gagal delete relasi, list relasi kosong, di prosedur deletefirst" << endl;
    }
}
void deleteLastRelasi(list_relasi &L){
    if(first(L) != nil && last(L) != nil){
        address_relasi P = last(L);
        last(L) = prev(first(L));
        next(last(L)) = nil;
        dealokasiRelasi(P);
    }else{
        cout << "Gagal delete relasi, list relasi kosong, di prosedur deletelast" << endl;
    }
}
void deleteAfterRelasi(list_relasi &L, address_relasi Prec){
    if(first(L) != nil && last(L) != nil && Prec != nil){
        address_relasi P = first(L);
        while(next(P) != nil && addressSiswa(P) != addressSiswa(Prec) && addressInstruktur(P) != addressInstruktur(Prec)){
            P = next(P);
        }
        if(addressSiswa(P) == addressSiswa(Prec) && addressInstruktur(P) == addressInstruktur(Prec)){
            if(P == last(L)){
                cout << "Gagal delete relasi, elemen dicari berada paling belakang, di prosedur deleteafter" << endl;
            }else if(next(P) == last(L)){
                deleteLastRelasi(L);
            }else{
                address_relasi q = next(P);
                next(P) = next(next(P));
                prev(next(P)) = P;
                next(q) = nil;
                prev(q) = nil;
                dealokasiRelasi(q);
            }
        }else{
            cout << "Gagal delete relasi, elemen dicari tidak ketemu, di prosedur deleteafter" << endl;
        }
    }else{
        cout << "Gagal delete relasi, list relasi kosong, di prosedur deleteafter" << endl;
    }
}
void deleteRelasi(list_relasi &L, infotype_relasi R){
    if(first(L) != nil && last(L)!= nil && R.siswa != nil && R.instruktur != nil){
        address_relasi P = findRelasi(L,R);
        if(P != nil){
            if(P == first(L)){
                deleteFirstRelasi(L);
            }else if(P == last(L)){
                deleteLastRelasi(L);
            }else{
                address_relasi prec = prev(P);
                deleteAfterRelasi(L,prec);
            }
        }else{
            cout << "Gagal delete relasi, elemen yang akan dihapus tidak ada di list" << endl;
        }
    }else{
        cout << "Gagal delete relasi, list siswa kosong" << endl;
    }
}
void printRelasi(list_relasi L){
    if(first(L) != nil && last(L) != nil){
        address_relasi q = first(L);
        int i = 1;
        while(q != nil){
            cout << "Relasi " << i << "." << endl;
            cout << "Nama siswa : " << infoNama(addressSiswa(q)) << endl;
            cout << "Nama instruktur : " << infoNama(addressInstruktur(q)) << endl;
            q = next(q);
            i++;
        }
    }else{
        cout << "List Relasi Kosong" << endl;
    }
}
address_relasi findRelasi(list_relasi L, infotype_relasi P){
    if(first(L) != nil && last(L) != nil && P.siswa != nil && P.instruktur != nil){
        address_relasi q = first(L);
        while(next(q) != nil && addressSiswa(q) != P.siswa && addressInstruktur(q) != P.instruktur){
            q = next(q);
        }
        if(addressSiswa(q) == P.siswa && addressInstruktur(q) == P.instruktur){
            return q;
        }else{
            return nil;
        }
    }else{
        return nil;
    }
}
