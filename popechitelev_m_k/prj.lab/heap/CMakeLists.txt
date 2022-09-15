add_library(heap heap.h heap.cpp)

add_executable(heap_test heap_test.cpp)

target_link_libraries(heap_test heap)