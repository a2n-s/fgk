#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Fighter.h"


int main(){
	sf::RenderWindow window(sf::VideoMode(800, 450), "fg Kernel!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	Fighter f(sf::Vector2<float>(100, 300));
	
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			switch (event.type){
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyReleased:
					switch (event.key.code){
						case sf::Keyboard::Q:
							f.stop();
							break;
						case sf::Keyboard::D:
							f.stop();
							break;
						case sf::Keyboard::Z:
							f.canJump();
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
			f.jump();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
			f.moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			f.protect();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			f.moveRight();
		}

		f.update();

		window.clear(sf::Color::Black);
		f.show(&window);
		window.display();
	}
	
	return 0;
}
