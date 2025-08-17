FLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -I include

all: my_cat

my_cat: temp/cat.o
	gcc temp/cat.o -o bin/my_cat ${FLAGS}

temp/cat.o: src/cat.c include/cat.h
	gcc -c src/cat.c -o temp/cat.o ${FLAGS}

clean:
	rm -f temp/*.o bin/my_cat