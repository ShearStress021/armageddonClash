#include "../include/baseCharacter.h"
#include <raylib.h>


namespace game {


	BaseCharacter::BaseCharacter(int w, int h) :
		windowWidth(w),
		windowHeight(h)
	{
		animationNumber =8.f;

	}

	void BaseCharacter::drawPlayer(float deltaTime)
	{
		characterMovement(deltaTime);

		makeAnimations(deltaTime);

		Rectangle src{(frame)*tex.width/animationNumber, 0, tex.width/animationNumber,tex.height/1.f};
		Rectangle dest{getCharacterPosition().x,getCharacterPosition().y, tex.width/ animationNumber* 3.f, tex.height/1.f * 3.f};
		Vector2 origin {};
		DrawTexturePro(tex, src, dest,origin, 0.f, WHITE);
	}


	Vector2 BaseCharacter::getCharacterPosition(){
		return characterPosition;
	}

	void BaseCharacter::setCharacterPosition(Vector2 pos)
	{
		characterPosition = pos;
	}

	void BaseCharacter::makeAnimations(float deltaTime)
	{
		runningTime += deltaTime;
		if (runningTime >= updateTime)
		{
			frame ++;
			runningTime = 0.f;

			if (frame > maxFrames) frame ++;
		}
	}
	void BaseCharacter::characterMovement(float deltaTime)
	{
		float currentDirection{0};

		if (IsKeyDown(KEY_A)) currentDirection -= 1.0;
		if (IsKeyDown(KEY_D)) currentDirection += 1.0;

		if (currentDirection) rightLeft = currentDirection;

		velocity.x += currentDirection * speed * deltaTime;

		if (std::abs(velocity.x) > maxSpeedX)
		{
			velocity.x = currentDirection * speed * deltaTime;

		}

		characterPosition.x += currentDirection * speed * deltaTime;

		characterJumping(deltaTime);

	}

	void BaseCharacter::characterJumping(float deltaTime)
	{
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

	bool BaseCharacter::isOnGround(){

		return characterPosition.y >= windowHeight - tex.height * 3.f;

	}


	

}
