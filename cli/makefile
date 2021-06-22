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

make: bin bin/OCS-cli

bin/OCS-cli: bin/main.o bin/schedules.o bin/positions.o bin/employees.o
	$(CC) -g -o $@$(EXECEXT) $^

bin/main.o: src/main.cpp
	$(CC) -c -g $(VERS) $(CWARN) -o $@ $<

bin/schedules.o: src/schedules.cpp inc/schedules.h
	$(CC) -c -g $(VERS) $(CWARN) -o $@ $<

bin/positions.o: src/positions.cpp inc/positions.h
	$(CC) -c -g $(VERS) $(CWARN) -o $@ $<

bin/employees.o: src/employees.cpp inc/employees.h
	$(CC) -c -g $(VERS) $(CWARN) -o $@ $<

.PHONY: bin clean

bin:
	${MKBINDIR}

clean:
	${CLEAN}
