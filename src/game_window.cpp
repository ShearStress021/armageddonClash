#include "game_window.h"
#include <raylib.h>




namespace game {
	GameWindow::GameWindow(int w, int h, std::string name):
		width(w),
		height(h),
		gameName(name)
	{
		initWindow();
	}

	void GameWindow::initWindow()
	{
		InitWindow(width, height,gameName.c_str());
		SetTargetFPS(60);
		Camera2D camera{0};
//		camera.target = 

	}
	GameWindow::~GameWindow(){
		 
		CloseWindow();
	}
		

} 
