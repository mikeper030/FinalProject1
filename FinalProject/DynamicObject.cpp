#include "DynamicObject.h"



DynamicObject::DynamicObject()
{
}

void DynamicObject::move(sf::Vector2f & v)
{
	m_sprite.move(v);
}

sf::Sprite & DynamicObject::getActiveObject()
{
	return m_sprite;
}



