// Library
#include <iostream>
#include <string>
#include <list>

using namespace std;

// CLASS PETSHOP
class Petshop
{
    
private: // Isi variabel-variabel dengan akses terprivate (tertutup)
    int id;                 // Variabel ID untuk identitas produk
    string nama_produk;     // Variabel nama produk untuk nama pada produk
    string kategori_produk; // Variabel kategori produk untuk kategori pada produk
    double harga_produk;    // Variabel harga produk untuk harga pada produk

public: // Isi dengan akses public (terbuka)

    // [CONSTRUCTOR] == PEMBUKA

    Petshop() // Default Constructor untuk inisialisasi dengan nilai kosong
    {
        // Semua isi dari tiap variabel di kosongkan
        this->id = 0;
        this->nama_produk = "";
        this->kategori_produk = "";
        this->harga_produk = 0.0;
    }

    Petshop(int id, string nama_produk, string kategori_produk, double harga_produk) // Constructor untuk memberikan nilai awal pada variabel (makanya pake parameter)
    {
        // Semua isi dari tiap variabel di berikan nilainya sesuai dengan parameternya
        this->id = id;
        this->nama_produk = nama_produk;
        this->kategori_produk = kategori_produk;
        this->harga_produk = harga_produk;
    }

    // [METHODS] == ACTION PADA CLASS

    // Dapatkan value dari variabel ID
    int get_id()
    {
        return this->id;
    }

    // Atur value dari variabel ID
    void set_id(int id)
    {
        this->id = id;
    }

    // Dapatkan value dari variabel nama produk
    string get_nama_produk()
    {
        return this->nama_produk;
    }

    // Atur value dari variabel nama produk
    void set_nama_produk(string nama_produk)
    {
        this->nama_produk = nama_produk;
    }

    // Dapatkan value dari variabel kategori produk
    string get_kategori_produk()
    {
        return this->kategori_produk;
    }

    // Atur value dari variabel kategori produk
    void set_kategori_produk(string kategori_produk)
    {
        this->kategori_produk = kategori_produk;
    }

    // Dapatkan value dari variabel harga produk
    double get_harga_produk()
    {
        return this->harga_produk;
    }

    // Atur value dari variabel haga produk
    void set_harga_produk(double harga_produk)
    {
        this->harga_produk = harga_produk;
    }

    // method untuk menampilkan isi dari database, bersifat tabel
    void tabelDatabase()
    {
        cout << "\n|ID: " << this->id << "|\n";
        cout << "|Nama Produk: " << this->nama_produk << "|\n";
        cout << "|Kategori Produk: " << this->kategori_produk << "|\n";
        cout << "|Harga Produk: " << this->harga_produk << "|\n";
    }

    // [DESTRUCTOR] == PENUTUP

    ~Petshop()
    {
    }
};