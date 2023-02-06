#include "Tile.h"


Tile::Tile()
	:Entity(getId(), "Tile") {}

Tile::Tile(const size_t wall_num, TileType tile_type = BRICK)
	:m_wall_num(wall_num), m_tile_type(tile_type), Entity(getId(), "Tile")
{
	m_wall_num++;
}

size_t Tile::getwall_num()
{
	return m_wall_num;
}

void Tile::setTexture(const TileType &tile_type)
{
	if (!texture.loadFromFile("TileTextures.png"))
	{
		std::cout << "file did not load\n";
	}

	switch (tile_type)
	{
	case BRICK:
		shape->rectangle.setTexture(&texture);
		shape->rectangle.setTextureRect(sf::IntRect(0, 0, 25, 25));
		break;

	case ICE:
		shape->rectangle.setTexture(&texture);
		shape->rectangle.setTextureRect(sf::IntRect(26, 0, 25, 25));
		break;

	}
}


std::shared_ptr<Tile> Tile::add_tile(const TileType& tile_type)
{
	auto t = std::shared_ptr<Tile>(new Tile(getwall_num(), tile_type));
	
	m_tile_vec.push_back(t);
	return t;
}

std::vector<std::shared_ptr<Tile>> Tile::get_tiles()
{
	return m_tile_vec;
}

void Tile::remove_tile()
{
	for (auto t : m_tile_vec)
	{
		if (!m_active)
		{
			m_tile_vec.erase(std::remove(m_tile_vec.begin(), m_tile_vec.end(), t), m_tile_vec.end());
		}
	}
}

bool Tile::delete_tile()
{
	m_active = false;
	return m_active;
}