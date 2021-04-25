
#include <assert.h>
#include <iostream>
#include <math.h>
#include <r3/sfml/text/r3-sfml-TextUtils.hpp>

bool testResolveLineHeight() {
	sf::Font font;
	font.loadFromFile("OpenSans-Regular.ttf");

	sf::Text text;
	text.setFont(font);

	sf::Vector2f lineHeight = r3::sfml::TextUtils::resolveLineHeight(text);

	bool result =
		(lineHeight.x == 0.0f) &&
		(lineHeight.y > (float)text.getCharacterSize());
	return result;
}

bool testResolveLineHeight_Rotated() {
	sf::Font font;
	font.loadFromFile("OpenSans-Regular.ttf");

	sf::Text nonRotatedText;
	nonRotatedText.setFont(font);

	sf::Text rotatedText;
	rotatedText.setFont(font);
	rotatedText.setRotation(-45.0f);

	sf::Vector2f nonRotatedLineHeight = r3::sfml::TextUtils::resolveLineHeight(nonRotatedText);
	float nonRotatedLineDistance = sqrtf(powf(nonRotatedLineHeight.x, 2.0f) + powf(nonRotatedLineHeight.y, 2.0f));

	sf::Vector2f rotatedLineHeight = r3::sfml::TextUtils::resolveLineHeight(rotatedText);
	float rotatedLineDistance = sqrtf(powf(rotatedLineHeight.x, 2.0f) + powf(rotatedLineHeight.y, 2.0f));

	bool result =
		(nonRotatedLineHeight.x == 0.0f) &&
		(rotatedLineHeight.x > 0.0f) &&
		(lroundf(nonRotatedLineDistance * 1000000.0f) == lroundf(rotatedLineDistance * 1000000.0f));
	return result;
}

int main() {
	assert(testResolveLineHeight());
	assert(testResolveLineHeight_Rotated());

	std::cout << "All tests passed!";
	return 0;
}
