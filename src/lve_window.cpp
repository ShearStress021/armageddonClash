#include "lve_window.h"



namespace game {
//	LiveWindow::LiveWindow(){};
	void LiveWindow::run(){
		while(!gameWindow.shouldClose())
		{

		    BeginDrawing();
				ClearBackground(RAYWHITE);
				DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
			EndDrawing();

		}
	}

//	LiveWindow::~LiveWindow(){};
}
