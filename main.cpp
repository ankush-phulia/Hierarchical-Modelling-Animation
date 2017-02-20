#include "Managers\Shader_Manager.h"
#include "Core\GameModels.h"
#include<iostream>
#include<stdio.h>;
#include<stdlib.h>;
#include<fstream>;
#include<vector>;

#include <iostream>

Models::GameModels* gameModels;
Managers::Shader_Manager* shaderLoader;
GLuint program;
GLint totalm;

void renderScene(void) {
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
	shaderLoader = new Managers::Shader_Manager();
	shaderLoader->CreateProgram("colorShader","Shaders/Vertex_Shader.glsl", "Shaders/Fragment_Shader.glsl");
	program = Managers::Shader_Manager::GetShader("colorShader");

}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	
	glutCreateWindow("OpenGL First Window");

	//auto c = glGetError();
	glewExperimental = true;
	glewInit();	
	
	if (glewIsSupported("GL_VERSION_4_3")){
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
	
	while (true) {
	}

	delete gameModels;
	delete shaderLoader;

	return 0;
}
