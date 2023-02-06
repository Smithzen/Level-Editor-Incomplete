#pragma once
#include "entity.h"

class Tile :public Entity
{
	friend class Editor;
	friend class Sidebar;
	sf::Texture texture;
	size_t m_wall_num = 0;
	enum TileType
	{
		BRICK,
		ICE
	};
	std::vector<std::shared_ptr<Tile>> m_tile_vec;
	TileType m_tile_type;
public:
	Tile();
	Tile(const size_t wall_num, TileType tile_type);
	std::shared_ptr<Tile> add_tile(const TileType& tile_type);
	void remove_tile();
	std::vector<std::shared_ptr<Tile>> get_tiles();
	size_t getwall_num();
	void setTexture(const TileType& tile_type);
	bool delete_tile();


};
