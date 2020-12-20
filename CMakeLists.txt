project(leetcode-solutions)
cmake_minimum_required(VERSION 3.18.3)

set(CONAN_SYSTEM_INCLUDES ON)

# Setup CMake-Conan wrapper
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.15/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(
        CONANFILE conanfile.py
        BASIC_SETUP
        BUILD missing)

add_executable(${PROJECT_NAME}
        data-structures/array/add_binary.cpp
        data-structures/array/diagonal_traverse.cpp
        data-structures/array/duplicate_zeros.cpp
        data-structures/array/find_numbers_with_even_number_of_digits.cpp
        data-structures/array/find_pivot_index.cpp
        data-structures/array/implement_str_str.cpp
        data-structures/array/largest_number_at_least_twice_of_others.cpp
        data-structures/array/max_consecutive_ones.cpp
        data-structures/array/plus_one.cpp
        data-structures/array/reverse_string.cpp
        data-structures/array/spiral_matrix.cpp
        data-structures/array/squares_of_a_sorted_array.cpp

        data-structures/linked-list/singly_linked_list.cpp
        data-structures/linked-list/doubly_linked_list.cpp
        data-structures/linked-list/linked_list_cycle.cpp
        data-structures/linked-list/linked_list_cycle_II.cpp
        data-structures/linked-list/singly_list_node.cpp

        data-structures/queue/circular_queue.cpp

        data-structures/stack/daily_temperatures.cpp
        data-structures/stack/min_stack.cpp
        data-structures/stack/valid_parentheses.cpp

        search-algorithms/binary-search/binary_search.cpp
        search-algorithms/binary-search/guess_number_higher_or_lower.cpp
        search-algorithms/binary-search/search_in_rotated_sorted_array.cpp
        search-algorithms/binary-search/sqrt.cpp

        search-algorithms/linear-search/linear_search.cpp

        search-algorithms/missing_number.cpp)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_CATCH2} -static)
