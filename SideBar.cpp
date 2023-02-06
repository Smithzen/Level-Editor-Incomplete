#include "SideBar.h"



Sidebar::Sidebar() { init(); }

void Sidebar::init()
{
	sidebar.setSize(sf::Vector2f(100.f, 600.f));
	sidebar.setFillColor(sf::Color::Blue);
	sidebar.setOutlineColor(sf::Color::Black);
	sidebar.setOutlineThickness(5.f);

	font.loadFromFile("calibri.ttf");

	tile_menu.setCharacterSize(20.f);
	tile_menu.setFont(font);
	tile_menu.setFillColor(sf::Color::Black);
	tile_menu.setString("Tiles");
	options.push_back(tile_menu);

	object_menu.setCharacterSize(20.f);
	object_menu.setFont(font);
	object_menu.setFillColor(sf::Color::Black);
	object_menu.setString("Objects");
	options.push_back(object_menu);

}

sf::RectangleShape Sidebar::create_sidebar()
{
	return sidebar;
}

std::vector<sf::Text> Sidebar::create_sidebar_options()
{
	return options;
}


Tile::TileType Sidebar::SelectTileTexture(const sf::Vector2f mouse_pos)
{
	if (mouse_pos.x < 200.f && mouse_pos.x > 0.f)
	{
		if (mouse_pos.y < 100.f && mouse_pos.y > 0.f)
		{
			tile_type = Tile::BRICK;
			return tile_type;
		}
		else if (mouse_pos.y < 200.f && mouse_pos.y > 100.f)
		{
			tile_type = Tile::ICE;
			return tile_type;
		}
	}
}