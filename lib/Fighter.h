#ifndef DEF_FIGHTER
#define DEF_FIGHTER

#include "Platform.h"
#include <SFML/Graphics.hpp>

class Fighter {
	public:
	Fighter();
	Fighter(float r);
	Fighter(sf::Vector2<float> pos, float r);
	Fighter(Fighter const& other);
	void spawn(sf::Vector2<float> pos);
	void jump();
	void canJump();
	void moveLeft();
	void moveRight();
	void stop();
	void protect();
	void update(Platform* platforms, int nb_platforms);
	bool outside() const;
	void show(sf::RenderWindow* window) const;
	~Fighter();

	private:
	sf::Vector2<float> m_pos;
	sf::Vector2<float> m_vel;
	sf::Vector2<float> m_acc;
	bool m_jumping;
	bool m_can_jump;
	bool m_left;
	bool m_right;
	float m_g;
	float m_r;
};

#endif
