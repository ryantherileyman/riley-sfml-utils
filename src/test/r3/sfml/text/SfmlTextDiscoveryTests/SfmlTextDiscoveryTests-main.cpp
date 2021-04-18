
#include <assert.h>
#include <iostream>
#include <SFML/Graphics.hpp>

bool testNewline_MidSentence() {
	sf::Font font;
	font.loadFromFile("OpenSans-Regular.ttf");
	
	sf::Text singleLine;
	singleLine.setFont(font);
	singleLine.setString(L"Hello world!");

	sf::Text multiLine;
	multiLine.setFont(font);
	multiLine.setString(L"Hello\nworld!");

	sf::Vector2f singleHPos = singleLine.findCharacterPos(0);
	sf::Vector2f singleWPos = singleLine.findCharacterPos(6);

	sf::Vector2f multiHPos = multiLine.findCharacterPos(0);
	sf::Vector2f multiWPos = multiLine.findCharacterPos(6);

	bool result =
		(singleHPos.x != singleWPos.x) &&
		(singleHPos.y == multiHPos.x) &&
		(singleWPos.y != multiWPos.y);
	return result;
}

bool testNewLine_EndOfString() {
	sf::Font font;
	font.loadFromFile("OpenSans-Regular.ttf");

	sf::Text text;
	text.setFont(font);
	text.setString(L"\n");

	sf::Vector2f startPos = text.findCharacterPos(0);
	sf::Vector2f endPos = text.findCharacterPos(1);

	bool result =
		(startPos.x == endPos.x) &&
		(startPos.y < endPos.y);
	return result;
}

int main() {
	assert(testNewline_MidSentence());
	assert(testNewLine_EndOfString());

	std::cout << "All tests passed!";
	return 0;
}
