# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++17 -Wall -I.

# Source Files
SRCS = main.cpp Net.cpp Neuron.cpp

# Object Files (Replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Output Executable
TARGET = main

# Default target
all: $(TARGET)

# Link Object Files to Create Executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile Source Files to Object Files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Build Files
clean:
	rm -f $(OBJS) $(TARGET)
