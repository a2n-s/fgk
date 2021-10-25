#include "Fighter.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

Fighter::Fighter() : m_pos(sf::Vector2<float>(0.f, 0.f)), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false){
}

Fighter::Fighter(sf::Vector2<float> pos) : m_pos(pos), m_vel(sf::Vector2<float>(0.f, 0.f)), m_acc(sf::Vector2<float>(0.f, 0.f)), m_jumping(false){
}

Fighter::Fighter(Fighter const& other) : m_pos(other.m_pos), m_vel(other.m_vel), m_acc(other.m_acc), m_jumping(other.m_jumping){
}

void Fighter::jump(){
	if (!m_jumping){
		m_vel = m_vel + sf::Vector2<float>(0, -5000);
		m_jumping = true;
		cout << "jumping" << endl;
	}
}

void Fighter::moveLeft(){
	m_pos.x = m_pos.x - 10;
}

void Fighter::moveRight(){
	m_pos.x = m_pos.x + 10;
}

void Fighter::protect(){

}

void Fighter::applyForce(sf::Vector2<float> force){
	m_acc = force;
}

void Fighter::update(){
	m_vel = m_vel + 0.01f * m_acc;
	m_pos = m_pos + 0.01f * m_vel;
	if (m_pos.y > 350){
		m_pos.y = 350;
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
