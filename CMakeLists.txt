cmake_minimum_required(VERSION 3.26)
project(TetrisS)

set(CMAKE_CXX_STANDARD 17)
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIR} )

add_executable(TetrisS main.cpp
        Tetramino.cpp
        Tetramino.h
        Grid.cpp
        Grid.h
        TetrisLogicController.cpp
        TetrisLogicController.h
        TetrisGameRenderer.cpp
        TetrisGameRenderer.h
        ScoreBoard.cpp
        ScoreBoard.h
        Menu.cpp
        Menu.h
)
target_link_libraries( TetrisS ${CURSES_LIBRARIES} )