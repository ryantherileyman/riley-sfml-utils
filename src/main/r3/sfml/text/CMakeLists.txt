
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(R3_SFML_UTILS_EXPORT_ALL_SYMBOLS ${CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

set(R3_SFML_UTILS_SOURCES
	r3-sfml-TextUtils.cpp
	r3-sfml-FontFamily.cpp
	r3-sfml-MultilineTextUtils.cpp
)

add_library(
	r3-SfmlTextUtils-lib STATIC
	${R3_SFML_UTILS_SOURCES}
)
target_link_libraries(
	r3-SfmlTextUtils-lib PRIVATE
	r3-StringUtils-lib
	sfml-graphics
)
target_include_directories(r3-SfmlTextUtils-lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ${R3_SFML_UTILS_EXPORT_ALL_SYMBOLS})
