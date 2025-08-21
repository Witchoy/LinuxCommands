FLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -I include

all: my_wc

my_wc: temp/wc.o
	@gcc temp/wc.o -o bin/my_wc ${FLAGS}

temp/wc.o: src/wc.c include/wc.h
	@gcc -c src/wc.c -o temp/wc.o ${FLAGS}

clean:
	@rm -f temp/*.o bin/my_wc