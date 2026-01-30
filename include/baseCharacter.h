
#pragma once

#include "raylib.h"
#include "string"

namespace game {
	enum class BaseCharacterState 
	{
		idle, running, jumping
	};


	class BaseCharacter 
	{
		private:
			Texture2D texIdle{LoadTexture("data/idle.png")};
			Texture2D texRun{LoadTexture("data/run.png")};
			Vector2 velocity{};
			BaseCharacterState state{};
			float runningTime{};
			float updateTime{1.0/12.f};
			float frame{};
			float maxFrames{8.f};
			int windowWidth{};
			int windowHeight{};
			bool isInAir{};
			int jumpingDistance{-600};
			int gravity{1000};
			float rightLeft{-1.f};
			float maxSpeedX{100.f};
			float speed{300.f};
			Vector2 characterPosition{};
			Vector2 worldPosition{};
		

			

			

		public:
			Texture2D tex{LoadTexture("data/idle.png")};
			BaseCharacter(int winWidth, int winHeight);
			void drawPlayer(float deltaTime);
			Vector2 getCharacterPosition();
			void setCharacterPosition(Vector2 & pos);
			Vector2 getWorldPosition();
			void characterJumping(float deltaTime);
			void characterMovement(float deltaTime);
			void makeAnimation(float deltaTime);
			bool isOnGround();
			std::string get_state(BaseCharacterState state);
			~BaseCharacter();




	};


}

