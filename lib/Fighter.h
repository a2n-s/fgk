#ifndef DEF_FIGHTER
#define DEF_FIGHTER

#include <SFML/Graphics.hpp>

class Fighter {
	public:
	Fighter();
	Fighter(int x, int y);
	Fighter(Fighter const& other);
	void show(sf::RenderWindow* window);
	~Fighter();

	private:
	int m_x, m_y;
};

#endif
