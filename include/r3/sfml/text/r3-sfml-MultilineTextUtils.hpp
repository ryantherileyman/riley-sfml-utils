
#include <limits>
#include <string>
#include <r3/sfml/text/r3-sfml-FontFamily.hpp>
#include <SFML/Graphics.hpp>

namespace r3 {

	namespace sfml {

		typedef enum class SfmlUtils_TextAlignment {
			LEFT,
			CENTER,
			RIGHT,
		} TextAlignment;

		typedef struct SfmlUtils_TypesettingDefn {
			const FontFamily* fontFamily;

			unsigned int characterSize = 30;
			float lineSpacing = 1.0f;
			float letterSpacing = 1.0f;
			sf::Uint32 style = sf::Text::Regular;
			sf::Color fillColor = sf::Color::White;
			sf::Color outlineColor = sf::Color::Black;
			float outlineThickness = 0.0f;
			TextAlignment alignment = TextAlignment::LEFT;
		} TypesettingDefn;

		typedef struct SfmlUtils_MultilineTextDefn {
			TypesettingDefn typesettingDefn;

			std::wstring string;

			sf::Vector2f position;
			sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
			float rotationDegrees = 0.0f;
			float maxLineWidth = std::numeric_limits<float>::max();
		} MultilineTextDefn;

		namespace MultilineTextUtils {

			sf::Text buildText(const MultilineTextDefn& multilineTextDefn);

		}

	}

}
