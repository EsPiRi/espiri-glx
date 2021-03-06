#include <Window.h>
#include <Context.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

std::vector<Window *> Window::windows;

Window::Window() : Window(800, 600)
{
}
Window::Window(int width, int height)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(window, Window::framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	context = new Context();
	windows.push_back(this);
}

Window::~Window()
{
	glfwTerminate();
}

void Window::render()
{
	while (windows.size() > 0)
	{
		for (std::vector<Window *>::iterator x = windows.begin(); x != windows.end(); ++x)
		{
			glfwMakeContextCurrent((*x)->window);
			if (!glfwWindowShouldClose((*x)->window))
			{
				//(*x)->processInput((*x)->window);
				(*x)->context->render();

				glfwSwapBuffers((*x)->window);
				glfwPollEvents();
			}
			else
			{
				glfwDestroyWindow((*x)->window);
				windows.erase(x);
				break;
			}
		}
	}
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Window::processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	std::cout << "Window: " << window << "key: " << key << std::endl;
}
