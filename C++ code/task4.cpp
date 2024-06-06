#include "predtren.h"

int main() {
    int N = 10;
    vector<Complex> time_dft(N);
    vector<Complex> time_fft(N);

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int k = 1; k <= N; k++) { 
        int len = pow(2, k);
        vector<Complex> dfte(len), ffte(len);

        for (int i = 0; i < len; i++) {
            double realPart = static_cast<double>(rand()) / RAND_MAX;
            double imagPart = static_cast<double>(rand()) / RAND_MAX;
            dfte[i] = ffte[i] = Complex(realPart, imagPart);
        }

        auto start = chrono::steady_clock::now();
        dft(dfte);
        auto end = chrono::steady_clock::now();
        time_dft[k - 1] = Complex(len, chrono::duration_cast<chrono::nanoseconds>(end - start).count());

        start = chrono::steady_clock::now();
        fft(ffte);
        end = chrono::steady_clock::now();
        time_fft[k - 1] = Complex(len, chrono::duration_cast<chrono::nanoseconds>(end - start).count());
    }

    write("time_dft.txt", time_dft);
    write("time_fft.txt",time_fft);

    return 0;
}