add_executable(analytics_test 
    my_random.cpp
    analytics_test.cpp
)

target_link_libraries(analytics_test PRIVATE analytics)
