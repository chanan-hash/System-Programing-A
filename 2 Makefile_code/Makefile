CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=mylib.o
FLAGS= -Wall -g

all: libmylib.so libmylib.a progmains progmaind	
progmains: $(OBJECTS_MAIN) libmylib.a 
	$(CC) $(FLAGS) -o progmains $(OBJECTS_MAIN) libmylib.a
progmaind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./libmylib.so
libmylib.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmylib.so $(OBJECTS_LIB)
libmylib.a: $(OBJECTS_LIB)
	$(AR) -rcs libmylib.a $(OBJECTS_LIB)	
mylib.o: mylib.c mylib.h
	$(CC) $(FLAGS) -c mylib.c
main.o: main.c mylib.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so progmains progmaind
