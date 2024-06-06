#include "func.h"

vector<complex<double>> readInput (const string& filename)
{
    ifstream file(filename);
    vector<complex<double>> data;
    double real, image;
    while (file >> real >> image)
    {
        data.emplace_back(real, image);
    }
    return data;

}

void write (const string& filename, const vector<complex<double>>& data)
{
    ofstream file(filename);
    for (const auto& i : data)
    {
        file << i.real() << "  " << i.imag() << endl;
    }
}

vector<complex<double>> dft (const vector<complex<double>>& input)
{
    size_t N = input.size();
    vector<complex<double>> output(N);
    for (size_t k=0; k<N; k++)
    {
        complex<double> sum (0.0,0.0);
        for (size_t j =0; j < N; j++)
        {
            double degree = -2.0*PI*k*j/N;
            sum += input[j]*exp(complex<double>(0.0,degree));
        }
        output[k]=sum/sqrt(static_cast<double>(N));
    }
    return output;
}

vector<complex<double>> idft (const vector<complex<double>>& input)
{
    size_t N = input.size();
    vector<complex<double>> output(N);
    for (size_t j=0; j<N; j++)
    {
        complex<double> sum (0.0,0.0);
        for (size_t k =0; k < N; k++)
        {
            double degree = 2.0*PI*k*j/N;
            sum += input[k]*exp(complex<double>(0.0,degree));
        }
        output[j]=sum/sqrt(static_cast<double>(N));
    }
    return output;
}

int main() {
    // Чтение входных данных
    vector<complex<double>> data = readInput("complex.txt");
    
    // Вычисление ДПФ
    std::vector<std::complex<double>> dft_result = dft(data);
    write("output_dft.txt", dft_result);

    // Вычисление ОДПФ
    std::vector<std::complex<double>> idft_result = idft(dft_result);
    write("output_idft.txt", idft_result);

    return 0;
}