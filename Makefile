CC=g++
LIBS=-lGL -lglut -lGLU
OBJ=timer.cpp gGL.o gTime.o

timer: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)
gGL.o: ./mylib/gGL.cpp
	$(CC) -c ./mylib/gGL.cpp
gTime.o: ./mylib/gTime.cpp
	$(CC) -c ./mylib/gTime.cpp
clean:
	rm -f ./*.o *~ core ./*~ 