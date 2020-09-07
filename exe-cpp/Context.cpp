#include <Context.h>
#include <glad/glad.h>
Context::Context()
{
}

void Context::render(){
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}