CC=g++
# CFLAGS=-std=c++2a -Wall -Wextra -trigraphs
CFLAGS=-std=c++17 -Wall -Wextra
NAME = a.exe
PN = ex1.cpp
PNO = ex.o

$(NAME): $(PNO)
	$(CC) $(CFLAGS) -g $(PNO) -o $(NAME)

$(PNO): $(PN)
	$(CC) $(CFLAGS) -c $(PN) -o $(PNO)

