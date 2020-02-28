#pragma once

#include <SFML/Graphics.hpp>

namespace Game
{
	class Assets
	{
	public:
		class LoadingFail{};

		static Assets& Instance() {
			static Assets assets;
			return assets;
		};
		void Load();

		sf::Font font;
		sf::Texture spaceship;

	private:
		Assets() {};
		~Assets() {};
		Assets(Assets const&) = delete;
		Assets& operator= (Assets const&) = delete;
	};
}