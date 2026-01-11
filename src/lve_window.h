#pragma once
#include "character.h"
#include "game_window.h"

#define  MAP_ROWS 5
#define  MAP_COLS 50




namespace game {
	class LiveWindow
	{
		public:
			static constexpr int WIDTH{1200};
			static constexpr int HEIGHT{920};
			
			void run();
			void createTile(Character& player);
			LiveWindow();
			LiveWindow(const LiveWindow& )= delete;
			LiveWindow & operator = (const LiveWindow& ) = delete;
			~LiveWindow();

	
		private:
			GameWindow gameWindow{WIDTH, HEIGHT, "The Armageddon Clash"};

		 
	};
}
