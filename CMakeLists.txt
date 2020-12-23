project(leetcode-solutions)
cmake_minimum_required(VERSION 3.18.3)

project(${PROJECT_NAME}
				VERSION 0.1
				DESCRIPTION "LeetCode solutions with modern approach in C++"
				LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #If the compiler doesn’t support the specified standard, by default CMake falls back to the latest standard the compiler does support instead. It does not generate an error by default. To prevent this fallback behaviour
set(CMAKE_CXX_EXTENSIONS OFF) #Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_POSITION_INDEPENDENT_CODE ON) #https://stackoverflow.com/questions/5311515/gcc-fpic-option
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CONAN_SYSTEM_INCLUDES ON) #Put -isystem instead of -I for third-parties

# Setup CMake-Conan wrapper
if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
	message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
	file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.15/conan.cmake"
			 "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.py
								BASIC_SETUP
								BUILD missing)

add_subdirectory(sources)
add_subdirectory(tests)
