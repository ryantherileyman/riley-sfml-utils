
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
	FontFamilyExample
	FontFamilyExample-main.cpp
)
target_link_libraries(
	FontFamilyExample PRIVATE
	sfml-graphics
	r3-SfmlTextUtils-lib
)
target_include_directories(FontFamilyExample PUBLIC "${PROJECT_SOURCE_DIR}/include")
add_custom_command(
	TARGET FontFamilyExample
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/src/test-resources/fonts
		$<TARGET_FILE_DIR:FontFamilyExample>
)
