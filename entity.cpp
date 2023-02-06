#include "common.h"
#include "entity.h"

Entity::Entity(const size_t id, const std::string& tag)
	:m_id(id), m_tag(tag) {}

const std::string& Entity::getTag() const
{
	return m_tag;
}

const size_t Entity::getId() const
{
	return m_id;
}


