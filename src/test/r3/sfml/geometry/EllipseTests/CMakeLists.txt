
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
	EllipseTests
	EllipseTests-main.cpp
)
target_link_libraries(
	EllipseTests PRIVATE
	sfml-graphics
	r3-SfmlGeometryUtils-lib
)

add_test(Ellipse COMMAND EllipseTests)
