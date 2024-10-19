#include "header.h"
#include <iostream>


void createPenumpangList(listPenumpang &LP){
    first(LP) = NULL;
}
adrPenumpang createPenumpang(Penumpang P){
    adrPenumpang p;
    p = new elmPenumpang;
    infoPenumpang(p) = P;
    nextPenumpang(p) = NULL;
    Booking(p) = NULL;


    return p;
}
void insertPenumpang(listPenumpang &LP,adrPenumpang P){
    adrPenumpang x;
    x = first(LP);
    if (isEmpty(LP)== true) {
        first(LP) = P;
    }
    else {
        while (nextPenumpang(x) != NULL) {
            x = nextPenumpang(x);
        }
        nextPenumpang(x) = P;
    }
}
void deleteFirstPenumpang(listPenumpang &LP, adrPenumpang &P) {
    if (first(LP) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        P = first(LP);
        if (nextPenumpang(P) == NULL) {
            first(LP) = NULL;
        } else {
            first(LP) = nextPenumpang(P);
            nextPenumpang(P) = NULL;
        }
    }
}
void deleteLastPenumpang(listPenumpang &LP, adrPenumpang &P){
    if (first(LP) == NULL) {
        cout << "List Kosong" << endl;
    } else if (nextPenumpang(first(LP)) == NULL) {
        P = first(LP);
        first(LP) = NULL;
    } else {
        adrPenumpang x = first(LP);
        while (nextPenumpang(nextPenumpang(x)) != NULL) {
            x = nextPenumpang(x);
        }
        P = nextPenumpang(x);
        nextPenumpang(x) = NULL;
    }
}


