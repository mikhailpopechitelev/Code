add_library(queue queue.h queue.cpp)

add_executable(queue_test queue_test.cpp)

target_link_libraries(queue_test queue)