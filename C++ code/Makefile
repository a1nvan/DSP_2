all: begin

../bin:
	@mkdir -p ../bin

begin: predtren.h ../bin 
	g++  task1.cpp predtren.cpp -o ../bin/task1
	g++  task2.cpp predtren.cpp -o ../bin/task2
	g++  task3.cpp predtren.cpp -o ../bin/task3
	g++  task4.cpp predtren.cpp -o ../bin/task4
	g++  task5.cpp predtren.cpp -o ../bin/task5
	g++  task6.cpp predtren.cpp -o ../bin/task6
	g++  task8.cpp predtren.cpp -o ../bin/task8
clean:
	@rm -r ../bin
