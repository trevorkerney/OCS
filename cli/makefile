CXX=g++
VERS=-std=c++17
CXXWARN=-Wall -Wextra -Wdeprecated
CXXFLAGS=

ifeq ($(DEBUG), 0)
	BINDIR=bin/release
else
	BINDIR=bin/debug
	CXXFLAGS+=-D_DEBUG -g
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
	$(CXX) $(CXXFLAGS) -o $@$(EXECEXT) $^

$(BINDIR)/main.o: src/main.cpp
	$(CXX) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

$(BINDIR)/schedules.o: src/schedules.cpp inc/schedules.h
	$(CXX) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

$(BINDIR)/positions.o: src/positions.cpp inc/positions.h
	$(CXX) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

$(BINDIR)/employees.o: src/employees.cpp inc/employees.h
	$(CXX) -c $(CXXFLAGS) $(VERS) $(CXXWARN) -o $@ $<

.PHONY: $(BINDIR) clean

$(BINDIR):
	${MKBINDIR}

clean:
	${CLEAN}
