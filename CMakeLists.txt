cmake_minimum_required(VERSION 3.20)
project(graphy)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address -Wall")

find_package(SDL3 REQUIRED)

add_library(graphylib
    src/matrix.c
)

target_link_libraries(graphylib PUBLIC SDL3::SDL3)

function(add_exe name)
    add_executable(${name} src/main.c)
    target_link_libraries(${name} PRIVATE SDL3::SDL3 graphylib m)
endfunction()

add_exe(graphy)
