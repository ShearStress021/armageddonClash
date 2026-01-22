
#include "raylib.h"
#include "raymath.h"

#include "../include/baseCharacter.h"
#define  WINDOWWIDTH 1200
#define  WINDOWHEIGHT 920


int main(void)
{
    InitWindow(WINDOWWIDTH,WINDOWHEIGHT, "armagadom clash");

	BaseCharacter character{WINDOWWIDTH, WINDOWHEIGHT};

    Vector2 pos{
        0.f,
        WINDOWHEIGHT - character.tex.height * 3.f
    };
    character.setCharacterPosition(pos);
	
    float bgx{};

    Texture2D map = LoadTexture("data/bg/bg_layer1.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        
            ClearBackground(RAYWHITE);


			float deltaTime{GetFrameTime()};
            
            bgx -=  20 *character.getWorldPosition().x * deltaTime;

            Vector2 posBg {
                bgx, 0.f
            };


            DrawTextureEx(map,posBg,0.0,4.f,WHITE);
        
            
            
            character.drawPlayer(deltaTime);

			
        EndDrawing();
    }
    UnloadTexture(map);

    CloseWindow();

    return 0;
}
