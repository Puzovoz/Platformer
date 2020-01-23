#include "Sprite.h"
#include "Renderer.h"
#include "shader_h.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>
#include <iomanip>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	};
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Platformer", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	Sprite first_sprite(0.2f, 0.2f, 0.2f, 0.2f);
	Sprite second_sprite(0.0f, 0.0f, 0.2f, 0.2f);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);

		Renderer::Instance().draw(first_sprite);
		Renderer::Instance().draw(second_sprite);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}