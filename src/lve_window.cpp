#include "character.h"
#include "lve_window.h"
#include <raylib.h>
#include "raymath.h"
#include <iostream>



namespace game {
//	LiveWindow::LiveWindow(){};
	void LiveWindow::run(){
		
		Character player{WIDTH, HEIGHT};
		Texture2D map = LoadTexture("data/bg/bg_layer1.png");

		Vector2 mapPosition{};


		while(!gameWindow.shouldClose())
		{
			float deltaTime = GetFrameTime();



		    BeginDrawing();
				ClearBackground(WHITE);

				mapPosition = Vector2Scale(player.getWorldPosition(), -1.0f);

				DrawTextureEx(map, mapPosition,0.f, 4.f, WHITE);

				player.drawCharacter(deltaTime);





			EndDrawing();

		}
	}

//	LiveWindow::~LiveWindow(){};
}
