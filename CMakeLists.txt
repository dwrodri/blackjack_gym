cmake_minimum_required(VERSION 3.10)
project(blackjack_gym C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)
set(CMAKE_C_STANDARD 11)

add_executable(blackjack_gym src/main.c src/GameInstance.c src/GameInstance.h)