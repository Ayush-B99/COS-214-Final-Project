# Variables
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Iinclude -Isrc
LDFLAGS = -lncurses -lpthread

ifneq ("$(wildcard lib)","")
    LDFLAGS += -Llib
endif

SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin
DOCSDIR = docs
TARGET = $(BINDIR)/my_project

# Filter out files
SOURCES = $(filter-out $(SRCDIR)/Memento.cpp $(SRCDIR)/Caretaker.cpp $(SRCDIR)/TestingMain.cpp, $(wildcard $(SRCDIR)/*.cpp))
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))
TEMP_DIR = temp
ZIP_DIR = submit

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

# Compiling
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the application
run: clean $(TARGET)
	$(TARGET)

# Run without cleaning
run_only: $(TARGET)
	$(TARGET)

# Setup ncurses
setup:
	@echo "Setting up ncurses..."
	@chmod +x setup_ncurses.sh
	@./setup_ncurses.sh

# Detect memory leaks using valgrind
leaks: $(TARGET)
	export MallocStackLogging=1; leaks -atExit --list -- $(TARGET) | awk 'BEGIN { print "Memory Leak Summary:\n" } /^Process/ { print } /^Leak/ { print }'

# Clean build artifacts
clean:
	rm -rf $(BUILDDIR) $(BINDIR) $(TEMP_DIR)
	rm -f $(SRCDIR)/*.gcno $(SRCDIR)/*.gcda $(SRCDIR)/*.gcov

# Static analysis with cppcheck
check:
	cppcheck --enable=all $(SRCDIR)/*.cpp

# Help command
help:
	@echo "Makefile Help:"
	@echo ""
	@echo "Targets:"
	@echo "  all       - Build the target executable"
	@echo "  run       - Clean and run the application"
	@echo "  run_only  - Run without cleaning"
	@echo "  setup     - Install ncurses library"
	@echo "  clean     - Clean build artifacts"
	@echo "  leaks     - Check for memory leaks"
	@echo "  check     - Run static analysis"

.PHONY: all run run_only clean check leaks setup help
