#include <Window.h>
#include <Context.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window():Window(800,600)
{
		
}
Window::Window(int width,int height){

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

	context=new Context();
}

Window::~Window(){
	glfwTerminate();
}

void Window::render(){
	while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        context->render();
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height){
	 glViewport(0, 0, width, height);
}


void Window::processInput(GLFWwindow *window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}