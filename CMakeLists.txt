cmake_minimum_required(VERSION 3.23)
project(feup_aed1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(feup_aed1
        src/sloth.cpp
        src/sloth.h
        src/student.cpp
        src/student.h
        src/turma.cpp
        src/turma.h
        src/uc.cpp
        src/uc.h
        src/DataManager.h
        src/DataManager.cpp
        src/main.cpp
)

