CC= g++
FLAGS = -g -Wall -c
INCLUDE_DIR_SDL = -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image

all : bin/Exec.out bin/ExecSDL.out

bin/Exec.out : obj/Image.o obj/Pixel.o obj/main.o
	$(CC) $(INCLUDE_DIR_SDL) $(LIBS_SDL) obj/Image.o obj/Pixel.o obj/main.o -o bin/Exec.out

bin/ExecSDL.out : obj/Image.o obj/Pixel.o obj/mainAffichage.o
	$(CC) $(INCLUDE_DIR_SDL) $(LIBS_SDL) obj/Image.o obj/Pixel.o obj/mainAffichage.o -o bin/ExecSDL.out

obj/main.o : src/Image.h src/Pixel.h src/main.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(LIBS_SDL) src/main.cpp -o obj/main.o

obj/mainAffichage.o : src/Image.h src/Pixel.h src/mainAffichage.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(LIBS_SDL) src/mainAffichage.cpp -o obj/mainAffichage.o

obj/Image.o : src/Image.h src/Image.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) $(LIBS_SDL) src/Image.cpp -o obj/Image.o

obj/Pixel.o : src/Pixel.h src/Pixel.cpp
	$(CC) $(FLAGS) src/Pixel.cpp -o obj/Pixel.o

clean:
	rm obj/*.o
