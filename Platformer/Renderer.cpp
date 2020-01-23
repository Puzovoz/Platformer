#include "Renderer.h"

#include <iostream>

Renderer::Renderer() : shader{ Shader("shaders/shader.vs", "shaders/shader.fs") }
{
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
}

void Renderer::draw(Sprite s)
{
	shader.use();

	const unsigned int indices[]{
		0, 1, 2,
		1, 2, 3
	};

	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ARRAY_BUFFER, s.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(s.vertices), &s.vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
};
