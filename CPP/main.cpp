#include <iostream>
#include <list>
#include "Petshop.cpp"

using namespace std;

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

void tampilkan_data(list<Petshop> &llist)
{
    if (llist.empty())
    {
        cout << "Data belum terisi cuy\n";
    }
    else
    {
        cout << "Data yang tersedia:\n";
        int i = 0;
        for (list<Petshop>::iterator it = llist.begin(); it != llist.end(); it++)
        {
            cout << (i + 1) << ". ";
            it->tabelDatabase();
            cout << '\n';
            i++;
        }
    }
}

void tambah_data(list<Petshop> &llist)
{
    int id;
    string nama_produk, kategori_produk;
    double harga_produk;

    cout << "Masukkan ID: ";
    cin >> id;
    cout << "Masukkan Nama Produk: ";
    cin >> nama_produk;
    cout << "Masukkan Kategori Produk: ";
    cin >> kategori_produk;
    cout << "Masukkan Harga Produk: ";
    cin >> harga_produk;

    Petshop temp;

    temp.set_id(id);
    temp.set_nama_produk(nama_produk);
    temp.set_kategori_produk(kategori_produk);
    temp.set_harga_produk(harga_produk);

    llist.push_back(temp);
    cout << "Yey, Data berhasil ditambahkan!\n";
}

void ubah_data(list<Petshop> &llist)
{
    int id;
    cout << "Masukkan ID data yang ingin diubah: ";
    cin >> id;

    for (list<Petshop>::iterator it = llist.begin(); it != llist.end(); it++)
    {
        if (it->get_id() == id)
        {
            string nama_produk, kategori_produk;
            double harga_produk;

            cout << "Masukkan Nama Produk Baru: ";
            cin >> nama_produk;
            cout << "Masukkan Kategori Produk Baru: ";
            cin >> kategori_produk;
            cout << "Masukkan Harga Produk Baru: ";
            cin >> harga_produk;

            it->set_nama_produk(nama_produk);
            it->set_kategori_produk(kategori_produk);
            it->set_harga_produk(harga_produk);

            cout << "Data berhasil diubah!\n";
            return;
        }
    }
    cout << "Data dengan ID " << id << " tidak ditemukan!\n";
}

void hapus_data(list<Petshop> &llist)
{
    int id;
    cout << "Masukkan ID data yang mau dihapus: ";
    cin >> id;

    for (list<Petshop>::iterator it = llist.begin(); it != llist.end(); it++)
    {
        if (it->get_id() == id)
        {
            llist.erase(it);
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }
    cout << "Data dengan ID " << id << " tidak ditemukan!\n";
}

void cari_data(list<Petshop> &llist)
{
    string nama_produk;
    cout << "Masukkan Nama Produk yang ingin dicari: ";
    cin >> nama_produk;

    for (list<Petshop>::iterator it = llist.begin(); it != llist.end(); it++)
    {
        if (it->get_nama_produk() == nama_produk)
        {
            cout << "Data ditemukan:\n";
            it->tabelDatabase();
            return;
        }
    }
    cout << "Data dengan nama produk " << nama_produk << " tidak ditemukan!\n";
}

int main()
{
    list<Petshop> llist;
    int pilihanMenu;

    do
    {
        tampilkan_menu();
        cout << "Pilih menu berapa: ";
        cin >> pilihanMenu;

        switch (pilihanMenu)
        {
        case 1:
            tampilkan_data(llist);
            break;
        case 2:
            tambah_data(llist);
            break;
        case 3:
            ubah_data(llist);
            break;
        case 4:
            hapus_data(llist);
            break;
        case 5:
            cari_data(llist);
            break;
        case 6:
            cout << "BAY BAY\n";
            break;
        default:
            cout << "gaada menu no " << pilihanMenu << "\n";
        }
    } while (pilihanMenu != 6);

    return 0;
}