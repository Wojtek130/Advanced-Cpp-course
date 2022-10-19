CC=g++
CFLAGS=-std=c++2a -Wall -Wextra -trigraphs
# CFLAGS=-std=c++17 -Wall -Wextra
NAME = a.exe

$(NAME): main.o 
	$(CC) $(CFLAGS) -g main.o -o $(NAME)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o