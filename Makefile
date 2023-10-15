all: main.c
	gcc -std=gnu11 -O0 -g -Wall -Wextra -Werror -pedantic -Wno-unused-result -Wconversion -o main *.c *.h

clean:
	rm main