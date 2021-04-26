PROG = main
CXX = g++
CPPFLAGS = -Wall 
OBJS = V1.o Game.o libs.o Player.o Tile.o Game2.o Player2.o Tile2.o
# This makefile creates objects from all of the .cpp and .h files in the directory
# and creates a single program called main.

$(PROG) : $(OBJS)
	$(CXX) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -o $@ -c $^ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean :
	rm -f core $(PROG) $(OBJS)
