#pragma once
#include "../Rendering/IGameObject.h"
#include "../Rendering/Models/Frog.h"

using namespace Rendering;

namespace Managers {
	class Models_Manager{
	public:
		Models_Manager();
		~Models_Manager();
		void Draw();
		void Update(glm::vec3 ins);
		void DeleteModel(const std::string& gameModelName);
		const IGameObject& GetModel(const std::string& gameModelName) const;

	private:
		std::map<std::string, IGameObject*> gameModelList,passinggameModelList;
	};
}
