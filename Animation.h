#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime;
	float switchTime;
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
		this->imageCount = imageCount;
		this->switchTime = switchTime;
		totalTime = 0.0f;
		currentImage.x = 0;
		currentImage.y = 0;
		uvRect.width = texture->getSize().x / float(imageCount.x);
		uvRect.height = texture->getSize().y / float(imageCount.y);
	}
	~Animation() {
	};
	sf::IntRect uvRect;
	void Update(int row, float deltaTime)
	{
		//currentImage.y = row;
		totalTime += deltaTime;
		if (totalTime >= switchTime)
		{
			totalTime -= switchTime;
			currentImage.x++;
			if (currentImage.x >= imageCount.x) {
				currentImage.x = 0;
				if (currentImage.y >= imageCount.y) {
					currentImage.y = 0;
				}
				else currentImage.y++;
			}
		}
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.top = currentImage.y * uvRect.height;
	}
};

