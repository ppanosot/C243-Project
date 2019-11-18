result: main.o interface.o makeArray.o
	g++ -o main main.o interface.o makeArray.o

main.o: main.cc interface.h makeArray.h
	g++ -c main.cc

interface.o: interface.cc interface.h
	g++ -c interface.cc

makeArray.o: makeArray.cc makeArray.h  
	g++ -c makeArray.cc
