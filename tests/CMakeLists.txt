set(PROJECT_TESTS ${PROJECT_NAME}-tests)

file(GLOB_RECURSE PROJECT_TEST_SOURCES CONFIGURE_DEPENDS *.cpp)
add_executable(${PROJECT_TESTS} ${PROJECT_TEST_SOURCES})

target_link_libraries(${PROJECT_TESTS} PRIVATE ${PROJECT_LIBRARY_SOURCE} ${CONAN_LIBS_CATCH2})
