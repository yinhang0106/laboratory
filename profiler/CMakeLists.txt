add_executable(test_profiler main.cpp)
target_link_libraries(test_profiler PUBLIC utils)

add_executable(test_benchmark test_benchmark.cpp)
target_link_libraries(test_benchmark PUBLIC benchmark::benchmark)