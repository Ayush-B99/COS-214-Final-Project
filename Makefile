# Variables
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Iinclude -Isrc
LDFLAGS = -lncursesw -lpthread

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
SOURCES = $(filter-out $(SRCDIR)/Memento.cpp $(SRCDIR)/Caretaker.cpp $(SRCDIR)/TestingMain.cpp $(SRCDIR)/DemoMain.cpp, $(wildcard $(SRCDIR)/*.cpp))
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

# === RUN VARIANTS ===
# Demo main build/run
DEMO_TARGET = $(BINDIR)/demo
DEMO_SRC = $(SRCDIR)/DemoMain.cpp
DEMO_OBJ = $(BUILDDIR)/DemoMain.o

# Testing main build/run
TEST_TARGET = $(BINDIR)/test
TEST_SRC = $(SRCDIR)/TestingMain.cpp
TEST_OBJ = $(BUILDDIR)/TestingMain.o

# Compile and run demo (clean build)
demo: clean $(DEMO_TARGET)
	$(DEMO_TARGET)

# Compile and run test (clean build)
test: clean $(TEST_TARGET)
	$(TEST_TARGET)

# Recompile only changed files then run
demo_only: $(DEMO_TARGET)
	$(DEMO_TARGET)

test_only: $(TEST_TARGET)
	$(TEST_TARGET)

# Build the demo and test binaries
$(DEMO_TARGET): $(OBJECTS) $(DEMO_OBJ)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(DEMO_OBJ) -o $@ $(LDFLAGS)

$(TEST_TARGET): $(OBJECTS) $(TEST_OBJ)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(TEST_OBJ) -o $@ $(LDFLAGS)

# Compile DemoMain and TestingMain separately
$(DEMO_OBJ): $(DEMO_SRC)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC)
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

# Detect memory leaks using valgrind (macOS)
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
	@echo "  all          - Build the main target executable"
	@echo "  run          - Clean and run main"
	@echo "  run_only     - Run main without cleaning"
	@echo "  demo         - Clean, build, and run demo main"
	@echo "  demo_only    - Build (if needed) and run demo main"
	@echo "  test         - Clean, build, and run testing main"
	@echo "  test_only    - Build (if needed) and run testing main"
	@echo "  setup        - Install ncurses"
	@echo "  clean        - Clean build artifacts"
	@echo "  leaks        - Check for memory leaks"
	@echo "  check        - Run static analysis"

# Valgrind variants

val: $(TEST_TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TEST_TARGET)

# Detailed valgrind with log and txt
val_full_txt: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(TARGET) > valgrind_out.txt 2>&1

# Full valgrind (including reachable)
val_full: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(TARGET)

.PHONY: all run run_only clean check leaks setup help val valgrind val_log val_full

doxygen:
	@echo "Generating documentation with Doxygen..."
	@if ! command -v doxygen >/dev/null 2>&1; then \
		echo "Error: doxygen not found. Please install it first (e.g. 'sudo apt install doxygen graphviz')."; \
		exit 1; \
	fi
	@mkdir -p $(DOCSDIR)
	@if [ ! -f Doxyfile ]; then \
		echo "No Doxyfile found. Creating a default one..."; \
		doxygen -g Doxyfile; \
		sed -i 's|OUTPUT_DIRECTORY       =|OUTPUT_DIRECTORY       = $(DOCSDIR)|' Doxyfile; \
		sed -i 's|RECURSIVE              = NO|RECURSIVE              = YES|' Doxyfile; \
		sed -i 's|EXTRACT_PRIVATE        = NO|EXTRACT_PRIVATE        = YES|' Doxyfile; \
		sed -i 's|EXTRACT_STATIC         = NO|EXTRACT_STATIC         = YES|' Doxyfile; \
		sed -i 's|GENERATE_LATEX         = YES|GENERATE_LATEX         = NO|' Doxyfile; \
		echo "Default Doxyfile created and configured."; \
	fi
	@doxygen Doxyfile
	@echo "Documentation generated in $(DOCSDIR)/html"