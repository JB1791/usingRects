#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	//variables
	sf::RectangleShape player;

public:
	//functions
	Player() {
		player.setSize(sf::Vector2f(32,32));
		player.setFillColor(sf::Color(128, 0, 0,255));
		player.setPosition(sf::Vector2f(50, 468));
	}

	void drawPlayer(sf::RenderWindow &window) {
		window.draw(player);
	}

	float getPosX() {
		return player.getPosition().x;
	}

	float getPosY() {
		return player.getPosition().y;
	}

	void move(sf::Vector2f dir) {
		player.move(dir);
	}

	void setPosition(sf::Vector2f(newPos)) {
		player.setPosition(newPos);
	}


};
