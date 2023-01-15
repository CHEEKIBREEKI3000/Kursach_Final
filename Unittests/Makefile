target = UnitTest
sources = main.cpp
CC = g++
CCFlags = -Wall
LDLIBS = -lstdc++fs -lcrypto++ -lUnitTest++
OPT = -Ofast
all:build
build:
	$(CC) $(CCFlags) $(OPT) $(sources) -o $(target) $(LDLIBS)
dbg:
	$(CC) -g $(sources) -o $(target)DBG
cls:
	del *.exe
