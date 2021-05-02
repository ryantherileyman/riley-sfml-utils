
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
	MultilineTypesettingBlockTests
	MultilineTypesettingBlockTests-main.cpp
)
target_link_libraries(
	MultilineTypesettingBlockTests PRIVATE
	sfml-graphics
	r3-SfmlTextUtils-lib
)
add_custom_command(
	TARGET MultilineTypesettingBlockTests
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/src/test-resources/fonts
		$<TARGET_FILE_DIR:MultilineTypesettingBlockTests>
)

add_test(NAME MultilineTypesettingBlock COMMAND MultilineTypesettingBlockTests)
