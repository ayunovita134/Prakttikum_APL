#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX_NARAPIDANA = 3;  

struct Narapidana {
  string nama;
  string nomor_identifikasi;
  string jenis_kejahatan;
  string tanggal_masuk_penjara;
  string jangka_waktu_hukuman;
  string status_kesehatan;
};

struct DataNarapidana {
  int jumlah_narapidana;
  Narapidana narapidana[MAX_NARAPIDANA];
};

DataNarapidana data_narapidana;

const string NAMA_BENAR = "Novita";
const string NIM_BENAR = "2309106134";

bool login() {
  int i = 0;
  string nama, NIM;

  while (i < 3) {
  	system ("cls") ;
    cout << "Masukkan nama: ";
    cin >> nama;
    cout << "Masukkan NIM: ";
    cin >> NIM;

    if (nama == NAMA_BENAR && NIM == NIM_BENAR) {
      cout << "Selamat, login berhasil!" << endl;
      return true;
    } else {
      cout << "Maaf, login gagal." << endl;
      i++;
    }
  }

  cout << "Anda telah mencapai batas percobaan login. Program berhenti." << endl;
  return false;
}

bool empty() {
  return data_narapidana.jumlah_narapidana == 0;
}

void add() {
  char loop;
  do {
  	system("cls");
  	if (data_narapidana.jumlah_narapidana < MAX_NARAPIDANA) {
      	cin.ignore();
      	cout << "Masukkan nama narapidana: ";
      	getline(cin, data_narapidana.narapidana[data_narapidana.jumlah_narapidana].nama);
      	cout << "Masukkan nomor identifikasi narapidana: ";
      	getline(cin, data_narapidana.narapidana[data_narapidana.jumlah_narapidana].nomor_identifikasi);
      	cout << "Masukkan jenis kejahatan: ";
      	getline(cin, data_narapidana.narapidana[data_narapidana.jumlah_narapidana].jenis_kejahatan);
      	cout << "Masukkan tanggal masuk penjara: ";
      	getline(cin, data_narapidana.narapidana[data_narapidana.jumlah_narapidana].tanggal_masuk_penjara);
      	cout << "Masukkan jangka waktu hukuman: ";
      	getline(cin, data_narapidana.narapidana[data_narapidana.jumlah_narapidana].jangka_waktu_hukuman);
      	cout << "Masukkan status kesehatan: ";
      	getline(cin, data_narapidana.narapidana[data_narapidana.jumlah_narapidana].status_kesehatan);

      	data_narapidana.jumlah_narapidana++;
    } else {
      cout << "==DATA NARAPIDANA SUDAH PENUH==" << endl;
    }

    cout << "Tambahkan data narapidana lain (y/t): ";
    cin >> loop;
  } while (loop == 'y');
}


void display() {
  if (!empty()) {
    char loop;
    do {
    	system ("cls") ;
      	cout << endl << "=== Daftar Narapidana ===" << endl;
      	for (int i = 0; i < data_narapidana.jumlah_narapidana; i++) {
        	cout << "Nama: " << data_narapidana.narapidana[i].nama << endl;
        	cout << "Nomor Identifikasi: " << data_narapidana.narapidana[i].nomor_identifikasi << endl;
        	cout << "Jenis Kejahatan: " << data_narapidana.narapidana[i].jenis_kejahatan << endl;
        	cout << "Tanggal Masuk Penjara: " << data_narapidana.narapidana[i].tanggal_masuk_penjara << endl;
        	cout << "Jangka Waktu Hukuman: " << data_narapidana.narapidana[i].jangka_waktu_hukuman << endl;
        	cout << "Status Kesehatan: " << data_narapidana.narapidana[i].status_kesehatan << endl;
        	cout << endl;
      	}

      	cout << "Tampilkan data narapidana lagi (y/t): ";
      	cin >> loop;
    	} while (loop == 'y');
  	} else {
  		system("cls"); 
    	cout << "==DATA NARAPIDANA KOSONG==" << endl;
  	}
}


