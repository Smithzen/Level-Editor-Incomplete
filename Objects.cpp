#include "Objects.h"


Objects::Objects()
	:Entity(getId(), "Object")
{

}

Objects::Objects(const size_t object_num, const ObjectType obj_type)
	:m_object_num(object_num), m_obj_type(obj_type), Entity(getId(), "Object")
{
	m_object_num++;
}

std::vector<std::shared_ptr<Objects>> Objects::get_Objects()
{
	return obj_vec;
}

size_t Objects::get_object_num()
{
	return m_object_num;
}

std::shared_ptr<Objects> Objects::add_object(const ObjectType &obj_type)
{
	auto obj = std::shared_ptr<Objects>(new Objects(get_object_num(), obj_type));
	obj_vec.push_back(obj);
	return obj;
}

void Objects::setObjectType(const ObjectType& obj_type)
{
	if (!texture.loadFromFile("Objects.png"))
	{
		std::cout << "objects did not load!\n";
	}

	switch (obj_type)
	{
	case BALL:
		shape->sprite.setTexture(texture);
		shape->sprite.setTextureRect(sf::IntRect(0, 0, 25, 25));
	}
}
