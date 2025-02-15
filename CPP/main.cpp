// Library
#include <iostream>
#include <list>

// Import petshop.cpp untuk definisi class
#include "Petshop.cpp"

using namespace std;

// fungsi untuk menampilkan menu pilihan
void tampilkan_menu()
{
    cout << "\n@=@=====================================@\n";
    cout << "|#| CRUD SEDERHANA, SILAHKAN PILIH MENU |\n";
    cout << "@=@=====================================@\n";
    cout << "|1| Tampilkan Data                      |\n";
    cout << "|2| Tambah Data Baru                    |\n";
    cout << "|3| Ubah Data                           |\n";
    cout << "|4| Hapus Data                          |\n";
    cout << "|5| Cari Data Berdasarkan Nama Produk   |\n";
    cout << "|6| Keluar                              |\n";
    cout << "@=======================================@\n";
}

// fungsi untuk menampilkan data nya
void tampil_data(list<Petshop> &llist)
{
    if (llist.empty()) // jika isi pada list kosong
    {
        cout << "Data belum terisi cuy\n"; // error handling
    }
    else // jika tidak kosong
    {
        // maka tampilkan datanya
        cout << "Data yang tersedia:\n";
        int i = 0;

        // iterasi tiap elemen pada list menggunakan semacam iterator
        for (list<Petshop>::iterator it = llist.begin(); it != llist.end(); it++)
        {
            cout << (i + 1) << ". "; // outputkan nomor urutan pada data di list
            it->tabelDatabase(); // panggil tabelDatabase, yang isinya outputan/isi dari list tersebut
            cout << '\n'; // outputkan newline sebagai spasi baru
            i++; // i beriterasi
        }
    }
}

// fungsi untuk menambahkan data nya
void tambah_data(list<Petshop> &llist)
{
    // variabel variabel yang dipakai
    int id;
    string nama_produk, kategori_produk;
    double harga_produk;

    // masukan sesuai atribut masing masing
    cout << "Masukkan ID: ";
    cin >> id;
    cout << "Masukkan Nama Produk: ";
    cin >> nama_produk;
    cout << "Masukkan Kategori Produk: ";
    cin >> kategori_produk;
    cout << "Masukkan Harga Produk: ";
    cin >> harga_produk;

    // buatkan suatu temp untuk menampung dan menambahkan ke list
    Petshop temp;

    // temp tersebut di set/atur value nya dengan inputan yang sudah user masukan
    temp.set_id(id);
    temp.set_nama_produk(nama_produk);
    temp.set_kategori_produk(kategori_produk);
    temp.set_harga_produk(harga_produk);

    // lalu masukan value value pada temp ke list dengan cara push back
    llist.push_back(temp);
    cout << "Yey, Data berhasil ditambahkan!\n";
}

// fungsi untuk mengubah data
void ubah_data(list<Petshop> &llist)
{
    int id; // variabel id
    cout << "Masukkan ID data yang ingin diubah: ";
    cin >> id; // inputkan id

    // iterasi tiap elemen pada list menggunakan semacam iterator
    for (list<Petshop>::iterator it = llist.begin(); it != llist.end(); it++)
    {
        if (it->get_id() == id) // jika ketemu id nya pada list
        {
            // atribut-atribut lainnya
            string nama_produk, kategori_produk;
            double harga_produk;

            // masukkan dan inputkan variabel/atribut2 tersebut
            cout << "Masukkan Nama Produk Baru: ";
            cin >> nama_produk;
            cout << "Masukkan Kategori Produk Baru: ";
            cin >> kategori_produk;
            cout << "Masukkan Harga Produk Baru: ";
            cin >> harga_produk;

            // lalu ganti data yang dulu menjadi yang baru. gunakan set untuk mengubah value nya
            it->set_nama_produk(nama_produk);
            it->set_kategori_produk(kategori_produk);
            it->set_harga_produk(harga_produk);

            cout << "Data berhasil diubah!\n";
            return;
        }
    }

    // jika tidak ketemu data ID yang tepat
    cout << "Data dengan ID " << id << " tidak ditemukan!\n";
}

// fungsi untuk menghapus data
void hapus_data(list<Petshop> &llist)
{
    int id; // variabel/atribut id
    cout << "Masukkan ID data yang mau dihapus: ";
    cin >> id; // inputkan id

    // iterasi tiap elemen pada list menggunakan semacam iterator
    for (list<Petshop>::iterator it = llist.begin(); it != llist.end(); it++)
    {
        if (it->get_id() == id) // jika ketemu id nya pada list
        {
            llist.erase(it); // hapus data tersebut dengan erase
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }

    // jika tidak ditemukan id nya
    cout << "Data dengan ID " << id << " tidak ditemukan!\n";
}

// fungsi untuk mencari data berdasarkan nama produk
void cari_data(list<Petshop> &llist)
{
    // inisialisasikan nama produk
    string nama_produk;
    cout << "Masukkan Nama Produk yang ingin dicari: ";
    cin >> nama_produk; // input nama produk

    // iterasi tiap elemen pada list menggunakan semacam iterator
    for (list<Petshop>::iterator it = llist.begin(); it != llist.end(); it++)
    {
        if (it->get_nama_produk() == nama_produk) // jika data ditemukan sesuai dengan input (gunakan get untuk mendapatkan value nama produk)
        {
            cout << "Data ditemukan:\n";
            it->tabelDatabase(); // tampilkan tabel database
            return;
        }
    }

    // jika nama produk tidak ditemukan
    cout << "Data dengan nama produk " << nama_produk << " tidak ditemukan!\n";
}

int main()
{
    list<Petshop> llist; // inisialisasikan list
    int pilihanMenu; // variabel untuk pilihan menunya

    do
    {
        tampilkan_menu(); // tampilkan menunya terlebih dahulu
        cout << "Pilih menu berapa: ";
        cin >> pilihanMenu; // inputkan pilihan menu

        switch (pilihanMenu)
        {
        case 1: // case 1: tampilkan data
            tampil_data(llist);
            break;
        case 2: // case 2: tambahkan data
            tambah_data(llist);
            break;
        case 3: // case 3: ubah data
            ubah_data(llist);
            break;
        case 4: // case 4: hapus data
            hapus_data(llist);
            break;
        case 5: // case 5: cari data berdasarkan nama produk
            cari_data(llist);
            break;
        case 6: // case 6: keluar dari program
            cout << "BAY BAY\n";
            break;
        default: // case selain 1-6: tampilkan error handling
            cout << "gaada menu no " << pilihanMenu << "\n";
        }
    } while (pilihanMenu != 6); // looping terus program sampai nomor 6 untuk exit

    return 0;
}