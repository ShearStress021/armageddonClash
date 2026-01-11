#include "lve_window.h"
#include <raylib.h>
#include "raymath.h"
#include <iostream>



namespace game {
	LiveWindow::LiveWindow(){
		
	};
	void LiveWindow::run(){
		
		Texture2D map = LoadTexture("data/bg/bg_layer1.png");

		Vector2 mapPosition{};
		Character player{WIDTH,HEIGHT};

		createTile(player);


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

	void LiveWindow::createTile(Character &player){

		short map[MAP_ROWS][MAP_COLS] = {
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		};



		for(int r=0; r < MAP_ROWS; r++){
			for (int c = 0; c < MAP_COLS; c++)
			{
				switch(map[r][c])
				{

					case 4:
						{
								
							Vector2 characterPosition = {
								static_cast<float>(c * player.tex.width) ,
								static_cast<float>(HEIGHT - (MAP_ROWS - r) * player.tex.height * 4 )
							};

							player.setCharacterPosition(characterPosition);
							
							
							break;

						}

				
				}

			}
		}

	}


	

	LiveWindow::~LiveWindow(){};
}
