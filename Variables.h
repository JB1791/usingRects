#pragma once

class Variables {
public:
	//jumping variables
	float groundHeight = 468;
	double gravity = 9.8;
	bool isJumping = false;
	const float diagnolJump = 2.0;
	float newGroundHeight = 468;

	//platform ground variables
	const float platOneHeight = 368;
	const float platTwoHeight = 318;
	const float platThreeHeight = 268;
	const float platFourHeight = 218;
	const float platFiveHeight = 168;

	const float platformXSize = 100;
	const float platformYSize = 20;


};
