#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Ball
{
private:
	sf::RectangleShape soccerBall;
	sf::Texture texSoccerBall;
	sf::RectangleShape soccerBall2;
	sf::Texture texSoccerBall2;
	float blockSpeed = 800.f;
	//float dataTime;
	float ballSpeed_x = 300.f, ballSpeed_y = 300.f;
	float width = 50.f, height = 50.f;
	float screenWidth, screenHeight;
public:
	Ball(float screenWidth, float screenHeight) {
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
		soccerBall.setSize(sf::Vector2f(width, height));
		texSoccerBall.loadFromFile("../picture/soccerBall.png");
		soccerBall.setTexture(&texSoccerBall);
		soccerBall.setPosition(screenWidth / 2 - soccerBall.getSize().x / 2, 0.0f);
	}
	/*bool checkBombCollisionWithBlock(sf::FloatRect anotherBlock) {
		return bomb.getGlobalBounds().intersects(anotherBlock);
	}*/
	void ballCheckCollision(sf::FloatRect anotherBlock) {
		if (soccerBall.getPosition().x <= 0 || soccerBall.getPosition().x >=  screenWidth- soccerBall.getSize().x) {
			ballSpeed_x *= -1;
		}
		if (soccerBall.getGlobalBounds().intersects(anotherBlock) || soccerBall.getPosition().y<=0) {
			ballSpeed_y *= -1;
		}
	}
	/*sf::Vector2f getPosition() {
		return bomb.getPosition();
	}
	bool checkBombCollisionWithBlock(sf::FloatRect anotherBlock) {
		return bomb.getGlobalBounds().intersects(anotherBlock);
	}*/
	void ballUpdate(float dataTime) {
		soccerBall.move(ballSpeed_x * dataTime, ballSpeed_y * dataTime);
		//soccerball.rotate(0.4f);
	}
	void Draw(sf::RenderWindow& rd) {
		rd.draw(soccerBall);
	}
};

