all: main

main: main.c comm.o
	avr-gcc -mmcu=atmega2560 -o main main.c comm.o

comm.o: comm.h comm.c
	avr-gcc -c -mmcu=atmega2560 comm.c 

parser.o: parser.h parser.c
	avr-gcc -c -mmcu=atmega2560 parser.c 

data.o: data.h data.c
	avr-gcc -c -mmcu=atmega2560 data.c