add_library(analytics STATIC src/analytics.cpp)

target_include_directories(analytics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(tests)
