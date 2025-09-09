FLAGS=-Wall -Wextra -Werror -Wno-unused-parameter -I include

all: my_pwd

my_pwd: temp/pwd.o
	@gcc temp/pwd.o -o bin/my_pwd ${FLAGS}

temp/pwd.o: src/pwd.c include/pwd.h
	@gcc -c src/pwd.c -o temp/pwd.o ${FLAGS}

clean:
	@rm -f temp/*.o bin/my_pwd