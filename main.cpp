#include <iostream>
#include <sfml/Graphics.hpp>
#include "Background.h"
#include "Player.h"
#include "Menu.h"
#include "Variables.h"
#include "Movement.h"

int main() {


	sf::RenderWindow window(sf::VideoMode(800, 600), "PLATFORMER");
	window.setKeyRepeatEnabled(true);
	window.setFramerateLimit(60);
	
	//objects for class files
	Background myBackground;
	Player myPlayer;
	Menu myMenu;
	Variables myVariables;
	Movement myMovement;


	while (window.isOpen()) {
		sf::Event evnt;

		float moveSpeed = 9.8;

		while (window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window.close();
			}
			//key released
			if (evnt.type == sf::Event::KeyReleased) {
				myVariables.isJumping = false;
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				myPlayer.move(sf::Vector2f(0, moveSpeed));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				myPlayer.move(sf::Vector2f(-moveSpeed, 0));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				myPlayer.move(sf::Vector2f(moveSpeed, 0));
			}
			//jump
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				myPlayer.move(sf::Vector2f(0, -moveSpeed));
				myVariables.isJumping = true;
			}

		}
		//gravity logic can't all be true
		if (myPlayer.getPosY() < myVariables.groundHeight && myVariables.isJumping == false) {
			myPlayer.move(sf::Vector2f(myVariables.diagnolJump, myVariables.gravity));
		}

		//all platform collision detection YAY, first platform
		if (myPlayer.getPosY() > myBackground.getPlatformOneY() && myPlayer.getPosX() > 200 && myPlayer.getPosX() < 300) {
			myVariables.groundHeight = myVariables.platOneHeight;
			std::cout << "collision plat one\n";
		}
		//second platform
		else if (myPlayer.getPosY() > myBackground.getPlatformTwoY() &&
			myPlayer.getPosX() > myBackground.getPlatformTwoX() && myPlayer.getPosX() < myBackground.getPlatformTwoX() + myVariables.platformXSize) {
			myVariables.groundHeight = myVariables.platTwoHeight;
			std::cout << "collision plat two\n";
		}
		//third platform
		else if (myPlayer.getPosY() > myBackground.getPlatformThreeY() &&
			myPlayer.getPosX() > myBackground.getPlatformThreeX() && myPlayer.getPosX() < myBackground.getPlatformThreeX() + myVariables.platformXSize) {
			myVariables.groundHeight = myVariables.platThreeHeight;
			std::cout << "collision plat three\n";
		}
		//fourth platform
		else if (myPlayer.getPosY() > myBackground.getPlatformFourY() &&
			myPlayer.getPosX() > myBackground.getPlatformFourX() && myPlayer.getPosX() < myBackground.getPlatformFourX() + myVariables.platformXSize) {
			myVariables.groundHeight = myVariables.platFourHeight;
			std::cout << "collision plat four\n";
		}
		//fifth platform
		else if (myPlayer.getPosY() > myBackground.getPlatformFiveY() &&
			myPlayer.getPosX() > myBackground.getPlatformFiveX() && myPlayer.getPosX() < myBackground.getPlatformFiveX() + myVariables.platformXSize) {
			myVariables.groundHeight = myVariables.platFiveHeight;
			std::cout << "collision plat five\n";
		}
		else//is not colliding with platform
		{
			myVariables.groundHeight = myVariables.newGroundHeight;
		}

		//sf float rect  sf::FloatRect  player_bounds = player.getGlobalBounds();
		
		
		window.clear();
		myPlayer.drawPlayer(window);
		myBackground.drawPlatforms(window);
		myBackground.drawGround(window);
		myMenu.drawText(window, "WELCOME");
		window.display();
	}//end main game loop

	//wiat for errors
	int tmp;
	std::cin >> tmp;

	return 0;
}
