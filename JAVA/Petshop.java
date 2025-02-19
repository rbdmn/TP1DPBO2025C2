public class Petshop {
    
    // atribut yang akan dipakai dan aksesnya di private kan
    private int id;
    private String nama_produk;
    private String kategori_produk;
    private double harga_produk;

    /* Constructor */

    public Petshop()
    {
        this.id = 0;
        this.nama_produk = "";
        this.kategori_produk = "";
        this.harga_produk = 0;
    }

    // Constructor dengan parameter.
    public Petshop(int id, String nama_produk, String kategori_produk, double harga_produk) {
        this.id = id;
        this.nama_produk = nama_produk;
        this.kategori_produk = kategori_produk;
        this.harga_produk = harga_produk;
    }

    /* Getter and Setter (ACCESSOR) */

    // Get id
    public int get_id() {
        return this.id;
    }

    // Set id
    public void set_id(int id) {
        this.id = id;
    }

    // Get nama produk
    public String get_nama_produk() {
        return this.nama_produk;
    }

    // Set nama produk
    public void set_nama_produk(String nama_produk) {
        this.nama_produk = nama_produk;
    }

    // Get kategori produk
    public String get_kategori_produk() {
        return this.kategori_produk;
    }

    // Set kategori produk
    public void set_kategori_produk(String kategori_produk) {
        this.kategori_produk = kategori_produk;
    }

    // Get harga produk
    public double get_harga_produk() {
        return this.harga_produk;
    }

    // Set harga produk
    public void set_harga_produk(double harga_produk) {
        this.harga_produk = harga_produk;
    }

    // Nahh, Java doesn't need a destructor
}