/* =============================================================================
 * UJIAN TENGAH SEMESTER (UTS) - ALGORITMA DAN PENGANTAR PEMROGRAMAN (SSI1144)
 * PROGRAM STUDI SISTEM INFORMASI - UNIVERSITAS MA CHUNG
 *
 * STUDI KASUS 02 : Sistem Perhitungan Biaya Laundry
 * MODUL A        : Proses Utama (Input Data, Validasi, Perhitungan, & Rincian Tagihan)
 * =============================================================================
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

// Definisi Konstanta Tarif dan Batasan
const double TARIF_REGULER   = 7000.0; // Biaya per kg layanan reguler
const double TARIF_EXPRESS   = 11000.0; // Biaya per kg layanan express
const double BIAYA_ANTAR     = 8000.0; // Biaya flat layanan antar jemput
const double MIN_BERAT       = 2.0;    // Berat minimum yang ditagihkan (kg)
const double MIN_BERAT_MEMBER_DISKON = 5.0;  // Syarat berat diskon member (kg)
const double MIN_BERAT_NON_DISKON    = 10.0; // Syarat berat diskon non-member (kg)
const double PERSEN_DISKON_MEMBER    = 0.05; // Diskon member (5%)
const double PERSEN_DISKON_NON       = 0.03; // Diskon non-member (3%)

int main() {
    // Variabel Input
    string namaPelanggan;
    double beratCucian = 0.0;
    int jenisLayanan = 0;       // 1 = Reguler, 2 = Express
    char statusMember = 'N';    // 'Y' atau 'N'
    char layananAntar = 'N';    // 'Y' atau 'N'
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

        // 1. Input Nama Pelanggan
        cout << "Masukkan Nama Pelanggan        : ";
        getline(cin >> ws, namaPelanggan);

        // 2. Input dan Validasi Berat Cucian (kg)
        while (true) {
            cout << "Masukkan Berat Cucian (kg)     : ";
            if (cin >> beratCucian) {
                if (beratCucian > 0.0) {
                    break; // Input valid
                } else {
                    cout << "  [ERROR] Berat cucian harus lebih besar dari 0 kg!\n";
                }
            } else {
                cout << "  [ERROR] Masukan harus berupa angka numerik valid!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // 3. Input dan Validasi Jenis Layanan (1. Reguler, 2. Express)
        while (true) {
            cout << "Pilih Jenis Layanan\n";
            cout << "  1. Reguler (Rp7.000 / kg)\n";
            cout << "  2. Express (Rp11.000 / kg)\n";
            cout << "Pilihan (1/2)                  : ";
            if (cin >> jenisLayanan) {
                if (jenisLayanan == 1 || jenisLayanan == 2) {
                    break;
                } else {
                    cout << "  [ERROR] Pilihan tidak valid! Masukkan angka 1 atau 2.\n";
                }
            } else {
                cout << "  [ERROR] Masukan harus berupa angka (1 atau 2)!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // 4. Input dan Validasi Status Keanggotaan (Member)
        while (true) {
            cout << "Apakah Pelanggan Memiliki Kartu Member? (Y/T): ";
            cin >> statusMember;
            statusMember = toupper(statusMember);
            if (statusMember == 'Y') {
                break;
            } else if (statusMember == 'T' || statusMember == 'N') {
                statusMember = 'T'; // Standarisasi 'T' (Tidak)
                break;
            } else {
                cout << "  [ERROR] Masukkan 'Y' untuk Ya atau 'T' (atau 'N') untuk Tidak!\n";
            }
        }

        // 5. Input dan Validasi Layanan Antar
        while (true) {
            cout << "Gunakan Layanan Antar (+Rp8.000)? (Y/T)      : ";
            cin >> layananAntar;
            layananAntar = toupper(layananAntar);
            if (layananAntar == 'Y') {
                break;
            } else if (layananAntar == 'T' || layananAntar == 'N') {
                layananAntar = 'T'; // Standarisasi 'T' (Tidak)
                break;
            } else {
                cout << "  [ERROR] Masukkan 'Y' untuk Ya atau 'T' (atau 'N') untuk Tidak!\n";
            }
        }

        // =================================================================
        // PROSES PERHITUNGAN
        // =================================================================

        // A. Aturan Pembulatan Berat
        // Ketentuan 1: Berat dibulatkan ke atas.
        beratBulat = ceil(beratCucian);

        // Ketentuan 2: Berat kurang dari dua kilogram tetap dihitung dua kilogram.
        if (beratBulat < MIN_BERAT) {
            beratHitung = MIN_BERAT;
        } else {
            beratHitung = beratBulat;
        }

        // B. Penentuan Tarif Layanan
        if (jenisLayanan == 1) {
            tarifPerKg = TARIF_REGULER;
            namaLayanan = "Reguler";
        } else {
            tarifPerKg = TARIF_EXPRESS;
            namaLayanan = "Express";
        }

        // C. Perhitungan Subtotal Biaya Cuci
        subtotalCuci = beratHitung * tarifPerKg;

        // D. Perhitungan Diskon
        // Ketentuan:
        // - Anggota dengan berat minimal 5 kg memperoleh diskon 5%
        // - Nonanggota minimal 10 kg memperoleh diskon 3%
        // - Diskon dihitung dari biaya cuci (layanan antar tidak memperoleh diskon)
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

        // E. Penentuan Biaya Antar
        // Ketentuan: Layanan antar Rp8.000 dan tidak didiskon
        if (layananAntar == 'Y') {
            biayaAntar = BIAYA_ANTAR;
        } else {
            biayaAntar = 0.0;
        }

        // F. Perhitungan Total Tagihan
        totalTagihan = (subtotalCuci - nilaiDiskon) + biayaAntar;

        // =================================================================
        // OUTPUT: RINCIAN TAGIHAN PELANGGAN
        // =================================================================
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
        cout << left << setw(30) << "Berat Dihitung (Aturan)" << ": " << beratHitung << " kg";
        if (beratCucian < MIN_BERAT) {
            cout << " (Dibulatkan ke min. 2 kg)";
        } else if (beratCucian != beratBulat) {
            cout << " (Dibulatkan ke atas)";
        }
        cout << "\n";
        cout << left << setw(30) << "Tarif per Kilogram"      << ": Rp " << tarifPerKg << "\n";
        cout << "-----------------------------------------------------------------\n";
        string strDiskon = "Potongan Diskon (" + to_string((int)persenDiskonTampil + 0) + "%)";
        cout << left << setw(30) << "Subtotal Biaya Cucian"   << ": Rp " << subtotalCuci << "\n";
        cout << left << setw(30) << strDiskon                 << ": -Rp " << nilaiDiskon << "\n";
        cout << left << setw(30) << "Biaya Layanan Antar"     << ": Rp " << biayaAntar << "\n";
        cout << "-----------------------------------------------------------------\n";
        cout << left << setw(30) << "TOTAL PEMBAYARAN"        << ": Rp " << totalTagihan << "\n";
        cout << "=================================================================\n\n";

        // Tanya apakah ingin menginput data pelanggan berikutnya
        while (true) {
            cout << "Apakah ingin memproses pelanggan lain? (Y/T): ";
            cin >> ulang;
            ulang = toupper(ulang);
            if (ulang == 'Y') {
                break;
            } else if (ulang == 'T' || ulang == 'N') {
                ulang = 'T';
                break;
            } else {
                cout << "  [ERROR] Masukkan 'Y' untuk Ya atau 'T' (atau 'N') untuk Tidak!\n";
            }
        }

    } while (ulang == 'Y');

    cout << "\nTerima kasih telah menggunakan program Sistem Laundry (Modul A).\n";
    cout << "Total transaksi yang diproses pada sesi ini: " << counterTransaksi << " transaksi.\n\n";

    return 0;
}
