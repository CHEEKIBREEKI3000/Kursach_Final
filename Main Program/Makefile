target = server
sources = main.cpp asd.cpp
CC = g++
CCFlags = -Wall
LDLIBS =  -lcrypto++
OPT = -Ofast
all:build
build:
	$(CC) $(CCFlags) $(OPT) $(sources) -o $(target) $(LDLIBS)
dbg:
	$(CC) -g $(sources) -o $(target)DBG
