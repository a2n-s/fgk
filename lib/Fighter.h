#ifndef DEF_FIGHTER
#define DEF_FIGHTER

#include <SFML/Graphics.hpp>

class Fighter {
	public:
	Fighter();
	Fighter(float x, float y);
	Fighter(Fighter const& other);
	void jump();
	void moveLeft();
	void moveRight();
	void protect();
	void show(sf::RenderWindow* window) const;
	~Fighter();

	private:
	float m_x, m_y;
};

#endif
