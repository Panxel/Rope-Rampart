CPP=g++
LD=g++



CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


all: main

main: main.o renderer.o entite.o unite.o guerrier.o robot.o attackCommande.o jeu.o
	$(LD) $(LDFLAGS)  main.o renderer.o entite.o unite.o guerrier.o attackCommande.o robot.o jeu.o -o main $(LIBS)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

jeu.o : jeu.cpp jeu.hpp
	$(CPP) $(CPPFLAGS) -c jeu.cpp
	
entite.o : entite.cpp entite.hpp
	$(CPP) $(CPPFLAGS) -c entite.cpp  

unite.o : unite.cpp unite.hpp
	$(CPP) $(CPPFLAGS) -c unite.cpp 

guerrier.o : guerrier.cpp guerrier.hpp
	$(CPP) $(CPPFLAGS) -c guerrier.cpp 

robot.o : robot.cpp robot.hpp
	$(CPP) $(CPPFLAGS) -c robot.cpp 

attackCommande.o : attackCommande.cpp attackCommande.hpp
	$(CPP) $(CPPFLAGS) -c attackCommande.cpp 

renderer.o : renderer.cpp renderer.hpp
	$(CPP) $(CPPFLAGS) -c renderer.cpp 



clean:
	rm -f *.o main
