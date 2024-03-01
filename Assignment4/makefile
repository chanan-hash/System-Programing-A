CC = gcc
CFlag = -Wall -g
AR = ar
AFLAGS = rcs
FP = -fPIC

.PHONY: all clean

all: digitcompress


digitcompress: encodemain.o libcompress.a
	$(CC) $(CFLAGS) $^ -o $@

libcompress.a: compress.o
		$(AR) $(AFLAGS) $@ $<
# ar rcs libcompress.a compress.o


encodemain.o: encodemain.c compress.h
	$(CC) $(CFLAGS) -c $<
# gcc -Wall -g  -c encodemain.c -o encodemain.o


compress.o: compress.c compress.h
		$(CC) $(CFLAGS) -c $<  
# taking them all and creating the o file
# gcc -Wall -g  -c compress.c -o compress.o, $< means the first prerequistie in the dependency list here


clean:
	rm -f *.o *.a digitcompress