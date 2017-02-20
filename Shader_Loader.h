#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<fstream>
#include<vector>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <glm\glm.hpp>

namespace Core{

	class Shader_Loader {
	private:
		std::string ReadShader(char *filename);
		GLuint CreateShader(GLenum shaderType, std::string source, char* shaderName);

	public:
		Shader_Loader();
		~Shader_Loader();
		GLuint CreateProgram(char* VertexShaderFilename, char* FragmentShaderFilename);

	};
}