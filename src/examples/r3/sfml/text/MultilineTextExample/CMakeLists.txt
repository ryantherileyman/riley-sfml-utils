
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
	MultilineTextExample
	MultilineTextExample-main.cpp
)
target_link_libraries(
	MultilineTextExample PRIVATE
	r3-StringUtils-lib
	sfml-graphics
	r3-SfmlTextUtils-lib
)
target_include_directories(MultilineTextExample PUBLIC "${PROJECT_SOURCE_DIR}/include")
add_custom_command(
	TARGET MultilineTextExample
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/src/test-resources/fonts
		$<TARGET_FILE_DIR:MultilineTextExample>
)
