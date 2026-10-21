# DOKUMENTASI PROYEK UTS - MODUL A (PROSES UTAMA)
**Mata Kuliah:** Algoritma dan Pengantar Pemrograman (SSI1144)  
**Program Studi:** Sistem Informasi - Fakultas Teknologi dan Desain, Universitas Ma Chung  
**Studi Kasus 02:** Sistem Perhitungan Biaya Laundry  
**Fokus Pengerjaan:** Modul A (Proses Utama, Validasi, Perhitungan Biaya, dan Rincian Tagihan)

---

## 1. Analisis Masalah

### 1.1 Latar Belakang & Deskripsi Masalah
Usaha laundry membutuhkan sistem kasir berbasis terminal/console yang dapat menghitung biaya transaksi laundry secara akurat, konsisten, dan otomatis berdasarkan aturan tarif, pembulatan berat, hak diskon pelanggan, serta biaya tambahan antar jemput. Program harus mampu memvalidasi kesalahan input pengguna dan menyajikan rincian tagihan transparan kepada pelanggan.

### 1.2 Pengguna Program (Target User)
- **Operator Kasir Laundry**: Memasukkan data transaksi cucian pelanggan setiap kali ada pesanan masuk dan mencetak rincian tagihan ke layar.

### 1.3 Ketentuan & Aturan Bisnis
1. **Pilihan Layanan & Tarif Dasar:**
   - Layanan **Reguler**: Rp7.000 per kilogram.
   - Layanan **Express**: Rp11.000 per kilogram.
2. **Aturan Perhitungan Berat:**
   - Berat cucian pecahan dibulatkan ke atas ke bilangan bulat terdekat (contoh: 2.1 kg menjadi 3 kg).
   - Berat cucian kurang dari 2 kg tetap dihitung 2 kg (minimum charge).
3. **Ketentuan Diskon:**
   - **Pelanggan Member**: Jika berat cucian terhitung $\ge 5$ kg, mendapatkan diskon 5% dari subtotal biaya cuci.
   - **Pelanggan Non-Member**: Jika berat cucian terhitung $\ge 10$ kg, mendapatkan diskon 3% dari subtotal biaya cuci.
   - Selain kondisi di atas, diskon adalah 0%.
4. **Layanan Antar:**
   - Layanan antar dikenakan biaya tambahan sebesar **Rp8.000**.
   - Biaya antar **tidak termasuk** komponen yang memperoleh potongan diskon.
5. **Rumus Perhitungan:**
   - $\text{Subtotal Cuci} = \text{Berat Hitung} \times \text{Tarif per kg}$
   - $\text{Nilai Diskon} = \text{Subtotal Cuci} \times \text{Persentase Diskon}$
   - $\text{Total Pembayaran} = (\text{Subtotal Cuci} - \text{Nilai Diskon}) + \text{Biaya Antar}$

### 1.4 Penanganan Input Tidak Valid (Validasi Data)
- Berat cucian bernilai $\le 0$ atau berupa input non-numerik harus ditolak dan diminta input ulang.
- Pilihan layanan selain angka `1` atau `2` harus ditolak.
- Pilihan status keanggotaan dan layanan antar selain `Y`/`y` atau `T`/`t`/`N`/`n` harus ditolak.
- Program tidak boleh berhenti secara tiba-tiba (*crash/infinite loop*).

---

## 2. Analisis Input-Process-Output (IPO)

