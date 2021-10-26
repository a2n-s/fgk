#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Fighter.h"
#include "Platform.h"


int main(){
	sf::RenderWindow window(sf::VideoMode(800, 450), "fg Kernel!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	Fighter f(10);
	f.spawn(sf::Vector2<float>(150, 200));
	Platform platforms[3];
	platforms[0] = Platform(50, 750, 420);
	platforms[1] = Platform(100, 200, 330);
	platforms[2] = Platform(600, 700, 330);
	
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

		f.update(platforms, 3);
		if (f.outside()){ f.spawn(sf::Vector2<float>(150, 200)); }

		window.clear(sf::Color::Black);
		f.show(&window);
		for (const Platform p : platforms){
			p.show(&window);
		}
		window.display();
	}
	
	return 0;
}
