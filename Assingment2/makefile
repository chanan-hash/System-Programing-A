# Flags and commands
CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs
FP = -fPIC


.PHONY clean all

# making all the files we need
all: connections 

# The target file
connections: 

# Creating the library for our program, from my_mat.o
libmat.a: my_mat.o 
	$(AR) $(AFLAGS) $@ $<
	


# Compile to main and include it, our library for the functions
main.o: main.c my_mat.h 
	$(CC) $(CFLAGS) -c $<
# gcc -Wall -g  -c main.c -o main.o
my_mat.o: my_mat.c my_mat.h #compiling boyh libraries
	$(CC) $(CFLAGS) -c $<  
# taking them all and creating the o file
# gcc -Wall -g  -c my_mat.c -o my_mat.o, $< means the first prerequistie in the dependency list here

clean:
	rm -f *.o *.a connections