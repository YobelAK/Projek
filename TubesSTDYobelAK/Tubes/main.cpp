#include <iostream>
#include "header.h"

using namespace std;

int main()
{

    ////Menu Tiket
    int masukan = 9;
    listTiket LT;
    listPenumpang LP;
    adrTiket t;
    Tiket T;
    Penumpang P;
    adrPenumpang p;
    //==========================================================================
    createTiketList(LT);
    createPenumpangList(LP);
    while(masukan != 0){
        cout<<"~~~~Selamat datang di Traveloke~~~~"<<endl;
        cout<<"1. Menu Admin"<<endl;
        cout<<"2. Menu Penumpang"<<endl;
        cout<<"0. Keluar"<<endl;
        cout<<endl;
        cout<<"Input angka sesuai dengan aksi yang diinginkan :";cin>> masukan;
        if (masukan == 1){
            while(masukan !=9){
                cout<<"~~~~~~~~~~~~Menu Admin~~~~~~~~~~~~"<<endl;
                cout<<"1. Insert Tiket"<<endl;
                cout<<"2. Delete Tiket"<<endl;
                cout<<"3. Total Tiket Not Order"<<endl;
                cout<<"5. Menu Data"<<endl;
                cout<<"9. Kembali"<<endl;
                cout << endl;
                cout<<"Input angka sesuai dengan aksi yang diinginkan :";cin>> masukan;
                if (masukan == 1) {
                    cout <<" Masukkan jenis transportasi: ";cin >> T.jenis;
                    cout <<" Masukkan kota asal: ";cin >> T.asal;
                    cout <<" Masukkan kota tujuan: ";cin >> T.tujuan;
                    cout <<" Masukkan kapasitas transportasi: ";cin >> T.kapasitas;
                    cout <<" Masukkan harga tiket: ";cin >> T.harga;
                    t = createTiket(T);
                    insertTiket(LT,t);
                    showTiket(LT);
                }
                else if (masukan == 2) {
                    string jenis;
                    cout <<" Masukkan jenis transportasi yang ingin dihapus :";cin >> jenis;
                    deleteTiket(LT,jenis);
                    showTiket(LT);
                }
                else if (masukan == 3) {
                    cout << "Jumlah tiket yang tidak diorder : " << countTiketNotOrder(LP,LT) <<endl;
                }
                else if(masukan == 5) {
                    while(masukan != 9) {
                        cout<<"~~~~~~~~~~~~Menu Data~~~~~~~~~~~~"<<endl;
                        cout<<"1. Show Penumpang"<<endl;
                        cout<<"2. Show Penumpang By Jenis Tiket"<<endl;
                        cout<<"3. Show Penumpang Masing Masing Tiket"<<endl;
                        cout<<"4. Show Tiket by Nama"<<endl;
                        cout<<"5. Show Tiket Masing Masing Penumpang"<<endl;
                        cout<<"6. Count Total Booking by Tiket"<<endl;
                        cout<<"7. Count Total Booking by Penumpang"<<endl;
                        cout<<"9. Kembali"<<endl;
                        cout << endl;
                        cout<<"Input angka sesuai dengan aksi yang diinginkan :";cin>> masukan;
                        if(masukan == 1) {
                            ShowPenumpang(LP);
                        }
                        else if(masukan == 2) {
                            string jenis;
                            cout << "Masukkan jenis tiket yang ingin dilihat : ";cin >> jenis;
                            showPenumpangByJenisTiket(LT,LP,jenis);
                        }
                        else if(masukan == 3) {
                            showTiketBYPenumpang(LP,LT);
                        }
                        else if(masukan == 4) {
                            string nama;
                            cout << "Masukkan nama penumpang : ";cin >> nama;
                            showTiketByNama(LP,LT,nama);
                        }
                        else if(masukan == 5) {

                            showPenumpangByTiket(LP,LT);
                        }
                        else if(masukan == 6) {
                            string jenis;
                            cout << "Masukkan jenis tiket yang ingin dilihat : ";cin >> jenis;
                            t = findTiket(LT,jenis);
                            if(t!=NULL){
                                cout << "Jumlah Total Booking By Tiket : " << countTotalBookingByTiket(LP,t)<<endl;
                            }else {
                                cout<<"Tiket tidak ditemukan"<<endl;
                            }

                        }
                        else if(masukan == 7) {
                            cout << "Jumlah Total Booking By Penumpang : "<< countTotalBookingByParent(LP)<<endl;
                        }
                    }
                }
            }
        }
        else if (masukan == 2) {
            while (masukan != 9) {
                cout<<"~~~~~~~~~~~~Menu Penumpang~~~~~~~~~~~~"<<endl;
                cout<<"1. Booking Tiket"<<endl;
                cout<<"2. Cancel Booking"<<endl;
                cout<<"3. Reschudle"<<endl;
                cout<<"4. Delete User"<<endl;
                cout<<"0. Show Tiket"<<endl;
                cout<<"9. Kembali"<<endl;
                cout<<"Input angka sesuai dengan aksi yang diinginkan :";cin>> masukan;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                if(masukan == 1) {
                    string nama,jenis;
                    adrPenumpang c;
                    showTiket(LT);
                    cout<<endl;
                    cout <<" Masukkan Data Berikut " << endl;
                    cout <<"-----------------------" << endl;
                    cout <<"Nama : ";cin>> P.nama;
                    c=findPenumpang(LP,P.nama);
                    if(c!=NULL){
                        cout <<"Jenis Tiket : ";cin >> jenis;
                        t = findTiket(LT,jenis);
                        if(t!=NULL){
                            adrBooking b;
                            b = createBooking(t);
                            insertBooking(LP,c,b);

                            showTiketByNama(LP,LT,P.nama);
                        }else {
                            cout<<"Jenis yang dicari tidak ditemukan"<<endl;
                        }
                    }else {
                        cout <<"-----------------------" << endl;
                        cout<<"Akan dimasukkan data baru"<<endl;
                        cout <<"ID : ";cin>> P.id;
                        cout <<"Gender : ";cin>> P.gender;
                        cout <<"Umur : ";cin>> P.umur;
                        cout <<"Jenis Tiket : ";cin >> jenis;


                        p = createPenumpang(P);
                        insertPenumpang(LP,p);
                        t = findTiket(LT,jenis);
                        if(t!=NULL){

                            adrBooking b;
                            b = createBooking(t);
                            insertBooking(LP,p,b);

                            showTiketByNama(LP,LT,P.nama);
                        }else {

                            cout<<"Jenis yang dicari tidak ditemukan"<<endl;
                        }
                    }


                }
                else if(masukan == 2){
                    string nama,jenis;
                    bool ketemu =false;

                    cout << "Masukkan nama penumpang : ";cin >> nama;
                    p = findPenumpang(LP,nama);
                    cout << "Masukkan jenis tiket : ";cin >> jenis;
                    t = findTiket(LT,jenis);
                    if(t!=NULL){

                        deleteBooking(LP,p,t);
                        showTiketByNama(LP,LT,nama);
                    }else {
                        cout<<"Jenis yang dicari tidak ditemukan"<<endl;
                    }


                }
                else if(masukan == 3) {
                    adrTiket newT;
                    string nama,newJenis,jenis;
                    cout << "Masukkan nama penumpang : ";cin >> nama;
                    p = findPenumpang(LP,nama);
                    cout << "Masukkan jenis tiket sekarang : ";cin >> jenis;
                    t = findTiket(LT,jenis);
                    cout << "Masukkan jenis tiket baru : ";cin >> newJenis;
                    newT = findTiket(LT,newJenis);
                    if(t!=NULL&&p!=NULL &&newT!=NULL){
                        reschudle(LP,p,t,newT);
                        showTiketByNama(LP,LT,nama);
                    }else {
                        cout<<"Data tidak ditemukan"<<endl;
                    }
                }
                else if(masukan ==4) {
                    string nama;
                    cout << "Masukkan nama penumpang : ";cin >> nama;
                    deletePenumpang(LP,nama);
                    ShowPenumpang(LP);
                }
                else if(masukan == 0) {
                    showTiket(LT);
                }
            }
        }
    }
    cout<<"Silahkan kunjungi Traveloke kembali !!"<<endl;
}










