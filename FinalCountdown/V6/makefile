PROG = main
CXX = g++
CPPFLAGS = -Wall 
OBJS = V1.o Game.o libs.o Player.o Tile.o Game2.o Player2.o Tile2.o
# Collider.o Platform.o

$(PROG) : $(OBJS)
	$(CXX) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -o $@ -c $^ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


clean :
	rm -f core $(PROG) $(OBJS)
