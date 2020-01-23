#ifndef SPRITE_H
#define SPRITE_H

#include <array>

class Sprite {
public:
	unsigned int VBO;
	float m_top;
	float m_bottom;
	float m_left;
	float m_right;
	float m_height;
	float m_width;
	std::array<float, 8> vertices;

	Sprite(float x_p, float y_p, float width_p, float height_p);

	static bool collideRect(const Sprite first, const Sprite second);
	void move(const float x_offset, const float y_offset);
};
#endif
