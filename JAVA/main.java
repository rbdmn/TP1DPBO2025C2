
// import library
import java.util.Scanner; // buat inputan
import java.util.ArrayList; // buat nyimpen data pada array list

public class main {
    public static void main(String[] args) {

        // Deklarasikan arraylist dengan class petshop
        ArrayList<Petshop> list = new ArrayList<>();

        // Deklarasikan scanner agar bisa dipakai untuk inputan
        Scanner sc = new Scanner(System.in);

        int pilihanMenu = 0; // variabel untuk pilihan pada menu
        int awalmulaID = 1; // Untuk ID sekarang bersifat Auto INCREMENT jadi otomatis sama mesinnya tidak
                            // usah di input lagi (tidak kayak waktu di cpp)

        // lakukan do while untuk looping program sampai berhenti
        do {

            // Tampilan menunya [JAVA VERSION]
            System.out.println("\n@=@=====================================@");
            System.out.println("|#| CRUD SEDERHANA JAVA VERSION         |");
            System.out.println("@=@=====================================@");
            System.out.println("|1| Tampilkan Data                      |");
            System.out.println("|2| Tambah Data Baru                    |");
            System.out.println("|3| Ubah Data                           |");
            System.out.println("|4| Hapus Data                          |");
            System.out.println("|5| Cari Data Berdasarkan Nama Produk   |");
            System.out.println("|6| Keluar                              |");
            System.out.println("@=@=====================================@");

            System.out.println("[JAVA VERSION WOW]");
            System.out.println("Pilih mau menu keberapa");

            // inputan
            try {
                pilihanMenu = sc.nextInt();
            } catch (Exception e) {
                // jika yang di input bukan tipe integer
                System.out.println("inputan harus tipe integer la cuy");
            }

            switch (pilihanMenu) {
                case 1: // jika 1, alias tampilkan data
                    // pastikan datanya tidak kosong
                    if (list.isEmpty()) { // data kosong
                        System.out.println("gaada data yang terisi bang");
                    } else { // jika datanya adaan
                        System.out.println("[SHOW]===================================");
                        System.out.println("Data ditemukan!");
                        System.out.println("Berikut data yang tersedia:");
                        for (int j = 0; j < list.size(); j++) { // looping selama total jumlah data pada list
                            // outputan data
                            System.out.println("@=============@");
                            System.out.println("| DATA KE : " + Integer.toString(j + 1) + " |");
                            System.out.println("@=============@=========================@");
                            System.out.println("| ID : " + list.get(j).get_id());
                            System.out.println("| NAMA PRODUK : " + list.get(j).get_nama_produk());
                            System.out.println("| KATEGORI PRODUK : " + list.get(j).get_kategori_produk());
                            System.out.println("| HARGA PRODUK (US DOLLARS) : $" + list.get(j).get_harga_produk());
                            System.out.println("@=======================================@");
                        }
                    }
                    break;
                case 2: // jika 2, alias tambah data
                    System.out.println("[ADD]====================================");

                    // inisialisasikan atribut dengan nilai kosong
                    String nama_produk_add = "";
                    String kategori_produk_add = "";
                    double harga_produk_add = 0;

                    sc.nextLine(); // bersihin buffer, soalnya kadang ada inputan yang ke skip

                    // INPUTAN NAMA PRODUK
                    System.out.println("Masukkan Nama Produk: ");
                    try {
                        nama_produk_add = sc.nextLine();
                    } catch (Exception e) {
                        System.out.println("inputan harus tipe string la cuy");
                    }

                    // INPUTAN KATEGORI PRODUK
                    System.out.println("Masukkan Kategori Produk: ");
                    try {
                        kategori_produk_add = sc.nextLine();
                    } catch (Exception e) {
                        System.out.println("inputan harus tipe string la cuy");
                    }

                    // INPUTAN HARGA PRODUK
                    System.out.println("Masukkan Harga Produk: ");
                    try {
                        harga_produk_add = sc.nextDouble();
                    } catch (Exception e) {
                        System.out.println("inputan harus tipe double la cuy");
                    }

                    // buat variabel temporary, lalu masukan ke parameter petshop untuk menambah data baru
                    Petshop temp = new Petshop(awalmulaID, nama_produk_add, kategori_produk_add, harga_produk_add);

                    list.add(temp); // masukan ke list
                    System.out.println("[DATA TELAH MASUK KE DATABASE]");
                    awalmulaID++; // ID beriterasi (AUTO INCEREMENT)

                    break;
                case 3: // Ubah Data
                    System.out.println("[UPDATE]=================================");
                    System.out.print("Masukkan ID yang ingin diubah: ");
                    int id_update = sc.nextInt(); // masukan inputan id yang ingin diubah
                    boolean flag_update = false; // variabel flagging untuk menentukan datanya valid atau tidak

                    // penjelasan for each jenis baru pada java
                    // jadi variabel produk itu adalah variabel sementara yang mewakili satu data pada list pada tiap iterasi
                    for (Petshop produk : list) {
                        if (produk.get_id() == id_update) { // jika id nya ditemukan pada data
                            flag_update = true; // mark si flag update ini menjadi boolean true
                            sc.nextLine(); // bersihin buffer lagi

                            // INPUTAN NAMA PRODUK
                            System.out.print("Masukkan Nama Produk Baru: ");
                            String nama_produk_update = sc.nextLine();

                            // INPUTAN KATEGORI PRODUK
                            System.out.print("Masukkan Kategori Produk Baru: ");
                            String kategori_produk_update = sc.nextLine();

                            // INPUTAN HARGA PRODUK
                            System.out.print("Masukkan Harga Produk Baru: ");
                            double harga_produk_update = sc.nextDouble();

                            // lalu ganti data yang udah ada dengan data yang baru dan langsung saja masukan dengan menggunakan set
                            produk.set_nama_produk(nama_produk_update);
                            produk.set_kategori_produk(kategori_produk_update);
                            produk.set_harga_produk(harga_produk_update);
                            System.out.println("[DATA BERHASIL DIUBAH]");
                            break;
                        }
                    }

                    if (!flag_update) { // jika id tidak ditemukan
                        System.out.println("data dengan ID '" + id_update + "'' tidak ditemukan cuy");
                    }
                    break;
                case 4: // DELETE

                    // [UNTUK DELETE BELUM BISA DINAMIS, belum ngerti hehe]

                    System.out.println("[DELETE]=================================");
                    System.out.print("Masukkan ID yang ingin dihapus: ");
                    int id_delete = sc.nextInt(); // masukin id yang mau dihapus
                    boolean flag_delete = false; // variabel flagging untuk menentukan datanya valid atau tidak

                    for (int j = 0; j < list.size(); j++) {
                        if (list.get(j).get_id() == id_delete) {
                            list.remove(j);
                            flag_delete = true;
                            System.out.println("[DATA BERHASIL DIHAPUS]");
                            break;
                        }
                    }

                    if (!flag_delete) { // jika id tidak ditemukan
                        System.out.println("data dengan ID '" + id_delete + "'' tidak ditemukan cuy");
                    }
                    break;
                case 5: // SEARCH
                    System.out.println("[SEARCH]=================================");
                    System.out.print("Masukkan Nama Produk yang ingin dicari: ");
                    sc.nextLine();
                    String nama_cari = sc.nextLine();
                    boolean flag_search = false;

                    for (Petshop produk : list) { // looping selama total jumlah data pada list
                        // equalsignorecase ini intinya menghindari masalah kapital pada kata
                        if (produk.get_nama_produk().equalsIgnoreCase(nama_cari)) { // jika ketemu
                            flag_search = true; // flag kan dengan true
                            System.out.println("@================@");
                            System.out.println("| DATA DITEMUKAN |");
                            System.out.println("@================@======================@");
                            System.out.println("| ID: " + produk.get_id());
                            System.out.println("| Nama Produk: " + produk.get_nama_produk());
                            System.out.println("| Kategori Produk: " + produk.get_kategori_produk());
                            System.out.println("| Harga Produk: " + produk.get_harga_produk());
                            System.out.println("@========================================@");
                            break;
                        }
                    }

                    if (!flag_search) { // jika tidak ketemu
                        System.out.println("data dengan nama produk '" + nama_cari + "' tidak ditemukan cuy");
                    }
                    break;
                case 6: // EXIT
                    System.out.println("bye bye java version");
                    break;

                default: // selain 1-6
                    System.out.println("gaada pilihan itu bang");
                    break;
            }
        } while (pilihanMenu != 6); // lakukan selama inputan pilihan menu itu bukan 6

        sc.close(); // close scanner (tadi diatas di buka dan sekarang ditutup karena program diberhentikan)

    }
}