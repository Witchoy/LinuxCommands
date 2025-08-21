FLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -I include

all: my_tail

my_tail: temp/tail.o
	@gcc temp/tail.o -o bin/my_tail ${FLAGS}

temp/tail.o: src/tail.c include/tail.h
	@gcc -c src/tail.c -o temp/tail.o ${FLAGS}

clean:
	@rm -f temp/*.o bin/my_tail