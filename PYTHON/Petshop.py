class Petshop:

    # ATRIBUT-ATRIBUT YANG MAU DIINISIALISASIKAN
    __id = 0
    __namaProduk = ""
    __kategoriProduk = ""
    __hargaProduk = 0.0

    # CONSTRUCTOR DENGAN PARAMETER UNTUK ME-NEW KAN
    def __init__(self, id = 0, namaProduk = "", kategoriProduk = "", hargaProduk = 0.0):
        self.__id = id
        self.__namaProduk = namaProduk
        self.__kategoriProduk = kategoriProduk
        self.__hargaProduk = hargaProduk

    # Getter and Setter

    # get id
    def get_id(self): return self.__id

    # set id
    def set_id(self, id): self.__id = id

    # get nama produk
    def get_namaProduk(self): return self.__namaProduk

    # set nama produk
    def set_namaProduk(self, namaProduk): self.__namaProduk = namaProduk

    # get kategori produk
    def get_kategoriProduk(self): return self.__kategoriProduk

    # set kategori produk
    def set_kategoriProduk(self, kategoriProduk): self.__kategoriProduk = kategoriProduk

    # get harga produk
    def get_hargaProduk(self): return self.__hargaProduk

    # set harga produk
    def set_hargaProduk(self, hargaProduk): self.__hargaProduk = hargaProduk