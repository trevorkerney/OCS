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

bin/OCS-cli: bin/main.o bin/schedule.o bin/position.o bin/employee.o
	$(CC) -g -o $@$(EXECEXT) $^

bin/main.o: src/main.cpp
	$(CC) -c -g $(VERS) $(CWARN) -o $@ $<

bin/schedule.o: src/schedule.cpp inc/schedule.h
	$(CC) -c -g $(VERS) $(CWARN) -o $@ $<

bin/position.o: src/position.cpp inc/position.h
	$(CC) -c -g $(VERS) $(CWARN) -o $@ $<

bin/employee.o: src/employee.cpp inc/employee.h
	$(CC) -c -g $(VERS) $(CWARN) -o $@ $<

.PHONY: bin clean

bin:
	${MKBINDIR}

clean:
	${CLEAN}
