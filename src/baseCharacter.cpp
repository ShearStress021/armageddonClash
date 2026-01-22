#include "../include/baseCharacter.h"
#include <raylib.h>
#include <raymath.h>
#include <string>


BaseCharacter::BaseCharacter(int wWidth, int wHeight) :
		windowWidth(wWidth),
		windowHeight(wHeight)
		
{
	tex = LoadTexture("data/idle.png");
	texIdle = LoadTexture("data/idle.png");
	texRun = LoadTexture("data/run.png");
	maxSpeedX = 100;
	animationNumber = 8.f;

}
Vector2 BaseCharacter::getCharacterPosition(){
	return characterPosition; 


}
void BaseCharacter::setCharacterPosition(Vector2 &pos){
	characterPosition = pos; 

}

void BaseCharacter::characterMovement(float deltaTime)
{

	float currentDirection{0};

	if(IsKeyDown(KEY_A)) currentDirection -= 1.0;
	if(IsKeyDown(KEY_D)) currentDirection += 1.0;

	if (currentDirection)
	{
		rightLeft = currentDirection;
	}


	switch(state)
	{
		case BaseCharacterState::idle:
			{
				if (currentDirection)
				{
					state = BaseCharacterState::running;
					animationNumber = 4.f;
					tex = texRun;
				}
				break;
			}

		case BaseCharacterState::running:
			{
				if (!currentDirection)
				{
					animationNumber = 8.f;
					state = BaseCharacterState::idle;
					tex = texIdle;
				}
				break;
			}
	}


	velocity.x += currentDirection * speed * deltaTime;

	if (std::abs(velocity.x) > maxSpeedX)
	{
		velocity.x = currentDirection * speed;
	}

	characterPosition.x += velocity.x * deltaTime;

	characterJumping(deltaTime);
}


void BaseCharacter::drawPlayer(float deltaTime)
{

	makeAnimation(deltaTime);
	characterMovement(deltaTime);






	Rectangle src{frame * tex.width/animationNumber, 0, tex.width/animationNumber * rightLeft,tex.height/1.f};
	Rectangle dest{getCharacterPosition().x,getCharacterPosition().y, tex.width/animationNumber * 3.f, tex.height/1.f * 3.f};
	Vector2 origin {};
	DrawTexturePro(tex, src, dest,origin, 0.f, WHITE);
	
}



bool BaseCharacter::isOnGround(){

	return characterPosition.y >= windowHeight - tex.height * 3.f;

}
void BaseCharacter::characterJumping(float deltaTime){


	if (isOnGround())
	{
		velocity.y  = 0;
		isInAir = false;
	}
	else 
	{

		velocity.y += gravity * deltaTime;
		isInAir = true;
	}
	if(IsKeyPressed(KEY_SPACE) && !isInAir)
	{
		velocity.y = jumpDistance;

	}

	characterPosition.y += velocity.y  * deltaTime;

	std::string inAir = "Is In Air ";
	inAir.append(std::to_string(static_cast<bool>(isInAir)));
	
	DrawText(inAir.c_str(),0,0,20,RED);


}

void BaseCharacter::makeAnimation(float deltaTime)
{

	runningTime += deltaTime;
	if (runningTime >= updateTime )
	{
		frame ++;
		runningTime = 0.f;

		if(frame > maxFrames) frame = 0;

	}
}

void BaseCharacter::updateData() {
}


Vector2 BaseCharacter::getWorldPosition()
{
	return worldPosition;
}



BaseCharacter::~BaseCharacter(){ 
	UnloadTexture(tex);
	UnloadTexture(texIdle);
	UnloadTexture(texRun);
}



