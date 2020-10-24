#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"

#include <ctime>
class Bomb
{
private:
	sf::RectangleShape bomb;
	sf::Texture texBomb;
	float bombSpeedX = 300.f, bombSpeedY = 100.f;
	float size_x, size_y;
public:
	Bomb(float width, float height,float size_x, float size_y) {
		this->size_x = size_x;
		this->size_y = size_y;
		bomb.setSize(sf::Vector2f(width, height));
		texBomb.loadFromFile("../picture/bomb.png");
		bomb.setTexture(&texBomb);
		bomb.setSize(sf::Vector2f(50.f, 50.f));
		bomb.setOrigin((sf::Vector2f)bomb.getSize() * 0.5f);
		bomb.setPosition(100.f, 150.f);
		srand(time(NULL));
	};
	void bombCheckCollision() {
		if (bomb.getPosition().x <= 0 || bomb.getPosition().x >= size_x - bomb.getSize().x) {
			bombSpeedX *= -1;
		}
	}
	void setPosition() {
		sf::Vector2f vt;
		srand(time(NULL));
		vt.x = rand() % ((int)size_x + 1);
		//vt.y = 0.f; /*rand() % ((int)size_y + 1);*/

		bomb.setPosition(vt);
	}
	sf::Vector2f getPosition() {
		return bomb.getPosition();
	}
	bool checkBombCollisionWithBlock(sf::FloatRect anotherBlock) {
		return bomb.getGlobalBounds().intersects(anotherBlock);
	}
	void bombUpdate(float dataTime) {
		bomb.move(bombSpeedX * dataTime, bombSpeedY * dataTime);
		//bomb.rotate(0.4f);
	}
	void Draw(sf::RenderWindow& rd) {
		rd.draw(bomb);
	}
	/*bool bombCheckColision() {
		if ()
	}*/
};

