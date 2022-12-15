buildVirus: ak07.c virusFunc.h usefulFunc.c
	gcc usefulFunc.c ak07.c -o ak07

clean:
	rm ak07