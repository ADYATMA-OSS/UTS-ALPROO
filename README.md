# Proyek UTS Algoritma dan Pengantar Pemrograman (SSI1144)
## Studi Kasus 02: Sistem Perhitungan Biaya Laundry

**Program Studi Sistem Informasi**  
**Fakultas Teknologi dan Desain - Universitas Ma Chung**  
**Tahun Akademik: Semester Ganjil (Semester 1)**

---

### Anggota Kelompok
| Peran | Nama Mahasiswa | NIM | Tanggung Jawab Utama |
| :--- | :--- | :--- | :--- |
| **Anggota 1** | *Nur Adyatma Pratama* | *322610016* | **Modul A (Proses Utama)** |
| **Anggota 2** | *(Isi Nama Anggota 2)* | *(Isi NIM)* | **Modul B (Rekapitulasi)** |

---

### Struktur Proyek
```text
uts-with-ema/
├── docs/
│   └── MODUL_A.md        # Dokumentasi lengkap Modul A (Analisis, IPO, Algoritma, Flowchart, Trace Table)
├── src/
│   ├── modul_a.cpp       # Source code C++ Modul A (Proses Utama & Rincian Tagihan)
│   └── modul_a           # Binary hasil kompilasi lokal
└── README.md             # Gambaran umum proyek dan petunjuk eksekusi
```

---

### Cara Mengompilasi dan Menjalankan Modul A
Pastikan terminal Anda memiliki compiler C++ (`g++` atau `clang++`).

1. **Kompilasi source code:**
   ```bash
   g++ -Wall -Wextra -std=c++11 src/modul_a.cpp -o src/modul_a
   ```
   *(atau menggunakan `clang++` di macOS)*
   ```bash
   clang++ -Wall -Wextra -std=c++11 src/modul_a.cpp -o src/modul_a
   ```

2. **Jalankan program:**
   ```bash
   ./src/modul_a
   ```

---

### Ringkasan Ketentuan Studi Kasus 02 (Modul A)
1. **Tarif Layanan Dasar:**
   - Layanan **Reguler**: Rp7.000 / kg
   - Layanan **Express**: Rp11.000 / kg
2. **Aturan Pembulatan Berat:**
   - Berat dibulatkan ke atas (`ceil`).
   - Berat kurang dari 2 kg tetap dihitung minimum 2 kg.
3. **Ketentuan Diskon:**
   - Member dengan berat $\ge 5$ kg: diskon 5%.
   - Non-member dengan berat $\ge 10$ kg: diskon 3%.
4. **Layanan Antar:**
   - Biaya flat Rp8.000 (tidak dipotong diskon).
5. **Validasi:**
   - Berat $\le 0$ kg ditolak dan meminta input ulang.
   - Pilihan menu dan karakter validasi divalidasi ketat agar terhindar dari *crash*.

---

### Rencana Selanjutnya
- [x] Analisis Masalah, IPO, Variabel, dan Konstanta Modul A
- [x] Algoritma Deskriptif, Pseudocode, dan Flowchart Modul A
- [x] Implementasi C++ Modul A dan Penanganan Validasi Input
- [x] Tabel Pengujian (8 Skenario) dan Trace Table Modul A
- [ ] Pengerjaan Modul B (Rekapitulasi Harian, Statistik Pendapatan, Transaksi Terbesar)
- [ ] Integrasi Modul A dan Modul B menjadi Program Utuh
- [ ] Publikasi ke GitHub Pages