void edit() {
  if (!empty()) {
    char loop;
    do {
    	system ("cls") ;
      	int index;
      	bool found = false;

      	cout << "Masukkan nomor narapidana yang ingin diubah: ";
      	cin >> index;

      	for (int i = 0; i < data_narapidana.jumlah_narapidana; i++) {
        	if (i + 1 == index) {
          	found = true;
          	cin.ignore();
          	cout << "Masukkan nama baru: ";
          	getline(cin, data_narapidana.narapidana[i].nama);
          	cout << "Masukkan nomor identifikasi baru: ";
          	getline(cin, data_narapidana.narapidana[i].nomor_identifikasi);
          	cout << "Masukkan jenis kejahatan baru: ";
          	getline(cin, data_narapidana.narapidana[i].jenis_kejahatan);
          	cout << "Masukkan tanggal masuk penjara baru: ";
          	getline(cin, data_narapidana.narapidana[i].tanggal_masuk_penjara);
          	cout << "Masukkan jangka waktu hukuman baru: ";
          	getline(cin, data_narapidana.narapidana[i].jangka_waktu_hukuman);
          	cout << "Masukkan status kesehatan baru: ";
          	getline(cin, data_narapidana.narapidana[i].status_kesehatan);
          	
          	
          	cout << "==Data narapidana berhasil diubah==" << endl;
          	break;
        	}
      	}

      if (!found) {
        cout << "Nomor narapidana tidak ditemukan." << endl;
      }

      cout << "Ubah data narapidana lain (y/t): ";
      cin >> loop;
    } while (loop == 'y');
  } else {
  	system ("cls") ;
    cout << "==DATA NARAPIDANA KOSONG==" << endl;
  }
}


void del() {
  if (!empty()) {
    char loop;
    do {
    	system("cls"); 
      	int index;
      	bool found = false;

      	cout << "Masukkan nomor narapidana yang ingin dihapus: ";
      	cin >> index;

      	for (int i = 0; i < data_narapidana.jumlah_narapidana; i++) {
        	if (i + 1 == index) {
          	found = true;
          	for (int j = i; j < data_narapidana.jumlah_narapidana - 1; j++) {
            	data_narapidana.narapidana[j] = data_narapidana.narapidana[j + 1];
          	}
          	data_narapidana.jumlah_narapidana--;
          	
          	cout << "==Data narapidana berhasil dihapus==" << endl;
          	break;
        }
      }

      if (!found) {
        cout << "Nomor narapidana tidak ditemukan." << endl;
      }

      cout << "Hapus data narapidana lain (y/t): ";
      cin >> loop;
    } while (loop == 'y');
  } else {
  	system("cls"); 
    cout << "==DATA NARAPIDANA KOSONG==" << endl;
  }
}


int main() {
  if (!login()) {
    cout << "Login gagal. Program berhenti." << endl;
    return 0;
  }

  int pilihan;
  do {
    cout << "::: DATA NARAPIDANA :::" << endl;
    cout << "-----------------------" << endl;

    cout << "[1]. Tambahkan data narapidana " << endl;
    cout << "[2]. Tampilkan data narapidana " << endl;
    cout << "[3]. Ubah data narapidana " << endl;
    cout << "[4]. Hapus data narapidana " << endl;
    cout << "[5]. Keluar" << endl;

    cout << "Pilih Menu: ";
    cin >> pilihan;

    switch(pilihan) {
      case 1 :
        add();
        break;
      case 2 :
        display();
        break;
      case 3 :
        edit();
        break;
      case 4 :
        del();
        break;
      case 5 :
        cout << "Keluar. " << endl ;
        break;
      default :
        cout << "Pilihan tidak valid." << endl ;
        break;
    }
    
    cout << "Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get(); 
    
  } while (pilihan != 5) ;

  cout << "PROGRAM SELESAI..." << endl;
  return 0;
}

