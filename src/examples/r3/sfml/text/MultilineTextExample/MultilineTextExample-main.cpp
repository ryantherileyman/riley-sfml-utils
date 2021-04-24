
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include <r3/sfml/text/r3-sfml-MultilineTextUtils.hpp>

int main() {
	r3::sfml::LoadFontFamilyDefn loadFontFamilyDefn;
	loadFontFamilyDefn.baseFontFilename = "OpenSans-Semibold.ttf";

	r3::sfml::FontFamily fontFamily;
	fontFamily.load(loadFontFamilyDefn);

	sf::RenderWindow window(sf::VideoMode(800, 450), "Riley SfmlTextUtils -- FontFamilyExample");

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

			r3::sfml::MultilineTextDefn textDefn;
			textDefn.typesettingDefn.fontFamily = &fontFamily;
			textDefn.typesettingDefn.characterSize = 12;
			textDefn.position = sf::Vector2f(20.0f, 20.0f);
			textDefn.maxLineWidth = currMaxLineWidth;
			textDefn.string = L"This is some example text that we want to wrap. \t\t\t\t It should totally wrap at least once, dude!\nA new line goes here no matter what.\n\nOr two new lines.";

			sf::Text text = r3::sfml::MultilineTextUtils::buildText(textDefn);
			window.draw(text);

			window.display();

			std::this_thread::sleep_for(std::chrono::microseconds(10));
		}
	}

	return 0;
}
