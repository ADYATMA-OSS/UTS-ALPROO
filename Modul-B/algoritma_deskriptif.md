# Algoritma Deskriptif Modul B

Penanggung jawab: **Khoirun Ni'mah** (322610007)

1. Mulai.
2. Set nomor pelanggan = 0, seluruh akumulator = 0, transaksi terbesar = 0, nama transaksi terbesar = "-".
3. Ulangi sampai valid: baca nama pelanggan; tolak jika kosong.
4. Ulangi sampai valid: baca berat cucian; tolak jika bukan angka, kurang dari atau sama dengan 0, atau lebih dari 100 kg.
5. Ulangi sampai valid: baca jenis layanan; hanya 1 (Reguler) atau 2 (Express) yang diterima.
6. Ulangi sampai valid: baca status anggota (y/t).
7. Ulangi sampai valid: baca pilihan layanan antar (y/t).
8. Hitung berat tagihan: bulatkan berat ke atas ke bilangan bulat; jika kurang dari 2, jadikan 2.
9. Tentukan tarif: jika jenis layanan 1 maka Rp7.000/kg, selain itu Rp11.000/kg.
10. Hitung biaya layanan = berat tagihan x tarif.
11. Tentukan persen diskon: jika anggota dan berat tagihan >= 5 maka 5%; jika bukan anggota dan berat tagihan >= 10 maka 3%; selain itu 0%.
12. Hitung nominal diskon = biaya layanan x persen diskon / 100.
13. Tentukan biaya antar: Rp8.000 jika memilih antar, selain itu Rp0 (biaya antar tidak didiskon).
14. Hitung total bayar = biaya layanan - nominal diskon + biaya antar.
15. Perbarui akumulator: tambah jumlah reguler atau express; tambah jumlah anggota jika anggota; tambahkan berat tagihan, nominal diskon, biaya antar, dan total bayar ke total masing-masing; jika total bayar lebih besar dari transaksi terbesar saat ini, simpan nilai dan nama pelanggannya.
16. Ulangi sampai valid: tanyakan apakah memproses pelanggan lain (y/t).
17. Jika jawaban y, kembali ke langkah 3; jika t, lanjut ke langkah 18.
18. Tampilkan rekapitulasi harian: total pelanggan, jumlah reguler, jumlah express, jumlah anggota, total berat, total diskon, total biaya antar, total pendapatan, transaksi terbesar.
19. Selesai.