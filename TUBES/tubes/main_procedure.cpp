#include "main_procedure.h"

int menu(){
    bool stop = false;
    int i;
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
void aksimenu(int menu, int sub){
    switch(menu){
    case 1:
        switch(sub){
        case 1:
            cout << "insert instruktur" << endl;
        break;
        case 2:
            cout << "insert siswa" << endl;
        break;
        case 3:
            cout << "insert relasi" << endl;
        break;
        }
    break;
    case 2:
        switch(sub){
        case 1:
            cout << "delete instruktur" << endl;
        break;
        case 2:
            cout << "delete siswa" << endl;
        break;
        case 3:
            cout << "delete relasi" << endl;
        break;
        }
    break;
    case 3:
        switch(sub){
        case 1:
            cout << "find instruktur" << endl;
        break;
        case 2:
            cout << "find siswa" << endl;
        break;
        case 3:
            cout << "find relasi" << endl;
        break;
        }
    break;
    case 4:
        switch(sub){
        case 1:
            cout << "print instruktur" << endl;
        break;
        case 2:
            cout << "print siswa" << endl;
        break;
        case 3:
            cout << "print relasi" << endl;
        break;
        }
    break;
    }
}
void tampilmenu(){
    int i,j;
    bool stop = false;
    do{
        i = menu();
        if(i != 0){
            j = submenu();
            if(j != 0){
                aksimenu(i,j);
            }
        }else{
            stop = true;
        }
    }while(stop != true);
}
