CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra
LDFLAGS =

SRCS = $(wildcard src/*.cpp engine/**/*.cpp game/**/*.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = bin/mygame

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)
