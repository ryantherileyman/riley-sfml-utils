
#include <assert.h>
#include <iostream>
#include <r3/sfml/text/r3-sfml-TextUtils.hpp>
#include <r3/sfml/text/r3-sfml-FontFamily.hpp>
#include <r3/sfml/text/r3-sfml-MultilineTypesettingBlock.hpp>

bool testSplitIntoLines_NoWrapping(const r3::sfml::FontFamily& fontFamily) {
	sf::Text rawText = fontFamily.createTextWithStyle(sf::Text::Regular);
	rawText.setString("two words\ntwo words");

	sf::Vector2f rawTextWidth = r3::sfml::TextUtils::resolveTextWidth(rawText);

	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setMaxLineWidth(rawTextWidth.x);

	std::vector<sf::String> blockLineList = block.splitIntoLines(rawText.getString());

	bool result =
		(blockLineList.size() == 2) &&
		(blockLineList.at(0).toAnsiString().compare("two words") == 0) &&
		(blockLineList.at(1).toAnsiString().compare("two words") == 0);
	return result;
}

bool testSplitIntoLines_Wrapping(const r3::sfml::FontFamily& fontFamily) {
	sf::Text rawText = fontFamily.createTextWithStyle(sf::Text::Regular);
	rawText.setString("two words");

	sf::Vector2f rawTextWidth = r3::sfml::TextUtils::resolveTextWidth(rawText);

	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setMaxLineWidth(rawTextWidth.x - 1.0f);

	std::vector<sf::String> blockLineList = block.splitIntoLines(rawText.getString());

	bool result =
		(blockLineList.size() == 2) &&
		(blockLineList.at(0).toAnsiString().compare("two") == 0) &&
		(blockLineList.at(1).toAnsiString().compare("words") == 0);
	return result;
}

int main() {
	r3::sfml::FontFamily fontFamily;
	fontFamily.loadBaseFontFromFile("OpenSans-Regular.ttf");

	assert(testSplitIntoLines_NoWrapping(fontFamily));
	assert(testSplitIntoLines_Wrapping(fontFamily));

	std::cout << "All tests passed!";
	return 0;
}
