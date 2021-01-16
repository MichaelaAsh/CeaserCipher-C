copy_text: copy_text.o
	gcc -ansi -Wall copy_text.o

rot13: rot13.o
	gcc -ansi -Wall rot13.o

encode: encode.o
	gcc -ansi -Wall encode.o


copy_text.o: copy_text.c
	gcc -ansi -Wall -c copy_text.c

rot13.o: rot13.c
	gcc -ansi -Wall -c rot13.c

encode.o: encode.c
	gcc -ansi -Wall -c encode.c


all: copy_text encode rot13

clean:
	rm *.o
	rm copy_text
	rm encode
	rm rot13
