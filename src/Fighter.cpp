#include "Fighter.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

Fighter::Fighter() : m_pos(sf::Vector2<float>(0.f, 0.f)), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false), m_g(10000){
}

Fighter::Fighter(sf::Vector2<float> pos) : m_pos(pos), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false), m_g(10000){
}

Fighter::Fighter(Fighter const& other) : m_pos(other.m_pos), m_vel(other.m_vel), m_acc(other.m_acc), m_jumping(other.m_jumping), m_g(10000){
}

void Fighter::jump(){
	if (!m_jumping){
		m_jumping = true;
		m_vel.y = -1000;
		m_g = 10000;
	}
}

void Fighter::moveLeft(){
	m_left = true;
	m_right = false;
}

void Fighter::moveRight(){
	m_left = false;
	m_right = true;
}

void Fighter::stop(){
	m_left = false;
	m_right = false;
}

void Fighter::protect(){

}

void Fighter::update(){
// Verlet integration.
	float v_x = 500;
	m_vel.x = (m_left)? -v_x : ((m_right)? v_x : 0);

	m_pos = m_pos + 0.01f * m_vel;

	sf::Vector2<float> new_acc = m_acc;
	m_acc.y = m_g;
	if (m_pos.y > 350){
		m_pos.y = 350;
		m_vel.y = 0;
		m_jumping = false;
	}

	m_vel = m_vel + 0.01f / 2 * (m_acc + new_acc);

	m_acc = new_acc;
//

	printf("pos: (%3.1f,%3.1f), vel: (%3.1f,%3.1f), acc: (%3.1f,%3.1f), m_g: %3.1f\n", m_pos.x, m_pos.y, m_vel.x, m_vel.y, m_acc.x, m_acc.y, m_g);
}

void Fighter::show(sf::RenderWindow* window) const {
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(m_pos.x, m_pos.y);
	window->draw(shape);
}

Fighter::~Fighter(){
}
