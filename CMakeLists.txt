cmake_minimum_required(VERSION 3.24)
project(Space_Shooter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Space_Shooter main.cpp Game.cpp Game.h Controller.cpp Controller.h Menu.cpp Menu.h Audio.cpp Audio.h Player.cpp Player.h Enemies.cpp Enemies.h Shoot.cpp Shoot.h Asteroid.cpp Asteroid.h)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Space_Shooter sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


