all: main

main: main.c data.o array.o status.o parser.o comm.o 
	avr-gcc -mmcu=atmega2560 -o main main.c comm.o parser.o status.o array.o data.o serail.o solenoid.o power_solenoid.o

data.o: data.h data.c
	avr-gcc -c -mmcu=atmega2560 data.c

array.o: array.h array.c
	avr-gcc -c -mmcu=atmega2560 array.c

status.o: status.h status.c data.h array.h
	avr-gcc -c -mmcu=atmega2560 status.c

parser.o: parser.h parser.c status.h packet_headers.h
	avr-gcc -c -mmcu=atmega2560 parser.c 

comm.o: comm.h comm.c parser.h status.h serial.h
	avr-gcc -c -mmcu=atmega2560 comm.c 

solenoid.o: solenoid_controller.c solenoid_controller.h
	avr-gcc -c -mmcu=atmega2560 solenoid_controller.c

power_solenoid.o: power_solenoid_controller.c power_solenoid_controller.h
	avr-gcc -c -mmcu=atmega2560 power_solenoid_controller.c

serial.o: serial.h serial.c
	avr-gcc -c -mmcu=atmega2560 serial.c