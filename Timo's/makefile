PROG = main
CC = g++
CPPFLAGS = -Wall 
OBJS = V1.o Game.o libs.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

V1.o :
	$(CC) $(CPPFLAGS) -c V1.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Game.o : Game.h
	$(CC) $(CPPFLAGS) -c Game.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

libs.o : libs.h
	$(CC) $(CPPFLAGS) -c libs.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean :
	rm -f core $(PROG) $(OBJS)
