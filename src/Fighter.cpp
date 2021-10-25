#include "Fighter.h"
#include <SFML/Graphics.hpp>

Fighter::Fighter() : m_x(0), m_y(0){
}

Fighter::Fighter(int x, int y) : m_x(x), m_y(y){
}

Fighter::Fighter(Fighter const& other) : m_x(other.m_x), m_y(other.m_y){
}

void Fighter::show(sf::RenderWindow* window){
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(300.f, 200.f);
	window->draw(shape);
}

Fighter::~Fighter(){
}
