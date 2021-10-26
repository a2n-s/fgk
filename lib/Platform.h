#ifndef DEF_PLATFORM
#define DEF_PLATFORM

#include <SFML/Graphics.hpp>

class Platform {
	public:
	Platform();
	Platform(float x1, float x2, float y);
	Platform(Platform const& other);
	float getLeft() const;
	float getRight() const;
	float getHeight() const;
	void show(sf::RenderWindow* window) const;
	~Platform();

	private:
	float m_x1, m_x2, m_y;
};

#endif
