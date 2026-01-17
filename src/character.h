#pragma once
#include "raylib.h"



namespace game {
	enum class CharacterState{
		idle, running, jumping
	};


	class Character {
		private:
			Texture2D texIdle{LoadTexture("data/idle.png")};
			Texture2D texRun{LoadTexture("data/run.png")};
			Vector2 worldPosition{};
			int windowWidth{}; int windowHeight{};
			Vector2 velocity{};
			const int maxFrames{8};
			int frame{};
			const float speed{4.0f};
			const float scale{4.0f};
			float runningTime{};
			float updateTime{1.0f/12.0f};
			int width{};
			int height{};
			CharacterState state{};
			float gravity{1000};
			float leftRight{-1.f};
			bool isInAir{false};
			const float jumpingDistance{-600};
			Vector2 characterPosition{};
			
		public:
			Character(int w, int h);
			Vector2 getCharacterPosition();
			Vector2 getWorldPosition();
			Vector2 playerPosition{};
			Texture2D tex{LoadTexture("data/idle.png")};
			void drawCharacter(float deltaTime);
			void setCharacterPosition(Vector2 pos);
			bool IsOnGround();
			int getWidth();
			int getHeight();
			~Character();
			


	};
}
