#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Ground
{
private:
	sf::RectangleShape ground;
	sf::Texture texback;
public:
	Ground(float width, float height) {
		ground.setSize(sf::Vector2f(width, height));
		texback.loadFromFile("../picture/background.png");
		ground.setTexture(&texback);
	}

	void Draw(sf::RenderWindow& rd) {
		rd.draw(ground);
	}
};

