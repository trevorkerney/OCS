CC=g++
VERS=-std=c++17
CWARN=-Wall -Wextra -Wdeprecated

ifeq ($(OS),Windows_NT)
	MKBINDIR=if not exist "bin" mkdir bin
	EXECEXT=.exe
	CLEAN=del /Q bin
else
	MKBINDIR=mkdir -p bin
	EXECEXT=
	CLEAN=-rm bin/*
endif

make: bin/OCS-cli

bin/OCS-cli: bin bin/main.o
	$(CC) -g -o $@$(EXECEXT) bin/main.o

bin/main.o: src/main.cpp
	$(CC) -c -g $(VERS) $(CWARN) -o $@ src/main.cpp

.PHONY: bin clean

bin:
	${MKBINDIR}

clean:
	${CLEAN}
