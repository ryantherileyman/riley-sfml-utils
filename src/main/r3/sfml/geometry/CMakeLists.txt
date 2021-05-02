
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(R3_SFML_GEOMETRY_UTILS_EXPORT_ALL_SYMBOLS ${CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

set(R3_SFML_GEOMETRY_UTILS_SOURCES
	r3-sfml-Ellipse.cpp
)

add_library(
	r3-SfmlGeometryUtils-lib STATIC
	${R3_SFML_GEOMETRY_UTILS_SOURCES}
)
target_link_libraries(
	r3-SfmlGeometryUtils-lib PRIVATE
	sfml-graphics
)
target_include_directories(r3-SfmlGeometryUtils-lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_library(
	r3-SfmlGeometryUtils-shared SHARED
	${R3_SFML_GEOMETRY_UTILS_SOURCES}
)
target_link_libraries(
	r3-SfmlGeometryUtils-shared PRIVATE
	sfml-graphics
)
target_include_directories(r3-SfmlGeometryUtils-shared PUBLIC "${PROJECT_SOURCE_DIR}/include")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ${R3_SFML_GEOMETRY_UTILS_EXPORT_ALL_SYMBOLS})
