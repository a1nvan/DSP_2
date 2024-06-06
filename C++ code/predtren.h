#include <vector>
#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <chrono>
#define PI 3.14159265
using namespace std;
using namespace std::complex_literals;
typedef complex<double> Complex;
const complex<double> i(0.0, 1.0);
vector<Complex> readInput (const string&);
void write (const string& filename, const vector<Complex>& data);
void dft (vector<complex<double>>&);
void idft (vector<complex<double>>&);
unsigned int bitReverse(vector<complex<double>>&);
void fft(vector<complex<double>>&);
void ifft(vector<complex<double>>&);
complex<double> omega(int, int) ;
double sqerror(vector<Complex>,vector<Complex>);
vector<Complex> directConvolution(vector<Complex>,vector<Complex>);
vector<Complex> Convolvefft(vector<Complex>, vector<Complex>);