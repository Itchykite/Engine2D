CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf
SRC = $(shell find src game engine -name '*.cpp')
OBJ = $(SRC:.cpp=.o)
TARGET = mygame

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

