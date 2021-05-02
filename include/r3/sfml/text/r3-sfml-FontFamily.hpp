
#include "r3-sfml-typesetting-defn.hpp"
#include <optional>
#include <string>
#include <SFML/Graphics.hpp>

#pragma once

namespace r3 {

	namespace sfml {

		typedef struct SfmlUtils_LoadFontFamilyDefn {
			std::string baseFontFilename;
			std::string boldFontFilename;
			std::string italicFontFilename;
			std::string boldItalicFontFilename;
		} LoadFontFamilyDefn;

		class FontFamily;

		class FontFamily {

		private:
			sf::Font baseFont;
			std::optional<sf::Font> boldFont;
			std::optional<sf::Font> italicFont;
			std::optional<sf::Font> boldItalicFont;

		public:
			bool load(const LoadFontFamilyDefn& loadDefn);

		public:
			bool loadBaseFontFromFile(const std::string& filename);
			bool loadBaseFontFromMemory(const void* data, std::size_t sizeInBytes);
			bool loadBaseFontFromStream(sf::InputStream& stream);

		public:
			bool loadBoldFontFromFile(const std::string& filename);
			bool loadBoldFontFromMemory(const void* data, std::size_t sizeInBytes);
			bool loadBoldFontFromStream(sf::InputStream& stream);

		public:
			bool loadItalicFontFromFile(const std::string& filename);
			bool loadItalicFontFromMemory(const void* data, std::size_t sizeInBytes);
			bool loadItalicFontFromStream(sf::InputStream& stream);

		public:
			bool loadBoldItalicFontFromFile(const std::string& filename);
			bool loadBoldItalicFontFromMemory(const void* data, std::size_t sizeInBytes);
			bool loadBoldItalicFontFromStream(sf::InputStream& stream);

		public:
			sf::Text createTextWithStyle(sf::Uint32 style) const;
			sf::Text createTextWithTypesetting(const TypesettingDefn& typesetting) const;

		};

	}

}
