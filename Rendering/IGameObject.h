#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "VertexFormat.h"

namespace Rendering{

	class IGameObject{
	public:
		virtual ~IGameObject() = 0;
		virtual void Draw() = 0;
		virtual void Update(glm::vec3 ins,std::map<std::string, IGameObject*> passinggameModelList) = 0;
		virtual void Destroy() = 0;
	};

	inline IGameObject::~IGameObject(){

	}
}
