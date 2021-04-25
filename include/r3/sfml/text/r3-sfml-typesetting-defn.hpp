
#include <limits>
#include <sfml/Graphics.hpp>

#pragma once

namespace r3 {

	namespace sfml {

		typedef enum class SfmlUtils_TextAlignment {
			LEFT,
			CENTER,
			RIGHT,
		} TextAlignment;

		typedef enum class SfmlUtils_VerticalAlignment {
			TOP,
			MIDDLE,
			BOTTOM,
		} VerticalAlignment;

		typedef struct SfmlUtils_TypesettingDefn {
			unsigned int characterSize = 30;
			float lineSpacing = 1.0f;
			float letterSpacing = 1.0f;
			sf::Uint32 style = sf::Text::Regular;
			sf::Color fillColor = sf::Color::White;
			sf::Color outlineColor = sf::Color::Black;
			float outlineThickness = 0.0f;
		} TypesettingDefn;

		typedef struct SfmlUtils_TextBlockRegionDefn {
			TextAlignment textAlignment = TextAlignment::LEFT;
			VerticalAlignment verticalAlignment = VerticalAlignment::TOP;
			sf::Vector2f position;
			sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
			float rotationDegrees = 0.0f;
			float maxLineWidth = std::numeric_limits<float>::max();
		} TextBlockRegionDefn;

	}

}
