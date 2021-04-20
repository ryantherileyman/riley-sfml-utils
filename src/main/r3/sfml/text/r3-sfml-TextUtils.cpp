
#include <r3/sfml/text/r3-sfml-TextUtils.hpp>

namespace r3 {

	namespace sfml {

		namespace TextUtils {

			float resolveTextWidth(const sf::Text& text) {
				float result = text.findCharacterPos(text.getString().getSize()).x - text.findCharacterPos(0).x;
				return result;
			}

		}

	}

}
