
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
	FontFamilyTests
	FontFamilyTests-main.cpp
)
target_link_libraries(
	FontFamilyTests PRIVATE
	sfml-graphics
	r3-SfmlTextUtils-lib
)
add_custom_command(
	TARGET FontFamilyTests
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/src/test-resources/fonts
		$<TARGET_FILE_DIR:FontFamilyTests>
)

add_test(NAME FontFamily COMMAND FontFamilyTests)
