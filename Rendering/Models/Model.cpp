#include "Model.h"
using namespace Rendering;
using namespace Models;

Model::Model(){

}

Model::~Model(){
	Destroy();
}

void Model::Draw(){
	//this is abstract, we don't continue to override this method
}

void Model::Update(glm::vec3 p,std::map<std::string, IGameObject*> passinggameModelList){
	//this is abstract, we don't continue to override this method
}

void Model::Destroy(){
}