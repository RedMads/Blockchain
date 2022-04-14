OUTFILES=$(shell find ./src -name '*.cpp')

main:

	g++ main.cpp $(OUTFILES) -o out/main.o
	./out/main.o

test:

	g++ test.cpp $(OUTFILES) -o out/test.o
	./out/test.o

remove:

	rm out/*.o