#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Keyboard.hpp>


int main() {

	int bx = 390, by = 290;
	int y1 = 225, y2 = 225;

	bool left = true;
	sf::RenderWindow window(sf::VideoMode(800, 600), "PONG");
	window.setFramerateLimit(60);
	//main loop
	while (window.isOpen()) {

		//controls
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			y1 = y1 - 10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			y1 = y1 + 10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			y2 = y2 - 10;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			y2 = y2 + 10;
		}

		//borders
		if (y1 <= 2) y1 = 2;
		if (y1 >= 448) y1 = 448;
		if (y2 <= 2) y2 = 2;
		if (y2 >= 448) y2 = 448;

		sf::Event event;
		window.clear();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.setActive();

		//drawing
		sf::RectangleShape rect1;
		rect1.setSize(sf::Vector2f(20, 150));
		rect1.setPosition(35, y1);

		sf::RectangleShape rect2;
		rect2.setSize(sf::Vector2f(20, 150));
		rect2.setPosition(755, y2);

		sf::RectangleShape ball;
		ball.setSize(sf::Vector2f(10, 10));
		ball.setPosition(bx, by);

		window.draw(rect1);
		window.draw(rect2);
		window.draw(ball);
		
		if (left == true) {
			bx = bx - 3;
		}
		else if (left == false) {
			bx = bx + 3;
		}

		if (bx == 55 && by + 10 < y1) {
			left = true;
		}
		else if (bx == 55 && by + 10 > y1 + 150) {
			left = true;
		}
		else if (bx == 55 && (by + 10 >= y1 && by + 10 <= y1 + 150)) {
			left = false;
		}
		
		

		//end of drawing
		window.display();
	}
}