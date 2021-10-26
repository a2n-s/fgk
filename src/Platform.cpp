#include "Platform.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;


Platform::Platform() : m_x1(0), m_x2(0), m_y(0){
}

Platform::Platform(float x1, float x2, float y) : m_x1(x1), m_x2(x2), m_y(y){
}

Platform::Platform(Platform const& other) : m_x1(other.m_x1), m_x2(other.m_x2), m_y(other.m_y){
}

float Platform::getLeft() const {
	return min(m_x1, m_x2);
}

float Platform::getRight() const {
	return max(m_x1, m_x2);
}

float Platform::getHeight() const {
	return m_y;
}

void Platform::show(sf::RenderWindow* window) const {
	sf::RectangleShape line(sf::Vector2f(m_x2 - m_x1, 5));
	line.setPosition(sf::Vector2f(m_x1, m_y));
	window->draw(line);
}

Platform::~Platform(){
}

