#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#define MAX 10
using namespace std;

struct Cpu{
	string namaCpu;
	long int hargaBarang;
};

class Stack {
	public:
		Stack() : top(0) {}
		bool isFull();
		bool isEmpty();
		void tambahCpu(string namaCpu, long int hargaBarang);
		void hapusCpu();
		void tampilCpu();
		
		
    private:
        Cpu stack[MAX];
        int top;
};

bool Stack::isFull(){
	return top == MAX;
}

bool Stack::isEmpty(){
	return top == 0;
}

void Stack::tambahCpu(string namaCpu, long int hargaBarang){
    if (!isFull()) {
        stack[top].namaCpu = namaCpu;
        stack[top].hargaBarang = hargaBarang;
        top++;
    } else {
        cout << "Barang penuh !!" << endl;
    }
}

void Stack::hapusCpu(){
	if (!isEmpty()) {
        top--;
        cout << "Data " << stack[top].namaCpu << " Rp. " << stack[top].hargaBarang << " dihapus" << endl;
	} else {
        cout << "Barang kosong !!" << endl;
    }
}

void Stack::tampilCpu(){
	cout << "ANTRIAN BARANG: " << endl;
        for (int i = top - 1; i >= 0; i--) {
            cout << "Nama Barang: " << stack[i].namaCpu<< ", hargaBarang: " << stack[i].hargaBarang << endl;
        }
}

class Login{
	public:
		void awal();
		void belumPunyaAkun();
		void punyaAkun();
		void adminLogin();
		void loginPembeli();
		
	private:
		string nama;
		string noTelp;
		string alamat;
		string email;
		string idPelanggan;
		string idAdmin;
		string pwAdmin;
		string pwPelanggan;
		string IdPelanggan;
		string PwPelanggan;
		char kelamin;
		char pilDaftar;
		int pilLog;
		int pilAkun;
		
};

class MenuAwal{
	public:
		void tampilAwal();
		void bagianKomputer();
		
		void cariCpu();
		
	private:
		string namaCpu;
		int pilMenu;
		int pilBagian;	
		char barangPilih;
			Cpu listCpu[MAX] = {
			{"Intel Core i7-12700", 239000},
			{"Intel Core i5 12400F", 279000},
			{"Intel Core i9-10900K", 359000},
		};
};

void Login::awal(){
	MenuAwal menuAwal;
	
	idAdmin = "admin";
	pwAdmin = "admin";
  cout << "====Selamat Datang di toko Tata Surya Komputer kami====" << endl;
  cout << " " << endl;
  cout << "|==========~~======<<<^>>>======~~==========|" << endl;
  cout << "|         1. Login sebagai admin            |" << endl;
  cout << "|         2. Login sebagai pembeli          |" << endl;
  cout << "|==========~~======<<<_>>>======~~==========|" << endl;
  cout << "\tPilih : ";
  cin >> pilLog;
  cout << "|==========~~======<<< >>>======~~==========|\n" << endl;

  switch (pilLog) {
  case 1:
    adminLogin();
    break;
  case 2:
    loginPembeli();
    break;
  default:
    cout << "Pilihan tidak tersedia" << endl;
    break;
  }
}

void Login::adminLogin(){
	
}

void Login::loginPembeli(){
	cout << "Selamat datang di toko komputer\n";
	cout << "Apakah sudah punya akun atau belum ? : \n";
	cout << "1. Sudah\n";
	cout << "2. Belum\n";
	cout << "Masukkan pilihan: "; cin >> pilAkun;
	
	if(pilAkun == 1){
		punyaAkun();
	} else if (pilAkun == 2) {
		belumPunyaAkun();
	} 
}

void Login::belumPunyaAkun(){
	cin.ignore();
	cout << "Silakkan daftarkan data diri anda\n";
	cout << "Masukkan nama panjang: "; getline(cin,nama);
	cout << "Masukkan no telphone: "; cin >> noTelp;
	cin.ignore();
	cout << "Masukkan alamat: "; getline(cin,alamat);
	cout << "Masukkan email : "; cin >> email;
	cout << "Pilih kelamin(L/P): "; cin >> kelamin;
	if(kelamin == 'L' || kelamin == 'l' ){
		cout << "LAKI - LAKI\n";
	} else if (kelamin == 'P' || kelamin == 'p'){
		cout << "PEREMPUAN\n";
	} else {
		cout << "Pilihan tidak tersedia\n";
	}
	cout << "Buat ID baru : "; cin >> idPelanggan;
	cout << "Buat password baru : "; cin >> pwPelanggan;
	cout << endl;
	loginPembeli();
}

void Login::punyaAkun(){
	MenuAwal menuAwal;
	cout << "Masukkan ID : "; cin >> IdPelanggan;
	cout << "Masukkan password : "; cin >> PwPelanggan;
	if (idPelanggan == IdPelanggan && pwPelanggan == PwPelanggan){
		cout << "Selamat Id & Pw anda benar\n";
		cout << endl;
		menuAwal.tampilAwal();
	} else if (idAdmin == IdPelanggan && pwAdmin == PwPelanggan){
		cout << "Selamat Id & Pw anda benar\n";
		cout << endl;
		menuAwal.tampilAwal();
	} else{
	cout << "Password Anda Salah" << endl;
    cout << "Apakah ingin mendaftar terlebih dahulu ? (y/n) : ";
    cin >> pilDaftar;
    cout << endl;
    if (pilDaftar == 'y' || pilDaftar == 'Y') {
      belumPunyaAkun();
    } else if (pilDaftar == 'n'|| pilDaftar == 'N') {
      punyaAkun();
    } else {
      cout << "Pilihan tidak tersedia" << endl;
    	}
	}
}

void MenuAwal::cariCpu(){
    cout << "Masukkan nama CPU yang dicari: ";
    cin.ignore();
    getline(cin, namaCpu);
	cout << endl;
	
    bool ditemukan = false;
    for (int i = 0; i < MAX; i++) {
        if (listCpu[i].namaCpu == namaCpu) {
        	cout << "Barang di temukan" << endl;
            cout << "Nama CPU: " << listCpu[i].namaCpu << endl;
            cout << "Harga: " << listCpu[i].hargaBarang << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "CPU tidak ditemukan!" << endl;
    }
}

void MenuAwal::bagianKomputer(){
	cout << "Bagian komputer: \n";
	cout << "1. CPU \n";
	cout << "2. VGA \n";
	cout << "3. PROSESOR \n";
	cout << "4. PSU \n";
	cout << "5. Motherboard \n";
	cout << "6. RAM \n";
	cout << "7. Cooler \n";
	cout << "8. VGA \n";
	cout << "9. ROM \n";
	cout << "Masukkan pilihan: ";
	cin >> pilBagian;
	
	switch(pilBagian) {
		case 1:
			cout << "Apakah ingin mencari barang terlebih dahulu (y/n) ? : ";
			cin >> barangPilih;
			if(barangPilih == 'y' || barangPilih == 'Y'){
				cariCpu();
			} else if(barangPilih == 'l' || barangPilih == 'L'){
				
			}
		break;	
	}
}

void MenuAwal::tampilAwal(){
	cout << "Pilih menu: \n";
	cout << "1. Bagian komputer \n";
	cout << "2. Aksesoris komputer \n";
	cout << "3. Pesan Sekarang \m";
	cout << "Masukkan pilihan: ";
	cin >> pilMenu;
	cout << endl;
	
	switch(pilMenu) {
		case 1:
			bagianKomputer();
		break;	
	}
	
}

int main(){
	Login log;
	
	log.awal();
}

