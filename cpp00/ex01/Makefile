# Define the C++ compiler to use
CXX = g++

# Define any compile-time flags
CXXFLAGS = -Wall -g -std=c++98

# Define the target file (executable)
TARGET = main

# Define the C++ source files
SRCS = main.cpp PhoneBook.cpp Contact.cpp

# Define the C++ object files 
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

clean:
	$(RM) $(TARGET) $(OBJS)

re: clean all