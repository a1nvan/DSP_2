#include "predtren.h"

int main() 
{
    vector<complex<double>> data = readInput("complex.txt");
    vector<complex<double>> data1 = readInput("complex2.txt");
    dft(data);
    write("output_dft.txt", data);

    idft(data);
    write("output_idft.txt", data);

    return 0;
}