
#include <chrono>
#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>
#include <r3/sfml/text/r3-sfml-FontFamily.hpp>
#include <r3/sfml/text/r3-sfml-MultilineTypesettingBlock.hpp>

void drawBlock(sf::RenderTarget& target, const r3::sfml::MultilineTypesettingBlock& block, const sf::String& string) {
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

			r3::sfml::MultilineTypesettingBlock leftBlock(fontFamily);
			leftBlock.updateTypesetting(typesettingDefn);
			leftBlock.setPosition(sf::Vector2f(20.0f, 100.0f));
			leftBlock.setMaxLineWidth(200.0f);
			drawBlock(window, leftBlock, string);

			r3::sfml::MultilineTypesettingBlock centerBlock(fontFamily);
			centerBlock.updateTypesetting(typesettingDefn);
			centerBlock.setTextAlignment(r3::sfml::TextAlignment::CENTER);
			centerBlock.setPosition(sf::Vector2f(400.0f, 100.0f));
			centerBlock.setMaxLineWidth(200.0f);
			drawBlock(window, centerBlock, string);

			r3::sfml::MultilineTypesettingBlock rightBlock(fontFamily);
			rightBlock.updateTypesetting(typesettingDefn);
			rightBlock.setTextAlignment(r3::sfml::TextAlignment::RIGHT);
			rightBlock.setPosition(sf::Vector2f(780.0f, 100.0f));
			rightBlock.setMaxLineWidth(200.0f);
			drawBlock(window, rightBlock, string);

			window.display();

			std::this_thread::sleep_for(std::chrono::microseconds(10));
		}
	}

	return 0;
}
