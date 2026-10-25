# Pseudocode Modul B (Rekapitulasi Harian)

```text
ALGORITMA ModulB_RekapLaundry

KONSTANTA
    TARIF_REGULER = 7000, TARIF_EXPRESS = 11000, BIAYA_ANTAR = 8000
    BERAT_MINIMUM = 2, BERAT_MAKSIMUM = 100
    BATAS_ANGGOTA = 5, BATAS_NONANGGOTA = 10
    DISKON_ANGGOTA = 5, DISKON_NONANGGOTA = 3

MULAI
    nomorPelanggan <- 0
    jumlahReguler <- 0 ; jumlahExpress <- 0 ; jumlahAnggota <- 0
    totalBerat <- 0 ; totalDiskon <- 0 ; totalAntar <- 0 ; totalPendapatan <- 0
    transaksiTerbesar <- 0 ; namaTransaksiTerbesar <- "-"
    ULANGI
        nomorPelanggan <- nomorPelanggan + 1
        // --- input dan validasi ---
        ULANGI
            BACA namaPelanggan
        SAMPAI namaPelanggan TIDAK KOSONG
        ULANGI
            BACA beratInput
        SAMPAI beratInput ANGKA DAN beratInput > 0 DAN beratInput <= BERAT_MAKSIMUM
        ULANGI
            BACA jenisLayanan
        SAMPAI jenisLayanan = 1 ATAU jenisLayanan = 2
        ULANGI
            BACA jawabanAnggota
        SAMPAI jawabanAnggota = "y" ATAU jawabanAnggota = "t"
        anggota <- (jawabanAnggota = "y")
        ULANGI
            BACA jawabanAntar
        SAMPAI jawabanAntar = "y" ATAU jawabanAntar = "t"
        layananAntar <- (jawabanAntar = "y")

        // --- proses ---
        beratTagihan <- beratInput dibulatkan ke atas
        JIKA beratTagihan < BERAT_MINIMUM MAKA
            beratTagihan <- BERAT_MINIMUM
        JIKA jenisLayanan = 1 MAKA
            namaLayanan <- "Reguler" ; tarif <- TARIF_REGULER
        SELAIN ITU
            namaLayanan <- "Express" ; tarif <- TARIF_EXPRESS
        biayaLayanan <- beratTagihan * tarif
        persenDiskon <- 0
        JIKA anggota DAN beratTagihan >= BATAS_ANGGOTA MAKA
            persenDiskon <- DISKON_ANGGOTA
        SELAIN ITU JIKA (BUKAN anggota) DAN beratTagihan >= BATAS_NONANGGOTA MAKA
            persenDiskon <- DISKON_NONANGGOTA
        nominalDiskon <- biayaLayanan * persenDiskon / 100
        JIKA layananAntar MAKA biayaAntar <- BIAYA_ANTAR SELAIN ITU biayaAntar <- 0
        totalBayar <- biayaLayanan - nominalDiskon + biayaAntar
        // --- akumulasi rekapitulasi ---
        JIKA jenisLayanan = 1 MAKA jumlahReguler <- jumlahReguler + 1
        SELAIN ITU jumlahExpress <- jumlahExpress + 1
        JIKA anggota MAKA jumlahAnggota <- jumlahAnggota + 1
        totalBerat <- totalBerat + beratTagihan
        totalDiskon <- totalDiskon + nominalDiskon
        totalAntar <- totalAntar + biayaAntar
        totalPendapatan <- totalPendapatan + totalBayar
        JIKA totalBayar > transaksiTerbesar MAKA
            transaksiTerbesar <- totalBayar
            namaTransaksiTerbesar <- namaPelanggan
        // --- ulang atau akhiri ---
        ULANGI
            BACA jawaban
        SAMPAI jawaban = "y" ATAU jawaban = "t"
        lanjut <- (jawaban = "y")
    SAMPAI lanjut = SALAH
    TAMPILKAN rekapitulasi: nomorPelanggan, jumlahReguler, jumlahExpress, jumlahAnggota,
              totalBerat, totalDiskon, totalAntar, totalPendapatan,
              transaksiTerbesar, namaTransaksiTerbesar
SELESAI
```

Pseudocode ini konsisten dengan algoritma deskriptif, flowchart, dan source code `modul_b.cpp`.