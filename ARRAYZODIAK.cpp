#include <iostream>
#include <string>

using namespace std;

struct Zodiak {
    string nama;
    int tanggal_mulai, bulan_mulai;
    int tanggal_selesai, bulan_selesai;
};

// Fungsi untuk mengecek apakah tanggal lahir berada di antara rentang zodiak
bool cekZodiak(int tgl, int bln, Zodiak z) {
    if (bln == z.bulan_mulai && tgl >= z.tanggal_mulai)
        return true;
    if (bln == z.bulan_selesai && tgl <= z.tanggal_selesai)
        return true;
    if (bln > z.bulan_mulai && bln < z.bulan_selesai)
        return true;
    return false;
}

int main() {
    // Array zodiak
    Zodiak daftarZodiak[12] = {
        {"CAPRICORN", 22, 12, 19, 1},
        {"AQUARIUS", 20, 1, 18, 2},
        {"PISCES", 19, 2, 20, 3},
        {"ARIES", 21, 3, 19, 4},
        {"TAURUS", 20, 4, 20, 5},
        {"GEMINI", 21, 5, 20, 6},
        {"CANCER", 21, 6, 22, 7},
        {"LEO", 23, 7, 22, 8},
        {"VIRGO", 23, 8, 22, 9},
        {"LIBRA", 23, 9, 22, 10},
        {"SCORPIO", 23, 10, 21, 11},
        {"SAGITTARIUS", 22, 11, 21, 12}
    };

    int tanggal, bulan, tahun;

    // Input tanggal lahir
    cout << "Tanggal Lahir Anda [tgl-bln-tahun]: ";
    cin >> tanggal;
    cin.ignore(1, '-');
    cin >> bulan;
    cin.ignore(1, '-');
    cin >> tahun;

    // Mencari zodiak berdasarkan tanggal dan bulan
    for (int i = 0; i < 12; i++) {
        if (cekZodiak(tanggal, bulan, daftarZodiak[i])) {
            cout << "Zodiak Anda adalah: " << daftarZodiak[i].nama << endl;
            break;
        }
    }

    return 0;
}
