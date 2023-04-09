CPP=g++
LD=g++



CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


all: main

main: main.o renderer.o entite.o unite.o guerrier.o robot.o attackCommande.o loadTexture.o moveCommande.o jeu.o 
	$(LD) $(LDFLAGS)  main.o renderer.o entite.o unite.o guerrier.o attackCommande.o robot.o loadTexture.o moveCommande.o jeu.o -o main $(LIBS)

main.o: main.cpp jeu.hpp renderer.hpp unite.hpp robot.hpp guerrier.hpp attackCommande.hpp settings.hpp loadTexture.hpp moveCommande.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

jeu.o : jeu.cpp jeu.hpp renderer.hpp unite.hpp robot.hpp guerrier.hpp attackCommande.hpp settings.hpp loadTexture.hpp moveCommande.hpp
	$(CPP) $(CPPFLAGS) -c jeu.cpp
	
entite.o : entite.cpp entite.hpp
	$(CPP) $(CPPFLAGS) -c entite.cpp  

unite.o : unite.cpp unite.hpp entite.hpp commande.hpp
	$(CPP) $(CPPFLAGS) -c unite.cpp 

guerrier.o : guerrier.cpp guerrier.hpp unite.hpp
	$(CPP) $(CPPFLAGS) -c guerrier.cpp 

robot.o : robot.cpp robot.hpp unite.hpp
	$(CPP) $(CPPFLAGS) -c robot.cpp 

attackCommande.o : attackCommande.cpp attackCommande.hpp unite.hpp commande.hpp
	$(CPP) $(CPPFLAGS) -c attackCommande.cpp 

moveCommande.o : moveCommande.cpp moveCommande.hpp unite.hpp commande.hpp
	$(CPP) $(CPPFLAGS) -c moveCommande.cpp 

renderer.o : renderer.cpp renderer.hpp settings.hpp
	$(CPP) $(CPPFLAGS) -c renderer.cpp 

loadTexture.o : loadTexture.cpp loadTexture.hpp
	$(CPP) $(CPPFLAGS) -c loadTexture.cpp 



clean:
	rm -f *.o main
