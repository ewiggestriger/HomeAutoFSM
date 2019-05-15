cmake_minimum_required(VERSION 3.13)
project(HomeAutoFSM)

set(CMAKE_CXX_STANDARD 14)

add_executable(HomeAutoFSM main.cpp StateMachine.h Source.h Sink.h SimExec.h Event.h Distribution.h Distribution.cpp SimExec.cpp Event.cpp Source.cpp StateMachine.cpp Sink.cpp)