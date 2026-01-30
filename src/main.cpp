
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
        0.f
    };
    Vector2 posC{
        0.f,
        WINDOWHEIGHT - character.tex.height * 3.f
    };
    character.setCharacterPosition(posC);
	
    float bgx{};

    Texture2D map = LoadTexture("data/bg/bg_layer1.png");
    Vector2 posBg {};




    Camera2D camera{};
    camera.target = (Vector2){};
    camera.offset = (Vector2){};
    camera.rotation = 0.f;
    camera.zoom = 1.f;

    while (!WindowShouldClose())
    {
        
        Vector2 charPos = character.getCharacterPosition();

        if (charPos.x > WINDOWWIDTH/2.f)
        {
           camera.target.x = charPos.x - WINDOWWIDTH / 2.f;
        }

        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);

			float deltaTime{GetFrameTime()};

            DrawTextureEx(map,posBg,0.0,4.f,WHITE);
        
            character.drawPlayer(deltaTime);

            EndMode2D();
			
        EndDrawing();
    }
    UnloadTexture(map);

    CloseWindow();




    return 0;
}
