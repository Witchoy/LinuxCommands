FLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -I include

all: my_ls

my_ls: temp/ls.o
	@gcc temp/ls.o -o bin/my_ls ${FLAGS}

temp/ls.o: src/ls.c include/ls.h
	@gcc -c src/ls.c -o temp/ls.o ${FLAGS}

clean:
	@rm -f temp/*.o bin/my_ls