add_library(arithmetics SHARED src/arithmetics.cpp)

target_include_directories(arithmetics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
