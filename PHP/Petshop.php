<?php

class Petshop
{
    // Atribut-atribut yang akan dipakai pada main.php
    private $ID = 0;
    private $nama_produk = "";
    private $kategori_produk = "";
    private $harga_produk = 0.0;
    private $foto_produk;

    // CONSTRUCTOR dengan parameter
    public function __construct($ID, $nama_produk, $kategori_produk, $harga_produk, $foto_produk)
    {
        $this->ID = $ID;
        $this->nama_produk = $nama_produk;
        $this->kategori_produk = $kategori_produk;
        $this->harga_produk = $harga_produk;
        $this->foto_produk = $foto_produk;
    }

    // GETTER SETTER

    // Setter ID
    public function set_id($ID)
    {
        $this->ID = $ID;
    }

    // Getter ID
    public function get_id()
    {
        return $this->ID;
    }

    // Setter nama produk
    public function set_namaProduk($nama_produk)
    {
        $this->nama_produk = $nama_produk;
    }

    // Getter nama produk
    public function get_namaProduk()
    {
        return $this->nama_produk;
    }

    // Setter kategori produk
    public function set_kategoriProduk($kategori_produk)
    {
        $this->kategori_produk = $kategori_produk;
    }

    // Getter kategori produk
    public function get_kategoriProduk()
    {
        return $this->kategori_produk;
    }

    // Setter harga produk
    public function set_hargaProduk($harga_produk)
    {
        $this->harga_produk = $harga_produk;
    }

    // Getter harga produk
    public function get_hargaProduk()
    {
        return $this->harga_produk;
    }

    // Setter foto produk
    public function set_fotoProduk($foto_produk)
    {
        $this->foto_produk = $foto_produk;
    }

    // Getter foto produk
    public function get_fotoProduk()
    {
        return $this->foto_produk;
    }

    // DESTRUKTOR
    public function __destruct()
    {
        
    }
}
