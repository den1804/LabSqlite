CC=gcc
LIB=DBapi
STATLIB=lib$(LIB).a

all: statlib 

statlib: modules
	ar rcs $(STATLIB) DBLib.o 

modules: clean
	$(CC) -fPIC -c DBLib.c 

clean:
	rm -f *.o
