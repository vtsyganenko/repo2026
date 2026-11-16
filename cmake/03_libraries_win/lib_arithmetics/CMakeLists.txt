add_library(arithmetics SHARED src/arithmetics.cpp)

target_include_directories(arithmetics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# define variable for export
target_compile_definitions(arithmetics PRIVATE ARITHMETICS_EXPORTS)
