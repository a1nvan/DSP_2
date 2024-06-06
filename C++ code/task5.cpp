#include "predtren.h"

int main()
{
    vector<Complex> data1 = readInput("complex2.txt");
    vector<Complex> data2 = readInput("complex3.txt");
    vector<Complex> result = directConvolution(data1,data2);

    write("directConv.txt",result);
}