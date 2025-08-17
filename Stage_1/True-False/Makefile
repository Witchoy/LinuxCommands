FLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -I include

all: my_true my_false

my_true: temp/true.o
	gcc temp/true.o -o bin/my_true ${FLAGS}

temp/true.o: src/true.c include/true.h
	gcc -c src/true.c -o temp/true.o ${FLAGS}

my_false: temp/false.o
	gcc temp/false.o -o bin/my_false ${FLAGS}

temp/false.o: src/false.c include/false.h
	gcc -c src/false.c -o temp/false.o ${FLAGS}

clean:
	rm -f temp/*.o bin/my_true bin/my_false