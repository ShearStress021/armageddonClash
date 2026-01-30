
#include "../include/baseCharacter.h"
#include <raylib.h>


namespace game {

	BaseCharacter::BaseCharacter(int wWidth, int wHeight) : 
		windowWidth(wWidth),
		windowHeight(wHeight)

	{
		maxFrames = 8.f;
	}

	void BaseCharacter::setCharacterPosition(Vector2 &pos)
	{
		characterPosition = pos;
	}

	Vector2 BaseCharacter::getCharacterPosition()
	{
		return characterPosition;
	}

	void BaseCharacter::drawPlayer(float deltaTime)
	{
		makeAnimation(deltaTime);
		characterMovement(deltaTime);

		Rectangle src{frame * tex.width/maxFrames, 0, tex.width/maxFrames* rightLeft,tex.height/1.f};
		Rectangle dest{getCharacterPosition().x,getCharacterPosition().y, tex.width/maxFrames* 3.f, tex.height/1.f * 3.f};
		Vector2 origin {};
		DrawTexturePro(tex, src, dest,origin, 0.f, WHITE);
	}

	void BaseCharacter::makeAnimation(float deltaTime)
	{
		runningTime += deltaTime;
		if (runningTime >= updateTime)
		{
			frame ++;
			runningTime = 0.f;

			if (frame > maxFrames) frame = 0;
		}
	}

	void BaseCharacter::characterMovement(float deltaTime)
	{
		float currentDirection{0};

		if(IsKeyDown(KEY_A)) currentDirection -= 1.0;
		if(IsKeyDown(KEY_D)) currentDirection += 1.0;

		if (currentDirection) rightLeft = currentDirection;

		switch(state)
		{
			case BaseCharacterState::idle:
				{
					if (currentDirection)
					{
						state = BaseCharacterState::running;
						maxFrames = 4.f;
						tex = texRun;

					}
					else 
					{
						velocity.x = 0;
					}
					break;
				}
			case BaseCharacterState::running:
				{
					if(!currentDirection)
					{
						state = BaseCharacterState::idle;
						maxFrames = 8.f;
						tex = texIdle;
					}
					break;
				}
		}

		velocity.x += currentDirection * speed * deltaTime;
		if(std::abs(velocity.x) > maxSpeedX)
		{
			velocity.x = currentDirection * speed;
		}
		characterPosition.x += velocity.x * deltaTime;
		
		characterJumping(deltaTime);

	}

	bool BaseCharacter::isOnGround()
	{
		return characterPosition.y >= windowHeight - tex.height * 3.f;

	}

	void BaseCharacter::characterJumping(float deltaTime)
	{
		if (isOnGround())
		{
			velocity.y = 0;
			isInAir = false;
		}
		else
		{
			velocity.y += gravity * deltaTime;
			isInAir = true;
		}

		if(IsKeyPressed(KEY_SPACE) && !isInAir)
		{
			velocity.y = jumpingDistance;
		}

		characterPosition.y += velocity.y * deltaTime;
	}


	BaseCharacter::~BaseCharacter()
	{
		UnloadTexture(tex);
		UnloadTexture(texRun);
		UnloadTexture(texIdle);
	}
	

}