void deleteAfterPenumpang(listPenumpang &LP,adrPenumpang Prec,adrPenumpang &P){
    P=nextPenumpang(Prec);
    nextPenumpang(Prec)=nextPenumpang(P);
    nextPenumpang(P)=NULL;
}
void deletePenumpang(listPenumpang &LP,string nama){
    adrPenumpang p =findPenumpang(LP,nama);
    if(p==NULL){
        cout<<"Nama penumpang tidak ditemukan"<<endl;
    }else if(isEmpty(LP)){
        cout<<"Tidak terdapat penumpang"<<endl;
    }else {
        adrPenumpang x,Prec;
        if(p==first(LP)){
            deleteFirstPenumpang(LP,x);
        }else if (nextPenumpang(p)==NULL){
            deleteLastPenumpang(LP,x);
        }else {
            Prec=first(LP);
            while(nextPenumpang(Prec)!=p){
                Prec=nextPenumpang(Prec);
            }
            deleteAfterPenumpang(LP,Prec,x);
        }
    }

}
adrPenumpang findPenumpang(listPenumpang LP,string nama){
    adrPenumpang x;
    if(isEmpty(LP)){
        cout<<"Tidak ada data penumpang"<<endl;
        return NULL;
    }else {
        x=first(LP);
        while(x!=NULL){
            if(infoPenumpang(x).nama==nama){
                return x;
            }
            x=nextPenumpang(x);
        }
        return NULL;
    }

}
void ShowPenumpang(listPenumpang LP){
    adrPenumpang x;
    if(isEmpty(LP)){
        cout<<"Tidak terdapat penumpang"<<endl;
    }else {
        x=first(LP);
        while(x!=NULL){
            cout<<"~~~~~~~~~PENUMPANG~~~~~~~~~"<<endl;
            cout<<"ID : "<<infoPenumpang(x).id<<endl;
            cout<<"NAMA : "<<infoPenumpang(x).nama<<endl;
            cout<<"GENDER : "<<infoPenumpang(x).gender<<endl;

            cout<<"UMUR : "<<infoPenumpang(x).umur<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            x=nextPenumpang(x);
        }
    }
}
void showPenumpangByJenisTiket(listTiket LT, listPenumpang LP, string jenis){
    //show penumpang dari 1 jenis tiket
    adrTiket t = findTiket(LT, jenis);
    adrPenumpang p = first(LP);

    if (t == NULL) {
        cout << "Jenis tiket yang dicari tidak ditemukan" << endl;
    } else if (isEmpty(LP)) {
        cout << "Tidak ada penumpang" << endl;
    } else {
        bool found = false; // Tambahkan variabel boolean untuk mengecek apakah ada penumpang dengan jenis tiket yang dicari

        while (p != NULL) {
            if (findBookingByNamaDanTiket(LP, p, t) != NULL) {
                cout << "~~~~~~~~~PENUMPANG~~~~~~~~~" << endl;
                cout << "ID : " << infoPenumpang(p).id << endl;
                cout << "NAMA : " << infoPenumpang(p).nama << endl;
                cout << "GENDER : " << infoPenumpang(p).gender << endl;

                cout << "UMUR : " << infoPenumpang(p).umur << endl;
                found = true; // Setel found menjadi true karena ada penumpang dengan jenis tiket yang dicari
            }
            p = nextPenumpang(p);
        }

        if (!found) {
            cout << "Tidak ada penumpang dengan jenis tiket " << jenis << endl;
        }
    }
}
void showTiketBYPenumpang(listPenumpang LP,listTiket LT){
    //menampilkan tiket dari masing masing penumpang
   if (isEmpty(LP) || isEmpty(LT)) {
        cout << "List Kosong" << endl;
    } else {
        adrPenumpang p = first(LP);

        while (p != NULL) {
            cout << "~~~~~~~~~PENUMPANG~~~~~~~~~" << endl;
            cout << "ID : " << infoPenumpang(p).id << endl;
            cout << "NAMA : " << infoPenumpang(p).nama << endl;
            cout << "GENDER : " << infoPenumpang(p).gender << endl;
            cout << "UMUR : " << infoPenumpang(p).umur << endl;

            adrBooking b = Booking(p);
            if(b!=NULL){
                adrTiket t = Tiket(b);

                cout << "~~~~~~~~TIKET~~~~~~~~" << endl;
                cout << "Jenis Tiket :" << infoTiket(t).jenis << endl;
                cout << "Asal : " << infoTiket(t).asal << endl;
                cout << "Tujuan : " << infoTiket(t).tujuan << endl;

                b = nextBooking(b);
            }
            while (b != Booking(p)) {
                adrTiket t = Tiket(b);

                cout << "~~~~~~~~TIKET~~~~~~~~" << endl;
                cout << "Jenis Tiket :" << infoTiket(t).jenis << endl;
                cout << "Asal : " << infoTiket(t).asal << endl;
                cout << "Tujuan : " << infoTiket(t).tujuan << endl;

                b = nextBooking(b);
            }

            p = nextPenumpang(p);
        }
    }
}

void createTiketList(listTiket &LT){
    first(LT) = NULL;
    last(LT) = NULL;
}
adrTiket createTiket(Tiket T){
    adrTiket t = new elmTiket;
    nextTiket(t) = NULL;
    prevTiket(t) = NULL;
    infoTiket(t) = T;

    return t;
}
void insertTiket(listTiket &LT,adrTiket T){
    if (isEmpty(LT) == true) {
        first(LT) = T;
        last(LT) = T;
    }
    else {
        nextTiket(last(LT)) = T;
        prevTiket(T) = last(LT);
        last(LT) = T;
    }
}
void deleteFirstTiket(listTiket &LT,adrTiket &T){
    if (isEmpty(LT) == true) {
        cout<<"List Kosong"<<endl;
    }else if (nextTiket(first(LT))==NULL){
        first(LT) = NULL;
        last(LT) = NULL;
    }else {
        T=first(LT);
        first(LT)=nextTiket(T);
        nextTiket(T)=NULL;
        prevTiket(first(LT))=NULL;
    }
}

