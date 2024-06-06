   # Отчет по лабораторной работе

    Реализовать на С или С++ алгоритмы непосредственного вычисления ДПФ и
ОДПФ по формулам (1) и (2) для комплексного входного сигнала с двойной
точностью (double). Входные данные загружать из текстового файла
(разделитель – пробел), сгенерированного, например, в MATLAB.
2. Реализовать на С или С++ алгоритмы прямого и обратного БПФ для
комплексного входного сигнала длиной n 2 , n – любое натуральное число:
а) с прореживанием по времени и двоично-инверсными перестановками
(вариант 1);
б) с прореживанием по времени без двоично-инверсных перестановок
(вариант 2);
в) с прореживанием по частоте и двоично-инверсными перестановками
(вариант 3);
г) с прореживанием по частоте без двоично-инверсных перестановок
(вариант 4);
3. Убедиться в корректности работы алгоритмов:
а) проверить выполнение равенства X  ОДПФ ДПФX, а также равенства
X  ОБПФ БПФX;
б) сравнить результаты ДПФ(Х) и БПФ(Х);
в) сравнить результаты работы реализованного алгоритма, например, с
результатами процедуры fft, встроенной в MATLAB.
(рекомендуется для сравнения использовать значение ошибки)
4. Проанализировать зависимость времени выполнения БПФ и непосредственного
вычисления ДПФ от длины N преобразования.
5. Реализовать на С или С++ процедуру прямого вычисления свертки двух
последовательностей по формуле (3). Входные данные загружать из текстового
файла (разделитель – пробел), сгенерированного, например, в MATLAB.
6. Реализовать процедуру нахождения дискретной свертки, основанную на БПФ.
При вычислении БПФ использовать результаты п. 2 задания.

7. Убедится в корректности работы процедуры из п. 5 и п. 6 задания, сравнив
полученные результаты с результатами работы встроенной функций MATLAB
conv.
(рекомендуется для сравнения использовать значение ошибки)
8. Сравнить производительность алгоритмов вычисления свертки по
определению (3) и с помощью БПФ в двух случаях: когда размер одной из
последовательностей фиксирован, и когда меняются длины обеих
последовательностей.