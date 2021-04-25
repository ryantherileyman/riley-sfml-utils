
#include <r3/sfml/text/r3-sfml-FontFamily.hpp>

namespace r3 {

	namespace sfml {

		bool FontFamily::load(const LoadFontFamilyDefn& loadDefn) {
			bool result = this->baseFont.loadFromFile(loadDefn.baseFontFilename);

			if (!loadDefn.boldFontFilename.empty()) {
				result = result && this->loadBoldFontFromFile(loadDefn.boldFontFilename);
			}

			if (!loadDefn.italicFontFilename.empty()) {
				result = result && this->loadItalicFontFromFile(loadDefn.italicFontFilename);
			}

			if (!loadDefn.boldItalicFontFilename.empty()) {
				result = result && this->loadBoldItalicFontFromFile(loadDefn.boldItalicFontFilename);
			}

			return result;
		}

		bool FontFamily::loadBaseFontFromFile(const std::string& filename) {
			bool result = this->baseFont.loadFromFile(filename);
			return result;
		}

		bool FontFamily::loadBaseFontFromMemory(const void* data, std::size_t sizeInBytes) {
			bool result = this->baseFont.loadFromMemory(data, sizeInBytes);
			return result;
		}

		bool FontFamily::loadBaseFontFromStream(sf::InputStream& stream) {
			bool result = this->baseFont.loadFromStream(stream);
			return result;
		}

		bool FontFamily::loadBoldFontFromFile(const std::string& filename) {
			this->boldFont = sf::Font();
			bool result = this->boldFont.value().loadFromFile(filename);
			return result;
		}

		bool FontFamily::loadBoldFontFromMemory(const void* data, std::size_t sizeInBytes) {
			this->boldFont = sf::Font();
			bool result = this->boldFont.value().loadFromMemory(data, sizeInBytes);
			return result;
		}

		bool FontFamily::loadBoldFontFromStream(sf::InputStream& stream) {
			this->boldFont = sf::Font();
			bool result = this->boldFont.value().loadFromStream(stream);
			return result;
		}

		bool FontFamily::loadItalicFontFromFile(const std::string& filename) {
			this->italicFont = sf::Font();
			bool result = this->italicFont.value().loadFromFile(filename);
			return result;
		}

		bool FontFamily::loadItalicFontFromMemory(const void* data, std::size_t sizeInBytes) {
			this->italicFont = sf::Font();
			bool result = this->italicFont.value().loadFromMemory(data, sizeInBytes);
			return result;
		}

		bool FontFamily::loadItalicFontFromStream(sf::InputStream& stream) {
			this->italicFont = sf::Font();
			bool result = this->italicFont.value().loadFromStream(stream);
			return result;
		}

		bool FontFamily::loadBoldItalicFontFromFile(const std::string& filename) {
			this->boldItalicFont = sf::Font();
			bool result = this->boldItalicFont.value().loadFromFile(filename);
			return result;
		}

		bool FontFamily::loadBoldItalicFontFromMemory(const void* data, std::size_t sizeInBytes) {
			this->boldItalicFont = sf::Font();
			bool result = this->boldItalicFont.value().loadFromMemory(data, sizeInBytes);
			return result;
		}

		bool FontFamily::loadBoldItalicFontFromStream(sf::InputStream& stream) {
			this->boldItalicFont = sf::Font();
			bool result = this->boldItalicFont.value().loadFromStream(stream);
			return result;
		}

		sf::Text FontFamily::createTextWithStyle(sf::Uint32 style) const {
			bool requestBoldFlag = style & sf::Text::Bold;
			bool requestItalicFlag = style & sf::Text::Italic;
			bool requestBoldItalicFlag = requestBoldFlag && requestItalicFlag;
			
			sf::Text result;
			result.setFont(this->baseFont);
			result.setStyle(style);

			if (requestBoldItalicFlag) {
				if (this->boldItalicFont.has_value()) {
					result.setFont(this->boldItalicFont.value());
					result.setStyle(style - sf::Text::Bold - sf::Text::Italic);
				}
				else if (this->boldFont.has_value()) {
					result.setFont(this->boldFont.value());
					result.setStyle(style - sf::Text::Bold);
				}
				else if (this->italicFont.has_value()) {
					result.setFont(this->italicFont.value());
					result.setStyle(style - sf::Text::Italic);
				}
			}
			else if (requestBoldFlag) {
				if (this->boldFont.has_value()) {
					result.setFont(this->boldFont.value());
					result.setStyle(style - sf::Text::Bold);
				}
			}
			else if (requestItalicFlag) {
				if (this->italicFont.has_value()) {
					result.setFont(this->italicFont.value());
					result.setStyle(style - sf::Text::Italic);
				}
			}

			return result;
		}

		sf::Text FontFamily::createTextWithTypesetting(const TypesettingDefn& typesetting) const {
			sf::Text result = this->createTextWithStyle(typesetting.style);
			result.setCharacterSize(typesetting.characterSize);
			result.setLineSpacing(typesetting.lineSpacing);
			result.setLetterSpacing(typesetting.letterSpacing);
			result.setFillColor(typesetting.fillColor);
			result.setOutlineColor(typesetting.outlineColor);
			result.setOutlineThickness(typesetting.outlineThickness);
			return result;
		}

	}

}
