FLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -I include

all: my_yes

my_yes: temp/yes.o
	gcc temp/yes.o -o bin/my_yes ${FLAGS}

temp/yes.o: src/yes.c include/yes.h
	gcc -c src/yes.c -o temp/yes.o ${FLAGS}

clean:
	rm -f temp/*.o bin/my_yes