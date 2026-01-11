#include "character.h"
#include <iostream>
#include "lve_window.h"
#include <raylib.h>
#include <variant>


namespace game {
	enum class PlayerState {
		running, idle, jumping

	};


	enum class ObjectType {
		player, level, enemy

	};

	


	struct EnemyData{

	};


	struct LevelData{

	};




	using ObjectData = std::variant<Character, EnemyData, LevelData>;
	struct GameObject {
		ObjectData data;
		ObjectType type{};
		Vector2 position{};
		Texture2D *texture{};

		GameObject() : data{LevelData()} 
		{
			texture = nullptr;
			position = Vector2{};
			type = ObjectType::level;
			
		}

	};


}

