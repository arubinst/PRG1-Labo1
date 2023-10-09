cmake_minimum_required(VERSION 3.16)
project(PRG1-Labo-1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-pedantic")

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests tests_labo1.cpp montantEnToutesLettres.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(Labo1 main.cpp montantEnToutesLettres.cpp)