#include "predtren.h"

complex<double> omega(int n, int k) {
    return exp(complex<double>(0, -2.0 * PI * k / n));
}

vector<Complex> readInput (const string& filename)
{
    ifstream file(filename);
    vector<Complex> data;
    double real, image;
    while (file >> real >> image)
    {
        data.emplace_back(real, image);
    }
    return data;

}

void write (const string& filename, const vector<Complex>& data)
{
    string filepath = "../output/" + filename;
    ofstream file(filepath);

    if (!file.is_open()) 
    {
        cerr << "Ошибка открытия файла: " << filepath << endl;
        return;
    }

    for (const auto& i : data)
    {
        file << setprecision(20) << i.real() << " " << setprecision(20) << i.imag() << endl;
    }
}

void dft(vector<complex<double>>& input) {
    size_t N = input.size();
    vector<complex<double>> output(N);
    for (size_t k = 0; k < N; ++k) {
        complex<double> sum(0.0, 0.0);
        for (size_t j = 0; j < N; ++j) {
            double degree = -2.0 * PI * k * j / N;
            sum += input[j] * exp(complex<double>(0.0, degree));
        }
        output[k] = sum / sqrt(static_cast<double>(N));
    }
    input = output;
}

void idft(vector<complex<double>>& input) {
    size_t N = input.size();
    vector<complex<double>> output(N);
    for (size_t k = 0; k < N; ++k) {
        complex<double> sum(0.0, 0.0);
        for (size_t j = 0; j < N; ++j) {
            double degree = 2.0 * PI * k * j / N;
            sum += input[j] * exp(complex<double>(0.0, degree));
        }
        output[k] = sum / sqrt(static_cast<double>(N));
    }
    input = output;
}

unsigned int reverseBits(unsigned int num, int log2n) {
    unsigned int reversedNum = 0;
    for (int i = 0; i < log2n; i++) {
        reversedNum = (reversedNum << 1) | (num & 1);
        num >>= 1;
    }
    return reversedNum;
}

void fft(vector<complex<double>> &a) {
    int N = a.size();
    int n = log2(N);

    for (unsigned int i = 0; i < N; ++i) {
        unsigned int rev = reverseBits(i, n);
        if (i < rev) {
            swap(a[i], a[rev]);
        }
    }

    for (int k = 1; k <= n; k++) {
        int degree = pow(2, k);
        double angle = -2 * PI / degree;
        Complex omega_m = exp(Complex(0, angle));

        for (int j = 0; j < N; j += degree) {
            Complex omega = 1;

            for (int l = 0; l < degree / 2; l++) {
                Complex t = omega * a[j + l + degree / 2];
                Complex u = a[j + l];
                a[j + l] = u + t;
                a[j + l + degree / 2] = u - t;
                omega *= omega_m;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        a[i] /= sqrt(N);
    }
}

void ifft(vector<complex<double>>& a) {
    for (auto& x : a) {
        x = conj(x);  
    }
    fft(a);  
    for (auto& x : a) {
        x = conj(x);  
    }
}

double sqerror(vector<Complex> x,vector<Complex> y){
    double sqerr=0;
    for(int i=0;i<x.size();i++)
        sqerr+=abs(pow(x[i]-y[i],2));
    return sqerr;
}

vector<Complex> directConvolution(vector<Complex> x, vector<Complex> y)
 {
    if (x.size() > y.size()) x.swap(y);
    int N = x.size();
    int M = y.size();
    vector<Complex> u(N + M - 1);

    for (int n = 0; n < N + M - 1; ++n) {
        Complex sum = 0;
        for (int k = 0; k < N; ++k) {
            if (n - k >= 0 && n - k < M) {
                sum += x[k] * y[n - k];
            }
        }
        u[n] = sum;
    }

    return u;
}


vector<Complex> Convolvefft(vector<Complex> x, vector<Complex> y) {
    Complex zero = (0, 0);
    int M = x.size();
    int L = y.size();
    int N2 = M > L ? 2 * M : 2 * L;
    int N = pow(2, ceil(log2(N2)));
    vector<Complex> c(N);
    x.resize(N , zero);
    y.resize(N, zero);
    fft(x);
    fft(y);
    double s = sqrt(N);
    for (size_t i = 0; i < N; i++) {
        c[i] = s * x[i] * y[i];
    }
    ifft(c);
    return c;
}