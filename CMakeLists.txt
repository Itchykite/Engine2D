cmake_minimum_required(VERSION 3.16)
project(mygame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Szukamy wszystkich .cpp w folderach src, game i engine
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    game/*.cpp
    engine/*.cpp
)

# Znajdź SDL2 i SDL2_ttf przez pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

# Dodaj ścieżki do include i bibliotek
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_TTF_LIBRARY_DIRS})

# Tworzymy plik wykonywalny
add_executable(mygame ${SOURCES})

# Linkujemy z SDL2 i SDL2_ttf
target_link_libraries(mygame ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
