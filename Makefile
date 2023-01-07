
CPPFLAGS=-g
LIBS=-l dstruct
INCLUDE_DIR=include
LIB_DIR=lib

CC=gcc
OUTPUT_LIB=libDstruct.a


$(OUTPUT_LIB):
	$(CC) $(CPPFLAGS) src/*.c -I $(INCLUDE_DIR) -c
	ar -rsc ./lib/$(OUTPUT_LIB) *.o


clean:
	rm *.o

test:
	$(CC) test/test.c -I $(INCLUDE_DIR) -L $(LIB_DIR) $(LIBS) -o test/test