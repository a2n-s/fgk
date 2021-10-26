#include "Fighter.h"
#include "Platform.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;


#define SPEED         1000
#define GRAVITY       10000
#define JUMP_HEIGHT   150
#define JUMP_DURATION .1


Fighter::Fighter() : m_pos(sf::Vector2<float>(0.f, 0.f)), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false), m_g(GRAVITY){
}

Fighter::Fighter(float r) : m_pos(sf::Vector2<float>(0.f, 0.f)), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false), m_g(GRAVITY), m_r(r){
}

Fighter::Fighter(sf::Vector2<float> pos, float r) : m_pos(pos), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false), m_g(GRAVITY), m_r(r){
}

Fighter::Fighter(Fighter const& other) : m_pos(other.m_pos), m_vel(other.m_vel), m_acc(other.m_acc), m_jumping(other.m_jumping), m_g(GRAVITY), m_r(other.m_r){
}

void Fighter::spawn(sf::Vector2<float> pos){
	m_pos = pos;
	m_vel = sf::Vector2<float>(0.f, 0.f);
	m_acc = sf::Vector2<float>(0.f, 0.f);
	m_jumping = false;
	m_can_jump = true;
}

void Fighter::jump(){
	float beta  = -JUMP_HEIGHT / JUMP_DURATION;
	if (!m_jumping && m_can_jump){
		m_jumping = true;
		m_can_jump = false;
		if (!m_left && !m_right){
			m_vel.y = beta;
			m_g = -beta / JUMP_DURATION;
		}
		else {
			m_vel.y = beta;
			m_g = -beta / JUMP_DURATION;
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

void Fighter::update(Platform* platforms, int nb_platforms){
	float dt = .01f;
	if (!m_jumping){
		m_vel.x = (m_left)? -SPEED : ((m_right)? SPEED : 0);
	}

// Verlet integration.
	m_pos = m_pos + 0.01f * m_vel;

	sf::Vector2<float> new_acc = m_acc;
	m_acc.y = (m_vel.y < 0)? m_g : 3 * m_g;

	for (int i = 0; i < nb_platforms; i++){
		if (m_pos.x > platforms[i].getLeft() && m_pos.x < platforms[i].getRight()){
			if (m_pos.y > platforms[i].getHeight() - 2*m_r && m_vel.y > 0){
				m_pos.y = platforms[i].getHeight() - 2*m_r;
				m_vel.y = 0;
				m_jumping = false;
			}
		}
	}

	m_vel = m_vel + dt * (m_acc + new_acc) / 2.f;

	m_acc = new_acc;
//
}

bool Fighter::outside() const {
	return m_pos.x < -1000 || m_pos.x > 1800 || m_pos.y < -500 || m_pos.y > 550;
}

void Fighter::show(sf::RenderWindow* window) const {
	sf::CircleShape shape(m_r);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(m_pos.x, m_pos.y);
	window->draw(shape);
}

Fighter::~Fighter(){
}
