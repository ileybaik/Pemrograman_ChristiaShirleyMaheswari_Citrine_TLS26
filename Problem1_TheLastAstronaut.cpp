#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan jumlah K awal: ";
    cin >> K;

    const int MAKS = 1000;
    int astronot[MAKS];
    for (int i = 0; i < N; i++) astronot[i] = i + 1;

    int urutan = N;
    int idx = 0;

    int urutanEliminasi[MAKS];
    int jumlahEliminasi = 0;

    cout << "\n=== Proses Eliminasi ===\n";
    int step = 1;
    while (urutan > 1) {
        idx = (idx + K - 1) % urutan;
        int eliminated = astronot[idx];

        urutanEliminasi[jumlahEliminasi] = eliminated;
        jumlahEliminasi++;

        cout << "Eliminasi ke-" << step << " Astronot #" << eliminated << " (K saat ini = " << K << ")\n";
        step++;

        for (int i = idx; i < urutan - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        urutan--;

        if (eliminated % 2 == 0) K += 2;
        else K -= 1;
        if (K < 2) K = 2;

        if (urutan > 0) idx = idx % urutan;
    }

    cout << "\n=== Urutan Astronot yang Dieliminasi ===\n";
    for (int i =0; i < jumlahEliminasi; i++) {
        cout << urutanEliminasi[i];
        if (i != jumlahEliminasi - 1) cout << " -> ";
    }

    cout << "\n\nAstronot yang bertahan (survivor): #" << astronot[0] << "\n";
    return 0;
}