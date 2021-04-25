
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
	TextUtilsTests
	TextUtilsTests-main.cpp
)
target_link_libraries(
	TextUtilsTests PRIVATE
	sfml-graphics
	r3-SfmlTextUtils-lib
)
add_custom_command(
	TARGET TextUtilsTests
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/src/test-resources/fonts
		$<TARGET_FILE_DIR:TextUtilsTests>
)

add_test(NAME TextUtils COMMAND TextUtilsTests)
