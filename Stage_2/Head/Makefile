FLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -I include

all: my_head

my_head: temp/head.o
	gcc temp/head.o -o bin/my_head ${FLAGS}

temp/head.o: src/head.c include/head.h
	gcc -c src/head.c -o temp/head.o ${FLAGS}

clean:
	rm -f temp/*.o bin/my_head