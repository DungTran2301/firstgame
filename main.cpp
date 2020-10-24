//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//#define screenHight 480
//#define screenWidth 700
//bool checkCollision_1(sf::CircleShape C, sf::RectangleShape S) {
//    if (C.getPosition().x - C.getRadius() <= S.getPosition().x + S.getSize().x) {
//        if (C.getPosition().y >= S.getPosition().y && C.getPosition().y <= S.getPosition().y + S.getSize().y) return true;
//    }
//    return false;
//}
//bool checkCollision_2(sf::CircleShape C, sf::RectangleShape S) {
//    if (C.getPosition().x + C.getRadius() >= S.getPosition().x) {
//        if (C.getPosition().y >= S.getPosition().y && C.getPosition().y <= S.getPosition().y + S.getSize().y) return true;
//    }
//    return false;
//}
//int main()
//{
//
//    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHight), "Pong!");
//    sf::CircleShape m_circle;
// 
//    m_circle.setRadius(15.f);
//    m_circle.setFillColor(sf::Color(9, 225, 232));
//    m_circle.setOutlineThickness(2.f);
//    m_circle.setOutlineColor(sf::Color(20, 19, 20));
//    m_circle.setPosition(sf::Vector2f(screenWidth/2.f, screenHight/2.f));
//    m_circle.setOrigin(15.f, 15.f);
//    sf::RectangleShape m_square;
//    m_square.setSize(sf::Vector2f(10.f, 100.f));
//    m_square.setFillColor(sf::Color(222, 171, 31));
//    m_square.setOutlineThickness(2.f);
//    m_square.setOutlineColor(sf::Color(20, 19, 20));
//    m_square.setPosition(sf::Vector2f(10.f, screenHight / 2.f - m_square.getSize().y / 2.f));
//
//    sf::RectangleShape m_bot_1;
//    m_bot_1.setSize(sf::Vector2f(10.f, 100.f));
//    m_bot_1.setFillColor(sf::Color(230, 11, 41));
//    m_bot_1.setOutlineThickness(2.f);
//    m_bot_1.setOutlineColor(sf::Color(20, 19, 20));
//    m_bot_1.setPosition(sf::Vector2f(screenWidth - 10.f - m_bot_1.getSize().x , screenHight / 2.f - m_bot_1.getSize().y / 2.f));
//   /* sf::RectangleShape m_bot_2;
//    m_bot_2.setSize(sf::Vector2f(10.f, 100.f));
//    m_bot_2.setFillColor(sf::Color(230, 11, 41));
//    m_bot_2.setOutlineThickness(2.f);
//    m_bot_2.setOutlineColor(sf::Color(20, 19, 20));
//    m_bot_2.setPosition(sf::Vector2f(screenWidth - 50.f - m_bot_2.getSize().x, screenHight / 2.f - m_bot_2.getSize().y / 2.f));*/
//
//    float dataTime = 0.f;
//    float m_vplayer = 1000.f;
//    float vx_circle = 300.f;
//    float vy_circle = 300.f;
//    float vy_bot = 1000.f;
//    // float vy_bot2 = -1000.f;
//
//    sf::Clock clock;
//
//    dataTime = clock.restart().asSeconds();
//
//    while (window.isOpen()) {
//        sf::Event evnt;
//        dataTime = clock.restart().asSeconds();
//        while (window.pollEvent(evnt)) {
//            
//            if (evnt.type == evnt.Closed) {
//                window.close();
//            }
//        }
//        // dieu khien thanh trai
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
//            m_square.move(sf::Vector2f(0.f, m_vplayer * dataTime));
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//            m_square.move(sf::Vector2f(0.f, - m_vplayer * dataTime));
//        }
//        // dieu khien thanh phai
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//            m_bot_1.move(sf::Vector2f(0.f, m_vplayer * dataTime));
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//            m_bot_1.move(sf::Vector2f(0.f, - m_vplayer * dataTime));
//        }
//        // dieu kien dung square
//        if (m_square.getPosition().y >= screenHight - m_square.getSize().y) {
//            m_square.setPosition(m_square.getSize().x, screenHight - m_square.getSize().y);
//        }
//        else {
//            if (m_square.getPosition().y <= 0) {
//                m_square.setPosition(m_square.getSize().x, 0);
//            }
//        }
//        // dieu kien dung bot
//        if (m_bot_1.getPosition().y >= screenHight - m_bot_1.getSize().y) {
//            m_bot_1.setPosition(screenWidth - m_bot_1.getSize().x - 10.f, screenHight - m_bot_1.getSize().y);
//        }
//        else {
//            if (m_bot_1.getPosition().y <= 0) {
//                m_bot_1.setPosition(screenWidth - m_bot_1.getSize().x - 10.f, 0);
//            }
//        }
//        /*if (m_bot_2.getPosition().y >= screenHight - m_bot_2.getSize().y) {
//            vy_bot2 = -vy_bot2;
//        }
//        else {
//            if (m_bot_2.getPosition().y <= 0) {
//                vy_bot2 = -vy_bot2;
//            }
//        }*/
//
//        if (checkCollision_1(m_circle, m_square) || checkCollision_2(m_circle, m_bot_1)) {
//            vx_circle = -vx_circle;
//        }
//        else
//        {
//            if (m_circle.getPosition().x <= 0.f || m_circle.getPosition().x >= screenWidth) {
//                vx_circle = -vx_circle;
//            }
//            //if ( m_circle.getPosition().x >= screenWidth) {
//            //    // vx_circle = -vx_circle;
//            //    std::cout << "Dung thang!";
//            //    return 0;
//            //}
//            if (m_circle.getPosition().y <= 0.f || m_circle.getPosition().y >= screenHight) {
//                  vy_circle = -vy_circle;
//            }
//        }
//        m_circle.move(sf::Vector2f(vx_circle * dataTime, vy_circle * dataTime));
//        //m_bot_1.move(sf::Vector2f(0, vy_bot * dataTime));
//        //m_bot_2.move(sf::Vector2f(0, vy_bot2 * dataTime));
//        window.clear(sf::Color(184, 32, 214));
//        window.draw(m_circle);
//        window.draw(m_square);
//        window.draw(m_bot_1);
//        //window.draw(m_bot_2);
//        window.display();
//        /*
//        if (checkCollision(m_circle, m_square)) {
//            std::cout << 1 << std::endl;
//            return 0;
//        }
//        */
//        // std::cout << checkCollision(m_circle, m_square) << std::endl;
//    }
//    return 0;
//}
////
////#include <SFML/Graphics.hpp>
////#include <iostream>
////#include <vector>
////using namespace std;
////using namespace sf;
////int main()
////{
////    RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
////    Texture texture;
////    texture.loadFromFile("Attack__000.png");
////    Sprite s;
////    s.getTexture(texture);
////
////    vector <Texture> listtexture;
////    float currentFrame = 0;
////
////    for (int i = 1; i < 5; i++) {
////        Texture img;
////        img.loadFromFile(to_string(i) + ".png");
////        listtexture.push_back(img);
////    }
////    while (window.isOpen())
////    {
////        sf::Event event;
////        while (window.pollEvent(event))
////        {
////            if (event.type == sf::Event::Closed)
////                window.close();
////        }
////
////        window.clear();
////        //window.draw(shape);
////        window.display();
////        
////    }
////
////    return 0;
////}

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Ground.h"
#include "Block.h"
#include "Bomb.h"
#include "Ball.h"
#include <ctime>
#include <iostream>
#define screenWidth 800.0f
#define screenHeight 600.0f
int main() {
	
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "HELLO");
	sf::RectangleShape explosion(sf::Vector2f(150.0f, 150.0f));
	Ground* ground = new Ground(screenWidth, screenHeight);
	Block* block = new Block(screenWidth, screenHeight);
	Bomb* bomb = new Bomb(50.f, 50.f, screenWidth, screenHeight);
	Ball* ball = new Ball(screenWidth, screenHeight);
	explosion.setPosition(screenWidth/2- explosion.getSize().x/2, screenHeight/2 - explosion.getSize().y/2);

	sf::Texture texture;
	texture.loadFromFile("../picture/explosion.png");
	explosion.setTexture(&texture);
	Animation animation(&texture, sf::Vector2u(4, 4), 0.07f);
	float deltaTime = 0.0f;
	float dataTime = 0.f;
	sf::Clock clock;
	dataTime = clock.restart().asSeconds();
	while (window.isOpen()) {
		dataTime = clock.restart().asSeconds();
		sf::Event evt;
		while (window.pollEvent(evt)) {
			switch (evt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		block->blockMove(dataTime);
		bomb->bombUpdate(dataTime);
		bomb->bombCheckCollision();
		ball->ballUpdate(dataTime);
		ball->ballCheckCollision(block->getFloatRect());
		//if (bomb->bombCheckColision())
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			blockDown.move(sf::Vector2f(-blockSpeed * dataTime, 0.f));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			blockDown.move(sf::Vector2f(blockSpeed * dataTime, 0.f));
		}
		if (blockDown.getPosition().x <= 0) {
			blockDown.setPosition(0.f, blockDown.getPosition().y);
		}
		if (blockDown.getPosition().x >= width - blockDown.getSize().x) {
			blockDown.setPosition(width - blockDown.getSize().x, blockDown.getPosition().y);
		}*/
		/*bomb.move(0.f * dataTime, bombSpeed * dataTime);
		if ((bomb.getPosition().x + bomb.getSize().x >= blockDown.getPosition().x) && (bomb.getPosition().x + bomb.getSize().x <= blockDown.getPosition().x + blockDown.getSize().x))
		{
			std::cout << "Bummmmmm!";
			break;
		}*/
		animation.Update(0, dataTime);
		explosion.setTextureRect(animation.uvRect);

		window.clear(sf::Color(150, 150, 150));


		
		ground->Draw(window);
		block->Draw(window);
		//bomb->Draw(window);
		if (bomb->checkBombCollisionWithBlock(block->getFloatRect())) {
			explosion.setPosition(bomb->getPosition());
			window.draw(explosion);
			bomb->setPosition();
		}
		else bomb->Draw(window);
		if (bomb->getPosition().y + 50.f >= screenHeight) bomb->setPosition();
		ball->Draw(window);
		//window.draw(blockDown);
		//window.draw(bomb);
		window.display();
		//window.draw(player);
		
	}
}