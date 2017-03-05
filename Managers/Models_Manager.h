#pragma once
#include <unordered_map>
#include "Shader_Manager.h"
#include "../Rendering/IGameObject.h"
#include "../Rendering/Models/Triangle.h"
#include "../Rendering/Models/Quad.h"

using namespace Rendering;

namespace Managers {
	class Models_Manager{
	public:
		int num_models;
		Models_Manager();
		~Models_Manager();
		void createModel(double x1, double y1, double z1, double r1, double b1, double g1, double x2, double y2, double z2, double r2, double b2, double g2, double x3, double y3, double z3, double r3, double b3, double g3);
		void createModel(double x1, double y1, double z1, double r1, double b1, double g1, double x2, double y2, double z2, double r2, double b2, double g2, double x3, double y3, double z3, double r3, double b3, double g3, double x4, double y4, double z4, double r4, double b4, double g4);
		
		void Draw();
		void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix);
		void Update();		
		
		void DeleteModel(const std::string& gameModelName);
		const IGameObject& GetModel(const std::string& gameModelName) const;
		void SetModel(const std::string& gameObjectName, IGameObject* gameObject);

	private:
		std::map<std::string, IGameObject*> gameModelList; //slow iteration?	
	};
}
