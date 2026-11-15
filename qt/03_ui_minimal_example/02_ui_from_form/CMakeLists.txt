cmake_minimum_required(VERSION 3.15)

project(Example_cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(SOURCES 
	main.cpp
	widget.cpp)

set(HEADERS
	widget.h)

set(FORMS
	widget.ui)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
