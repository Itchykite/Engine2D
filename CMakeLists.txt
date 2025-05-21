cmake_minimum_required(VERSION 3.16)
project(mygame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    game/*.cpp
    engine/*.cpp
)

# ----------------------------
# Linux
# ----------------------------
if(UNIX AND NOT APPLE)  # Linux
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
    link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_TTF_LIBRARY_DIRS})

    set(EXTRA_LIBS ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})

# ----------------------------
# Windows
# ----------------------------
elseif(WIN32)
    set(SDL2_DIR "F:/lib/SDL2")
    set(SDL2_TTF_DIR "F:/lib/SDL2_ttf")

    include_directories(
        ${SDL2_DIR}/include
        ${SDL2_TTF_DIR}/include
    )

    link_directories(
        ${SDL2_DIR}/lib
        ${SDL2_TTF_DIR}/lib
    )

    set(EXTRA_LIBS SDL2 SDL2main SDL2_ttf)
endif()

# Kompilacja końcowa
add_executable(mygame ${SOURCES})
target_link_libraries(mygame ${EXTRA_LIBS})
