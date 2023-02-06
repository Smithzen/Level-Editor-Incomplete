#pragma once
#include "common.h"
#include "entity.h"
#include "Tile.h"
#include "SideBar.h"
#include "Objects.h"

class Editor
{

	sf::RenderWindow m_window;
	sf::View view;
	sf::View sidebar_view;
	sf::Cursor cursor;

	int view_top_hor = 0;
	int view_top_vert = 0;



	//sf::Vector2i mousePosScreen = sf::Mouse::getPosition();
	//sf::Vector2i mousePosWindow = sf::Mouse::getPosition(m_window);
	//sf::Vector2f mousePosView = m_window.mapPixelToCoords(mousePosWindow);
	//sf::Vector2u mousePosGrid;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;
	sf::Text text;
	std::stringstream ss;
	sf::Font font_calibri;
	sf::RectangleShape shape;
	sf::RectangleShape tileSelector;
	sf::Vector2f menu_pos;
	sf::Vector2f option_pos;


	int currentFrame = 0;
	float gridSize = 50.f;
	unsigned gridSizeU = static_cast<unsigned>(gridSize);
	float view_speed = 10.f;
	bool m_running = true;
	bool bCollision = false;
	bool place = true;
	bool bDelete = false;
	bool bBuild = false;
	bool bMenu = false;

	Tile m_tiles;
	Tile::TileType tile_type;
	Objects::ObjectType obj_type;
	Objects m_objects;
	Vec2 mouse_pos;
	Sidebar m_menu;

	void init();
	void Render();
	void sUserInput();
	void sBuildTile(const Tile::TileType tile_type, sf::Vector2f mouse_pos);
	void sPlaceObject(const Objects::ObjectType obj_type, sf::Vector2f mouse_pos);
	void sDelete(sf::Vector2f mousePosGrid);
	void sCollision();

public:
	Editor();
	void run();
};

