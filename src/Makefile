CPP=g++
LD=g++



CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


all: main

main: main.o renderer.o entite.o unite.o
	$(LD) $(LDFLAGS)  main.o renderer.o entite.o unite.o -o main $(LIBS)

main.o: main.cpp renderer.hpp settings.hpp guerrier.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

entite.o : entite.cpp entite.hpp
	$(CPP) $(CPPFLAGS) -c entite.cpp 

unite.o : unite.cpp unite.hpp
	$(CPP) $(CPPFLAGS) -c unite.cpp 

guerrier.o : guerrier.cpp guerrier.hpp
	$(CPP) $(CPPFLAGS) -c guerrier.cpp 

renderer.o : renderer.cpp renderer.hpp settings.hpp
	$(CPP) $(CPPFLAGS) -c renderer.cpp 

clean:
	rm -f *.o main
