
#include <assert.h>
#include <iostream>
#include <r3/sfml/geometry/r3-sfml-Ellipse.hpp>

template <typename T>
bool testContains(const r3::sfml::Ellipse<T>& ellipse, const sf::Vector2<T>& point, bool expectedResult) {
	bool actual = ellipse.contains(point);
	bool result = (actual == expectedResult);
	return result;
}

int main() {
	r3::sfml::FloatEllipse floatEllipse(10.0f, 20.0f, 2.0f, 5.0f);

	assert(testContains(floatEllipse, sf::Vector2f(10.0f, 20.0f), true));
	assert(testContains(floatEllipse, sf::Vector2f(12.0f, 20.0f), true));
	assert(testContains(floatEllipse, sf::Vector2f(8.0f, 20.0f), true));
	assert(testContains(floatEllipse, sf::Vector2f(10.0f, 15.0f), true));
	assert(testContains(floatEllipse, sf::Vector2f(10.0f, 25.0f), true));
	assert(testContains(floatEllipse, sf::Vector2f(12.01f, 20.0f), false));
	assert(testContains(floatEllipse, sf::Vector2f(7.99f, 20.0f), false));
	assert(testContains(floatEllipse, sf::Vector2f(10.0f, 14.99), false));
	assert(testContains(floatEllipse, sf::Vector2f(10.0f, 25.01f), false));
	assert(testContains(floatEllipse, sf::Vector2f(8.4f, 16.0f), false));

	r3::sfml::IntEllipse intEllipse(10, 20, 2, 5);

	assert(testContains(intEllipse, sf::Vector2i(10, 20), true));
	assert(testContains(intEllipse, sf::Vector2i(13, 20), false));

	std::cout << "All tests passed!\n";
	return 0;
}
