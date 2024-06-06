#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <cmath>

const double PI = 3.141592653589793238460;

// Функция для чтения входных данных из файла
std::vector<std::complex<double>> readInput(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::complex<double>> data;
    double real, imag;
    while (file >> real >> imag) {
        data.emplace_back(real, imag);
    }
    return data;
}

// Функция для записи данных в файл
void writeOutput(const std::string& filename, const std::vector<std::complex<double>>& data) {
    std::ofstream file(filename);
    for (const auto& c : data) {
        file << c.real() << " " << c.imag() << "\n";
    }
}

// Функция для вычисления ДПФ
std::vector<std::complex<double>> dft(const std::vector<std::complex<double>>& input) {
    size_t N = input.size();
    std::vector<std::complex<double>> output(N);
    for (size_t k = 0; k < N; ++k) {
        std::complex<double> sum(0.0, 0.0);
        for (size_t n = 0; n < N; ++n) {
            double angle = -2.0 * PI * k * n / N;
            sum += input[n] * std::exp(std::complex<double>(0.0, angle));
        }
        output[k] = sum/sqrt(static_cast<double>(N));
    }
    return output;
}

// Функция для вычисления ОДПФ
std::vector<std::complex<double>> idft(const std::vector<std::complex<double>>& input) {
    size_t N = input.size();
    std::vector<std::complex<double>> output(N);
    for (size_t n = 0; n < N; ++n) {
        std::complex<double> sum(0.0, 0.0);
        for (size_t k = 0; k < N; ++k) {
            double angle = 2.0 * PI * k * n / N;
            sum += input[k] * std::exp(std::complex<double>(0.0, angle));
        }
        output[n] = sum / sqrt(static_cast<double>(N));
    }
    return output;
}

int main() {
    // Чтение входных данных
    std::vector<std::complex<double>> data = readInput("complex.txt");

    // Вычисление ДПФ
    std::vector<std::complex<double>> dft_result = dft(data);
    writeOutput("output_dft.txt", dft_result);

    // Вычисление ОДПФ
    std::vector<std::complex<double>> idft_result = idft(dft_result);
    writeOutput("output_idft.txt", idft_result);

    return 0;
}