CC=gcc
LIB=DBapi

all: builds

builds: test.c clean
	$(CC) test.c -o DBStart -l$(LIB) -lsqlite3 -L./module -I.


clean: 
	rm -f *.o
