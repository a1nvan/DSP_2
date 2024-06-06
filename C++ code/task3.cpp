#include "predtren.h"

int main() {
    vector<Complex> test = readInput("complex.txt");
    vector<Complex> test_dft(test);
    vector<Complex> test_fft(test);

    cout<<"A)"<<endl;
    dft(test_dft);
    idft(test_dft);
    cout<<"Ошибка ДПФ "<< sqerror(test,test_dft) <<endl;

    cout<<"\nB)"<<endl;
    fft(test_fft);
    ifft(test_fft);
    cout<<"Ошибка БПФ "<< sqerror(test,test_fft) <<endl;

    cout<<"\nC)"<<endl;
    return 0;
}