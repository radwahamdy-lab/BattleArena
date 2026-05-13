set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

cmake_minimum_required(VERSION 3.21)
project(mygame)

add_executable(
    game
    gui/main.cpp
    gui/CharacterScreen.h
    gui/StartScreen.h
    gui/StartScreen.cpp
    gui/GameScreen.h
    gui/GameScreen.cpp
    gui/Character.h
    gui/Character.cpp
    gui/Projectile.h
    gui/Projectile.cpp
    gui/Scoreboard.h
    gui/Scoreboard.cpp
    gui/Obstacle.h
    gui/Obstacle.cpp
    gui/game.cpp
    gui/game.h
    gui/GameOverScreen.h
    gui/GameOverScreen.cpp
    assets/resources.qrc
)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

target_link_libraries(game PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
