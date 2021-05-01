
#include <chrono>
#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>
#include <r3/sfml/text/r3-sfml-FontFamily.hpp>
#include <r3/sfml/text/r3-sfml-MultilineTypesettingBlock.hpp>

void drawBlock(sf::RenderTarget& target, const r3::sfml::MultilineTypesettingBlock& block, const sf::String& string) {
	sf::CircleShape positionShape;
	positionShape.setPosition(block.getPosition() - sf::Vector2f(5.0f, 5.0f));
	positionShape.setRadius(5.0f);
	positionShape.setFillColor(sf::Color::Black);
	target.draw(positionShape);

	std::vector<sf::Text> textList = block.createTextList(string);

	for (const auto& currText : textList) {
		target.draw(currText);
	}
}

int main() {
	r3::sfml::LoadFontFamilyDefn loadFontFamilyDefn;
	loadFontFamilyDefn.baseFontFilename = "OpenSans-Semibold.ttf";

	r3::sfml::FontFamily fontFamily;
	fontFamily.load(loadFontFamilyDefn);

	r3::sfml::TypesettingDefn typesettingDefn;
	typesettingDefn.characterSize = 12;

	sf::RenderWindow window(sf::VideoMode(800, 450), "Riley SfmlTextUtils -- MultilineTextExample");

	float currMaxLineWidth = 300.0f;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (window.isOpen()) {
			window.clear(sf::Color(64, 64, 64, 255));

			sf::String string = "This is some example text that we want to wrap.  It should wrap at least once, I should think!\nA new line goes here no matter what.\n\nOr two new lines.";

			std::vector<sf::Text> textList;

			r3::sfml::MultilineTypesettingBlock topLeftBlock(fontFamily);
			topLeftBlock.updateTypesetting(typesettingDefn);
			topLeftBlock.setVerticalAlignment(r3::sfml::VerticalAlignment::TOP);
			topLeftBlock.setPosition(sf::Vector2f(20.0f, 20.0f));
			topLeftBlock.setMaxLineWidth(200.0f);
			drawBlock(window, topLeftBlock, string);

			r3::sfml::MultilineTypesettingBlock middleLeftBlock(fontFamily);
			middleLeftBlock.updateTypesetting(typesettingDefn);
			middleLeftBlock.setVerticalAlignment(r3::sfml::VerticalAlignment::MIDDLE);
			middleLeftBlock.setPosition(sf::Vector2f(20.0f, 225.0f));
			middleLeftBlock.setMaxLineWidth(200.0f);
			drawBlock(window, middleLeftBlock, string);

			r3::sfml::MultilineTypesettingBlock bottomLeftBlock(fontFamily);
			bottomLeftBlock.updateTypesetting(typesettingDefn);
			bottomLeftBlock.setVerticalAlignment(r3::sfml::VerticalAlignment::BOTTOM);
			bottomLeftBlock.setPosition(sf::Vector2f(20.0f, 430.0f));
			bottomLeftBlock.setMaxLineWidth(200.0f);
			drawBlock(window, bottomLeftBlock, string);

			r3::sfml::MultilineTypesettingBlock topCenterBlock(fontFamily);
			topCenterBlock.updateTypesetting(typesettingDefn);
			topCenterBlock.setTextAlignment(r3::sfml::TextAlignment::CENTER);
			topCenterBlock.setPosition(sf::Vector2f(400.0f, 20.0f));
			topCenterBlock.setMaxLineWidth(200.0f);
			drawBlock(window, topCenterBlock, string);

			r3::sfml::MultilineTypesettingBlock middleCenterBlock(fontFamily);
			topCenterBlock.updateTypesetting(typesettingDefn);
			topCenterBlock.setTextAlignment(r3::sfml::TextAlignment::CENTER);
			topCenterBlock.setVerticalAlignment(r3::sfml::VerticalAlignment::MIDDLE);
			topCenterBlock.setPosition(sf::Vector2f(400.0f, 225.0f));
			topCenterBlock.setMaxLineWidth(200.0f);
			drawBlock(window, topCenterBlock, string);

			r3::sfml::MultilineTypesettingBlock bottomCenterBlock(fontFamily);
			topCenterBlock.updateTypesetting(typesettingDefn);
			topCenterBlock.setTextAlignment(r3::sfml::TextAlignment::CENTER);
			topCenterBlock.setVerticalAlignment(r3::sfml::VerticalAlignment::BOTTOM);
			topCenterBlock.setPosition(sf::Vector2f(400.0f, 430.0f));
			topCenterBlock.setMaxLineWidth(200.0f);
			drawBlock(window, topCenterBlock, string);

			r3::sfml::MultilineTypesettingBlock topRightBlock(fontFamily);
			topRightBlock.updateTypesetting(typesettingDefn);
			topRightBlock.setTextAlignment(r3::sfml::TextAlignment::RIGHT);
			topRightBlock.setPosition(sf::Vector2f(780.0f, 20.0f));
			topRightBlock.setMaxLineWidth(200.0f);
			drawBlock(window, topRightBlock, string);

			r3::sfml::MultilineTypesettingBlock middleRightBlock(fontFamily);
			middleRightBlock.updateTypesetting(typesettingDefn);
			middleRightBlock.setTextAlignment(r3::sfml::TextAlignment::RIGHT);
			middleRightBlock.setVerticalAlignment(r3::sfml::VerticalAlignment::MIDDLE);
			middleRightBlock.setPosition(sf::Vector2f(780.0f, 225.0f));
			middleRightBlock.setMaxLineWidth(200.0f);
			drawBlock(window, middleRightBlock, string);

			r3::sfml::MultilineTypesettingBlock bottomRightBlock(fontFamily);
			bottomRightBlock.updateTypesetting(typesettingDefn);
			bottomRightBlock.setTextAlignment(r3::sfml::TextAlignment::RIGHT);
			bottomRightBlock.setVerticalAlignment(r3::sfml::VerticalAlignment::BOTTOM);
			bottomRightBlock.setPosition(sf::Vector2f(780.0f, 430.0f));
			bottomRightBlock.setMaxLineWidth(200.0f);
			drawBlock(window, bottomRightBlock, string);

			window.display();

			std::this_thread::sleep_for(std::chrono::microseconds(10));
		}
	}

	return 0;
}
