#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Background {
	public:
		//variables
		sf::RectangleShape ground;
		sf::RectangleShape sky;
		sf::RectangleShape platform1;
		sf::RectangleShape platform2;
		sf::RectangleShape platform3;
		sf::RectangleShape platform4;
		sf::RectangleShape platform5;


	public:
		//functions
		Background() {
			ground.setSize(sf::Vector2f(800, 100));
			ground.setPosition(sf::Vector2f(0, 500));
			ground.setFillColor(sf::Color(139, 69, 19, 255));
			setPlatforms();
			
			sky.setSize(sf::Vector2f(600, 50));
			sky.setPosition(sf::Vector2f(0, 100));
			sky.setFillColor(sf::Color(0, 0, 139, 255));
		}

		void setPlatforms() {
			platform1.setSize(sf::Vector2f(100, 20));
			platform1.setPosition(sf::Vector2f(200, 400));
			platform1.setFillColor(sf::Color(105, 105, 105, 255));

			platform2.setSize(sf::Vector2f(100, 20));
			platform2.setPosition(sf::Vector2f(300, 350));
			platform2.setFillColor(sf::Color(105, 105, 105, 255));

			platform3.setSize(sf::Vector2f(100, 20));
			platform3.setPosition(sf::Vector2f(400, 300));
			platform3.setFillColor(sf::Color(105, 105, 105, 255));

			platform4.setSize(sf::Vector2f(100, 20));
			platform4.setPosition(sf::Vector2f(500, 250));
			platform4.setFillColor(sf::Color(105, 105, 105, 255));

			platform5.setSize(sf::Vector2f(100, 20));
			platform5.setPosition(sf::Vector2f(600, 200));
			platform5.setFillColor(sf::Color(105, 105, 105, 255));
		}

		void drawGround(sf::RenderWindow &window) {
			window.draw(ground);
			window.draw(sky);
		}

		void drawPlatforms(sf::RenderWindow &window) {
			window.draw(platform1);
			window.draw(platform2);
			window.draw(platform3);
			window.draw(platform4);
			window.draw(platform5);
		}

		//collisons
		float getPlatformOneY() {
			return platform1.getPosition().y - 32;
		}
		float getPlatformOneX() {
			return platform1.getPosition().x;
		}
		float getPlatformTwoY() {
			return platform2.getPosition().y - 32;
		}
		float getPlatformTwoX() {
			return platform2.getPosition().x;
		}
		float getPlatformThreeY() {
			return platform3.getPosition().y - 32;
		}
		float getPlatformThreeX() {
			return platform3.getPosition().x;
		}
		float getPlatformFourY() {
			return platform4.getPosition().y - 32;
		}
		float getPlatformFourX() {
			return platform4.getPosition().x;
		}
		float getPlatformFiveY() {
			return platform5.getPosition().y - 32;
		}
		float getPlatformFiveX() {
			return platform5.getPosition().x;
		}

		

};
