# import dari file class Petshop
from Petshop import Petshop

# List untuk nyimpen semua data produk di petshop
ListPetshop = []  
autoincrement_ID = 1  # ID auto increment biar unik

# Menampilkan data yang udah disimpan
def SHOW():
    if not ListPetshop:  # Kalau list kosong, kasih tahu user
        print("datanya kosong cuy!")
        return 

    # kalau list tidak kosong
    print("\nberikut daftar semua produk di Petshop:")
    for isiList in ListPetshop:
        print("@=======================================@")
        print(f"| ID : {isiList.get_id()}")  
        print(f"| NAMA PRODUK : {isiList.get_namaProduk()}")  
        print(f"| KATEGORI PRODUK : {isiList.get_kategoriProduk()}")  
        print(f"| HARGA PRODUK : ${isiList.get_hargaProduk():.2f}")  
        print("@=======================================@")

# Menambahkan data baru ke dalam list
def ADD(nama_produk, kategori_produk, harga_produk):
    global autoincrement_ID  # Biar bisa update ID di luar fungsi
    temp = Petshop(autoincrement_ID, nama_produk, kategori_produk, float(harga_produk))  # Bikin objek Petshop
    ListPetshop.append(temp)  # Masukin ke list dengan append
    print("[DATA BERHASIL DITAMBAHKAN!!]")  
    autoincrement_ID += 1  # Naikin ID biar unik buat produk berikutnya

# Mengubah data berdasarkan ID
def UPDATE(id_update):
    ketemu = False  # Flag buat ngecek data ketemu atau nggak
    for isiList in ListPetshop:
        if isiList.get_id() == id_update:  # Kalau IDnya cocok

            # Inputkan elemen yang mau diubahnya dengan mereplace isi data sebelumnya
            isiList.set_namaProduk(input("Inputkan Nama Produk Baru: "))  
            isiList.set_kategoriProduk(input("Inputkan Kategori Produk Baru: "))  
            isiList.set_hargaProduk(float(input("Inputkan Harga Produk Baru: ")))  
            print("[DATA BERHASIL DIUBAH!!]")
            ketemu = True  # Tandai kalau data ketemu

    if not ketemu:  # Error handling
        print(f"Ga nemu Id dari {id_update} !")

# Menghapus data berdasarkan ID
def DELETE(id_delete):
    ketemu_ga = False  # Flag buat ngecek data ketemu atau nggak
    for IsiList in ListPetshop:
        if IsiList.get_id() == id_delete:  # Kalau IDnya cocok
            ListPetshop.remove(IsiList)  # Hapus dari list
            print("[DATA BERHASIL DIHAPUS!!]")  
            ketemu_ga = True  # Tandai kalau data ketemu

    if not ketemu_ga:  # Error handling
        print(f"Ga nemu Id dari {id_delete} !")

# Mencari data berdasarkan nama produk
def SEARCH(nama_cari):
    ketemu = False  # Flag buat cek apakah ada produk yang cocok
    for IsiList in ListPetshop:
        if IsiList.get_namaProduk() == nama_cari:  # Cek kalau namanya cocok
            print("\n@================@")
            print("| DATA DITEMUKAN |")
            print("@================@=======================@")
            print(f"| ID: {IsiList.get_id()}")  
            print(f"| Nama Produk: {IsiList.get_namaProduk()}")  
            print(f"| Kategori Produk: {IsiList.get_kategoriProduk()}")  
            print(f"| Harga Produk: ${IsiList.get_hargaProduk():.2f}")  
            print("@========================================@")
            ketemu = True  # Set flag ke True kalau ada yang ketemu

    if not ketemu:  # Kalau nggak ada satupun yang cocok
        print("produk tidak ditemukan!") 

# ========================================================================================================
# Ini sistem berbasis command line pake metode "tape" kayak di bahasa pemrograman lama
# Maksudnya program bisa dieksekusi dalam satu baris tanpa harus masuk ke mode interaktif
# ========================================================================================================

programJalan = True  # Flag buat ngejalanin program (daripada pake break)

# FORMAT TAPE
# ADD [nama produk] [kategori produk] [harga produk]
# CHANGE [ID yang mau diubah]
# DELETE [ID yang mau didelete]
# FIND [nama produk yang di cari]
# SHOW
# EXIT

# Loop utama buat programnya
while programJalan == True:  # Jalan terus selama program belum dihentikan

    print("\n@=@=====================================@")
    print("|#| PYTHON DBMS TAPE VERSION            |")
    print("@=@=====================================@====================================================@")
    print("|1| Tampilkan Data                      | SHOW                                               |")
    print("|2| Tambah Data Baru                    | ADD [nama produk] [kategori produk] [harga produk] |")
    print("|3| Ubah Data                           | CHANGE [ID yang mau diubah]                        |")
    print("|4| Hapus Data                          | DELETE [ID yang mau didelete]                      |")
    print("|5| Cari Data Berdasarkan Nama Produk   | FIND [nama produk yang di cari]                    |")
    print("|6| Keluar                              | EXIT                                               |")
    print("@=@=====================================@====================================================@")
    
    # Minta input perintah dari user
    tape = input("dbms ular piton> ").strip()  # .strip ini intinya menghapus/menghindari spasi berlebih

    if tape.lower() == "show":  # Kalau user ketik SHOW
        SHOW()
    
    elif tape.lower() == "exit":  # Kalau user ketik EXIT
        print("Bay Bay!")
        programJalan = False  # Matikan loop dan keluar dari loop

    else:
        split_tape = tape.split()  # Pecah input jadi list berdasarkan spasi

        # inti dari .lower ialah meng non kapital kan kata string, contoh dari AYAM jadi ayam agar sesuai kriterianya
        if split_tape[0].lower() == "add":  # [ADD]
            if len(split_tape) != 4:  # error handling jumlah kata tape
                print("formatnya salah bung! contoh yg benar: add [Nama] [Kategori] [Harga]")
            elif not split_tape[3].isdigit():  # error handling tipe harga produk
                print("ID harus berupa angka! contoh yg benar: add [Nama] [Kategori] 1200")
            else:
                ADD(split_tape[1], split_tape[2], split_tape[3])  # Panggil fungsi ADD

        elif split_tape[0].lower() == "change":  # [CHANGE]
            if len(split_tape) != 2:  # error handling jumlah kata tape
                print("formatnya salah bung! contoh yg benar: change [ID]")
            elif not split_tape[1].isdigit():  # error handling tipe id
                print("ID harus berupa angka! contoh yg benar: change 1")
            else:
                UPDATE(int(split_tape[1]))  # [UPDATE]

        elif split_tape[0].lower() == "delete":  # [DELETE]
            if len(split_tape) != 2:  # error handling jumlah kata tape
                print("formatnya salah bung! contoh yg benar: delete [ID]")
            elif not split_tape[1].isdigit():  # error handling tipe id
                print("ID harus berupa angka! contoh yg benar: delete 1")
            else:
                DELETE(int(split_tape[1]))  # Panggil fungsi DELETE

        elif split_tape[0].lower() == "find":  # [FIND]
            if len(split_tape) != 2:  # error handling jumlah kata tape
                print("formatnya salah bung! contoh yg benar: find [NamaProduk]")
            else:
                SEARCH(split_tape[1])  # Panggil fungsi SEARCH

        else:
            print("harus sesuai format ya, harap liat tabel")  # Kalau input salah format
