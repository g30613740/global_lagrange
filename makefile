CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude
TARGET = a
SRCS = src/main.cpp src/functions.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