void deleteLastTiket(listTiket &LT,adrTiket &T){
    if (isEmpty(LT) == true) {
        cout<<"List Kosong"<<endl;
    }else if (next(first(LT))==NULL){
        first(LT) = NULL;
        last(LT) = NULL;
    }else {
        T=last(LT);
        last(LT)=prevTiket(T);
        prevTiket(T)=NULL;
        nextTiket(last(LT))=NULL;
    }
}
void deleteAfterTiket(listTiket &LT,adrTiket Prec,adrTiket &T){
    T=nextTiket(Prec);
    nextTiket(Prec)=nextTiket(T);
    prevTiket(nextTiket(T))=Prec;
    nextTiket(T)=NULL;
    prevTiket(T)=NULL;
}
void deleteTiket(listTiket &LT,string jenis){
    if(isEmpty(LT)){
        cout<<"List Kosong"<<endl;
    }else {
        adrTiket p,Prec;
        p=findTiket(LT,jenis);
        if(p==first(LT)){
            deleteFirstTiket(LT,p);
        }else if (last(LT)==p){
            deleteLastTiket(LT,p);
        }else {
            Prec=first(LT);
            while(nextTiket(Prec)!=p){
                Prec=nextTiket(Prec);
            }
            deleteAfterTiket(LT,Prec,p);
        }
    }
}
adrTiket findTiket(listTiket LT,string jenis){
    adrTiket T;
    T=first(LT);
    while(T!=NULL){
        if(infoTiket(T).jenis==jenis){
            return T;
        }
        T=nextTiket(T);
    }
    return NULL;
}
void showTiket(listTiket LT){
    adrTiket x;
    if(isEmpty(LT)){
        cout<<"~~~~~~~~~~~TIKET~~~~~~~~~~~"<<endl;
        cout<<"Tidak ada tiket yang tersedia"<<endl;
    }else {
        x=first(LT);
        while(x!=NULL){
            cout<<"~~~~~~~~~~~TIKET~~~~~~~~~~~"<<endl;
            cout<<"TUJUAN : "<<infoTiket(x).tujuan<<endl;
            cout<<"ASAL : "<<infoTiket(x).asal<<endl;
            cout<<"JENIS TRANSPORTASI : "<<infoTiket(x).jenis<<endl;
            cout<<"KAPASITAS : "<<infoTiket(x).kapasitas<<endl;
            cout<<"HARGA : RP. "<<infoTiket(x).harga<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            x=nextTiket(x);
        }
    }
}

