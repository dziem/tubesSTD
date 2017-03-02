#include "list_instruktur.h"

void createListInstruktur(list_instruktur &L){
    first(L) = nil;
}
address_instruktur alokasiInstruktur(infotype_instruktur info){
    address_instruktur q = new elmlist_instruktur;
    infoNama(q) = info.nama;
    infoTelp(q) = info.telp;
    next(q) = nil;
    return q;
}
address_instruktur dealokasiInstruktur(address_instruktur P){
    delete P;
}
void insertInstruktur(list_instruktur &L, address_instruktur P){
    if(first(L) != nil){
        next(P) = first(L);
        first(L) = P;
    }else{
        first(L) = P;
    }
}
void deleteFirstInstruktur(list_instruktur &L){
    if(first(L) != nil){
        address_instruktur P = first(L);
        first(L) = next(first(L));
        next(P) = nil;
        dealokasiInstruktur(P);
    }else{
        cout << "Tidak bisa hapus instruktur, list kosong, di prosedur deletefirst" << endl;
    }
}
void deleteLastInstruktur(list_instruktur &L){
    if(first(L) != nil){
        address_instruktur P = first(L);
        while(next(next(P)) != nil){
            P = next(P);
        }
        address_instruktur q = next(P);
        next(P) = nil;
        next(q) = nil;
        dealokasiInstruktur(q);
    }else{
        cout << "Tidak bisa hapus instruktur, list kosong, di prosedur deletelast" << endl;
    }
}
void deleteAfterInstruktur(list_instruktur &L, address_instruktur prec){
    if(first(L) != nil && prec != nil){
        address_instruktur q = first(L);
        while(next(q) != nil && infoNama(q) != infoNama(prec) && infoTelp(q) != infoTelp(prec)){
            q = next(q);
        }
        if(infoNama(q) == infoNama(prec) && infoTelp(q) == infoTelp(prec)){
            if(next(q) == nil){
                cout << "Gagal delete instruktur, elemen dicari berada paling belakang, di prosedur deleteafter" << endl;
            }
            else if(next(next(q)) == nil){
                deleteLastInstruktur(L);
            }else{
                address_instruktur r = q;
                next(q) = next(next(q));
                next(r) = nil;
                dealokasiInstruktur(r);
            }
        }else{
            cout << "Gagal delete instruktur, elemen dicari tidak ketemu, di prosedur deleteafter" << endl;
        }
    }else{
        cout << "Gagal delete instruktur, list kosong, di prosedur deleteafter" << endl;
    }
}
void deleteInstruktur(list_instruktur &L, infotype_instruktur R){
    if(first(L) != nil && R.nama != "" && R.telp != ""){
        address_instruktur P = findInstruktur(L, R);
        if(P != nil){
            if(P == first(L)){
                deleteFirstInstruktur(L);
            }else if(next(P) == nil){
                deleteLastInstruktur(L);
            }else{
                address_instruktur q = first(L);
                while(next(q) != P){
                    q = next(q);
                }
                deleteAfterInstruktur(L,q);
            }
        }else{
            cout << "Gagal delete instruktur, elemen yang akan dihapus tidak ada di list" << endl;
        }
    }else{
        cout << "Gagal delete instrukrur, list sudah kosong" << endl;
    }
}
void printInstruktur(list_instruktur L){
    if(first(L) != nil){
        address_instruktur q = first(L);
        int i = 1;
        while(q != nil){
            cout << "Instruktur " << i << "." << endl;
            cout << "Nama : " << infoNama(q) << endl;
            cout << "Telp. : " << infoTelp(q) << endl;
            q = next(q);
            i++;
        }
    }else{
        cout << "List Siswa Kosong" << endl;
    }
}
address_instruktur findInstruktur(list_instruktur L, infotype_instruktur P){
    if(first(L) != nil && P.nama != "" && P.telp != ""){
        address_instruktur q = first(L);
        while(next(q) != nil &&  infoNama(q) != P.nama && infoTelp(q) != P.telp){
            q = next(q);
        }
        if(infoNama(q) == P.nama && infoTelp(q) == P.telp){
            return q;
        }else{
            return nil;
        }
    }else{
        return nil;
    }
}
