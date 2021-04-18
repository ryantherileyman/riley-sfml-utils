
add_executable(
	SfmlTextDiscoveryTests
	SfmlTextDiscoveryTests-main.cpp
)
target_link_libraries(
	SfmlTextDiscoveryTests PRIVATE
	sfml-graphics
)
add_custom_command(
	TARGET SfmlTextDiscoveryTests
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${PROJECT_SOURCE_DIR}/src/test-resources/fonts
		$<TARGET_FILE_DIR:SfmlTextDiscoveryTests>
)

add_test(NAME SfmlTextDiscovery COMMAND SfmlTextDiscoveryTests)
