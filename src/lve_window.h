#pragma once
#include "game_window.h"




namespace game {
	class LiveWindow
	{
		public:
			static constexpr int WIDTH{800};
			static constexpr int HEIGHT{600};
			void run();
//			LiveWindow();
//			LiveWindow(const LiveWindow& )= delete;
//			LiveWindow & operator = (const LiveWindow& ) = delete;
//			~LiveWindow();



	
		private:
			GameWindow gameWindow{WIDTH, HEIGHT, "The Armageddon Clash"};

		 
	};
}
