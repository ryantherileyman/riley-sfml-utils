
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

bool testCreateAlignedTextList_TopLeft(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::LEFT);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::TOP);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	bool result = (textList.size() == stringList.size());
	for (const auto& currText : textList) {
		result = result &&
			(currText.getPosition().x == block.getPosition().x) &&
			(currText.getPosition().y >= block.getPosition().y);
	}
	return result;
}

bool testCreateAlignedTextList_MiddleLeft(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::LEFT);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::MIDDLE);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	size_t expectedLinesBelowPosition = stringList.size() / 2;

	int linesBelowPosition = 0;
	bool result = (textList.size() == stringList.size());
	for (const auto& currText : textList) {
		if (currText.getPosition().y > block.getPosition().y) {
			linesBelowPosition++;
		}
		result = result && (currText.getPosition().x == block.getPosition().x);
	}
	result = result && (linesBelowPosition == expectedLinesBelowPosition);
	return result;
}

bool testCreateAlignedTextList_BottomLeft(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::LEFT);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::BOTTOM);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	bool result = (textList.size() == stringList.size());
	for (const auto& currText : textList) {
		result = result &&
			(currText.getPosition().x == block.getPosition().x) &&
			(currText.getPosition().y < block.getPosition().y);
	}
	return result;
}

bool testCreateAlignedTextList_TopCenter(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::CENTER);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::TOP);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	bool result = (textList.size() == stringList.size());
	for (auto const& currText : textList) {
		float currTextWidth = r3::sfml::TextUtils::resolveTextWidth(currText).x;

		result = result &&
			(currText.getPosition().x <= block.getPosition().x) &&
			((currText.getPosition().x + currTextWidth) >= block.getPosition().x) &&
			(currText.getPosition().y >= block.getPosition().y);
	}
	return result;
}

bool testCreateAlignedTextList_MiddleCenter(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::CENTER);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::MIDDLE);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	size_t expectedLinesBelowPosition = stringList.size() / 2;

	size_t linesBelowPosition = 0;
	bool result = (textList.size() == stringList.size());
	for (auto const& currText : textList) {
		if (currText.getPosition().y > block.getPosition().y) {
			linesBelowPosition++;
		}

		float currTextWidth = r3::sfml::TextUtils::resolveTextWidth(currText).x;

		result = result &&
			(currText.getPosition().x <= block.getPosition().x) &&
			((currText.getPosition().x + currTextWidth) >= block.getPosition().x);
	}
	result = result && (linesBelowPosition == expectedLinesBelowPosition);
	return result;
}

bool testCreateAlignedTextList_BottomCenter(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::CENTER);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::BOTTOM);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	bool result = (textList.size() == stringList.size());
	for (const auto& currText : textList) {
		float currTextWidth = r3::sfml::TextUtils::resolveTextWidth(currText).x;

		result = result &&
			(currText.getPosition().x <= block.getPosition().x) &&
			((currText.getPosition().x + currTextWidth) >= block.getPosition().x) &&
			(currText.getPosition().y < block.getPosition().y);
	}
	return result;
}

bool testCreateAlignedTextList_TopRight(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::RIGHT);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::TOP);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	bool result = (textList.size() == stringList.size());
	for (const auto& currText : textList) {
		result = result &&
			(currText.getPosition().x <= block.getPosition().x) &&
			(currText.getPosition().y >= block.getPosition().y);
	}
	return result;
}

bool testCreateAlignedTextList_MiddleRight(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::RIGHT);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::MIDDLE);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	size_t expectedLinesBelowPosition = stringList.size() / 2;

	size_t linesBelowPosition = 0;
	bool result = (textList.size() == stringList.size());
	for (const auto& currText : textList) {
		if (currText.getPosition().y > block.getPosition().y) {
			linesBelowPosition++;
		}

		result = result &&
			(currText.getPosition().x <= block.getPosition().x);
	}
	result = result && (linesBelowPosition == expectedLinesBelowPosition);
	return result;
}

bool testCreateAlignedTextList_BottomRight(const r3::sfml::FontFamily& fontFamily, const std::vector<sf::String>& stringList) {
	r3::sfml::MultilineTypesettingBlock block(fontFamily);
	block.setPosition(sf::Vector2f(100.0f, 100.0f));
	block.setTextAlignment(r3::sfml::TextAlignment::RIGHT);
	block.setVerticalAlignment(r3::sfml::VerticalAlignment::BOTTOM);

	std::vector<sf::Text> textList = block.createAlignedTextList(stringList);

	bool result = (textList.size() == stringList.size());
	for (const auto& currText : textList) {
		result = result &&
			(currText.getPosition().x <= block.getPosition().x) &&
			(currText.getPosition().y <= block.getPosition().y);
	}
	return result;
}

int main() {
	r3::sfml::FontFamily fontFamily;
	fontFamily.loadBaseFontFromFile("OpenSans-Regular.ttf");

	assert(testSplitIntoLines_NoWrapping(fontFamily));
	assert(testSplitIntoLines_Wrapping(fontFamily));

	std::vector<sf::String> stringList;
	stringList.push_back("It's the first line");
	stringList.push_back("And a second line");
	stringList.push_back("Wow a third line");
	stringList.push_back("Why is there a fourth line?");
	stringList.push_back("Now it's just getting silly");

	assert(testCreateAlignedTextList_TopLeft(fontFamily, stringList));
	assert(testCreateAlignedTextList_MiddleLeft(fontFamily, stringList));
	assert(testCreateAlignedTextList_BottomLeft(fontFamily, stringList));

	assert(testCreateAlignedTextList_TopCenter(fontFamily, stringList));
	assert(testCreateAlignedTextList_MiddleCenter(fontFamily, stringList));
	assert(testCreateAlignedTextList_BottomCenter(fontFamily, stringList));

	assert(testCreateAlignedTextList_TopRight(fontFamily, stringList));
	assert(testCreateAlignedTextList_MiddleRight(fontFamily, stringList));
	assert(testCreateAlignedTextList_BottomRight(fontFamily, stringList));

	std::cout << "All tests passed!";
	return 0;
}
