# compiler and flags

CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = number_guessing

# Source files
SRCS = number_guessing.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
# Clean rule to remove compiled files
clean:
	rm -f $(TARGET)
