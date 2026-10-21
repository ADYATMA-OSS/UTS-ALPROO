/* =============================================================================
 * UJIAN TENGAH SEMESTER (UTS) - ALGORITMA DAN PENGANTAR PEMROGRAMAN (SSI1144)
 * PROGRAM STUDI SISTEM INFORMASI - UNIVERSITAS MA CHUNG
 *
 * STUDI KASUS 02 : Sistem Perhitungan Biaya Laundry
 * MODUL A + B    : Proses Utama dan Rekapitulasi Harian
 * =============================================================================
 */

#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

const double TARIF_REGULER = 7000.0;
const double TARIF_EXPRESS = 11000.0;
const double BIAYA_ANTAR = 8000.0;
const double MIN_BERAT = 2.0;
const double MIN_BERAT_MEMBER_DISKON = 5.0;
const double MIN_BERAT_NON_DISKON = 10.0;
const double PERSEN_DISKON_MEMBER = 0.05;
const double PERSEN_DISKON_NON = 0.03;

int main() {
    string namaPelanggan;
    double beratCucian = 0.0;
    int jenisLayanan = 0;
    char statusMember = 'T';
    char layananAntar = 'T';
    char ulang = 'T';

    double beratBulat = 0.0;
    double beratHitung = 0.0;
    double tarifPerKg = 0.0;
    string namaLayanan;
    double subtotalCuci = 0.0;
    double persenDiskonTampil = 0.0;
    double nilaiDiskon = 0.0;
    double biayaAntar = 0.0;
    double totalTagihan = 0.0;
    int counterTransaksi = 0;

    int jumlahReguler = 0;
    int jumlahExpress = 0;
    int jumlahAnggota = 0;
    double totalBeratCucian = 0.0;
    double totalDiskon = 0.0;
    double totalBiayaAntar = 0.0;
    double totalPendapatan = 0.0;
    double transaksiTerbesar = 0.0;
    int nomorTransaksiTerbesar = 0;
    string namaPelangganTerbesar;

    cout << "=================================================================\n";
    cout << "       SISTEM PERHITUNGAN BIAYA LAUNDRY - MODUL A + B\n";
    cout << "=================================================================\n\n";

    do {
        ++counterTransaksi;
        cout << "\n-----------------------------------------------------------------\n";
        cout << " [TRANSAKSI #" << counterTransaksi << "]\n";
        cout << "-----------------------------------------------------------------\n";

        cout << "Masukkan Nama Pelanggan        : ";
        getline(cin >> ws, namaPelanggan);

        while (true) {
            cout << "Masukkan Berat Cucian (kg)     : ";
            if (cin >> beratCucian) {
                if (beratCucian > 0.0) {
                    break;
                }
                cout << "  [ERROR] Berat cucian harus lebih besar dari 0 kg!\n";
            } else {
                cout << "  [ERROR] Masukan harus berupa angka numerik valid!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        while (true) {
            cout << "Pilih Jenis Layanan\n";
            cout << "  1. Reguler (Rp7.000 / kg)\n";
            cout << "  2. Express (Rp11.000 / kg)\n";
            cout << "Pilihan (1/2)                  : ";
            if (cin >> jenisLayanan) {
                if (jenisLayanan == 1 || jenisLayanan == 2) {
                    break;
                }
                cout << "  [ERROR] Pilihan tidak valid! Masukkan angka 1 atau 2.\n";
            } else {
                cout << "  [ERROR] Masukan harus berupa angka (1 atau 2)!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        while (true) {
            cout << "Apakah Pelanggan Memiliki Kartu Member? (Y/T): ";
            cin >> statusMember;
            statusMember = static_cast<char>(
                toupper(static_cast<unsigned char>(statusMember)));
            if (statusMember == 'Y') {
                break;
            }
            if (statusMember == 'T' || statusMember == 'N') {
                statusMember = 'T';
                break;
            }
            cout << "  [ERROR] Masukkan 'Y' untuk Ya atau 'T' (atau 'N') untuk Tidak!\n";
        }

        while (true) {
            cout << "Gunakan Layanan Antar (+Rp8.000)? (Y/T)      : ";
            cin >> layananAntar;
            layananAntar = static_cast<char>(
                toupper(static_cast<unsigned char>(layananAntar)));
            if (layananAntar == 'Y') {
                break;
            }
            if (layananAntar == 'T' || layananAntar == 'N') {
                layananAntar = 'T';
                break;
            }
            cout << "  [ERROR] Masukkan 'Y' untuk Ya atau 'T' (atau 'N') untuk Tidak!\n";
        }

        beratBulat = ceil(beratCucian);
        beratHitung = (beratBulat < MIN_BERAT) ? MIN_BERAT : beratBulat;

        if (jenisLayanan == 1) {
            tarifPerKg = TARIF_REGULER;
            namaLayanan = "Reguler";
        } else {
            tarifPerKg = TARIF_EXPRESS;
            namaLayanan = "Express";
        }

        subtotalCuci = beratHitung * tarifPerKg;
        if (statusMember == 'Y' && beratHitung >= MIN_BERAT_MEMBER_DISKON) {
            persenDiskonTampil = 5.0;
            nilaiDiskon = subtotalCuci * PERSEN_DISKON_MEMBER;
        } else if (statusMember == 'T' && beratHitung >= MIN_BERAT_NON_DISKON) {
            persenDiskonTampil = 3.0;
            nilaiDiskon = subtotalCuci * PERSEN_DISKON_NON;
        } else {
            persenDiskonTampil = 0.0;
            nilaiDiskon = 0.0;
        }

        biayaAntar = (layananAntar == 'Y') ? BIAYA_ANTAR : 0.0;
        totalTagihan = (subtotalCuci - nilaiDiskon) + biayaAntar;

        cout << "\n=================================================================\n";
        cout << "                    RINCIAN TAGIHAN LAUNDRY\n";
        cout << "=================================================================\n";
        cout << left << setw(30) << "No. Transaksi" << ": #" << counterTransaksi << "\n";
        cout << left << setw(30) << "Nama Pelanggan" << ": " << namaPelanggan << "\n";
        cout << left << setw(30) << "Status Keanggotaan" << ": "
             << (statusMember == 'Y' ? "Member" : "Non-Member") << "\n";
        cout << left << setw(30) << "Layanan" << ": " << namaLayanan << "\n";
        cout << fixed << setprecision(2);
        cout << left << setw(30) << "Berat Aktual" << ": " << beratCucian << " kg\n";
        cout << fixed << setprecision(0);
        cout << left << setw(30) << "Berat Dihitung (Aturan)" << ": " << beratHitung << " kg";
        if (beratCucian < MIN_BERAT) {
            cout << " (Dibulatkan ke min. 2 kg)";
        } else if (beratCucian != beratBulat) {
            cout << " (Dibulatkan ke atas)";
        }
        cout << "\n";
        cout << left << setw(30) << "Tarif per Kilogram" << ": Rp " << tarifPerKg << "\n";
        cout << "-----------------------------------------------------------------\n";
        cout << left << setw(30) << "Subtotal Biaya Cucian" << ": Rp " << subtotalCuci << "\n";
        cout << left << setw(30)
             << ("Potongan Diskon (" + to_string(static_cast<int>(persenDiskonTampil)) + "%)")
             << ": -Rp " << nilaiDiskon << "\n";
        cout << left << setw(30) << "Biaya Layanan Antar" << ": Rp " << biayaAntar << "\n";
        cout << "-----------------------------------------------------------------\n";
        cout << left << setw(30) << "TOTAL PEMBAYARAN" << ": Rp " << totalTagihan << "\n";
        cout << "=================================================================\n\n";

        if (jenisLayanan == 1) {
            ++jumlahReguler;
        } else {
            ++jumlahExpress;
        }
        if (statusMember == 'Y') {
            ++jumlahAnggota;
        }

        totalBeratCucian += beratCucian;
        totalDiskon += nilaiDiskon;
        totalBiayaAntar += biayaAntar;
        totalPendapatan += totalTagihan;

        if (counterTransaksi == 1 || totalTagihan > transaksiTerbesar) {
            transaksiTerbesar = totalTagihan;
            nomorTransaksiTerbesar = counterTransaksi;
            namaPelangganTerbesar = namaPelanggan;
        }

        while (true) {
            cout << "Apakah ingin memproses pelanggan lain? (Y/T): ";
            cin >> ulang;
            ulang = static_cast<char>(toupper(static_cast<unsigned char>(ulang)));
            if (ulang == 'Y') {
                break;
            }
            if (ulang == 'T' || ulang == 'N') {
                ulang = 'T';
                break;
            }
            cout << "  [ERROR] Masukkan 'Y' untuk Ya atau 'T' (atau 'N') untuk Tidak!\n";
        }
    } while (ulang == 'Y');

    cout << "\n=================================================================\n";
    cout << "                   REKAPITULASI HARIAN LAUNDRY\n";
    cout << "=================================================================\n";
    cout << left << setw(36) << "Jumlah transaksi Reguler" << ": " << jumlahReguler << "\n";
    cout << left << setw(36) << "Jumlah transaksi Express" << ": " << jumlahExpress << "\n";
    cout << left << setw(36) << "Jumlah pelanggan anggota" << ": " << jumlahAnggota << "\n";
    cout << fixed << setprecision(2);
    cout << left << setw(36) << "Total berat cucian aktual" << ": " << totalBeratCucian << " kg\n";
    cout << fixed << setprecision(0);
    cout << left << setw(36) << "Total diskon" << ": Rp " << totalDiskon << "\n";
    cout << left << setw(36) << "Total biaya antar" << ": Rp " << totalBiayaAntar << "\n";
    cout << left << setw(36) << "Total pendapatan" << ": Rp " << totalPendapatan << "\n";
    if (counterTransaksi > 0) {
        cout << left << setw(36) << "Transaksi terbesar"
             << ": #" << nomorTransaksiTerbesar << " - " << namaPelangganTerbesar << "\n";
        cout << left << setw(36) << "Nilai transaksi terbesar"
             << ": Rp " << transaksiTerbesar << "\n";
    } else {
        cout << "Transaksi terbesar                 : Belum ada transaksi\n";
    }
    cout << "Jumlah transaksi diproses           : " << counterTransaksi << "\n";
    cout << "=================================================================\n";
    cout << "\nTerima kasih telah menggunakan program Sistem Laundry.\n\n";

    return 0;
}
