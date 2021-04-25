
#include <r3/sfml/text/r3-sfml-TextUtils.hpp>

namespace r3 {

	namespace sfml {

		namespace TextUtils {

			float resolveTextWidth(const sf::Text& text) {
				float result = text.findCharacterPos(text.getString().getSize()).x - text.findCharacterPos(0).x;
				return result;
			}

			sf::Vector2f resolveLineHeight(const sf::Text& text) {
				sf::Text textCopy = text;
				textCopy.setString("A\nB");

				sf::Vector2f aPos = textCopy.findCharacterPos(0);
				sf::Vector2f bPos = textCopy.findCharacterPos(2);

				sf::Vector2f result = bPos - aPos;
				return result;
			}

		}

	}

}
