CC=g++
CFLAGS=-Wall 
LDFLAGS=-L/usr/lib/x86_64-linux-gnu/ -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
EXEC=carRacing

all: $(EXEC)

carRacing: main.o Car.o collision.o game.o OpenFileError.o RoadBlock.o FileLoader.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
