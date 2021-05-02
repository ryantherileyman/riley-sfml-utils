
#include <r3/sfml/geometry/r3-sfml-Ellipse.hpp>

namespace r3 {

	namespace sfml {

		template <typename T>
		Ellipse<T>::Ellipse() {
		}

		template Ellipse<int>::Ellipse();
		template Ellipse<float>::Ellipse();

		template <typename T>
		Ellipse<T>::Ellipse(const sf::Vector2<T>& position, const sf::Vector2<T>& radius) {
			this->position = position;
			this->radius = radius;
		}

		template Ellipse<int>::Ellipse(const sf::Vector2i& position, const sf::Vector2i& radius);
		template Ellipse<float>::Ellipse(const sf::Vector2f& position, const sf::Vector2f& radius);

		template <typename T>
		Ellipse<T>::Ellipse(T x, T y, T horizontalRadius, T verticalRadius) {
			this->position.x = x;
			this->position.y = y;
			this->radius.x = horizontalRadius;
			this->radius.y = verticalRadius;
		}

		template Ellipse<int>::Ellipse(int x, int y, int horizontalRadius, int verticalRadius);
		template Ellipse<float>::Ellipse(float x, float y, float horizontalRadius, float verticalRadius);

		template <typename T>
		bool Ellipse<T>::contains(T x, T y) const {
			T horizontalDistance = x - this->position.x;
			T verticalDistance = y - this->position.y;

			double equation =
				((double)(horizontalDistance * horizontalDistance) / (double)(radius.x * radius.x)) +
				((double)(verticalDistance * verticalDistance) / (double)(radius.y * radius.y));

			bool result = (equation <= 1.0);
			return result;
		}

		template bool Ellipse<int>::contains(int x, int y) const;
		template bool Ellipse<float>::contains(float x, float y) const;

		template <typename T>
		bool Ellipse<T>::contains(const sf::Vector2<T>& position) const {
			bool result = this->contains(position.x, position.y);
			return result;
		}

		template bool Ellipse<int>::contains(const sf::Vector2i& position) const;
		template bool Ellipse<float>::contains(const sf::Vector2f& position) const;

		template <typename T>
		bool operator ==(const Ellipse<T>& left, const Ellipse<T>& right) {
			bool result =
				(left.position.x == right.position.x) &&
				(left.position.y == right.position.y) &&
				(left.radius.x == right.radius.x) &&
				(left.radius.y == right.radius.y);
			return result;
		}

		template bool operator ==(const Ellipse<int>& left, const Ellipse<int>& right);
		template bool operator ==(const Ellipse<float>& left, const Ellipse<float>& right);

		template <typename T>
		bool operator !=(const Ellipse<T>& left, const Ellipse<T>& right) {
			bool result =
				(left.position.x != right.position.x) ||
				(left.position.y != right.position.y) ||
				(left.radius.x != right.radius.x) ||
				(left.radius.y != right.radius.y);
			return result;
		}

		template bool operator !=(const Ellipse<int>& left, const Ellipse<int>& right);
		template bool operator !=(const Ellipse<float>&left, const Ellipse<float>&right);

	}

}
