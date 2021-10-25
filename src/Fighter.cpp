#include "Fighter.h"
#include <SFML/Graphics.hpp>

Fighter::Fighter() : m_x(0), m_y(0){
}

Fighter::Fighter(float x, float y) : m_x(x), m_y(y){
}

Fighter::Fighter(Fighter const& other) : m_x(other.m_x), m_y(other.m_y){
}

void Fighter::jump(){

}

void Fighter::moveLeft(){
	m_x = m_x - 10;
}

void Fighter::moveRight(){
	m_x = m_x + 10;
}

void Fighter::protect(){

}

void Fighter::show(sf::RenderWindow* window) const {
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(m_x, m_y);
	window->draw(shape);
}

Fighter::~Fighter(){
}
