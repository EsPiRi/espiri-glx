#ifndef CONTEXT_H
#define CONTEXT_H
class Context{

public:

	Context();
	~Context();
	void render();
	unsigned int shaderProgram;
	unsigned int VAO,VBO;
};

#endif
