CC=g++
VERS=-std=c++17
CXXWARN=
CXXFLAGS=

ifeq ($(DEBUG), 1)
	BINDIR=bin/debug
	CXXFLAGS+=-D_DEBUG -g
else
	BINDIR=bin/release
	CXXWARN+=-Wall -Wextra -Wdeprecated
endif

ifeq ($(OS),Windows_NT)
	MKBINDIR=if not exist "$(BINDIR)" mkdir "$(BINDIR)"
	EXECEXT=.exe
	CLEAN=if exist "$(BINDIR)" del /Q "$(BINDIR)"
else
	MKBINDIR=mkdir -p $(BINDIR)
	EXECEXT=
	CLEAN=-rm $(BINDIR)/*
endif

all: $(BINDIR) $(BINDIR)/OCS-cli

$(BINDIR)/OCS-cli: $(BINDIR)/main.o $(BINDIR)/schedules.o $(BINDIR)/positions.o $(BINDIR)/employees.o
	$(CC) $(CXXFLAGS) -o $@$(EXECEXT) $^

$(BINDIR)/main.o: src/main.cpp
	$(CC) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

$(BINDIR)/schedules.o: src/schedules.cpp inc/schedules.h
	$(CC) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

$(BINDIR)/positions.o: src/positions.cpp inc/positions.h
	$(CC) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

$(BINDIR)/employees.o: src/employees.cpp inc/employees.h
	$(CC) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

.PHONY: $(BINDIR) clean

$(BINDIR):
	${MKBINDIR}

clean:
	${CLEAN}
