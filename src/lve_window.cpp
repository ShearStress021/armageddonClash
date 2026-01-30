#include "../include/lve_window.h"
#include <raylib.h>
#include "raymath.h"
#include <iostream>






namespace game {
	LiveWindow::LiveWindow(){
		
	};
	void LiveWindow::run(){


		// Camera setting
		Camera2D camera{};
		camera.target = (Vector2){};
		camera.offset = (Vector2) {};
		camera.rotation = 0.f;
		camera.zoom = 1.f;
		
		Texture2D map = LoadTexture("data/bg/bg_layer1.png");

		Vector2 mapPosition{};

		BaseCharacter player{WIDTH,HEIGHT};


		createTile(player);




		while(!gameWindow.shouldClose())
		{
			float deltaTime = GetFrameTime();

			Vector2 characterPos = player.getCharacterPosition();

			if (characterPos.x > WIDTH/2.f)
			{
				camera.target.x = characterPos.x - WIDTH/2.f;
			}

			mapPosition.x = -camera.target.x * 0.5f * deltaTime;

			float mapWidth = map.width * 4.f;

			mapPosition.x = fmod(mapPosition.x, mapWidth);
			std::cout << mapPosition.x << " " << -mapWidth << "\n";

			if (mapPosition.x <=  -mapWidth) mapPosition.x -= mapWidth;




		    BeginDrawing();
				ClearBackground(WHITE);
				BeginMode2D(camera);


				DrawTextureEx(map, mapPosition,0.f, 4.f, WHITE);

				player.drawPlayer(deltaTime);



				EndMode2D();
			EndDrawing();

		}
	}


	void LiveWindow::createTile(BaseCharacter & player)
	{
		short map[MAP_ROWS][MAP_COLS] = {
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			};

		for (int r=0; r < MAP_ROWS; r++)
		{
			for (int c=0; c < MAP_COLS; c++)
			{
				switch(map[r][c])
				{
					case 4:
						{
							Vector2 pos {
								(c * player.tex.width/1.f),
								(HEIGHT - (MAP_ROWS - r) * player.tex.height/1.f * 4)
							};

							player.setCharacterPosition(pos);
							
							break;
								
						}
				
				}
			}

		}
	}
	

	LiveWindow::~LiveWindow(){};
}
