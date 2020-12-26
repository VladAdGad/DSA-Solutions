set(PROJECT_LIBRARY_SOURCE ${PROJECT_NAME}-source CACHE STRING libraries)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS *.cpp)
add_library(${PROJECT_LIBRARY_SOURCE} STATIC ${PROJECT_SOURCES})

target_include_directories(${PROJECT_LIBRARY_SOURCE}
													 INTERFACE
													 data-structures/array
													 data-structures/binary-tree
													 data-structures/linked-list
													 data-structures/queue
													 data-structures/stack
													 search-algorithms
													 search-algorithms/binary-search
													 search-algorithms/linear-search
													 sorting-algorithms)
