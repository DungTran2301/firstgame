#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Block
{
private:
	sf::RectangleShape blockDown;
	sf::Texture texDown;
	float blockSpeed = 800.f;
	//float dataTime;
	float width = 180.f, height = 45.f;
	float screenWidth, screenHeight;
public:
	Block(float screenWidth, float screenHeight) {
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
		blockDown.setSize(sf::Vector2f(width, height));
		texDown.loadFromFile("../picture/blockDown.png");
		blockDown.setTexture(&texDown);
		blockDown.setPosition(screenWidth / 2 - blockDown.getSize().x / 2, screenHeight - 80.0f);
	}
	sf::FloatRect getFloatRect() {
		return blockDown.getGlobalBounds();
	}
	void blockMove(float dataTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			blockDown.move(sf::Vector2f(-blockSpeed * dataTime, 0.f));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			blockDown.move(sf::Vector2f(blockSpeed * dataTime, 0.f));
		}
		//return;
		if (blockDown.getPosition().x <= 0) {
			blockDown.setPosition(0.f, blockDown.getPosition().y);
		}
		if (blockDown.getPosition().x >= screenWidth - blockDown.getSize().x) {
			blockDown.setPosition(screenWidth - blockDown.getSize().x, blockDown.getPosition().y);
		}
	}
	void Draw(sf::RenderWindow& rd) {
		rd.draw(blockDown);
	}
};

