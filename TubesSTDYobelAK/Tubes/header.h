#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>>
#define first(L) L.first
#define last(L) L.last
#define infoPenumpang(P) P->infoPenumpang
#define nextPenumpang(P) P->nextPenumpang

#define Tiket(p) p->Tiket
#define infoTiket(p) p->infoTiket
#define nextTiket(P) P->nextTiket
#define prevTiket(p) p->prevTiket
#define nextBooking(P) P->nextBooking
#define prevBooking(p) p->prevBooking
#define Booking(p) p->Booking
#define isEmpty(L) (first(L) == NULL)
using namespace std;

struct Penumpang {
    string id, nama, gender;
    int jumlaht;
    int umur;
};

struct Tiket {
    string tujuan, asal, jenis;
    int kapasitas;
    float harga;
};

typedef struct elmPenumpang *adrPenumpang;
typedef struct elmTiket *adrTiket;
typedef struct elmBooking *adrBooking;

struct elmPenumpang {
    Penumpang infoPenumpang;
    adrPenumpang nextPenumpang;
    adrBooking Booking;
};

struct listPenumpang {
    adrPenumpang first;
};

struct elmTiket {
    Tiket infoTiket;
    adrTiket nextTiket,prevTiket;
};

struct listTiket {
    adrTiket first,last;
};

struct elmBooking {
    adrBooking nextBooking,prevBooking;
    adrTiket Tiket;
};

void createPenumpangList(listPenumpang &LP);
adrPenumpang createPenumpang(Penumpang P);
void insertPenumpang(listPenumpang &LP,adrPenumpang P);
void deleteFirstPenumpang(listPenumpang &LP,adrPenumpang &P);
void deleteLastPenumpang(listPenumpang &LP,adrPenumpang &P);
void deleteAfterPenumpang(listPenumpang &LP,adrPenumpang Prec,adrPenumpang &P);
void deletePenumpang(listPenumpang &LP,string nama);
adrPenumpang findPenumpang(listPenumpang LP,string nama);
void ShowPenumpang(listPenumpang LP);
void showPenumpangByJenisTiket(listTiket LT, listPenumpang LP, string jenis);
void showPenumpangByTiket(listPenumpang LP,listTiket LT);

void createTiketList(listTiket &LT);
adrTiket createTiket(Tiket T);
void insertTiket(listTiket &LT,adrTiket T);
void deleteFirstTiket(listTiket &LT,adrTiket &T);
void deleteLastTiket(listTiket &LT,adrTiket &T);
void deleteAfterTiket(listTiket &LT,adrTiket Prec,adrTiket &T);
void deleteTiket(listTiket &LT,string jenis);
adrTiket findTiket(listTiket LT,string jenis);
void showTiket(listTiket LT);
void showTiketByNama(listPenumpang LP, listTiket LT,string nama);
void showTiketBYPenumpang(listPenumpang LP,listTiket LT);
int countTiketNotOrder(listPenumpang LP,listTiket LT);

adrBooking createBooking(adrTiket T);
void insertBooking(listPenumpang &LP, adrPenumpang P,adrBooking B);
void deleteFirstBooking(listPenumpang &LP,adrPenumpang P,adrBooking &B);
void deleteLastBooking(listPenumpang &LP,adrPenumpang P,adrBooking &B);
void deleteAfterBooking(listPenumpang &LP,adrPenumpang P,adrBooking Prec, adrBooking &B);
void deleteBooking(listPenumpang &LP,adrPenumpang P, adrTiket T);
adrBooking findBookingByNamaDanTiket(listPenumpang &LP, adrPenumpang P, adrTiket T);
void reschudle(listPenumpang &LP, adrPenumpang &P,adrTiket T,adrTiket newT);
int countTotalBookingByParent(listPenumpang &LP);
int countTotalBookingByTiket(listPenumpang &LP, adrTiket T);



#endif // HEADER_H_INCLUDED
