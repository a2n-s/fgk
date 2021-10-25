#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Fighter.h"


int main(){
	sf::RenderWindow window(sf::VideoMode(800, 450), "fg Kernel!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	Fighter f1, f2;
	
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type){
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
						cout << "hello" << endl;
					}
					switch (event.key.code){
						case sf::Keyboard::Z:
							f1.jump();
							break;
						case sf::Keyboard::Q:
							f1.moveLeft();
							break;
						case sf::Keyboard::S:
							f1.protect();
							break;
						case sf::Keyboard::D:
							f1.moveRight();
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		f1.applyForce(sf::Vector2<float>(0, 10000));
		f1.update();

		window.clear(sf::Color::Black);
		f1.show(&window);
		window.display();
	}
	
	return 0;
}
