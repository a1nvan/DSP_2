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
const std::complex<double> i(0.0, 1.0);
vector<complex<double>> readInput (const string&);
void write (const string& filename, const vector<complex<double>>& data);
vector<complex<double>> dft (const vector<complex<double>>& input);
vector<complex<double>> idft (const vector<complex<double>>& input);
