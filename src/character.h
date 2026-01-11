#pragma once
#include "raylib.h"



namespace game {
	class Character {
		private:
			Texture2D tex{LoadTexture("data/idle.png")};
			Texture2D texIdle{LoadTexture("data/idle.png")};
			Texture2D texRun{LoadTexture("data/run.png")};
			
			Vector2 characterPosition{};
			Vector2 worldPosition{};
			int windowWidth{};
			int windowHeight{};
			Vector2 velocity{};
			const int maxFrames{8};
			int frame{};
			const float speed{4.0f};
			const float scale{4.0f};
			float runningTime{};
			float updateTime{1.0f/12.0f};
			int width{};
			int height{};
		public:
			Character(int w, int h);
			Vector2 getCharacterPosition();
			Vector2 getWorldPosition();
			void drawCharacter(float deltaTime);
			~Character();
			


	};
}
