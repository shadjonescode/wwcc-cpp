# compiler and flags

CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = coin_flip

# Source files
SRCS = coin_flip.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
# Clean rule to remove compiled files
clean:
	rm -f $(TARGET)
