#include "raylib.h"
#include "raymath.h"
#include <iostream>



namespace game {

	enum class BaseCharacterState {
		idle, running, jumping

	};
	class BaseCharacter {
		public:
			Texture2D tex{LoadTexture("data/idle.png")};
			BaseCharacter(int w, int h);
			void drawPlayer(float deltaTime);
			void characterMovement(float deltaTime);
			void characterJumping(float deltaTime) ;
			void setCharacterPosition(Vector2 pos);
			Vector2 getCharacterPosition();
			void makeAnimations(float deltaTime);
			bool isOnGround();




		private:
			Texture2D texRun{LoadTexture("data/run.png")};
			Texture2D texIdle{LoadTexture("data/idle.png")};
			BaseCharacterState state{};
			Vector2 characterPosition{};
			Vector2 velocity{};
			int jumpDistance{-600};
			int gravity{1000};
			int windowWidth{};
			int windowHeight{};
			int frame{};
			int maxFrames{8};
			float runningTime{};
			float updateTime{1.0/8.0};
			float animationNumber{};
			bool isInAir{};
			float rightLeft{-1.f};
			float speed{300.f};
			float maxSpeedX{100.f};


	};

}
