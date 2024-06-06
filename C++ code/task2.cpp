#include "predtren.h"

int main()
{
    
    vector<complex<double>> data = readInput("complex.txt");
    fft(data);
    write("output_fft.txt", data);

    ifft(data);
    write("output_ifft.txt", data);
}