#pragma once
#include "common.h"
#include "components.h"
#include <memory>

//entity class from which all objects will derive from
class Entity
{
	size_t m_id = 0;
	std::string m_tag = "default";
	Entity();
public:
	bool m_active = true;
	Entity(const size_t id, const std::string& tag);
	//component pointers
	std::shared_ptr<CTransform> transform;
	std::shared_ptr<CShape> shape;
	std::shared_ptr<CCollision> collision;
	std::shared_ptr<CInput> input;
	std::shared_ptr<CGravity> gravity;
	const std::string& getTag() const;
	const size_t getId() const;
};


