#ifndef WINDOW_H
#define WINDOW_H

struct GLFWwindow;
class Context;

class Window{

public:
	Context *context;
	GLFWwindow *window;
	Window();
	Window(int width,int height);
	~Window();
	void render();
	static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
	void processInput(GLFWwindow *window);
};

#endif
