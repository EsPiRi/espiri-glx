#ifndef WINDOW_H
#define WINDOW_H
#include <vector>
struct GLFWwindow;
class Context;

class Window
{

public:
	Context *context;
	GLFWwindow *window;
	static std::vector<Window *> windows;
	Window();
	Window(int width, int height);
	~Window();
	static void render();
	static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
	void processInput(GLFWwindow *window);
};

#endif
