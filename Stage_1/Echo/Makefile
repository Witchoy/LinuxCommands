FLAGS=-Wall -Wextra -Werror -I include

all: my_echo

my_echo: temp/echo.o
	@gcc temp/echo.o -o bin/my_echo ${FLAGS}

temp/echo.o: src/echo.c include/echo.h
	@gcc -c src/echo.c -o temp/echo.o ${FLAGS}

clean:
	@rm -f temp/*.o bin/my_echo