void showTiketByNama(listPenumpang LP, listTiket LT,string nama){
    //show tiket berdasarkan nama
    adrPenumpang p=findPenumpang(LP,nama);
     if (p == NULL) {
        cout << "Penumpang yang dicari tidak ditemukan" << endl;
    } else if (isEmpty(LT)) {
        cout << "Tidak ada tiket" << endl;
    } else {
        adrTiket t = first(LT);
        adrPenumpang p = findPenumpang(LP,nama);
        cout << "~~~~~~~~~Penumpang~~~~~~~~~" << endl;
        cout << "Nama :" << infoPenumpang(p).nama<<endl;

        while(t!=NULL){
            if(findBookingByNamaDanTiket(LP,p,t)!=NULL){
                cout<<"~~~~~~~~~~~TIKET~~~~~~~~~~~"<<endl;
                cout<<"TUJUAN : "<<infoTiket(t).tujuan<<endl;
                cout<<"ASAL : "<<infoTiket(t).asal<<endl;
                cout<<"JENIS TRANSPORTASI : "<<infoTiket(t).jenis<<endl;
                cout<<"KAPASITAS : "<<infoTiket(t).kapasitas<<endl;
                cout<<"HARGA : RP."<<infoTiket(t).harga<<endl;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            }
            t=nextTiket(t);
        }
    }
}
void showPenumpangByTiket(listPenumpang LP,listTiket LT){
    //show tiket dengan penumpangnya
   if (isEmpty(LT)) {
        cout << "Tidak ada tiket" << endl;
    } else if (isEmpty(LP)) {
        cout << "Tidak ada penumpang" << endl;
    } else {
        adrTiket t = first(LT);
        while (t != NULL) {
            cout << "~~~~~~~~~~~TIKET~~~~~~~~~~~" << endl;
            cout << "TUJUAN : " << infoTiket(t).tujuan << endl;
            cout << "ASAL : " << infoTiket(t).asal << endl;
            cout << "JENIS TRANSPORTASI : " << infoTiket(t).jenis << endl;
            cout << "KAPASITAS : " << infoTiket(t).kapasitas << endl;
            cout << "HARGA : RP. " << infoTiket(t).harga << endl;

            adrPenumpang p = first(LP);
            bool penumpangDitemukan = false;

            while (p != NULL) {
                if (findBookingByNamaDanTiket(LP, p, t) != NULL) {
                    if (!penumpangDitemukan) {
                        cout << "Penumpang yang memesan:" << endl;
                        penumpangDitemukan = true;
                    }
                    cout << "  - " << infoPenumpang(p).nama << endl;
                }
                p = nextPenumpang(p);
            }

            if (!penumpangDitemukan) {
                cout << "Tidak ada penumpang yang memesan tiket ini." << endl;
            }

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            t = nextTiket(t);
        }
    }
}
int countTiketNotOrder( listPenumpang LP, listTiket LT) {
    //hitung jumlah tiket yang belum di order
    int i = 0;
    if (isEmpty(LT)) {
        cout << "Tidak ada tiket" << endl;
    } else if (isEmpty(LP)) {
        cout << "Tidak ada penumpang" << endl;
    } else {
        adrTiket t = first(LT);
        while (t != NULL) {
            adrPenumpang p = first(LP);
            bool found = false;
            while (p != NULL) {
                if (findBookingByNamaDanTiket(LP, p, t) != NULL) {
                    found = true;
                    break;
                }
                p = nextPenumpang(p);
            }
            if (!found) {
                i++;
            }
            t = nextTiket(t);
        }
    }
    return i;
}

