CP = gcc

hilbert3D: main.o turtle.o list.o world.o
	$(CP) -o hilbert3D main.o turtle.o list.o world.o -lm

main.o: main.c world.h list.h turtle.h
	$(CP) -c main.c -o main.o

turtle.o: turtle.c world.h list.h turtle.h
	$(CP) -c turtle.c -o turtle.o

list.o: list.c world.h list.h 
	$(CP) -c list.c -o list.o

world.o: world.c world.h 
	$(CP) -c world.c -o world.o

