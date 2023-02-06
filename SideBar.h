#pragma once
#include "common.h"
#include "entity.h"
#include "Tile.h"


class Sidebar
{
	sf::RectangleShape sidebar;
	std::vector<sf::Text> options;
	sf::Text tile_menu;
	sf::Text object_menu;
	sf::Font font;
	void init();
	bool bMenu = false;
	Tile texture_selector;
	Tile::TileType tile_type;
public:
	Sidebar();
	sf::RectangleShape create_sidebar();
	std::vector<sf::Text> create_sidebar_options();
	Tile::TileType SelectTileTexture(sf::Vector2f mouse_pos);

};