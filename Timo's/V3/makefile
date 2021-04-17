PROG = main
CC = g++
CPPFLAGS = -Wall 
OBJS = V1.o Game.o libs.o Player.o Collider.o Platform.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

libs.o : libs.h
	$(CC) $(CPPFLAGS) -c libs.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

V1.o :
	$(CC) $(CPPFLAGS) -c V1.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Player.o : Player.h
	$(CC) $(CPPFLAGS) -c Player.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Collider.o : Collider.h
	$(CC) $(CPPFLAGS) -c Collider.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Platform.o : Platform.h
	$(CC) $(CPPFLAGS) -c Platform.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Game.o : Game.h
	$(CC) $(CPPFLAGS) -c Game.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


clean :
	rm -f core $(PROG) $(OBJS)
