
#include <chrono>
#include <thread>
#include <r3/sfml/text/r3-sfml-TextUtils.hpp>
#include <r3/sfml/text/r3-sfml-FontFamily.hpp>

int main() {
	r3::sfml::LoadFontFamilyDefn loadFontFamilyDefn;
	loadFontFamilyDefn.baseFontFilename = "OpenSans-Semibold.ttf";
	loadFontFamilyDefn.boldFontFilename = "OpenSans-Bold.ttf";
	loadFontFamilyDefn.italicFontFilename = "OpenSans-SemiboldItalic.ttf";
	loadFontFamilyDefn.boldItalicFontFilename = "OpenSans-BoldItalic.ttf";

	r3::sfml::FontFamily fontFamily;
	fontFamily.load(loadFontFamilyDefn);

	sf::RenderWindow window(sf::VideoMode(800, 450), "Riley SfmlTextUtils -- FontFamilyExample");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (window.isOpen()) {
			window.clear(sf::Color(64, 64, 64, 255));

			sf::Text descriptionText = fontFamily.createTextWithStyle(sf::Text::Regular);
			descriptionText.setCharacterSize(24);
			descriptionText.setString(L"SFML-rendered text is on the left, natural text is on the right");
			float descriptionTextWidth = r3::sfml::TextUtils::resolveTextWidth(descriptionText);
			descriptionText.setPosition(400.0f - descriptionTextWidth / 2.0f, 10.0f);
			window.draw(descriptionText);

			sf::Text sfmlPlainText = fontFamily.createTextWithStyle(sf::Text::Regular);
			sfmlPlainText.setCharacterSize(16);
			sfmlPlainText.setString(L"OpenSans Semibold 16pt");
			sfmlPlainText.setPosition(sf::Vector2f(20.0f, 60.0f));
			window.draw(sfmlPlainText);

			sf::Text naturalPlainText = fontFamily.createTextWithStyle(sf::Text::Regular);
			naturalPlainText.setCharacterSize(16);
			naturalPlainText.setString(L"OpenSans Semibold 16pt");
			naturalPlainText.setPosition(sf::Vector2f(420.0f, 60.0f));
			window.draw(naturalPlainText);

			sf::Text sfmlBoldText = fontFamily.createTextWithStyle(sf::Text::Regular);
			sfmlBoldText.setCharacterSize(16);
			sfmlBoldText.setStyle(sf::Text::Bold);
			sfmlBoldText.setString(L"OpenSans SFML Bold");
			sfmlBoldText.setPosition(sf::Vector2f(20.0f, 110.0f));
			window.draw(sfmlBoldText);

			sf::Text naturalBoldText = fontFamily.createTextWithStyle(sf::Text::Bold);
			naturalBoldText.setCharacterSize(16);
			naturalBoldText.setString(L"OpenSans Natural Bold");
			naturalBoldText.setPosition(sf::Vector2f(420.0f, 110.0f));
			window.draw(naturalBoldText);

			sf::Text sfmlItalicText = fontFamily.createTextWithStyle(sf::Text::Regular);
			sfmlItalicText.setCharacterSize(16);
			sfmlItalicText.setStyle(sf::Text::Italic);
			sfmlItalicText.setString(L"OpenSans SFML Italic");
			sfmlItalicText.setPosition(sf::Vector2f(20.0f, 160.0f));
			window.draw(sfmlItalicText);

			sf::Text naturalItalicText = fontFamily.createTextWithStyle(sf::Text::Italic);
			naturalItalicText.setCharacterSize(16);
			naturalItalicText.setString(L"OpenSans Natural Italic");
			naturalItalicText.setPosition(sf::Vector2f(420.0f, 160.0f));
			window.draw(naturalItalicText);

			sf::Text sfmlBoldItalicText = fontFamily.createTextWithStyle(sf::Text::Regular);
			sfmlBoldItalicText.setCharacterSize(16);
			sfmlBoldItalicText.setStyle(sf::Text::Bold | sf::Text::Italic);
			sfmlBoldItalicText.setString(L"OpenSans SFML Bold Italic");
			sfmlBoldItalicText.setPosition(sf::Vector2f(20.0f, 210.0f));
			window.draw(sfmlBoldItalicText);

			sf::Text naturalBoldItalicText = fontFamily.createTextWithStyle(sf::Text::Bold | sf::Text::Italic);
			naturalBoldItalicText.setCharacterSize(16);
			naturalBoldItalicText.setString(L"OpenSans Natural Bold Italic");
			naturalBoldItalicText.setPosition(sf::Vector2f(420.0f, 210.0f));
			window.draw(naturalBoldItalicText);

			sf::Text comboText = fontFamily.createTextWithStyle(sf::Text::Bold);
			comboText.setCharacterSize(16);
			comboText.setStyle(sf::Text::Italic);
			comboText.setString(L"OpenSans Natural Bold, SFML Italic");
			float comboTextWidth = r3::sfml::TextUtils::resolveTextWidth(comboText);
			comboText.setPosition(400.0f - comboTextWidth / 2.0f, 260.0f);
			window.draw(comboText);

			sf::Text licenseText = fontFamily.createTextWithStyle(sf::Text::Regular);
			licenseText.setCharacterSize(12);
			licenseText.setString(L"OpenSans (by Ascender Fonts) is available on fontsquirrel.com under the Apache 2.0 License");
			float licenseTextWidth = r3::sfml::TextUtils::resolveTextWidth(licenseText);
			licenseText.setPosition(400.0f - licenseTextWidth / 2.0f, 310.0f);
			window.draw(licenseText);

			window.display();

			std::this_thread::sleep_for(std::chrono::microseconds(10));
		}
	}

	return 0;
}
