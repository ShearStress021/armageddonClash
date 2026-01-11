#include "character.h"
#include <raylib.h>
#include <raymath.h>

namespace game {

	Character::Character(int w, int h) :
		windowWidth(w),
		windowHeight(h)
	{
		width = tex.width/ maxFrames;
		height = tex.height;

	}


	Vector2 Character::getWorldPosition(){
		return worldPosition;
	}
	
	void Character::drawCharacter(float deltaTime){

		if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
		if (IsKeyDown(KEY_D)) velocity.x += 1.0;

		runningTime += deltaTime;

		if (runningTime >= updateTime){
			frame ++;
			runningTime = 0.f;

			if (frame >  maxFrames) frame = 0;
		}

		if (Vector2Length(velocity) != 0.0)

		{
			worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(velocity), speed));
			tex = texRun;
		}
		else 
		{
			tex = texIdle;
		}


		Rectangle src {
			.x = static_cast<float>(width) * frame,
			.y = 0,
			.width = static_cast<float>(width),
			.height = height/1.f

		};

		Rectangle dest {
			.x = getCharacterPosition().x,
			.y = getCharacterPosition().y, 
			.width = width / 1.f * scale,
			.height = height/ 1.f * scale 
		};
		Vector2 origin {};
		


		


		velocity = {};
		DrawTexturePro(tex, src ,dest,origin,0.f,WHITE);



	}

	Vector2 Character::getCharacterPosition(){
		return Vector2{
			static_cast<float>(windowWidth)/2.f - width,
			static_cast<float>(windowHeight) - (height * scale)

		};
	}


	Character::~Character(){
		UnloadTexture(tex);

	}
		

}

