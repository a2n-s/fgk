#ifndef DEF_FIGHTER
#define DEF_FIGHTER

#include <SFML/Graphics.hpp>

class Fighter {
	public:
	Fighter();
	Fighter(sf::Vector2<float> pos);
	Fighter(Fighter const& other);
	void jump();
	void moveLeft();
	void moveRight();
	void stop();
	void protect();
	void update();
	void show(sf::RenderWindow* window) const;
	~Fighter();

	private:
	sf::Vector2<float> m_pos;
	sf::Vector2<float> m_vel;
	sf::Vector2<float> m_acc;
	bool m_jumping;
	bool m_left;
	bool m_right;
	float m_g;
};

#endif
