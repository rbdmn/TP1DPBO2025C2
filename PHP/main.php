<?php
// panggil file Petshop.php biar si class-nya bisa dipakai
require 'Petshop.php';

// pake dan mulai sesi biar data bisa disimpan, kalo tidak nanti datanya langsung ilang
session_start();

// kalo belum ada daftar produk, buat array kosong
if (!isset($_SESSION['ListPetshop'])) {
    $_SESSION['ListPetshop'] = [];
}

// biar gampang dipakai, buat alias ke session
$ListPetshop = &$_SESSION['ListPetshop'];

// if (!file_exists('uploads')) {
//     mkdir('uploads', 0777, true);
// }

$edit_id = null; // ID produk yang bakal diedit (default null)
$edit_produk = null; // data produk yang bakal diedit (default null)
$kueri_pencarian = isset($_GET['search']) ? $_GET['search'] : ""; // cek kalau ada pencarian produk

// Proses pengeditan
if (isset($_GET['edit'])) { // cek ada yang pencet tombol url edit tidak di isi data tabel
    $edit_id = $_GET['edit']; // ambil nilai idnya yang mau di update
    foreach ($ListPetshop as $produk) { // tiap isi dari list petshop
        if ($produk->get_id() == $edit_id) { // double verification id nya sesuai tidak ama id yang mau di edit
            $edit_produk = $produk; // simpan produk yang bakal diedit
        }
    }
}

// kalao ada form yang dikirim
if ($_SERVER["REQUEST_METHOD"] == "POST") { // cek request datang tidak dengan metode post
    // cek semua input harus diisi
    if (!empty($_POST['name']) && !empty($_POST['kategori']) && !empty($_POST['harga'])) {

        // ambil semua atribut dari form
        $nama = $_POST['name'];
        $kategori = $_POST['kategori'];
        $harga = $_POST['harga'];

        $file_si_foto = ""; // default kosong, nanti diisi kalau ada gambar

        if ($edit_produk) {
            $file_si_foto = $edit_produk->get_fotoProduk(); // kalau edit, pakai foto lama dulu
        }

        // jika user mengupload foto baru maka masukan ke folder fhoto yang sudah saya buat
        if (!empty($_FILES['image']['name'])) {
            $file_si_foto = "fhoto/" . basename($_FILES["image"]["name"]);
            move_uploaded_file($_FILES["image"]["tmp_name"], $file_si_foto);
        }

        // kalau edit produk, cari di array dan update datanya
        $flag = false; // flagger
        if ($edit_id) { // jika id dari editnya valid
            for ($i = 0; $i < count($ListPetshop); $i++) { // cari ampe data/elemen terakhir pada list
                if ($ListPetshop[$i]->get_id() == $edit_id) {
                    $ListPetshop[$i] = new Petshop($edit_id, $nama, $kategori, $harga, $file_si_foto); // dan replace dengan yang baru
                    $flag = true; // flag stop
                }
            }
        } else {
            // kalau tambah produk baru, buat ID baru (lanjutan dari yang ada)
            $id = count($ListPetshop) + 1;
            $ListPetshop[] = new Petshop($id, $nama, $kategori, $harga, $file_si_foto);
        }
    }
    header("Location: main.php"); // refresh halaman biar datanya update
    exit;
}

// Untuk menghapus produk
if (isset($_GET['delete'])) { // cek ada yang pencet tombol url delete tidak di isi data tabel
    $deleteId = $_GET['delete'];

    $ListBaru = []; // array baru buat produk yang nggak dihapus
    $IDbaru = 1; // reset ID biar tetap urut

    foreach ($ListPetshop as $produk) {
        if ($produk->get_id() != $deleteId) { // simpan yang nggak dihapus
            $produk->set_id($IDbaru);
            $ListBaru[] = $produk;
            $IDbaru++;
        }
    }

    $ListPetshop = $ListBaru; // ganti list lama dengan yang baru

    header("Location: main.php"); // refresh halaman biar bersih
    exit;
}
?>

<!-- TAMPILAN DI WEB MENGGUNAKAN HTML DAN CSS BIASA SAJA -->
<!DOCTYPE html>
<html lang="id">

<head>
    <title>Petshop</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }

        table {
            width: 70%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        th,
        td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }

        img {
            width: 100px;
            height: 100px;
            object-fit: cover;
        }
    </style>
</head>

<body>

    <h2><?php echo $edit_id ? "Edit Produk" : "Tambah Produk"; ?></h2>

    <!-- Form buat tambah/edit produk -->
    <form method="post" enctype="multipart/form-data">
        <label for="name">Nama Produk:</label><br>
        <input type="text" id="name" name="name" value="<?php echo $edit_produk ? $edit_produk->get_namaProduk() : ''; ?>" required><br><br>

        <label for="kategori">Kategori Produk:</label><br>
        <input type="text" id="kategori" name="kategori" value="<?php echo $edit_produk ? $edit_produk->get_kategoriProduk() : ''; ?>" required><br><br>

        <label for="harga">Harga Produk:</label><br>
        <input type="number" id="harga" name="harga" min="1" value="<?php echo $edit_produk ? $edit_produk->get_hargaProduk() : ''; ?>" required><br><br>

        <label for="image">Foto Produk:</label><br>
        <input type="file" id="image" name="image" accept="image/*"><br><br>

        <!-- Kalau edit, tampilkan foto lama dengan get -->
        <?php if ($edit_produk) {
            echo '<img src="' . $edit_produk->get_fotoProduk() . '" width="100"><br>';
        } ?>

        <!-- Mau edit apa tambahin produk -->
        <input type="submit" value="<?php echo $edit_id ? "Update Produk" : "Tambahkan Produk"; ?>"> 
    </form>

    <h2>Daftar Produk</h2>

    <!-- Form pencarian produk -->
    <form method="get">
        <input type="text" name="search" placeholder="Cari Produk..." value="<?php echo $kueri_pencarian; ?>">
        <input type="submit" value="Cari">
    </form>

    <!-- Tabel daftar produk -->
    <table>
        <tr>
            <th>ID</th>
            <th>Nama</th>
            <th>Kategori</th>
            <th>Harga</th>
            <th>Foto</th>
            <th>Aksi</th>
        </tr>
        <?php
        // Tampilkan daftar produk yang sesuai pencarian (kalau ada)
        foreach ($ListPetshop as $produk) { // looping ke tiap isi produk dari listpetshop sebagai produk

            // lalu filter pencariannya
            // stripos itu intinya mencari substring tanpa case-sensitive
            // kalau nama produk ga mengandung kata kunci pada pencarian, maka continue ini intinya untuk melewati produknya
            if ($kueri_pencarian && stripos($produk->get_namaProduk(), $kueri_pencarian) === false) {
                continue; 
            }
            echo "<tr>";
            echo "<td>" . $produk->get_id() . "</td>";
            echo "<td>" . $produk->get_namaProduk() . "</td>";
            echo "<td>" . $produk->get_kategoriProduk() . "</td>";
            echo "<td>Rp " . number_format((float) $produk->get_hargaProduk(), 0, ',', '.') . "</td>";
            echo "<td><img src='" . $produk->get_fotoProduk() . "' alt='Foto Produk'></td>";
            echo "<td>
                <a href='?edit=" . $produk->get_id() . "'>Edit</a> 
                <a href='?delete=" . $produk->get_id() . "' onclick='return confirm(\"Hapus produk ini?\");'>Hapus</a>
              </td>";
            echo "</tr>";
        }
        ?>
    </table>

</body>

</html>