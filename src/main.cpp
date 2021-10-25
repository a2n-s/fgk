#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Fighter.h"


int main(){
	sf::RenderWindow window(sf::VideoMode(800, 450), "fg Kernel!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

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
							cout << "Z pressed" << endl;
							break;
						case sf::Keyboard::Q:
							cout << "Q pressed" << endl;
							break;
						case sf::Keyboard::S:
							cout << "S pressed" << endl;
							break;
						case sf::Keyboard::D:
							cout << "D pressed" << endl;
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
		
		window.clear(sf::Color::Black);
		f1.show(&window);
		window.display();
	}
	
	return 0;
}