| Kategori | Data / Operasi | Keterangan |
| :--- | :--- | :--- |
| **Input** | `namaPelanggan` | Nama lengkap pelanggan (teks / string) |
| | `beratCucian` | Berat aktual cucian dalam kilogram (angka desimal / double) |
| | `jenisLayanan` | Jenis layanan cucian: 1 untuk Reguler, 2 untuk Express (integer) |
| | `statusMember` | Status kartu keanggotaan: 'Y' (Ya) / 'T' (Tidak) (karakter) |
| | `layananAntar` | Penggunaan opsi antar jemput: 'Y' (Ya) / 'T' (Tidak) (karakter) |
| | `ulang` | Pilihan pemrosesan transaksi berikutnya: 'Y' / 'T' (karakter) |
| **Process** | Validasi Input | Memastikan data numerik positif dan menu pilihan valid |
| | Pembulatan Berat | `beratBulat = ceil(beratCucian)` |
| | Penerapan Berat Minimum | `IF beratBulat < 2 THEN beratHitung = 2 ELSE beratHitung = beratBulat` |
| | Penentuan Tarif per kg | `IF jenisLayanan == 1 THEN tarif = 7000 ELSE tarif = 11000` |
| | Subtotal Cuci | `subtotalCuci = beratHitung * tarifPerKg` |
| | Evaluasi Diskon | `IF member == 'Y' AND beratHitung >= 5 THEN diskon = 5%`<br>`ELSE IF member == 'T' AND beratHitung >= 10 THEN diskon = 3%`<br>`ELSE diskon = 0%` |
| | Biaya Antar | `IF layananAntar == 'Y' THEN biayaAntar = 8000 ELSE biayaAntar = 0` |
| | Total Akhir | `totalTagihan = (subtotalCuci - nilaiDiskon) + biayaAntar` |
| **Output** | Struk Rincian Tagihan | Nomor transaksi, Nama pelanggan, Status member, Nama layanan, Berat aktual, Berat dihitung, Tarif/kg, Subtotal cucian, Nilai diskon, Biaya antar, Total pembayaran |

---

## 3. Variabel, Konstanta, dan Tipe Data

### 3.1 Tabel Konstanta
| Nama Konstanta | Tipe Data | Nilai | Kegunaan |
| :--- | :--- | :--- | :--- |
| `TARIF_REGULER` | `const double` | `7000.0` | Tarif per kg layanan reguler |
| `TARIF_EXPRESS` | `const double` | `11000.0` | Tarif per kg layanan express |
| `BIAYA_ANTAR` | `const double` | `8000.0` | Biaya tetap jasa antar jemput |
| `MIN_BERAT` | `const double` | `2.0` | Batas minimum berat tagihan (kg) |
| `MIN_BERAT_MEMBER_DISKON` | `const double` | `5.0` | Ambang batas berat diskon pelanggan member |
| `MIN_BERAT_NON_DISKON` | `const double` | `10.0` | Ambang batas berat diskon non-member |
| `PERSEN_DISKON_MEMBER` | `const double` | `0.05` | Besaran diskon member (5%) |
| `PERSEN_DISKON_NON` | `const double` | `0.03` | Besaran diskon non-member (3%) |

### 3.2 Tabel Variabel
| Nama Variabel | Tipe Data | Nilai Awal | Kegunaan |
| :--- | :--- | :--- | :--- |
| `namaPelanggan` | `string` | `""` | Menyimpan nama lengkap pelanggan |
| `beratCucian` | `double` | `0.0` | Menyimpan nilai berat asli dari timbangan |
| `jenisLayanan` | `int` | `0` | Menyimpan pilihan kode layanan (1 atau 2) |
| `statusMember` | `char` | `'N'` | Menyimpan status keanggotaan ('Y' / 'T') |
| `layananAntar` | `char` | `'N'` | Menyimpan pilihan opsi antar ('Y' / 'T') |
| `ulang` | `char` | `'T'` | Menyimpan pilihan perulangan transaksi ('Y' / 'T') |
| `beratBulat` | `double` | `0.0` | Menyimpan hasil pembulatan ke atas berat cucian |
| `beratHitung` | `double` | `0.0` | Berat final yang dikenakan tarif setelah aturan minimum 2 kg |
| `tarifPerKg` | `double` | `0.0` | Tarif per kg yang berlaku sesuai jenis layanan |
| `namaLayanan` | `string` | `""` | Deskripsi teks nama layanan ("Reguler" / "Express") |
| `subtotalCuci` | `double` | `0.0` | Hasil kali `beratHitung` dengan `tarifPerKg` |
| `persenDiskonTampil` | `double` | `0.0` | Persentase diskon untuk ditampilkan di struk (0, 3, atau 5) |
| `nilaiDiskon` | `double` | `0.0` | Besaran diskon dalam bentuk Rupiah |
| `biayaAntar` | `double` | `0.0` | Biaya antar dalam bentuk Rupiah (0 atau 8000) |
| `totalTagihan` | `double` | `0.0` | Total biaya akhir yang wajib dibayarkan pelanggan |
| `counterTransaksi` | `int` | `0` | Menghitung nomor urut transaksi yang diproses |
