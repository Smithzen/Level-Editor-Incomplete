#pragma once
#include "common.h"
#include "entity.h"

class Objects :public Entity
{
	friend class Editor;
	friend class Sidebar;
	sf::Texture texture;
	size_t m_object_num = 0;
	sf::Sprite player;
	std::vector<std::shared_ptr<Objects>> obj_vec;
	enum ObjectType
	{
		BALL
	};
	ObjectType m_obj_type;
public:
	Objects();
	Objects(const size_t Object_num, const ObjectType obj_type);
	std::shared_ptr<Objects> add_object(const ObjectType &obj_type);
	std::vector < std::shared_ptr<Objects>> get_Objects();
	size_t get_object_num();
	void setObjectType(const ObjectType& obj_type);
};