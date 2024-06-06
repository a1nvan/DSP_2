   # Отчет по лабораторной работе


1.Реализовать на С или С++ алгоритмы непосредственного вычисления ДПФ и
ОДПФ по формулам (1) и (2) для комплексного входного сигнала с двойной
точностью (double). Входные данные загружать из текстового файла
(разделитель – пробел), сгенерированного, например, в MATLAB.
```C++
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
```

2. Реализовать на С или С++ алгоритмы прямого и обратного БПФ для
комплексного входного сигнала длиной $2^n$ , n – любое натуральное число:
а) с прореживанием по времени и двоично-инверсными перестановками
(вариант 1);
б) с прореживанием по времени без двоично-инверсных перестановок
(вариант 2);
в) с прореживанием по частоте и двоично-инверсными перестановками
(вариант 3);
г) с прореживанием по частоте без двоично-инверсных перестановок
(вариант 4);
```C++
#include "predtren.h"
int main()
{
    vector<complex<double>> data = readInput("complex.txt");
    fft(data);
    write("output_fft.txt", data);

    ifft(data);
    write("output_ifft.txt", data);
}

3. Убедиться в корректности работы алгоритмов:
а) проверить выполнение равенства $X= ОДПФ(ДПФ(Х))$, а также равенства
$X=ОБПФ(БПФ(Х))$;
б) сравнить результаты ДПФ(Х) и БПФ(Х);
в) сравнить результаты работы реализованного алгоритма, например, с
результатами процедуры $fft$, встроенной в MATLAB.
(рекомендуется для сравнения использовать значение ошибки)
```C++
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

A)
Ошибка ДПФ = 1.9779e-13
B)
Ошибка БПФ = 3.65341e-29

$Ошибка моя и не моя =  1.9680606904870108e-11$

4. Проанализировать зависимость времени выполнения БПФ и непосредственного
вычисления ДПФ от длины N преобразования.
```C++
#include "predtren.h"
int main() {
    int N = 10;
    vector<Complex> time_dft(N);
    vector<Complex> time_fft(N);
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int k = 1; k <= N; k++) { 
        int len = pow(2, k);
        vector<Complex> dfte(len), ffte(len);
        for (int i = 0; i < len; i++) {
            double realPart = static_cast<double>(rand()) / RAND_MAX;
            double imagPart = static_cast<double>(rand()) / RAND_MAX;
            dfte[i] = ffte[i] = Complex(realPart, imagPart);
        }
        auto start = chrono::steady_clock::now();
        dft(dfte);
        auto end = chrono::steady_clock::now();
        time_dft[k - 1] = Complex(len, chrono::duration_cast<chrono::nanoseconds>(end - start).count());
        start = chrono::steady_clock::now();
        fft(ffte);
        end = chrono::steady_clock::now();
        time_fft[k - 1] = Complex(len, chrono::duration_cast<chrono::nanoseconds>(end - start).count());
    }
    write("time_dft.txt", time_dft);
    write("time_fft.txt",time_fft);
    return 0;
}


![image](https://github.com/a1nvan/DSP_2/assets/143883568/d11acc89-c11c-4740-a4b5-843088d92dc9)

5. Реализовать на С или С++ процедуру прямого вычисления свертки двух
последовательностей по формуле (3). Входные данные загружать из текстового
файла (разделитель – пробел), сгенерированного, например, в MATLAB.
```C++
#include "predtren.h"
int main()
{
    vector<Complex> data1 = readInput("complex2.txt");
    vector<Complex> data2 = readInput("complex3.txt");
    vector<Complex> result = directConvolution(data1,data2);
    write("directConv.txt",result);
}


6. Реализовать процедуру нахождения дискретной свертки, основанную на БПФ.
При вычислении БПФ использовать результаты п. 2 задания.
```C++
#include "predtren.h"
int main()
{
    vector<Complex> data1 = readInput("complex2.txt");
    vector<Complex> data2 = readInput("complex3.txt");
    vector<Complex> result = Convolvefft(data1,data2);
    write("Convolvfft.txt",result);
}


7. Убедится в корректности работы процедуры из п. 5 и п. 6 задания, сравнив
полученные результаты с результатами работы встроенной функций MATLAB
conv.
(рекомендуется для сравнения использовать значение ошибки)

$Ошибка между прямой свертки и свертки с БПФ =  1.3306385211402124e-11$
$Ошибка между питоновскорй свертки и прямой свертки =  1.3306385523421496e-11$
$Ошибка между питоновской свертки и свертки с БПФ =  1.3306385523421496e-11$


8. Сравнить производительность алгоритмов вычисления свертки по
определению (3) и с помощью БПФ в двух случаях: когда размер одной из
последовательностей фиксирован, и когда меняются длины обеих
последовательностей.
```C++
#include "predtren.h"

int main() {
    int N = 15;
    vector<Complex> time_direct(N);
    vector<Complex> time_fft(N);
    vector<Complex> x;
    vector<Complex> y;

    y.resize(256, 1);  

    for (int k = 0; k < N; k++) {
        x.resize(pow(2, k), 1);

        auto start = chrono::steady_clock::now();
        directConvolution(x, y);
        auto end = chrono::steady_clock::now();
        time_direct[k] = Complex(k, chrono::duration<double, std::nano>(end - start).count());

        start = chrono::steady_clock::now();
        Convolvefft(x, y);
        end = chrono::steady_clock::now();
        time_fft[k] = Complex(k, chrono::duration<double, std::nano>(end - start).count());
    }

    write("time_direct_fixed.txt", time_direct);
    write("time_fft_fixed.txt", time_fft);

    for (int k = 0; k < N; k++) {
        x.resize(pow(2, k), 1);
        y.resize(pow(2, k), 1);

        auto start = chrono::steady_clock::now();
        directConvolution(x, y);
        auto end = chrono::steady_clock::now();
        time_direct[k] = Complex(k, chrono::duration<double, std::nano>(end - start).count());

        start = chrono::steady_clock::now();
        Convolvefft(x, y);
        end = chrono::steady_clock::now();
        time_fft[k] = Complex(k, chrono::duration<double, std::nano>(end - start).count());
    }

    write("time_direct_variable.txt", time_direct);
    write("time_fft_variable.txt", time_fft);

    return 0;
}

![image](https://github.com/a1nvan/DSP_2/assets/143883568/77a5ba5c-51ec-4bdb-94cc-e691757f889c)
![image](https://github.com/a1nvan/DSP_2/assets/143883568/411d3ff8-e8f4-4ab9-b268-8ff417605c00)


