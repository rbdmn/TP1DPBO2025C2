#include <iostream>
#include <string>
#include <list>

using namespace std;

class Petshop
{
    private:
        int id;
        string nama_produk;
        string kategori_produk;
        double harga_produk;

    public:
        Petshop()
        {
            this->id = 0;
            this->nama_produk = "";
            this->kategori_produk = "";
            this->harga_produk = 0.0;
        }

        Petshop(int id, string nama_produk, string kategori_produk, double harga_produk)
        {
            this->id = id;
            this->nama_produk = nama_produk;
            this->kategori_produk = kategori_produk;
            this->harga_produk = harga_produk;
        }

        int get_id()
        {
            return this->id;
        }
        
        void set_id(int id)
        {
            this->id = id;
        }

        string get_nama_produk()
        {
            return this->nama_produk;
        }
        
        void set_nama_produk(string nama_produk)
        {
            this->nama_produk = nama_produk;
        }

        string get_kategori_produk()
        {
            return this->kategori_produk;
        }
        
        void set_kategori_produk(string kategori_produk)
        {
            this->kategori_produk = kategori_produk;
        }

        double get_harga_produk()
        {
            return this->harga_produk;
        }
        
        void set_harga_produk(double harga_produk)
        {
            this->harga_produk = harga_produk;
        }

        void tabelDatabase()
        {
            cout << "\n|ID: " << this->id << "|\n";
            cout << "|Nama Produk: " << this->nama_produk << "|\n";
            cout << "|Kategori Produk: " << this->kategori_produk << "|\n";
            cout << "|Harga Produk: " << this->harga_produk << "|\n";
        }

        ~Petshop()
        {
            
        }
};