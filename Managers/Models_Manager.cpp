#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager(){
	num_models = 0;
	//num_models++;
	/*Models::Cuboid* cube = new Models::Cuboid();
	cube->SetProgram(Shader_Manager::GetShader("colorShader"));
	cube->Create();
	gameModelList["cub" + num_models] = cube;*/
}

Models_Manager::~Models_Manager(){	
	for (auto model: gameModelList)	{
		delete model.second;
	}
	gameModelList.clear();
}

void Models_Manager::createModel(double x1, double y1, double z1, double r1, double b1, double g1,
	double x2, double y2, double z2, double r2, double b2, double g2,
	double x3, double y3, double z3, double r3, double b3, double g3) {
	num_models++;
	Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(Shader_Manager::GetShader("colorShader"));
	triangle->Create(x1, y1, z1, r1, b1, g1, x2, y2, z2, 
		r2, b2, g2, x3, y3, z3, r3, b3, g3);
	gameModelList["tri"+num_models] = triangle;
}

void Models_Manager::createModel(double x1, double y1, double z1, double r1, double b1, double g1,
	double x2, double y2, double z2, double r2, double b2, double g2,
	double x3, double y3, double z3, double r3, double b3, double g3,
	double x4, double y4, double z4, double r4, double b4, double g4) {
	num_models++;
	Models::Quad* quad = new Models::Quad();
	quad->SetProgram(Shader_Manager::GetShader("colorShader"));
	quad->Create(x1, y1, z1, r1, b1, g1, x2, y2, z2,
		r2, b2, g2, x3, y3, z3,	r3, b3, g3, 
		x4, y4, z4, r4, b4, g4);
	gameModelList["quad"+num_models] = quad;
}

void Models_Manager::DeleteModel(const std::string& gameModelName){
	IGameObject* model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);
}

const IGameObject& Models_Manager::GetModel(const std::string& gameModelName) const{
	return (*gameModelList.at(gameModelName));
}

void Models_Manager::Update(){
	for (auto model: gameModelList){
		model.second->Update();
	}
}

void Models_Manager::Draw(){
	for (auto model : gameModelList){
		model.second->Draw();
	}
}

void Models_Manager::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix){
	for (auto model : gameModelList){
		model.second->Draw(projection_matrix, view_matrix);
	}
}

void Models_Manager::SetModel(const std::string& gameObjectName, IGameObject* gameObject){
	gameModelList[gameObjectName.c_str()] = gameObject;
}