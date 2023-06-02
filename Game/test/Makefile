CPP=g++
EXEC = test
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
CPPFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

all: $(EXEC)

%.o : %.cpp %.hpp
	$(CPP)  $(CPPFLAGS) -o $@ -c $< 


$(EXEC): $(OBJ)
	$(CPP) $^ $(LIBS) -o $@


clean:
	rm -rf *.o

aclean : clean
	rm -rf $(EXEC)
