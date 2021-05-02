
#include <sfml/Graphics.hpp>

namespace r3 {

	namespace sfml {

		template <typename T>
		class Ellipse
		{

		public:
			sf::Vector2<T> position;
			sf::Vector2<T> radius;

		public:
			Ellipse();
			Ellipse(const sf::Vector2<T>& position, const sf::Vector2<T>& radius);
			Ellipse(T x, T y, T horizontalRadius, T verticalRadius);

		public:
			bool contains(T x, T y) const;
			bool contains(const sf::Vector2<T>& position) const;

		};

		template <typename T>
		bool operator ==(const Ellipse<T>& left, const Ellipse<T>& right);

		template <typename T>
		bool operator !=(const Ellipse<T>& left, const Ellipse<T>& right);

		typedef Ellipse<int> IntEllipse;
		typedef Ellipse<float> FloatEllipse;

	}

}
