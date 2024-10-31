# Makefile

# Compiler
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g

# Directories
SRC_DIR = src
BIN_DIR = bin
TEST_DIR = test

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Test files
TEST_SRCS = $(wildcard $(TEST_DIR)/test-*.cpp)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Executables
LAST_TRADING_DAY_EXEC = $(BIN_DIR)/last_trading_day
TEST_EXEC = $(BIN_DIR)/test

# Build last trading day program
$(LAST_TRADING_DAY_EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile unit tests
$(TEST_EXEC): $(TEST_DIR)/run.cpp $(TEST_SRCS) $(SRC_DIR)/dayutils.cpp $(SRC_DIR)/get_option.cpp
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_DIR)/run.cpp $(TEST_SRCS) $(SRC_DIR)/dayutils.cpp $(SRC_DIR)/get_option.cpp

# Install target
install: $(LAST_TRADING_DAY_EXEC)
	install -Dm755 $(LAST_TRADING_DAY_EXEC) /usr/local/bin/last_trading_day

# Clean up
clean:
	rm -f $(OBJS) $(LAST_TRADING_DAY_EXEC) $(TEST_EXEC) $(TEST_OBJS)

# Run unit tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

.PHONY: clean test install

