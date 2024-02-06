# Flags and commands
CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs
FP = -fPIC

.PHONY: all clean

# making all the files we need
all: connections 

# Creating the target file by compile the main and the static library
connections: main.o libmat.a
	$(CC) $(CFLAGS) $^ -o $@
# This is how to replace the short cuts
# connections: main.o libmat.a
#    $(CC) $(CFLAGS) -c main.c -o main.o
#    $(CC) $(CFLAGS) -c libmat.c -o libmat.o
#    $(CC) $(CFLAGS) main.o libmat.o -o connections




# Creating the library for our program, from my_mat.o
# my_mat.o is the dependency, and the ar for archive is for creating the static library
# rcs - for combine those two $@ - is the target, and $< is the first file here
libmat.a: my_mat.o 
	$(AR) $(AFLAGS) $@ $<
# ar rcs libmat.a my_mat.o


# Compile to main and include it, our library for the functions
main.o: main.c my_mat.h 
	$(CC) $(CFLAGS) -c $<
# gcc -Wall -g  -c main.c -o main.o

# Compiling both libraries
my_mat.o: my_mat.c my_mat.h 
	$(CC) $(CFLAGS) -c $<  
# taking them all and creating the o file
# gcc -Wall -g  -c my_mat.c -o my_mat.o, $< means the first prerequistie in the dependency list here

clean:
	rm -f *.o *.a connections
