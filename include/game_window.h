#pragma once

#include "raylib.h"
#include <string>


namespace game {
	class GameWindow {
		public:
			GameWindow(int w, int h, std::string name);
			bool shouldClose(){return WindowShouldClose();}
			GameWindow(const GameWindow&) =delete;
			GameWindow & operator=(const GameWindow &) = delete;
			~GameWindow();

		private:
			void initWindow();
			const int height{};
			const int width{};
			std::string gameName{};
			


	};
}
