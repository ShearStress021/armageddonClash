#pragma once
#include "raylib.h"
#include "raymath.h"
#include "string"
#define WINDOWWIDTH 1200
#define WINDOWHEIGHT 920


enum class BaseCharacterState {
	idle, running , jumping
};


class BaseCharacter {

	private:
		Texture2D texIdle{};
		Texture2D texRun{};
		Vector2 velocity{};
		BaseCharacterState state{};
		float runningTime{};
		float updateTime{1.0/12.0};
		float frame{};
		float maxFrames{8};
		int windowWidth{};
		int windowHeight{};
		bool isInAir{};
		float animationNumber{};
		int jumpDistance{-600};
		int gravity{1000};
		float rightLeft{-1.f};
		float maxSpeedX{};
		float speed{300.f};
		Vector2 characterPosition{};
		Vector2 worldPosition{};
		
	
	public:
		Texture2D tex{};
		BaseCharacter(int width, int height);
		void drawPlayer(float deltaTime);
		Vector2 getCharacterPosition();
		void setCharacterPosition(Vector2 &pos);
		Vector2 getWorldPosition();
		void characterJumping(float deltaTime);
		void characterMovement(float deltaTime);
		void makeAnimation(float deltaTime);
		void updateData();
		bool isOnGround();
		std::string get_state(BaseCharacterState state);
		~BaseCharacter();


};
