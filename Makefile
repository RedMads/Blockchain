OUTFILES=$(shell find ./src -name '*.cpp')

main:

	g++ main.cpp $(OUTFILES) -o out/main.o
	

test:

	g++ test.cpp $(OUTFILES) -o out/test.o

	
runt:
	./out/test.o


runm:
	./out/main.o

remove:

	rm out/*.o