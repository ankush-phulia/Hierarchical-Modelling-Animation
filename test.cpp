#include "Shader_Loader.h"
#include "GameModels.h"
#include <iostream>
#include <fstream>
#include <string>

Models::GameModels* gameModels;
GLuint program;

void renderScene(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3, 0.3, 1.0);

	glBindVertexArray(gameModels->GetModel("triangle1"));
	glUseProgram(program);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers();
}

void closeCallback(){
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init(){

	glEnable(GL_DEPTH_TEST);

	gameModels = new Models::GameModels();
	gameModels->CreateTriangleModel("triangle1");

	//load and compile shaders
	Core::Shader_Loader shaderLoader;	

	program = shaderLoader.CreateProgram("Source/Vertex_Shader.vert", "Source/Fragment_Shader.frag");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glewInit();
	if (glewIsSupported("GL_VERSION_4_3"))	{
		std::cout << " OpenGL Version is 4.3\n ";
	}
	else{
		std::cout << "OpenGL 4.3 not supported\n ";
	}

	Init();
	// register callbacks
	glutDisplayFunc(renderScene);
	glutCloseFunc(closeCallback);

	glutMainLoop();

	delete gameModels;
	glDeleteProgram(program);
	return 0;
}