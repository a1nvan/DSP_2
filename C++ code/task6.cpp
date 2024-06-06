#include "predtren.h"

int main()
{
    vector<Complex> data1 = readInput("complex2.txt");
    vector<Complex> data2 = readInput("complex3.txt");
    vector<Complex> result = Convolvefft(data1,data2);

    write("Convolvfft.txt",result);
}