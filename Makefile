all: ak07.o usefulFunc.o virusFunc.h
	gcc -o ak07 ak07.o usefulFunc.o

ak07.o: ak07.c
	gcc -c ak07.c

usefulFunc.o: usefulFunc.c
	gcc -c usefulFunc.c

clean:
	rm ak07.exe usefulFunc.o ak07.o