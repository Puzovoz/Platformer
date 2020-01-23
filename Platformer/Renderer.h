#ifndef RENDERER_H
#define RENDERER_H

#include "Sprite.h"
#include "shader_h.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <vector>

class Renderer
{
public:
	static Renderer& Instance()
	{
		static Renderer s;
		return s;
	};

	void draw(Sprite s);

private:
	std::vector<float> sprite_vertices;
	Shader shader;
	unsigned int EBO;

	Renderer();
	~Renderer() {};

	Renderer(Renderer const&) = delete;
	Renderer& operator= (Renderer const&) = delete;
};
#endif