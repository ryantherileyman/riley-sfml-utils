
cmake_minimum_required(VERSION 3.19)

project(RileySfmlUtils VERSION 1.1)

add_subdirectory(dependencies/riley-cpp-utils)
add_subdirectory(dependencies/sfml)

option(RILEY_SFML_UTILS_WITH_EXAMPLES "Build RileySfmlUtils example programs" ON)
option(RILEY_SFML_UTILS_WITH_TESTS "Build and run RileySfmlUtils test executables" ON)

add_subdirectory(src/main/r3/sfml)

if (${RILEY_SFML_UTILS_WITH_EXAMPLES})
	add_subdirectory(src/examples/r3/sfml)
endif()

if (${RILEY_SFML_UTILS_WITH_TESTS})
	enable_testing()
	add_subdirectory(src/test/r3/sfml)
endif()
