#pragma once
#include <sfml/Graphics.hpp>
#include <sfml/Graphics/Font.hpp>
#include <iostream>

class Menu {
public:
	//variables
	sf::Font font;
	sf::Text text;

public:
	//functions
	Menu() {
		//constructor
		loadFont("lunchds.ttf");
		text.setFont(font);
		text.setPosition(sf::Vector2f(350, 50));
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(50);
	}
	void loadFont(std::string fontFile) {
		if (!font.loadFromFile(fontFile)) {
			std::cout << "connot load font from file\n";
		}
	}

	void drawText(sf::RenderWindow &window, std::string output) {
		text.setString(output);
		window.draw(text);
	}

};
