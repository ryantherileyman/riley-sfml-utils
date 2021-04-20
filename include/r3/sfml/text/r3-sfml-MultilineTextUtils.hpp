
#include "r3-sfml-FontFamily.hpp"
#include <limits>
#include <string>
#include <SFML/Graphics.hpp>

namespace r3 {

	namespace sfml {

		typedef enum class SfmlUtils_TextAlignment {
			LEFT,
			CENTER,
			RIGHT,
		} TextAlignment;

		typedef struct SfmlUtils_MultilineTextDefn {
			const FontFamily* fontFamily;

			unsigned int characterSize = 30;
			float lineSpacing = 1.0f;
			float letterSpacing = 1.0f;
			sf::Uint32 style = sf::Text::Regular;
			sf::Color fillColor = sf::Color::White;
			sf::Color outlineColor = sf::Color::Black;
			float outlineThickness = 0.0f;

			std::wstring string;

			sf::Vector2f position;
			sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
			float rotationDegrees = 0.0f;
			TextAlignment alignment = TextAlignment::LEFT;
			float maxLineWidth = std::numeric_limits<float>::max();

			struct SfmlUtils_MultilineTextDefn(const FontFamily& fontFamily) {
				this->fontFamily = &fontFamily;
			}
		} MultilineTextDefn;

		namespace MultilineTextUtils {

			sf::Text buildText(const MultilineTextDefn& multilineTextDefn);

		}

	}

}
