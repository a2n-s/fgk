#include "Fighter.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;


#define SPEED 1000
#define GRAVITY 10000

Fighter::Fighter() : m_pos(sf::Vector2<float>(0.f, 0.f)), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false), m_g(GRAVITY){
}

Fighter::Fighter(sf::Vector2<float> pos) : m_pos(pos), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false), m_g(GRAVITY){
}

Fighter::Fighter(Fighter const& other) : m_pos(other.m_pos), m_vel(other.m_vel), m_acc(other.m_acc), m_jumping(other.m_jumping), m_g(GRAVITY){
}

void Fighter::jump(){
	float h = 200;
	float t_h = .07;
	float beta  = -h / t_h;
	if (!m_jumping && m_can_jump){
		m_jumping = true;
		m_can_jump = false;
		if (!m_left && !m_right){
			m_vel.y = beta;
			m_g = -beta / t_h;
		}
		else {
			m_vel.y = beta;
			m_g = -beta / t_h;
		}
	}
}

void Fighter::canJump(){
	m_can_jump = true;
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
	float dt = .01f;
	if (!m_jumping){
		m_vel.x = (m_left)? -SPEED : ((m_right)? SPEED : 0);
	}

// Verlet integration.
	m_pos = m_pos + 0.01f * m_vel;

	sf::Vector2<float> new_acc = m_acc;
	m_acc.y = (m_vel.y < 0)? m_g : 3 * m_g;

	m_vel = m_vel + dt * (m_acc + new_acc) / 2.f;

	m_acc = new_acc;
//

	if (m_pos.y > 350){
		m_pos.y = 350;
		m_vel.y = 0;
		m_jumping = false;
	}
}

void Fighter::show(sf::RenderWindow* window) const {
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(m_pos.x, m_pos.y);
	window->draw(shape);
}

Fighter::~Fighter(){
}
