#include <iostream>
using namespace std;

int hitungPanjang(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

char keHurufBesar(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}

int nilaiHuruf(char c) {
    return keHurufBesar(c) - 'A' + 1;
}

char hurufDariNilai(int v) {
    int sisa = (v - 1) % 26;
    return 'A' + sisa;
}

int main() {
    const int MAKS = 1000;
    char pesan[MAKS];
    char sandi[MAKS];

    cout << "Masukkan pesan (huruf tanpa spasi): ";
    cin >> pesan;

    int panjang = hitungPanjang(pesan);

    for (int i = 0; i < panjang; i++) {
        pesan[i] = keHurufBesar(pesan[i]);
    }

    sandi[0] = pesan[0];
    for (int i = 1; i < panjang; i++) {
        int nilaiSekarang = nilaiHuruf(pesan[i]);
        int nilaiSebelumnya = nilaiHuruf(pesan[i - 1]);
        int nilaiBaru = nilaiSekarang + nilaiSebelumnya;
        sandi[i] = hurufDariNilai(nilaiBaru);
    } 
    sandi[panjang] = '\0';

    cout << "\nPesan asli : " << pesan << "\n";
    cout << "Pesan sandi : " << sandi << "\n";

    return 0;
}