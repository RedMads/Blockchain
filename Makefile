main:

	g++ main.cpp src/*.cpp -o out/main.o
	./main.o

test:

	g++ test.cpp src/*.cpp -o out/test.o
	./test.o

remove:

	rm out/*.o