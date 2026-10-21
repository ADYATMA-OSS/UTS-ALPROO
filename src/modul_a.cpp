/* =============================================================================
 * UJIAN TENGAH SEMESTER (UTS) - ALGORITMA DAN PENGANTAR PEMROGRAMAN (SSI1144)
 * PROGRAM STUDI SISTEM INFORMASI - UNIVERSITAS MA CHUNG
 *
 * STUDI KASUS 02 : Sistem Perhitungan Biaya Laundry
 * MODUL A        : Proses Utama (Input, Perhitungan Biaya, dan Rincian Tagihan)
 * =============================================================================
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Definisi Konstanta Tarif dan Batasan
const double TARIF_REGULER           = 7000.0;  // Biaya per kg layanan reguler
const double TARIF_EXPRESS           = 11000.0; // Biaya per kg layanan express
const double BIAYA_ANTAR             = 8000.0;  // Biaya flat layanan antar jemput
const double MIN_BERAT               = 2.0;     // Berat minimum yang ditagihkan (kg)
const double MIN_BERAT_MEMBER_DISKON = 5.0;     // Syarat berat diskon member (kg)
const double MIN_BERAT_NON_DISKON    = 10.0;    // Syarat berat diskon non-member (kg)
const double PERSEN_DISKON_MEMBER    = 0.05;    // Diskon member (5%)
const double PERSEN_DISKON_NON       = 0.03;    // Diskon non-member (3%)

int main() {
    // Variabel Input
    string namaPelanggan;
    double beratCucian = 0.0;
    int jenisLayanan = 0;       // 1 = Reguler, 2 = Express
    char statusMember = 'N';    // 'Y' atau 'T'
    char layananAntar = 'N';    // 'Y' atau 'T'
    char ulang = 'T';

    // Variabel Perhitungan
    double beratBulat = 0.0;
    double beratHitung = 0.0;
    double tarifPerKg = 0.0;
    string namaLayanan = "";
    double subtotalCuci = 0.0;
    double persenDiskonTampil = 0.0;
    double nilaiDiskon = 0.0;
    double biayaAntar = 0.0;
    double totalTagihan = 0.0;
    int counterTransaksi = 0;

    cout << "=================================================================\n";
    cout << "       SISTEM PERHITUNGAN BIAYA LAUNDRY - MODUL A (PROSES UTAMA) \n";
    cout << "=================================================================\n\n";

    do {
        counterTransaksi++;
        cout << "\n-----------------------------------------------------------------\n";
        cout << " [TRANSAKSI #" << counterTransaksi << "]\n";
        cout << "-----------------------------------------------------------------\n";

        // Input Data Pelanggan
        cout << "Masukkan Nama Pelanggan        : ";
        getline(cin >> ws, namaPelanggan);

        cout << "Masukkan Berat Cucian (kg)     : ";
        cin >> beratCucian;

        cout << "Pilih Jenis Layanan (1. Reguler / 2. Express): ";
        cin >> jenisLayanan;

        cout << "Apakah Pelanggan Memiliki Kartu Member? (Y/T): ";
        cin >> statusMember;
        statusMember = toupper(statusMember);

        cout << "Gunakan Layanan Antar (+Rp8.000)? (Y/T)      : ";
        cin >> layananAntar;
        layananAntar = toupper(layananAntar);

        // Aturan Pembulatan Berat
        beratBulat = ceil(beratCucian);
        if (beratBulat < MIN_BERAT) {
            beratHitung = MIN_BERAT;
        } else {
            beratHitung = beratBulat;
        }

        // Penentuan Tarif Layanan
        if (jenisLayanan == 1) {
            tarifPerKg = TARIF_REGULER;
            namaLayanan = "Reguler";
        } else {
            tarifPerKg = TARIF_EXPRESS;
            namaLayanan = "Express";
        }

        // Perhitungan Subtotal
        subtotalCuci = beratHitung * tarifPerKg;

        // Perhitungan Diskon
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

        // Penentuan Biaya Antar
        if (layananAntar == 'Y') {
            biayaAntar = BIAYA_ANTAR;
        } else {
            biayaAntar = 0.0;
        }

        // Total Pembayaran
        totalTagihan = (subtotalCuci - nilaiDiskon) + biayaAntar;

        // Cetak Struk Rincian Tagihan
        cout << "\n=================================================================\n";
        cout << "                    RINCIAN TAGIHAN LAUNDRY                      \n";
        cout << "=================================================================\n";
        cout << left << setw(30) << "No. Transaksi"           << ": #" << counterTransaksi << "\n";
        cout << left << setw(30) << "Nama Pelanggan"          << ": " << namaPelanggan << "\n";
        cout << left << setw(30) << "Status Keanggotaan"      << ": " << (statusMember == 'Y' ? "Member" : "Non-Member") << "\n";
        cout << left << setw(30) << "Layanan"                 << ": " << namaLayanan << "\n";
        cout << fixed << setprecision(2);
        cout << left << setw(30) << "Berat Aktual"            << ": " << beratCucian << " kg\n";
        cout << fixed << setprecision(0);
        cout << left << setw(30) << "Berat Dihitung (Aturan)" << ": " << beratHitung << " kg\n";
        cout << left << setw(30) << "Tarif per Kilogram"      << ": Rp " << tarifPerKg << "\n";
        cout << "-----------------------------------------------------------------\n";
        cout << left << setw(30) << "Subtotal Biaya Cucian"   << ": Rp " << subtotalCuci << "\n";
        string strDiskon = "Potongan Diskon (" + to_string((int)persenDiskonTampil) + "%)";
        cout << left << setw(30) << strDiskon                 << ": -Rp " << nilaiDiskon << "\n";
        cout << left << setw(30) << "Biaya Layanan Antar"     << ": Rp " << biayaAntar << "\n";
        cout << "-----------------------------------------------------------------\n";
        cout << left << setw(30) << "TOTAL PEMBAYARAN"        << ": Rp " << totalTagihan << "\n";
        cout << "=================================================================\n\n";

        cout << "Apakah ingin memproses pelanggan lain? (Y/T): ";
        cin >> ulang;
        ulang = toupper(ulang);

    } while (ulang == 'Y');

    return 0;
}