adrBooking createBooking(adrTiket T){
    //mengembalikan adr booking yang telah dimasukkan addres t
    adrBooking b = new elmBooking;
    Tiket(b) = T;
    nextBooking(b) = NULL;
    prevBooking(b) = NULL;
    return b;
}
void insertBooking(listPenumpang &LP, adrPenumpang P,adrBooking B){
    if(Booking(P) == NULL) {
        Booking(P) = B;
        nextBooking(B) = B;
        prevBooking(B) = B;
    }
    else {
        adrBooking bk = Booking(P);
        while(nextBooking(bk) != Booking(P)){
            bk=nextBooking(bk);
        }
        nextBooking(bk)=B;
        prevBooking(B)=bk;
        nextBooking(B)=Booking(P);
        prevBooking(Booking(P))=B;
    }

}
void deleteFirstBooking(listPenumpang &LP,adrPenumpang P,adrBooking &B){
    if(Booking(P) == NULL) {
        cout << "List Booking Kosong" << endl;
    }
    else if(nextBooking(Booking(P)) == Booking(P)) {
        B=Booking(P);
        Booking(P)=NULL;
    }else {
        adrBooking bk = Booking(P);
        while(nextBooking(bk) != Booking(P)){
            bk=nextBooking(bk);
        }
        B=Booking(P);
        Booking(P)=nextBooking(B);
        nextBooking(B)=NULL;
        prevBooking(B)=NULL;
        prevBooking(Booking(P))=bk;
        nextBooking(bk)=Booking(P);
    }
}
void deleteLastBooking(listPenumpang &LP,adrPenumpang P,adrBooking &B){
    if (Booking(P) == NULL) {
        cout << "List Booking Kosong" << endl;
    } else if (nextBooking(Booking(P)) == Booking(P)) {
        B = Booking(P);
        Booking(P) = NULL;
    } else {
        adrBooking bk = Booking(P);
        while (nextBooking(nextBooking(bk)) != Booking(P)) {
            bk = nextBooking(bk);
        }
        B = nextBooking(bk);
        nextBooking(bk) = Booking(P);
        prevBooking(B) = NULL;
        nextBooking(B) = NULL;
        prevBooking(Booking(P)) = bk;
    }
}
void deleteAfterBooking(listPenumpang &LP,adrPenumpang P,adrBooking Prec, adrBooking &B){
    if (Booking(P) == NULL || Prec == NULL || Prec == NULL) {
        cout << "List Booking Kosong atau Prec tidak valid" << endl;
    } else {
        B = nextBooking(Prec);
        if (B != Booking(P)) {
            nextBooking(Prec) = nextBooking(B);
            prevBooking(nextBooking(B)) = Prec;
            nextBooking(B) = NULL;
            prevBooking(B) = NULL;
        } else {
            cout << "Prec berada di akhir list Booking" << endl;
        }
    }
}
void deleteBooking(listPenumpang &LP,adrPenumpang P, adrTiket T){
    if(isEmpty(LP)){
        cout<<"List Kosong"<<endl;
    }else {
        adrBooking c,x,Prec;
        x = Booking(P);
        while(nextBooking(x) != Booking(P)) {
            x = nextBooking(x);
        }
        c=findBookingByNamaDanTiket(LP,P,T);
        if (c != NULL) {
            if (c == Booking(P)) {
                deleteFirstBooking(LP, P, c);
            } else if (c == x) {
                deleteLastBooking(LP, P, c);
            } else {
                Prec = Booking(P);
                while (nextBooking(Prec) != c) {
                    Prec = nextBooking(Prec);
                }
                deleteAfterBooking(LP, P, Prec, c);
            }
        } else {
            cout << "Booking tidak ditemukan" << endl;
        }
    }
}
adrBooking findBookingByNamaDanTiket(listPenumpang &LP, adrPenumpang P, adrTiket T){

    if (Booking(P) == NULL) {
        return NULL;
    } else {
        adrBooking b = Booking(P);
        do {
            if (Tiket(b) == T) {
                return b;
            }
            b = nextBooking(b);
        } while (b != Booking(P));
        return NULL;
    }
}
void reschudle(listPenumpang &LP, adrPenumpang &P,adrTiket T,adrTiket newT){
     if (Booking(P) != NULL) {
        adrBooking b = findBookingByNamaDanTiket(LP, P, T);
        if (b != NULL) {
            Tiket(b) = newT;
        } else {
            cout << "Booking tidak ditemukan" << endl;
        }
    } else {
        cout << "Penumpang tidak memiliki booking" << endl;
    }
}
int countTotalBookingByParent(listPenumpang &LP){
    int i = 0;
    adrPenumpang p = first(LP);

    while (p != NULL) {
        adrBooking b = Booking(p);
        do {
            i++;
            b = nextBooking(b);
        } while (b != Booking(p));

        p = nextPenumpang(p);
    }

    return i;
}
int countTotalBookingByTiket(listPenumpang &LP, adrTiket T){
    int i = 0;
    adrPenumpang p = first(LP);

    while (p != NULL) {
        if (findBookingByNamaDanTiket(LP, p, T) != NULL) {
            i++;
        }
        p = nextPenumpang(p);
    }

    return i;
}
/*
1
1
Pesawat
jakarta
bali
75
100000
1
Kapal
Palembang
TanjungPeriuk
125
75000
1
Bus
Jakarta
Bandung
30
35000
1
Kereta
Jakarta
Yogyakarta
175
90000


dhio
1
L
19
Pesawat
1
yobel
2
L
19
Pesawat
1
dhio
Kereta
1
rifqi
3
L
19
Kapal
*/
