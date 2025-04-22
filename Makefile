CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf
SRC = src/main.cpp game/Game.cpp engine/core/Engine.cpp engine/input/InputManager.cpp engine/renderer/Renderer.cpp engine/fps/Fps.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = mygame

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

