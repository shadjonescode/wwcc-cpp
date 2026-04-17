# compiler and flags

CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = hello_student

# Source files
SRCS = hello_student.cpp

# Build rule
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
# Clean rule to remove compiled files
clean:
	rm -f $(TARGET)
