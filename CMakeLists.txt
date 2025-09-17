cmake_minimum_required(VERSION 3.10)
project(dsa)

set(CMAKE_C_STANDARD 99)

include_directories(include)
# add_library(mylib src/mylib.c)

# main program
set(SOURCES
    src/main.c
    src/util/util.c
    src/basic_data_structures/linkedlist.c
    src/basic_data_structures/stack.c
    src/basic_data_structures/dynamicarray.c
    src/basic_data_structures/queue_linkedlist.c
    src/basic_data_structures/queue.c
    src/basic_data_structures/hashtable.c
    src/sorting_algorithms/bubblesort.c
    src/sorting_algorithms/insertionsort.c
)
add_executable(my_program ${SOURCES})

# enable_testing()
# add_executable(linkedlist_test 
#     tests/linkedlist_test.c
#     src/linkedlist.c
# )
# target_include_directories(linkedlist_test PRIVATE include)

add_test(NAME LinkedListTests COMMAND linkedlist_test)