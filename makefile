result: main.o interface.o sortfunctions.o
	g++ -o sort main.o interface.o sortfunctions.o

main.o: main.cc interface.h sortfunctions.h
	g++ -c main.cc

interface.o: interface.cc interface.h
	g++ -c interface.cc

sortfunctions.o: sortfunctions.cc sortfunctions.h
	g++ -c sortfunctions.cc
