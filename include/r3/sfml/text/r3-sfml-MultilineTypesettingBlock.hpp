
#include "r3-sfml-typesetting-defn.hpp"
#include "r3-sfml-FontFamily.hpp"
#include <vector>

#pragma once

namespace r3 {

	namespace sfml {

		class MultilineTypesettingBlock {

		private:
			const FontFamily* fontFamily;
			TypesettingDefn typesettingDefn;
			TextBlockRegionDefn textBlockRegionDefn;
			bool roundingCorrectionFlag = true;

		public:
			MultilineTypesettingBlock(const FontFamily& fontFamily);

		public:
			void updateTypesetting(const TypesettingDefn& typesettingDefn);

			unsigned int getCharacterSize() const;
			void setCharacterSize(unsigned int characterSize);

			float getLineSpacing() const;
			void setLineSpacing(float lineSpacing);

			float getLetterSpacing() const;
			void setLetterSpacing(float letterSpacing);

			sf::Uint32 getStyle() const;
			void setStyle(sf::Uint32 style);

			sf::Color getFillColor() const;
			void setFillColor(const sf::Color& color);

			sf::Color getOutlineColor() const;
			void setOutlineColor(const sf::Color& color);

			float getOutlineThickness() const;
			void setOutlineThickness(float outlineThickness);

			void updateRegion(const TextBlockRegionDefn& regionDefn);

			TextAlignment getTextAlignment() const;
			void setTextAlignment(TextAlignment alignment);

			VerticalAlignment getVerticalAlignment() const;
			void setVerticalAlignment(VerticalAlignment alignment);

			sf::Vector2f getPosition() const;
			void setPosition(sf::Vector2f position);

			sf::Vector2f getScale() const;
			void setScale(sf::Vector2f scale);

			float getRotation() const;
			void setRotation(float rotationDegrees);

			float getMaxLineWidth() const;
			void setMaxLineWidth(float maxLineWidth);

			bool getRoundingCorrection() const;
			void setRoundingCorrection(bool roundingCorrection);

		public:
			std::vector<sf::String> splitIntoLines(const sf::String& string) const;
			std::vector<sf::Text> createAlignedTextList(const std::vector<sf::String>& stringList) const;

		};

	}

}
