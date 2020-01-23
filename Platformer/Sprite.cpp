#include "Sprite.h"
#include "Renderer.h"

Sprite::Sprite(float x_p, float y_p, float width_p, float height_p) :
	m_top{ y_p },
	m_bottom{ y_p + height_p },
	m_left{ x_p },
	m_right{ x_p + width_p },
	m_height{ height_p },
	m_width{ width_p },
	vertices{ m_left,  m_top,
			  m_right, m_top,
			  m_left,  m_bottom,
			  m_right, m_bottom }
{
	glGenBuffers(1, &this->VBO);
};

bool Sprite::collideRect(Sprite s_1, Sprite s_2)
{
	return s_1.m_top    < s_2.m_bottom &&
		   s_1.m_bottom > s_2.m_top    &&
		   s_1.m_left   < s_2.m_right  &&
		   s_1.m_right  > s_2.m_left;
};

void Sprite::move(float x_offset, float y_offset)
{
	this->m_top -= y_offset;
	this->m_bottom += y_offset;
	this->m_left -= x_offset;
	this->m_right += x_offset;
};