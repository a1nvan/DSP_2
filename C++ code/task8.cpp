#include "predtren.h"

int main() {
    int N = 15;
    vector<Complex> time_direct(N);
    vector<Complex> time_fft(N);
    vector<Complex> x;
    vector<Complex> y;

    y.resize(256, 1);  

    for (int k = 0; k < N; k++) {
        x.resize(pow(2, k), 1);

        auto start = chrono::steady_clock::now();
        directConvolution(x, y);
        auto end = chrono::steady_clock::now();
        time_direct[k] = Complex(k, chrono::duration<double, std::nano>(end - start).count());

        start = chrono::steady_clock::now();
        Convolvefft(x, y);
        end = chrono::steady_clock::now();
        time_fft[k] = Complex(k, chrono::duration<double, std::nano>(end - start).count());
    }

    write("time_direct_fixed.txt", time_direct);
    write("time_fft_fixed.txt", time_fft);

    for (int k = 0; k < N; k++) {
        x.resize(pow(2, k), 1);
        y.resize(pow(2, k), 1);

        auto start = chrono::steady_clock::now();
        directConvolution(x, y);
        auto end = chrono::steady_clock::now();
        time_direct[k] = Complex(k, chrono::duration<double, std::nano>(end - start).count());

        start = chrono::steady_clock::now();
        Convolvefft(x, y);
        end = chrono::steady_clock::now();
        time_fft[k] = Complex(k, chrono::duration<double, std::nano>(end - start).count());
    }

    write("time_direct_variable.txt", time_direct);
    write("time_fft_variable.txt", time_fft);

    return 0;
}