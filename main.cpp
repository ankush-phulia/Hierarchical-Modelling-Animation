#pragma once
#include "Core\Init_GLUT.h"
#include "Managers\Scene_Manager.h"
#include "Cuboid.h"

using namespace Core;
using namespace Init;
using namespace Rendering;

int main(int argc, char **argv){

	Managers::Scene_Manager*  scene_manager;
	Managers::Shader_Manager* shader_manager;
	Managers::Models_Manager* models_manager;
	TextureLoader* texture_loader;

	WindowInfo window(800, 600);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	Init::Init_GLUT::Init(window, frameBufferInfo);

	scene_manager = new Managers::Scene_Manager();
	Init::Init_GLUT::SetListener(scene_manager);
	shader_manager = new Managers::Shader_Manager();
	texture_loader = new TextureLoader();

	shader_manager->CreateProgram("colorShader",
		"Shaders\\Cube_Vertex_Shader.glsl",
		"Shaders\\Cube_Fragment_Shader.glsl");

	Models::Cuboid* cube = new Models::Cuboid();
	cube->SetProgram(shader_manager->GetShader("colorShader"));
	cube->Create();

	//unsigned int texture = texture_loader->LoadTexture("Textures\\frog.bmp", 256, 256);
	//cube->SetTexture("frog", texture);

	models_manager = new Managers::Models_Manager();
	models_manager->SetModel("cube", cube);
	scene_manager->SetModelsManager(models_manager);

	glDisable(GL_CULL_FACE);

	Init::Init_GLUT::Run();
	return 0;
}
